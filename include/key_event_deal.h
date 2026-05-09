#ifndef __KEY_EVENT_DEAL_H__
#define __KEY_EVENT_DEAL_H__

#include "typedef.h"
#include "system/event.h"

enum {
    KEY_POWER_ON = 0x80,//从0x80开始,避免与系统默认事件冲突
    KEY_POWER_ON_HOLD,
    KEY_POWEROFF,
    KEY_POWEROFF_HOLD,
    KEY_POWEROFF_UP,
    KEY_BT_DIRECT_INIT,
    KEY_BT_DIRECT_CLOSE,
    KEY_MUSIC_PP,                    //暂停
    KEY_MUSIC_PREV,                  //上一曲
    KEY_MUSIC_NEXT,                  //下一曲
    KEY_MUSIC_FF,                    //快进
    KEY_MUSIC_FR,                    //快退
    KEY_MUSIC_PLAYER_START,          //播放
    KEY_MUSIC_PLAYER_END,            //播放结束
    KEY_MUSIC_PLAYER_DEC_ERR,        //解码错误
    KEY_MUSIC_DEVICE_TONE_END,       //设备音结束
    KEY_MUSIC_PLAYER_QUIT,           //退出
    KEY_MUSIC_PLAYER_AUTO_NEXT,      //自动下一曲
    KEY_MUSIC_PLAYER_PLAY_FIRST,     //播放第一首
    KEY_MUSIC_PLAYER_PLAY_LAST,      //播放最后一首
    KEY_MUSIC_CHANGE_REPEAT,         //歌曲循环
    KEY_MUSIC_CHANGE_DEV,            //切换设备
    KEY_MUSIC_AUTO_NEXT_DEV,         //自动切换设备
    KEY_MUSIC_CHANGE_DEV_REPEAT,     //切换设备和循环模式
    KEY_MUSIC_SET_PITCH,             //设置音调
    KEY_MUSIC_SET_SPEED,             //设置速度
    KEY_MUSIC_PLAYE_BY_DEV_FILENUM,  //按设备和文件序号播放
    KEY_MUSIC_PLAYE_BY_DEV_SCLUST,   //按设备和scluster播放
    KEY_MUSIC_PLAYE_BY_DEV_PATH,     //按设备和路径播放
    KEY_MUSIC_DELETE_FILE,           //删除文件
    KEY_MUSIC_PLAYE_NEXT_FOLDER,     //播放下一个文件夹
    KEY_MUSIC_PLAYE_PREV_FOLDER,     //播放上一个文件夹
    KEY_MUSIC_PLAYE_REC_FOLDER_SWITCH,  //切换录音文件夹
    KEY_MUSIC_PLAYER_AB_REPEAT_SWITCH,  //切换AB循环
    KEY_VOL_UP,                      //音量加
    KEY_VOL_DOWN,                    //音量减
    KEY_CALL_LAST_NO,                //挂断 回拨
    KEY_CALL_HANG_UP,                //挂断
    KEY_CALL_ANSWER,                 //接听
    KEY_OPEN_SIRI,                   //打开siri
    KEY_HID_CONTROL,                 //打开hid控制
    KEY_LOW_LANTECY,                 //低延迟
    KEY_CHANGE_MODE,                 //切换模式

    KEY_BT_POWER,                    //断开蓝牙
    KEY_BT_CONN_OR_DCONN,            //回连蓝牙

    KEY_VOICES_REMOVE,

    KEY_DUAN_VOL_UP,
    KEY_LINEIN_VOL,


    KEY_MIC_VOL_START,
    KEY_ECHO_VOL_START,
    KEY_MUSIC_VOL_START,
    KEY_ECHO_MIC_VOL_MAX,
    KEY_ECHO_DELAY_UP,
    KEY_ECHO_DELAY_DOWN,

    KEY_EQ_MODE,                     //EQ模式
    KEY_THIRD_CLICK,                 //三击

