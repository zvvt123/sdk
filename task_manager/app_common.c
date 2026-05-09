// #include "common/app_common.h"
// #include "app_task.h"
// #include "app_main.h"
// #include "key_event_deal.h"
// #include "music/music.h"
// #include "pc/pc.h"
// #include "record/record.h"
// #include "linein/linein.h"
// #include "fm/fm.h"
// #include "btstack/avctp_user.h"
// #include "app_power_manage.h"
// #include "app_chargestore.h"
// #include "usb/otg.h"
// #include "usb/host/usb_host.h"
// #include <stdlib.h>
// #include "bt/bt_tws.h"
// #include "audio_config.h"
// #include "common/power_off.h"
// #include "common/user_msg.h"
// #include "audio_config.h"
// #include "audio_enc.h"
// #include "ui/ui_api.h"
// #include "fm_emitter/fm_emitter_manage.h"
// #include "common/fm_emitter_led7_ui.h"
// #if TCFG_CHARGE_ENABLE
// #include "app_charge.h"
// #endif
// #include "dev_multiplex_api.h"
// #include "chgbox_ctrl.h"
// #include "device/chargebox.h"
// #include "app_online_cfg.h"
// #include "soundcard/soundcard.h"
// #include "smartbox_bt_manage.h"
// #include "bt.h"
// #include "common/dev_status.h"
// #include "tone_player.h"
// #include "ui_manage.h"
// #include "soundbox.h"
// #include "bt_emitter.h"

#include "common/app_common.h"
#include "app_task.h"
#include "app_main.h"
#include "key_event_deal.h"
#include "music/music.h"
#include "pc/pc.h"
#include "record/record.h"
#include "linein/linein.h"
#include "fm/fm.h"
#include "btstack/avctp_user.h"
#include "app_power_manage.h"
#include "app_chargestore.h"
#include "usb/otg.h"
#include "usb/host/usb_host.h"
#include <stdlib.h>
#include "bt/bt_tws.h"
#include "audio_config.h"
#include "common/power_off.h"
#include "common/user_msg.h"
#include "audio_config.h"
#include "audio_enc.h"
#include "ui/ui_api.h"
#include "fm_emitter/fm_emitter_manage.h"
#include "common/fm_emitter_led7_ui.h"
#if TCFG_CHARGE_ENABLE
#include "app_charge.h"
#endif
#include "dev_multiplex_api.h"
#include "chgbox_ctrl.h"
#include "device/chargebox.h"
#include "app_online_cfg.h"
#include "soundcard/soundcard.h"
#include "smartbox_bt_manage.h"
#include "bt.h"
#include "common/dev_status.h"
#include "tone_player.h"
#include "ui_manage.h"
#include "soundbox.h"
#include "bt_emitter.h"

#define LOG_TAG_CONST       APP_ACTION
#define LOG_TAG             "[APP_ACTION]"
#define LOG_ERROR_ENABLE
#define LOG_DEBUG_ENABLE
#define LOG_INFO_ENABLE
/* #define LOG_DUMP_ENABLE */
#define LOG_CLI_ENABLE
#include "debug.h"

u8 echo_delay_count = 10;

int JL_rcsp_event_handler(struct rcsp_event *rcsp);
int bt_background_event_handler(struct sys_event *event);
extern u32 timer_get_ms(void);
extern int alarm_sys_event_handler(struct sys_event *event);
extern void bt_tws_sync_volume();

static u32 input_number = 0;
static u16 input_number_timer = 0;
static void input_number_timeout(void *p)
{
    input_number_timer = 0;
    printf("input_number = %d\n", input_number);
    if (app_get_curr_task() == APP_MUSIC_TASK) {
        app_task_put_key_msg(KEY_MUSIC_PLAYE_BY_DEV_FILENUM, (int)input_number);
    }
    input_number = 0;
}

extern u8 mic_online_flag;
#if TCFG_MIC_EFFECT_ENABLE
u8 eff_mode_pth = 0;

