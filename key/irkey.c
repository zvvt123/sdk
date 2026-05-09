#include "key_driver.h"
#include "irkey.h"
#include "gpio.h"
#include "asm/irflt.h"
#include "app_config.h"

#if TCFG_IRKEY_ENABLE

u8 ir_get_key_value(void);
//按键驱动扫描参数列表
struct key_driver_para irkey_scan_para = {
    .scan_time 	  	  = 10,				//按键扫描频率, 单位: ms
    .last_key 		  = NO_KEY,  		//上一次get_value按键值, 初始化为NO_KEY;
    .filter_time  	  = 2,				//按键消抖延时;
    .long_time 		  = 75,  			//按键判定长按数量
    .hold_time 		  = (75 + 15),  	//按键判定HOLD数量
    .click_delay_time = 20,				//按键被抬起后等待连击延时数量
    .key_type		  = KEY_DRIVER_TYPE_IR,
    .get_value 		  = ir_get_key_value,
};



const u8 IRTabFF00[] = {
    // 0        1        2        3        4        5        6        7        8        9        0A       0B       0C       0D       0E       0F
       NKEY_00, NKEY_01, NKEY_02, NKEY_03, NKEY_04, NKEY_05, NKEY_06, NKEY_06, NKEY_06, NKEY_06, NKEY_0A, NKEY_0B, NKEY_06, NKEY_06, NKEY_0E, NKEY_0F,
    // 10       11       12       13       14       15       16       17       18       19       1A       1B       1C       1D       1E       1F
       NKEY_10, NKEY_11, NKEY_12, NKEY_13, NKEY_14, NKEY_00, NKEY_00, NKEY_17, NKEY_00, NKEY_00, NKEY_1A, NKEY_1B, NKEY_00, NKEY_1D, NKEY_1E, NKEY_1F,
    // 20       21       22       23       24       25       26       27       28       29       2A       2B       2C       2D       2E       2F
       NKEY_20, NKEY_21, NKEY_22, NKEY_23, NKEY_24, NKEY_25, NKEY_26, NKEY_27, NKEY_28, NKEY_29, NKEY_2A, NKEY_2B, NKEY_2C, NKEY_2D, NKEY_2E, NKEY_2F,
    // 30       31       32       33       34       35       36       37       38       39       3A       3B       3C       3D       3E       3F
       NKEY_30, NKEY_31, NKEY_32, NKEY_33, NKEY_34, NKEY_35, NKEY_36, NKEY_37, NKEY_38, NKEY_39, NKEY_3A, NKEY_3B, NKEY_3C, NKEY_3D, NKEY_3E, NKEY_3F,
    // 40       41       42       43       44       45       46       47       48       49       4A       4B       4C       4D       4E       4F
       NKEY_41, NKEY_41, NKEY_00, NKEY_00, NKEY_00, NKEY_00, NKEY_00, NKEY_00, NKEY_48, NKEY_49, NKEY_00, NKEY_4B, NKEY_4C, NKEY_4D, NKEY_4E, NKEY_4F,
    // 50       51       52       53       54       55       56       57       88       59       5A       5B       5C       5D       5E       5F
       NKEY_50, NKEY_51, NKEY_00, NKEY_53, NKEY_54, NKEY_55, NKEY_56, NKEY_57, NKEY_58, NKEY_59, NKEY_00, NKEY_5B, NKEY_5C, NKEY_5D, NKEY_00, NKEY_5F,
   };


/*----------------------------------------------------------------------------*/
/**@brief   获取ir按键值
   @param   void
   @param   void
   @return  void
   @note    void get_irkey_value(void)
*/
/*----------------------------------------------------------------------------*/
u8 ir_get_key_value(void)
{
    u8 tkey = 0xff;
    tkey = get_irflt_value();
    if (tkey == 0xff) {
        return tkey;
    }
    tkey = IRTabFF00[tkey];
    return tkey;
}


/*----------------------------------------------------------------------------*/
/**@brief   ir按键初始化
   @param   void
   @param   void
   @return  void
   @note    void ir_key_init(void)
*/
/*----------------------------------------------------------------------------*/
int irkey_init(const struct irkey_platform_data *irkey_data)
{
    printf("irkey_init ");

    ir_input_io_sel(irkey_data->port);

    ir_output_timer_sel();

    irflt_config();

    ir_timeout_set();

    return 0;
}

#endif

