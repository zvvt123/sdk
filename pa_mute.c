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


#if TCFG_MUTE_ENABLE
void pa_mute(void)
{

#if TCFG_VAL_HALF_MUTE
    gpio_set_pull_up(TCFG_VAL_HALF_IO,0);
    gpio_set_pull_down(TCFG_VAL_HALF_IO,0);
    gpio_set_direction(TCFG_VAL_HALF_IO,0);
#else
    gpio_set_pull_up(TCFG_MUTE_IO,0);
    gpio_set_pull_down(TCFG_MUTE_IO,0);
    gpio_set_direction(TCFG_MUTE_IO,0);
#endif

#if TCFG_MUTE_EFFECTIVE

#if TCFG_VAL_HALF_MUTE
    gpio_direction_output(TCFG_VAL_HALF_IO,1);
#else
    gpio_direction_output(TCFG_MUTE_IO,1);

#endif

#else

#if TCFG_VAL_HALF_MUTE
    gpio_direction_output(TCFG_VAL_HALF_IO,0);
#else
    gpio_direction_output(TCFG_MUTE_IO,0);
#endif

#endif

}


void pa_umute(void)
{

#if TCFG_VAL_HALF_MUTE
    if (app_get_curr_task()==APP_FM_TASK)
    {
        gpio_set_pull_up(TCFG_VAL_HALF_IO,1);
        gpio_set_pull_down(TCFG_VAL_HALF_IO,1);
        gpio_set_direction(TCFG_VAL_HALF_IO,1);
    }
    else
    {
        gpio_set_pull_up(TCFG_VAL_HALF_IO,0);
        gpio_set_pull_down(TCFG_VAL_HALF_IO,0);
        gpio_set_direction(TCFG_VAL_HALF_IO,0);
    }


#else

    gpio_set_pull_up(TCFG_MUTE_IO,0);
    gpio_set_pull_down(TCFG_MUTE_IO,0);
    gpio_set_direction(TCFG_MUTE_IO,0);

#endif

#if TCFG_MUTE_EFFECTIVE

#if TCFG_VAL_HALF_MUTE
    if (app_get_curr_task()==APP_FM_TASK)
    {

    }
    else
    {
        gpio_direction_output(TCFG_VAL_HALF_IO,0);
    }

#else
    gpio_direction_output(TCFG_MUTE_IO,0);
#endif

#else

#if TCFG_VAL_HALF_MUTE
    if (app_get_curr_task()==APP_FM_TASK)
    {

    }
    else
    {
        gpio_direction_output(TCFG_VAL_HALF_IO,1);
    }
#else
    gpio_direction_output(TCFG_MUTE_IO,1);
#endif

#endif

}
 u8 linein_umate_cnt = 0;
 u8 power_mute_up = 0;
 u8 power_mute_flag = 0;
 u8 Aux_Mute_Flag=0;
 u8 Fm_Mute_Flag=0;
 u8 bt_music_online = 0;
 u8 music_mute_flag = 0;
 u8 power_onliine_mute;
 u8 mute_power_flag = 0;
 u8 mute_count = 0;
 extern u8 mic_online_flag;