void eff_mode_init(void)
{
    if(!mic_online_flag)
    {
        return;
    }

     mic_start_mute = 1; 
     printf("-------------eff_mode_pth=%d\n",eff_mode_pth);
     mic_voicechange_switch(eff_mode_pth);
     sys_timeout_add(NULL,conn_mic_mute,700);
}

#endif

static void input_number_deal(u32 num)
{
    input_number = input_number * 10 + num;
    if (input_number > 9999) {
        input_number = num;
    }
    printf("num = %d, input_number = %d, input_number_timer = %d\n", num, input_number, input_number_timer);
    if (input_number_timer == 0) {
        input_number_timer = sys_timeout_add(NULL, input_number_timeout, 1000);
    } else {
        sys_timer_modify(input_number_timer, 1000);
    }
    UI_SHOW_MENU(MENU_FILENUM, 4 * 1000, input_number, NULL);
}

u8 tws_key_dconn_flag = 0;
u8 music_dev = 0;
int app_common_key_msg_deal(struct sys_event *event)
{
    int ret = false;
    struct key_event *key = &event->u.key;
    int key_event = event->u.key.event;
    int key_value = event->u.key.value;

    if (key_event == KEY_NULL) {
        return false;
    }

    if (key_is_ui_takeover()) {
        ui_key_msg_post(key_event);
        return false;
    }

#if (TCFG_UI_ENABLE && TCFG_APP_FM_EMITTER_EN)
    if (!ui_fm_emitter_common_key_msg(key_event)) {
        return false;
    }
#endif

    log_info("common_key_event:%d\n", key_event);

    if ((key_event != KEY_POWEROFF) && (key_event != KEY_POWEROFF_HOLD)) {
        extern u8 goto_poweroff_first_flag;
        goto_poweroff_first_flag = 0;
    }

#if (SMART_BOX_EN)
    extern bool smartbox_key_event_filter_before(int key_event);
    if (smartbox_key_event_filter_before(key_event)) {
        return true;
    }
#endif

    switch (key_event) {
#if TCFG_APP_BT_EN

#if TCFG_USER_TWS_ENABLE
    case KEY_TWS_CONN:
        log_info("    KEY_TWS_CONN \n");
        bt_open_tws_conn(0);
        break;
    case KEY_TWS_DISCONN:
        log_info("    KEY_TWS_DISCONN \n");
        bt_disconnect_tws_conn();
        break;
    case KEY_TWS_REMOVE_PAIR:
        log_info("    KEY_TWS_REMOVE_PAIR \n");
        bt_tws_remove_tws_pair();
        break;
    case KEY_TWS_SEARCH_PAIR:
        log_info("    KEY_TWS_SEARCH_PAIR \n");
        if (tws_api_get_tws_state() & TWS_STA_SIBLING_DISCONNECTED)
        {
            bt_tws_start_search_and_pair();
            ui_update_status(STATUS_TWS_SCAN);
            tone_play_by_path(tone_table[IDEX_TONE_TWS_SCAN], 1);
        }else
        {
            bt_tws_search_or_remove_pair();
        }

        break;
    case KEY_TWS_SEARCH_REMOVE_PAIR:
        log_info("    KEY_TWS_SEARCH_REMOVE_PAIR \n");
        bt_tws_search_or_remove_pair();
        break;
#endif

    case KEY_BT_DIRECT_INIT:
        bt_direct_init();
        break;
    case KEY_BT_DIRECT_CLOSE:
        bt_direct_close();
        break;
#endif

    case  KEY_POWEROFF:
    case  KEY_POWEROFF_HOLD:
        power_off_deal(event, key_event - KEY_POWEROFF);
        
        break;

    case KEY_IR_NUM_0:
    case KEY_IR_NUM_1:
    case KEY_IR_NUM_2:
    case KEY_IR_NUM_3:
    case KEY_IR_NUM_4:
    case KEY_IR_NUM_5:
    case KEY_IR_NUM_6:
    case KEY_IR_NUM_7:
    case KEY_IR_NUM_8:
    case KEY_IR_NUM_9:
        input_number_deal(key_event - KEY_IR_NUM_0);
        break;

    case KEY_CHANGE_MODE:
#if (TCFG_DEC2TWS_ENABLE)
        if (!key->init) {
            break;
        }
#endif

#if TWFG_APP_POWERON_IGNORE_DEV
        if ((timer_get_ms() - app_var.start_time) > TWFG_APP_POWERON_IGNORE_DEV)
#endif//TWFG_APP_POWERON_IGNORE_DEV

        {
            printf("KEY_CHANGE_MODE\n");
#if TCFG_APP_MUSIC_EN
            if ((app_get_curr_task()==APP_MUSIC_TASK)&&(music_player_get_dev_next(0)>1)&&(!music_dev))
            {
                music_dev=1;
                app_task_put_key_msg(KEY_MUSIC_CHANGE_DEV,0);
            }else
#endif
            {
                 music_dev=0;
                app_task_switch_next();
            }
        }
        break;

    case KEY_VOL_UP:
        log_info("COMMON KEY_VOL_UP\n");
        if (!tone_get_status()) {
            app_audio_volume_up(1);
            printf("common vol+: %d", app_audio_get_volume(APP_AUDIO_CURRENT_STATE));
        }
        if (app_audio_get_volume(APP_AUDIO_CURRENT_STATE) == app_audio_get_max_volume()) {
            if (tone_get_status() == 0) {
#if TCFG_MAX_VOL_PROMPT

#if TCFG_MUTE_ENABLE
                music_mute_flag = 1;
#endif
                tone_play_by_path(tone_table[IDEX_TONE_MAX_VOL], 1);
#endif
            }
        }

#if (TCFG_DEC2TWS_ENABLE)
        bt_tws_sync_volume();
#endif
        UI_SHOW_MENU(MENU_MAIN_VOL, 1000, app_audio_get_volume(APP_AUDIO_CURRENT_STATE), NULL);
        break;


    case KEY_MUTE_VOL_UP:
#if TCFG_MUTE_ENABLE
         music_mute_flag = 0;
#endif
        break;

    case KEY_VOL_DOWN:
        log_info("COMMON KEY_VOL_DOWN\n");
        app_audio_volume_down(1);
        printf("common vol-: %d", app_audio_get_volume(APP_AUDIO_CURRENT_STATE));
#if (TCFG_DEC2TWS_ENABLE)
        bt_tws_sync_volume();
#endif
        UI_SHOW_MENU(MENU_MAIN_VOL, 1000, app_audio_get_volume(APP_AUDIO_CURRENT_STATE), NULL);
        break;

    case  KEY_EQ_MODE:
#if(TCFG_EQ_ENABLE == 1)
        eq_mode_sw();
#endif
        break;
#if (AUDIO_OUTPUT_WAY == AUDIO_OUTPUT_WAY_BT)


    case KEY_BT_EMITTER_RECEIVER_SW:
        printf(" KEY_BT_EMITTER_RECEIVER_SW\n");
        bt_emitter_receiver_sw();
        break;

    case KEY_BT_EMITTER_PAUSE:
        r_printf(" KEY_BT_EMITTER_PAUSE\n");
        bt_emitter_pp(0);
        break;

    case KEY_BT_EMITTER_PLAY:
        r_printf(" KEY_BT_EMITTER_PLAY\n");
        bt_emitter_pp(1);
        break;

    case KEY_BT_EMITTER_SW:
        r_printf("KEY_BT_EMITTER_SW\n");
        {
            extern u8 bt_emitter_stu_sw(void);

            if (bt_emitter_stu_sw()) {
                printf("bt emitter start \n");
            } else {
                printf("bt emitter stop \n");
            }
        }
        break;
#endif


#if (TCFG_CHARGE_BOX_ENABLE)
    case  KEY_BOX_POWER_CLICK:
    case  KEY_BOX_POWER_LONG:
    case  KEY_BOX_POWER_HOLD:
    case  KEY_BOX_POWER_UP:
    case  KEY_BOX_POWER_DOUBLE:
    case  KEY_BOX_POWER_THREE:
    case  KEY_BOX_POWER_FOUR:
    case  KEY_BOX_POWER_FIVE:
        charge_box_key_event_handler(key_event);
        break;
#endif
#if (TCFG_MIC_EFFECT_ENABLE)
    case KEY_REVERB_OPEN:
#if TCFG_USER_TWS_ENABLE
        if (!key->init) {
            break;
        }
#endif
        if (mic_effect_get_status()) {
            mic_effect_stop();
        } else {
            printf("get_call_status() %d\n", get_call_status());
            if (get_call_status() == BT_CALL_INCOMING) {
                //来电响铃声过程，不允许打开混响，
                log_i("phone ringring, not alloc open mic_effect\n");
            } else {
                mic_effect_start();
            }
        }
        ret = true;
        break;
#endif
    case KEY_ENC_START:
#if (RECORDER_MIX_EN)
        if (recorder_mix_get_status()) {
            printf("recorder_encode_stop\n");
            recorder_mix_stop();
        } else {
            printf("recorder_encode_start\n");
            recorder_mix_start();
        }
#endif/*RECORDER_MIX_EN*/
        break;

        #if AUDIO_VOCAL_REMOVE_EN
        case KEY_VOICES_REMOVE:                     //消音
            printf("KEY_VOICES_REMOVE\n");
            void musc_remove_colse(void);
            musc_remove_colse();
            break;
    #endif
    
    /*---------------无线话筒按键消息存放区--------------------------*/
    #if TCFG_MIC_EFFECT_ENABLE
    
        case KEY_SOUNDCARD_MODE_PITCH:
             eff_mode_pth++;
             if(eff_mode_pth>4)
             {
                 eff_mode_pth = 0;
             }
    
             if (app_get_curr_task()==APP_LINEIN_TASK)
             {
                 audio_linein_mute(1);
                 linein_key_online = 1;
             }
    
                 switch(eff_mode_pth)
              {
    
                case 0:   //原声
                          tone_play_with_callback_by_name(tone_table[IDEX_TONE_YUAN_SHEN], 1, eff_mode_init, (void *)IDEX_TONE_YUAN_SHEN);
                          break;
    
                  case 1:   //男声
                          tone_play_with_callback_by_name(tone_table[IDEX_TONE_NAN_SHEN], 1, eff_mode_init, (void *)IDEX_TONE_NAN_SHEN);
                          break;
    
    
                  case 2:   //女声
                          tone_play_with_callback_by_name(tone_table[IDEX_TONE_NV_SHEN], 1, eff_mode_init, (void *)IDEX_TONE_NV_SHEN);
                          break;
    
    
                  case 3:   //娃娃音
                          tone_play_with_callback_by_name(tone_table[IDEX_TONE_WA_WA], 1, eff_mode_init, (void *)IDEX_TONE_WA_WA);
                          break;
    
    
                  case 4:   //魔兽音
                          tone_play_with_callback_by_name(tone_table[IDEX_TONE_MOYIN], 1, eff_mode_init, (void *)IDEX_TONE_MOYIN);
                          break;
             }
    
            break;
    
    
        case KEY_MIC_VOL_START:
             if (app_get_curr_task()==APP_LINEIN_TASK)
             {
                 audio_linein_mute(1);
                 linein_key_online = 1;
             }
    
             tone_play_with_callback_by_name(tone_table[IDEX_TONE_MIC_TJ], 1,
                                                  0, (void *)IDEX_TONE_MIC_TJ);
            break;
    
         case KEY_ECHO_VOL_START:
             if (app_get_curr_task()==APP_LINEIN_TASK)
             {
                 audio_linein_mute(1);
                 linein_key_online = 1;
             }
                 tone_play_with_callback_by_name(tone_table[IDEX_TONE_ECHO_TJ], 1,
                                                  0, (void *)IDEX_TONE_ECHO_TJ);
            break;
    
         case KEY_MUSIC_VOL_START:
             if (app_get_curr_task()==APP_LINEIN_TASK)
             {
                 audio_linein_mute(1);
                 linein_key_online = 1;
             }
                 tone_play_with_callback_by_name(tone_table[IDEX_TONE_MUSIC_TJ], 1,
                                                  0, (void *)IDEX_TONE_MUSIC_TJ);
            break;
    
    
         case KEY_ECHO_MIC_VOL_MAX:
             if (app_get_curr_task()==APP_LINEIN_TASK)
             {
                 audio_linein_mute(1);
                 linein_key_online = 1;
             }
             tone_play_with_callback_by_name(tone_table[IDEX_TONE_MAX_VOL], 1,
                                            0, (void *)IDEX_TONE_MAX_VOL);
            break;
    
    
        case KEY_ECHO_DELAY_UP:
            printf("echo_delay_count=%d\n",echo_delay_count);
            void mic_effect_set_echo_delay(u32 delay);
            if(echo_delay_count<10)
            {
                echo_delay_count++;
            }else
            {
                if(!tone_get_status())
                {
                   tone_play_by_path(tone_table[IDEX_TONE_MAX_VOL], 1);
                }
            }
            mic_effect_set_echo_delay(echo_delay_count*30);
            break;
    
    
        case KEY_ECHO_DELAY_DOWN:
            printf("echo_delay_count=%d\n",echo_delay_count);
            void mic_effect_set_echo_delay(u32 delay);
            if(echo_delay_count)
            {
                echo_delay_count--;
            }
            mic_effect_set_echo_delay(echo_delay_count*30);
            break;
    
    #endif



    case KEY_TONE_PLAY:
        extern void linein_tone_play(u8 index, u8 preemption);
        //下面是叠加播放的
        tone_play_by_path(TONE_NORMAL, 0);   //播放一段正弦波
        /* tone_play_by_path(TONE_BT_CONN, 0); */  //播放一个文件提示音
        /* linein_tone_play(IDEX_TONE_NORMAL,0);//模拟linein模式下提示音的时候用这个接口,播正弦波 */
        /* linein_tone_play(IDEX_TONE_BT_CONN,0);//模拟linein模式下提示音的时候用这个接口 ,播提示音文件 */
        //下面是打断播放的
        /* tone_play_by_path(TONE_NORMAL, 1); */   //播放一段正弦波
        /* tone_play_by_path(TONE_BT_CONN, 1); */  //播放一个文件提示音
        /* linein_tone_play(IDEX_TONE_NORMAL,1);//模拟linein模式下播提示音的时候要用这个接口,播正弦波 */
        /* linein_tone_play(IDEX_TONE_BT_CONN,1);//模拟linein模式下播提示音的时候要用这个接口,播提示音文件 */
        break;

    default:
        ui_key_msg_post(key_event);
        ui_simple_key_msg_post(key_event, key_value);
#if (SOUNDCARD_ENABLE)
        soundcard_event_deal(event);
#endif
        break;

    }
#if (SMART_BOX_EN)
    extern int smartbox_common_key_event_deal(int key_event, int ret);
    ret = smartbox_common_key_event_deal(key_event, ret);
#endif


    return ret;
}

