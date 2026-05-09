#include "cpu.h"
#include "system/includes.h"
#include "btstack/btstack_task.h"
#include "app_config.h"
#include "app_action.h"
#include "asm/pwm_led.h"
#include "tone_player.h"
#include "ui_manage.h"
#include "gpio.h"
#include "app_main.h"
#include "asm/charge.h"
#include "update.h"
#include "app_power_manage.h"
#include "audio_config.h"
#include "app_charge.h"
#include "user_cfg.h"
#include "bt_tws.h"
#include "clock_cfg.h"
#include "timer.h"
#include "btstack/avctp_user.h"
#include "app_core.h"
#include "key_event_deal.h"
#include "bt_tws.h"
#include "audio_dec_file.h"
#include "string.h"
#include "app_task.h"
#include "app_msg.h"
#include "mic_effect.h"
#include "ui/ui_api.h"
#include "audio_dec.h"
#include "audio_digital_vol.h"
#include "music_player.h"
#include "application/audio_output_dac.h"
#include "mic_effect.h"
#include "audio_dec.h"
#include "app_action.h"

#if TCFG_DEV_POWER_ENABLE
extern u8 dev_power_online = 0;
void dev_power_init(void)
{
    if(dev_power_online)
    {
       TCFG_DEV_POWER_OFF();
    }else
    {
       TCFG_DEV_POWER_ON();
    }
}
#endif


#if TCFG_CHANGE_POWER_ENABLE
extern u8 change_online_stat = 0;
void change_power_init(void)
{
    if(!power_mute_up)
    {
        return;
    }

    TCFG_CHANGE_POWER_INIT();
    if(TCFG_CHANGE_POWER_INSERT())
    {
       if(!change_online_stat)
       {
           change_online_stat  = 1;
       }
    }else
    {
       if(change_online_stat)
       {
           if (app_get_curr_task()==APP_IDLE_TASK)
           {
               power_set_soft_poweroff();
           }
           change_online_stat = 0;
       }
    }
}

#endif

//无线有线麦检测///////////////////////////
#if TCF_MIC_DETECTION_ENABLE
extern u8 mic_online_start = 0;

u8 mic_online_flag = 0;+
u8 mic_off_count = 0;
u8 mic_staer = 0;


u8 mic_start_mute = 0;
u8 mic_conn_flag = 0;
u8 linein_key_online = 0;
void conn_mic_mute(void)
{
    if (app_get_curr_task()==APP_LINEIN_TASK)
    {
       if(!linein_key_online)
       {
          audio_linein_mute(0);
       }
    }

    mic_start_mute = 0;

}

void mic_dev_detection_init(void)
{
    
    if(!power_mute_up)
    {
        return;
    }
    
    // TCFG_MIC_DETECTION_INIT();
    // printf("is_wireless_mic_online=%d\n",is_wireless_mic_online);
    if(/*TCFG_MIC_DETECTION_ONLINE()*/is_wireless_mic_online)
    {
        if(!mic_online_flag)
        {
#if TCFG_MIC_EFFECT_ENABLE
            // mic_start_mute = 1;
             mic_voicechange_switch(0); //变声音效指定模式切换
#endif
            sys_timeout_add(NULL,conn_mic_mute,1000);
            mic_online_flag = 1;
        }

#if TCFG_MIC_DODGE_EN
        int audio_mic_energy_get(void);
        if(audio_mic_energy_get()<300)   //麦克风能量检测接口
        {
            if(mic_off_count<10)    //100
            {
                mic_off_count++;

            }

        }else
        {
            mic_off_count = 0;
        }

        if(mic_off_count==10)      //100
        {
            if(!mic_staer)
            {
                mic_effect_set_dvol(0);//数字音量调节接口
                mic_staer = 1;
            }

        }else
        {
            if(mic_staer)
            {
                mic_effect_set_dvol(30);
                mic_staer = 0;
            }
        }


#endif
    }else
    {
        if(mic_online_flag)
        {
#if TCFG_MIC_EFFECT_ENABLE
            mic_effect_stop(); //(mic数据流)混响关闭接口
#endif
            mic_online_flag = 0;
        }
    }
}
#endif