    KEY_FM_SCAN_ALL,                 //全频搜台
    KEY_FM_SCAN_ALL_UP,              //全频搜台
    KEY_FM_SCAN_ALL_DOWN,            //全频搜台
    KEY_FM_PREV_STATION,             //上一个频道
    KEY_FM_NEXT_STATION,             //下一个频道
    KEY_FM_PREV_FREQ,                //上一个频率
    KEY_FM_NEXT_FREQ,                //下一个频率
    KEY_FM_SCAN_UP,//半自动搜台
    KEY_FM_SCAN_DOWN,//半自动搜台
    KEY_FM_DEL_STATION,//删除频道


    KEY_FM_EMITTER_MENU,             //FM发射菜单
    KEY_FM_EMITTER_NEXT_FREQ,        //FM发射下一个频率
    KEY_FM_EMITTER_PERV_FREQ,        //FM发射上一个频率

    KEY_RTC_UP,                      //RTC加
    KEY_RTC_DOWN,                    //RTC减
    KEY_RTC_SW,                      //RTC开关
    KEY_RTC_SW_POS,                  //RTC开关位置

    KEY_SPDIF_SW_SOURCE,             //SPDIF开关源

    KEY_BT_EMITTER_SW,               //BT发射开关
    KEY_BT_EMITTER_PLAY,             //BT发射播放
    KEY_BT_EMITTER_PAUSE,            //BT发射暂停
    KEY_BT_EMITTER_RECEIVER_SW,      //BT接收开关

    KEY_SWITCH_PITCH_MODE,           //切换音调模式
    KEY_ENC_START,                   //编码器启动
    KEY_REVERB_OPEN,                 //打开混响
    KEY_REVERB_DEEPVAL_UP,           //混响深度加
    KEY_REVERB_DEEPVAL_DOWN,         //混响深度减
    KEY_REVERB_GAIN0_UP,             //混响增益加
    KEY_REVERB_GAIN1_UP,             //混响增益加
    KEY_REVERB_GAIN2_UP,             //混响增益加
    // KEY_REVERB_GAIN_DOWN,

    KEY_TM_GMA_SEND,                 //发送GMA
    KEY_APP_SEND_SPEECH_START,       //开始AI对话
    KEY_SEND_SPEECH_START,              //开始AI对话
    KEY_SEND_SPEECH_STOP,               //结束AI对话
    KEY_AI_DEC_SUSPEND,               //AI解码挂起
    KEY_AI_DEC_RESUME,                //AI解码恢复
    KEY_DUEROS_CONNECTED,             //dueros连接
    KEY_DUEROS_DISCONNECTED,          //dueros断开
    KEY_DUEROS_VER,                   //dueros版本
    KEY_DUEROS_SEND,                  //dueros发送
    KEY_TWS_DUEROS_RAND_SET,          //dueros随机设置
    KEY_TWS_BLE_SLAVE_SPEECH_START,   //tws ble从机开始语音
    KEY_SPEECH_START_FROM_TWS,        //tws开始语音
    KEY_SPEECH_STOP_FROM_TWS,         //tws ble从机结束语音
    KEY_TWS_BLE_DUEROS_CONNECT,       //tws ble从机连接dueros
    KEY_TWS_BLE_DUEROS_DISCONNECT,    //tws ble从机断开dueros

    KEY_TWS_SEARCH_PAIR,              //tws搜索配对
    KEY_TWS_REMOVE_PAIR,              //tws移除配对
    KEY_TWS_SEARCH_REMOVE_PAIR,       //tws搜索移除配对
    KEY_TWS_DISCONN,                  //tws断开连接
    KEY_TWS_CONN,                     //tws连接

    KEY_BOX_POWER_CLICK,              //电源单击
    KEY_BOX_POWER_LONG,              //电源长按
    KEY_BOX_POWER_HOLD,              //电源按住
    KEY_BOX_POWER_UP,                //电源上
    KEY_BOX_POWER_DOUBLE,            //电源双击
    KEY_BOX_POWER_THREE,             //电源三击
    KEY_BOX_POWER_FOUR,              //电源四击
    KEY_BOX_POWER_FIVE,              //电源五击