u8 low_power_off_count = 0;
int app_power_user_event_handler(struct device_event *dev)
{
#if(TCFG_SYS_LVD_EN == 1)
    switch (dev->event) {
    case POWER_EVENT_POWER_WARNING:
        ui_update_status(STATUS_LOWPOWER);

#if TCFG_APP_LINEIN_EN
           if (app_get_curr_task()==APP_LINEIN_TASK)
           {
              audio_linein_mute(1);
           }
#endif

#if TCFG_LOW_POWER
        low_power_off_count++;
        if(low_power_off_count>3)
        {
           tone_play_with_callback_by_name(tone_table[IDEX_TONE_POWER_OFF], 1,
                                              power_mute_init, (void *)IDEX_TONE_POWER_OFF);
        }else
        {
            #if TCFG_APP_LINEIN_EN
            tone_play_with_callback_by_name(tone_table[IDEX_TONE_LOW_POWER], 1,
                                             linein_mute_init, (void *)IDEX_TONE_LOW_POWER);
            #else         
            tone_play_with_callback_by_name(tone_table[IDEX_TONE_LOW_POWER], 1,
                                            NULL, (void *)IDEX_TONE_LOW_POWER);
            #endif 
        }
#else
        tone_play_by_path(tone_table[IDEX_TONE_LOW_POWER], 1);
#endif
        /* return 0; */
    }
#if (SOUNDCARD_ENABLE)
    soundcard_power_event(dev);
#endif
#endif
    return app_power_event_handler(dev);
}