#if TCFG_MUSIC_VOL_DETECTION
u8 music_vol_ad_size = 0;
u8 music_vol_ad_date = 0;
u8 linein_mute_online = 0;
void music_vol_init(void)
{

   if(!power_mute_up)
    {
        return;
    }

    if (app_get_curr_task()==APP_IDLE_TASK)
    {
        return;
    }

    if(tone_get_status())
    {
       music_vol_ad_date =  0;
       return;
    }

   TCFG_MUSIC_VOL_INIT();
   adc_add_sample_ch(TCFG_MUSIC_VOL_AD);
   adc_get_voltage(TCFG_MUSIC_VOL_AD);

   music_vol_ad_size=adc_get_voltage(TCFG_MUSIC_VOL_AD)/117;

   if(music_vol_ad_size>app_audio_get_max_volume())
   {
       music_vol_ad_size = app_audio_get_max_volume();
   }

   if(music_vol_ad_date!=music_vol_ad_size)
   {
      music_vol_ad_date = music_vol_ad_size;
      app_audio_echo_up(music_vol_ad_size);
   }
}
#endif



#if TCFG_ENCODER_DETECTION

extern void bt_tws_sync_volume();
struct rdec_device_soft
{
  unsigned char sin_port0;
  unsigned char sin_port1;
  int msg;

  unsigned char io[2];
  unsigned char st[2];
};

unsigned char rdec_device_num = 0;
struct rdec_device_soft user_rdeckey_list[]={
  {
     .sin_port0 = TCFG_ENCODER_ONE_IO,
     .sin_port1 = TCFG_ENCODER_TWO_IO,
     .msg = USER_MSG_TEST,
  },
};

void rdec_device_scan(void)
{
  unsigned char tp0,tp1;
  unsigned char index = 0;
  struct rdec_device_soft *rdec;

   if(!power_mute_up)
    {
        return;
    }

  for(index = 0; index < rdec_device_num;index++)
  {
        rdec = &user_rdeckey_list[index];
        tp0 = gpio_read(rdec->sin_port0);
        tp1 = gpio_read(rdec->sin_port1);

        if((tp0&&tp1)||((!tp0)&&(!tp1)))
        {
           if(rdec->io[0])
           {
              printf("-----1-------\n");
             if (app_get_curr_task()==APP_BT_TASK)
             {
                 app_task_put_key_msg(KEY_VOL_UP,0);
#if TCFG_USER_TWS_ENABLE
                bt_tws_sync_volume();
#endif
             }else
             {
                app_task_put_key_msg(KEY_VOL_UP,0);

             }

           }else if(rdec->io[1])
           {
              printf("-----2-------\n");
             if (app_get_curr_task()==APP_BT_TASK)
             {
               app_task_put_key_msg(KEY_VOL_DOWN,0);
#if TCFG_USER_TWS_ENABLE
                bt_tws_sync_volume();
#endif
             }else
             {
                app_task_put_key_msg(KEY_VOL_DOWN,0);
             }
           }
           rdec->st[0] = tp0;
           rdec->st[1] = tp1;
           rdec->io[0] = 0;
           rdec->io[1] = 0;
        }else if(rdec->io[0]||rdec->io[1])
        {
            return ;
        }else if(tp0 != rdec -> st[0])
        {
                rdec->io[0] = 1;
        }else if(tp1 != rdec -> st[1])
        {
                rdec->io[1] = 1;
        }
  }
}

void user_rdec_device_init(void)
{
   unsigned char index =0;
   rdec_device_num = sizeof(user_rdeckey_list)/sizeof(user_rdeckey_list[0]);
   unsigned char enable = 0;
   struct rdec_device_soft *rdec;
   for(index =0;index<rdec_device_num;index++)
   {
        rdec = &user_rdeckey_list[index];
        gpio_direction_input(rdec->sin_port0);
        gpio_set_pull_down(rdec->sin_port0,0);
        gpio_set_pull_up(rdec->sin_port0,1);
        gpio_set_die(rdec->sin_port0,1);

        gpio_direction_input(rdec->sin_port1);
        gpio_set_pull_down(rdec->sin_port1,0);
        gpio_set_pull_up(rdec->sin_port1,1);
        gpio_set_die(rdec->sin_port1,1);
   }

   printf("----------------user_rdec_device_init=%d\n",rdec_device_num);
}

#endif


void detection_timer(void)
{
#if TCFG_DEV_POWER_ENABLE
    dev_power_init();
#endif

#if TCFG_CHANGE_POWER_ENABLE
    change_power_init();
#endif

#if TCF_MIC_DETECTION_ENABLE
    mic_dev_detection_init();
#endif

#if TCFG_MUSIC_VOL_DETECTION
    music_vol_init();
#endif

#if TCFG_ENCODER_DETECTION
    rdec_device_scan();
#endif

#if TCFG_DEV_POWER_ENABLE
    TCFG_DEV_POWER_ON();
#endif

}