    ///soundcard相关按键消息
    KEY_SOUNDCARD_MODE_ELECTRIC,     //电音
    KEY_SOUNDCARD_MODE_PITCH,        //音调
    KEY_SOUNDCARD_MODE_PITCH_BY_VALUE,  //音调
    KEY_SOUNDCARD_MODE_MAGIC,        //魔幻
    KEY_SOUNDCARD_MODE_BOOM,         //爆音
    KEY_SOUNDCARD_MODE_SHOUTING_WHEAT,  //呐喊
    KEY_SOUNDCARD_MODE_DODGE,        //闪避
    KEY_SOUNDCARD_MODE_ELECTRIC_CANCEL, //电音取消

    KEY_SOUNDCARD_MAKE_NOISE0,  
    KEY_SOUNDCARD_MAKE_NOISE1,
    KEY_SOUNDCARD_MAKE_NOISE2,
    KEY_SOUNDCARD_MAKE_NOISE3,
    KEY_SOUNDCARD_MAKE_NOISE4,
    KEY_SOUNDCARD_MAKE_NOISE5,
    KEY_SOUNDCARD_MAKE_NOISE6,
    KEY_SOUNDCARD_MAKE_NOISE7,
    KEY_SOUNDCARD_MAKE_NOISE8,
    KEY_SOUNDCARD_MAKE_NOISE9,
    KEY_SOUNDCARD_MAKE_NOISE10,
    KEY_SOUNDCARD_MAKE_NOISE11,
///旋钮按键
    KEY_SOUNDCARD_SLIDE_MIC,         //MIC
    KEY_SOUNDCARD_SLIDE_WET_GAIN,   
    KEY_SOUNDCARD_SLIDE_HIGH_SOUND,
    KEY_SOUNDCARD_SLIDE_LOW_SOUND,
    KEY_SOUNDCARD_SLIDE_RECORD_VOL,
    KEY_SOUNDCARD_SLIDE_MUSIC_VOL,
    KEY_SOUNDCARD_SLIDE_EARPHONE_VOL,

    KEY_SOUNDCARD_USB_MIC_MUTE_SWICH,   //USBMIC静音开关
    KEY_SOUNDCARD_NORMAL_MIC_STATUS_UPDATE, //正常MIC状态更新
    KEY_SOUNDCARD_EAR_MIC_STATUS_UPDATE,    //耳麦状态更新
    KEY_SOUNDCARD_AUX_STATUS_UPDATE,       //AUX状态更新


    KEY_TEST_DEMO_0,    //测试按键
    KEY_TEST_DEMO_1,    //测试按键
    KEY_MUTE_VOL_UP,    //长按解mute**************************
    KEY_LINEIN_UP,      //长按解mute**************************
    KEY_TWS_VOL_UP,     //长按解mute**************************

    KEY_IR_NUM_0,  //中间不允许插入
    KEY_IR_NUM_1,
    KEY_IR_NUM_2,
    KEY_IR_NUM_3,
    KEY_IR_NUM_4,
    KEY_IR_NUM_5,
    KEY_IR_NUM_6,
    KEY_IR_NUM_7,
    KEY_IR_NUM_8,
    KEY_IR_NUM_9,//中间不允许插入
    //在这里增加元素
    //
    KEY_HID_MODE_SWITCH,
    KEY_HID_TAKE_PICTURE,
    KEY_LINEIN_START,
    MSG_HALF_SECOND,//半秒的事件
    //不会出现在按键主流程，用于不重要得其他操作
    KEY_MINOR_OPT,
    KEY_TONE_PLAY,

    KEY_NULL = 0xFFFF,

    KEY_MSG_MAX = 0xFFFF,
    //音箱sdk 按键消息已经加大为0xffff
};


enum {
    ONE_KEY_CTL_NEXT_PREV = 1,
    ONE_KEY_CTL_VOL_UP_DOWN,
};


#endif