static void app_common_device_event_handler(struct sys_event *event)
{
    int ret = 0;
    const char *logo = NULL;
    const char *usb_msg = NULL;
    u8 app  = 0xff ;
    u8 alarm_flag = 0;
    switch ((u32)event->arg) {
#if (TCFG_SOUNDBOX_TOOL_ENABLE || TCFG_ONLINE_ENABLE)
    case DEVICE_EVENT_FROM_SOUNDBOX_TOOL:
        extern int app_soundbox_tool_event_handler(struct soundbox_tool_event * soundbox_tool_dev);
        app_soundbox_tool_event_handler(&event->u.soundbox_tool);
        break;
#endif
#if TCFG_CHARGE_ENABLE
    case DEVICE_EVENT_FROM_CHARGE:
        app_charge_event_handler(&event->u.dev);
        break;
#endif//TCFG_CHARGE_ENABLE

#if (TCFG_ONLINE_ENABLE || TCFG_SOUNDBOX_TOOL_ENABLE)
    case DEVICE_EVENT_FROM_CI_UART:
        ci_data_rx_handler(CI_UART);
        break;

#if TCFG_USER_TWS_ENABLE
    case DEVICE_EVENT_FROM_CI_TWS:
        ci_data_rx_handler(CI_TWS);
        break;
#endif//TCFG_USER_TWS_ENABLE
#endif//TCFG_ONLINE_ENABLE

    case DEVICE_EVENT_FROM_POWER:
        app_power_user_event_handler(&event->u.dev);
        break;

#if TCFG_CHARGESTORE_ENABLE || TCFG_TEST_BOX_ENABLE
    case DEVICE_EVENT_CHARGE_STORE:
        app_chargestore_event_handler(&event->u.chargestore);
        break;
#endif//TCFG_CHARGESTORE_ENABLE || TCFG_TEST_BOX_ENABLE

#if(TCFG_CHARGE_BOX_ENABLE)
    case DEVICE_EVENT_FROM_CHARGEBOX:
        charge_box_ctrl_event_handler(&event->u.chargebox);
        break;
#endif


    case DEVICE_EVENT_FROM_OTG:
        ///先分析OTG设备类型
        usb_msg = (const char *)event->u.dev.value;
        if (usb_msg[0] == 's') {
            ///是从机
#if (TCFG_PC_ENABLE || TCFG_USB_CDC_BACKGROUND_RUN)
            ret = pc_device_event_handler(event);
            if (ret == true) {
                app = APP_PC_TASK;
            }
#endif
            break;
        } else if (usb_msg[0] == 'h') {
            ///是主机, 统一于SD卡等响应主机处理，这里不break
        } else {
            log_e("unknow otg devcie !!!\n");
            break;
        }
    case DRIVER_EVENT_FROM_SD0:
    case DRIVER_EVENT_FROM_SD1:
    case DRIVER_EVENT_FROM_SD2:
#if TCFG_APP_MUSIC_EN
        ret = dev_status_event_filter(event);///解码设备上下线， 设备挂载等处理
        if (ret == true) {
            if (event->u.dev.event == DEVICE_EVENT_IN) {
                ///设备上线， 非解码模式切换到解码模式播放
                if (app_get_curr_task() != APP_MUSIC_TASK) {
                    app = APP_MUSIC_TASK;
                }
            }
        }
#endif
        break;

#if TCFG_APP_LINEIN_EN
    case DEVICE_EVENT_FROM_LINEIN:
        ret = linein_device_event_handler(event);
        if (ret == true) {
            app = APP_LINEIN_TASK;
        }
        break;
#endif//TCFG_APP_LINEIN_EN

#if TCFG_APP_RTC_EN
    case DEVICE_EVENT_FROM_ALM:
        ret = alarm_sys_event_handler(event);
        if (ret == true) {
            alarm_flag = 1;
            app = APP_RTC_TASK;
        }
        break;
#endif//TCFG_APP_RTC_EN

    default:
        /* printf("unknow SYS_DEVICE_EVENT!!, %x\n", (u32)event->arg); */
        break;
    }

#if (SMART_BOX_EN)
    extern void smartbox_update_dev_state(u32 event);
    smartbox_update_dev_state((u32)event->arg);
#endif

    if (app != 0xff) {
        if ((true != app_check_curr_task(APP_PC_TASK)) || alarm_flag) {

            //PC 不响应因为设备上线引发的模式切换
#if TWFG_APP_POWERON_IGNORE_DEV
            if ((timer_get_ms() - app_var.start_time) <= TWFG_APP_POWERON_IGNORE_DEV) {
                vddiom_set_dynamic(TCFG_LOWPOWER_VDDIOM_LEVEL);
                return;
            }
#endif//TWFG_APP_POWERON_IGNORE_DEV

#if (TCFG_CHARGE_ENABLE && (!TCFG_CHARGE_POWERON_ENABLE))
            extern u8 get_charge_online_flag(void);
            if (get_charge_online_flag()) {

            } else
#endif
            {

                printf(">>>>>>>>>>>>>%s %d \n", __FUNCTION__, __LINE__);
                app_task_switch_to(app);
            }
        }
    }
}


