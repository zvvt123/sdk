#include "key_event_deal.h"
#include "key_driver.h"
#include "app_config.h"
#include "board_config.h"
#include "app_task.h"

#ifdef CONFIG_BOARD_AC696X_DEMO
/***********************************************************
 *				bt 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_BT_EN
const u16 bt_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
    //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        [KEY_EVENT_CLICK] = KEY_CHANGE_MODE,//单击切换模式
        [KEY_EVENT_LONG] = KEY_POWEROFF,//长按关机
        [KEY_EVENT_HOLD] = KEY_POWEROFF_HOLD,//hold关机
        [KEY_EVENT_DOUBLE_CLICK] = KEY_NULL,
        [KEY_EVENT_UP] = KEY_POWEROFF_UP,//关机抬起
    },
    [1] = {
        [KEY_EVENT_CLICK] = KEY_VOL_UP,//单击音量加
        [KEY_EVENT_LONG] = KEY_MUSIC_PREV,//长按上一首
        [KEY_EVENT_DOUBLE_CLICK] = KEY_NULL,
    },
    [2] = {
        [KEY_EVENT_CLICK] = KEY_NULL,
        [KEY_EVENT_LONG] = KEY_NULL,
        [KEY_EVENT_DOUBLE_CLICK] = KEY_NULL,    
    },
    [3] = {
        [KEY_EVENT_CLICK] = KEY_VOL_DOWN,//单击音量减
        [KEY_EVENT_LONG] = KEY_MUSIC_NEXT,//长按下一首
        [KEY_EVENT_DOUBLE_CLICK] = KEY_NULL,    
    },
    [4] = {
        [KEY_EVENT_CLICK] = KEY_MUSIC_PP,//单击播放/暂停
        [KEY_EVENT_LONG] = KEY_CALL_HANG_UP,//长按挂断电话
        [KEY_EVENT_DOUBLE_CLICK] = KEY_OPEN_SIRI,//双击打开siri
        [KEY_EVENT_TRIPLE_CLICK] = KEY_TWS_SEARCH_PAIR,//三击tws搜索配对    
    },
};
#endif

/***********************************************************
 *				fm 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_FM_EN
const u16 fm_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
    //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				linein 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_LINEIN_EN
const u16 linein_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
     //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				music 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_MUSIC_EN
const u16 music_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
     //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        [KEY_EVENT_CLICK] = KEY_CHANGE_MODE,//单击切换模式
        // [KEY_EVENT_LONG] = KEY_POWEROFF,//长按关机
        // [KEY_EVENT_HOLD] = KEY_POWEROFF_HOLD,//hold关机
        [KEY_EVENT_DOUBLE_CLICK] = KEY_NULL,
        [KEY_EVENT_UP] = KEY_POWEROFF_UP,//关机抬起	  
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				pc 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_PC_EN
const u16 pc_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
    //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				record 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_RECORD_EN
const u16 record_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
    //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				rtc 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_RTC_EN
const u16 rtc_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
     //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				spdif 模式的 iokey table
 ***********************************************************/
#if TCFG_APP_SPDIF_EN
const u16 spdif_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
    //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif

/***********************************************************
 *				idle 模式的 iokey table
 ***********************************************************/
const u16 idle_key_io_table[KEY_IO_NUM_MAX][KEY_EVENT_MAX] = {
     //单击                      //长按                           //hold                          //抬起                          //双击                             //三击
    [0] = {
        KEY_NULL,                KEY_NULL,		                KEY_NULL,	                   KEY_NULL,	                   KEY_NULL,		                   KEY_NULL
    },
    [1] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [2] = {
        KEY_NULL,	             KEY_NULL,	                    KEY_NULL,			           KEY_NULL,		               KEY_NULL,	                       KEY_NULL
    },
    [3] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,		                   KEY_NULL
    },
    [4] = {
        KEY_NULL,	             KEY_NULL,		                KEY_NULL,		               KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
    [5] = {
        KEY_NULL,		         KEY_NULL,			            KEY_NULL,			           KEY_NULL,		               KEY_NULL,			               KEY_NULL
    },
};
#endif