void Mute_can(void)
{
    if(!power_mute_up)
    {
        pa_mute();
        return;
    }

    if(tone_get_status())
    {
        pa_umute();
        return;
    }

#if TCFG_USER_TWS_ENABLE
    if(bt_mute_flag)
    {
       pa_mute();
       return;
    }
#endif

    if(power_mute_flag)
    {
        pa_mute();
        return;
    }

    if(music_mute_flag)
    {
        pa_mute();
        return;
    }

    #if TCF_MIC_DETECTION_ENABLE
    if(mic_start_mute)
    {
        pa_mute();
        return;
    }
    
    if(mic_online_flag){
        pa_umute();
        return;
    }
    #endif

    #if TCFG_UART_DEMO_OPEN
    if(is_wireless_mic_online)//无线麦克风打开
    {
           pa_umute();
           return;
    //     if(mic_conn_flag)
    //    {
           
    //    }
    }
#endif

    if(app_var.music_volume==0)
    {
        pa_mute();
        return;
    }

    if (app_get_curr_task()==APP_BT_TASK)
    {
        if ((get_call_status() == BT_CALL_ACTIVE) ||
                (get_call_status() == BT_CALL_OUTGOING) ||
                (get_call_status() == BT_CALL_ALERT) ||
                (get_call_status() == BT_CALL_INCOMING))
        {
            pa_umute();

            return;
        }

        if((a2dp_get_status() == BT_MUSIC_STATUS_STARTING)||(app_var.siri_stu)||(bt_music_online))
        {
            pa_umute();
            return;
        }
        else
        {
            pa_mute();

            return;
        }
    }
#if TCFG_FM_ENABLE
    else if (app_get_curr_task()==APP_FM_TASK)
    {
        if(!Fm_Mute_Flag)
        {

            pa_umute();

            return;
        }
        else
        {

            pa_mute();

            return;
        }
    }
#endif

#if TCFG_APP_MUSIC_EN
    else if (app_get_curr_task()==APP_MUSIC_TASK)
    {
        if(music_player_get_play_status()==1)
        {

            pa_umute();

            return;
        }
        else
        {

            pa_mute();

            return;
        }

    }
#endif

#if TCFG_LINEIN_ENABLE
    else if (app_get_curr_task()==APP_LINEIN_TASK)
    {

        if(!Aux_Mute_Flag)
        {

            pa_umute();

            return;
        }
        else
        {

            pa_mute();

            return;
        }

    }else
#endif
    if (app_get_curr_task()==APP_IDLE_TASK)
    {
         pa_mute();
         return;
    }

}
#endif

#if TCFG_APP_LINEIN_EN
void linein_vol_max_mute_up_init(void)
{
    if(linein_cnt_umate_flag)
    {
        printf("linein_umate_cnt = %d\n",linein_umate_cnt);
        if(++linein_umate_cnt>30)
        {
            linein_cnt_umate_flag = 0;
            linein_umate_cnt = 0;
            audio_linein_mute(0);
        }
        else
        {
            audio_linein_mute(1);
        }
        
    }
    else
    {
        linein_umate_cnt = 0;
    }
}
#endif

u8 mic_delay=0;
void all_time_init(void)
{
    #if TCFG_APP_LINEIN_EN
        linein_vol_max_mute_up_init();
    #endif
#if TCFG_MUTE_ENABLE
    Mute_can();

    if(mute_power_flag)
    {
       mute_count++;
       if(mute_count>10)
       {
           power_mute_up = 1;
           mute_count = 0;
           mute_power_flag = 0;
       }
    }
#endif

#if TCFG_MIC_EFFECT_ENABLE
    if(mic_play_online)
    {
           if(tone_get_status())
           {
               mic_delay = 0;
               return;
           }
           mic_delay++;
           if(mic_delay>25)
           {
               mic_delay = 0;
               mic_conn_flag = 0;
               linein_key_online = 0;
               mic_play_online = 0;

               if (app_get_curr_task()==APP_LINEIN_TASK)
               {
                   audio_linein_mute(0);
               }
           }
    }
#endif
}

u16 bt_count = 0;
void bt_dconn_power_init(void)
{

#if TCFG_UART_DEMO_OPEN
    if (app_get_curr_task()==APP_BT_TASK)
    {
        if((!get_total_connect_dev())&&(!is_wireless_mic_online))//蓝牙和无线麦克风都断开时进入
        {
             if(bt_count<600)
             {
                 bt_count++;
             }

             if(bt_count==600)
             {
                 tone_play_with_callback_by_name(tone_table[IDEX_TONE_POWER_OFF], 1,
                                              power_mute_init, (void *)IDEX_TONE_POWER_OFF);
                 bt_count = 601;
              }
        }else
        {
            bt_count = 0;
        }
    }else
    {
        bt_count = 0;
    }
#endif


}



void detection_timer(void);
void time_start(void)
{

    sys_timer_add(NULL, all_time_init, 30);
    sys_timer_add(NULL, detection_timer, 50);
}