///公共事件处理， 各自模式没有处理的事件， 会统一在这里处理
void app_default_event_deal(struct sys_event *event)
{
    int ret;
    SYS_EVENT_HANDLER_SPECIFIC(event);
    switch (event->type) {
    case SYS_DEVICE_EVENT:
        /*默认公共设备事件处理*/
        /* printf(">>>>>>>>>>>>>%s %d \n", __FUNCTION__, __LINE__); */
        app_common_device_event_handler(event);
        break;
#if TCFG_APP_BT_EN
    case SYS_BT_EVENT:
        if (true != app_check_curr_task(APP_BT_TASK)) {
            /*默认公共BT事件处理*/
            bt_background_event_handler(event);
        }
        break;
#endif
    case SYS_KEY_EVENT:
        app_common_key_msg_deal(event);
        break;
    default:
        printf("unknow event\n");
        break;
    }
}


#if 0
extern int key_event_remap(struct sys_event *e);
extern const u16 bt_key_ad_table[KEY_AD_NUM_MAX][KEY_EVENT_MAX];
u8 app_common_key_var_2_event(u32 key_var)
{
    u8 key_event = 0;
    u8 key_value = 0;
    struct sys_event e = {0};
#if TCFG_ADKEY_ENABLE
    for (; key_value < KEY_AD_NUM_MAX; key_value++) {
        for (key_event = 0; key_event < KEY_EVENT_MAX; key_event++) {
            if (bt_key_ad_table[key_value][key_event] == key_var) {
                e.type = SYS_KEY_EVENT;
                e.u.key.type = KEY_DRIVER_TYPE_AD;
                e.u.key.event = key_event;
                e.u.key.value = key_value;
                /* e.u.key.tmr = timer_get_ms(); */
                e.arg  = (void *)DEVICE_EVENT_FROM_KEY;
                /* printf("key2event:%d %d %d\n", key_var, key_value, key_event); */
                if (key_event_remap(&e)) {
                    sys_event_notify(&e);
                    return true;
                }
            }
        }
    }
#endif
    return false;
}

#else

u8 app_common_key_var_2_event(u32 key_var)
{
    struct sys_event e = {0};
    e.type = SYS_KEY_EVENT;
    e.u.key.type = KEY_DRIVER_TYPE_SOFTKEY;
    e.u.key.event = key_var;
    e.arg  = (void *)DEVICE_EVENT_FROM_KEY;
    sys_event_notify(&e);
    return true;
}
#endif

