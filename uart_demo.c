#if TCFG_UART_DEMO_OPEN

#include "typedef.h"
#include "system/event.h"
#include "system/includes.h"
#include "key_event_deal.h"
#include "app_task.h"


// #define IO_TX_PIN   IO_PORTB_04//IO_PORTB_02    //---注意RX端的 唤醒--需要关机配置 呼应  PB2/PB4时---OK---mic RX可以正确接收
// #define IO_RX_PIN   IO_PORTB_04//IO_PORTB_02


//---实际样机
#define IO_TX_PIN                       IO_PORTB_10//    PB7时---fail---mic RX只接收 单个字节0
#define IO_RX_PIN                       IO_PORTB_05//

#define BAUD_RATE                       9600//115200

#include "key_event_deal.h"

#define SEND_VOCAL_REMOVE               0x10
#define SEND_PITCH_SW                   0x40
#define SEND_PP                         0x41
#define SEND_MIC_CONN                   0xF1
#define SEND_MIC_DCONN                  0xF0
#define SEND_ECHO_OFF                   0x42
#define SEND_ECHO_ON                    0x43

#define MIC_VOL_START                   0x14           //MIC音量调节开启
#define ECHO_VOL_START                  0x15           //混响音量调节
#define MUSIC_VOL_START                 0x16           //背景音乐调节

#define ECHO_VOL_UP                     0X18
#define ECHO_VOL_DOWM                   0X19

#define MIC_VOL_DUAN_UP                 0x20           //单击效果加
#define MIC_MUSIC_NEXT                  0x31           //长按下一曲
#define MIC_VOL_DUAN_DOWM               0x30           //单击效果减
#define MIC_MUSIC_PREV                  0x21           //长按上一曲
#define ECHO_MIC_VOL_MAX                0x17           //最大提示

u8 uart_cbuf[64] __attribute__((aligned(4)));
u8 uart_rxbuf[16] __attribute__((aligned(4)));
u8 uart_txbuf[16] __attribute__((aligned(4)));
uart_bus_t *uart_bus = NULL;


static void my_put_u8hex(u8 dat)
{
    u8 tmp;
    tmp = dat / 16;
    if (tmp < 10) {
        putchar(tmp + '0');
    } else {
        putchar(tmp - 10 + 'A');
    }
    tmp = dat % 16;
    if (tmp < 10) {
        putchar(tmp + '0');
    } else {
        putchar(tmp - 10 + 'A');
    }
    putchar(0x20);
}


//static void uart_send_data(u8 *buf, u32 len)
void uart_send_data(u8 *buf, u32 len)
{
    printf(" -0-  [%s]:%d\n",__func__,__LINE__);
    put_buf(buf, len);
	if(uart_bus){
		uart_bus->write(buf, len);
	}
}


extern u8 is_wireless_mic_online = 0;//extern u8 is_wireless_mic_online;
extern u8 mic_online_flag;
extern u8 mic_on_off=0;

u32 uart_rxcnt = 0;
static void uart_isr_hook(void *arg, u32 status)
{
    uart_rxcnt = uart_bus->read(uart_rxbuf, sizeof(uart_rxbuf), 0);
	if (status == UT_RX) {
        // printf("----UT_RX---- \n");
    }
    if (status == UT_RX_OT) {   //跑这里
        // printf("----UT_RX_OT---- \n");

        put_buf(uart_rxbuf, uart_rxcnt);
        if(uart_rxbuf[0] == 0x55)
        {
            printf("--------uart_rxbuf[1] = 0x%x\n",uart_rxbuf[1]);
                  switch(uart_rxbuf[1])
                 {
                        case SEND_VOCAL_REMOVE:
                            app_task_put_key_msg(KEY_VOICES_REMOVE,0);
                        break;

                        case SEND_PITCH_SW:

                            app_task_put_key_msg(KEY_SOUNDCARD_MODE_PITCH,0);
                        break;

                        case SEND_PP:
                            app_task_put_key_msg(KEY_MUSIC_PP,0);
                        break;


                        case SEND_MIC_CONN:
                             is_wireless_mic_online = 1;
                        break;

                        case SEND_MIC_DCONN:

                             is_wireless_mic_online = 0;

                        break;

                        case MIC_VOL_DUAN_UP:
                            if (app_get_curr_task()==APP_LINEIN_TASK)
                            {
                                app_task_put_key_msg(KEY_LINEIN_VOL,0);
                            }else if (app_get_curr_task()==APP_MUSIC_TASK)
                            {
                                app_task_put_key_msg(KEY_DUAN_VOL_UP,0);
                            }else
                            {
#if TCFG_MUTE_ENABLE
                                 music_mute_flag = 0;
#endif
                                app_task_put_key_msg(KEY_VOL_UP,0);
                            }

                            break;

                        case MIC_VOL_DUAN_DOWM:
                            app_task_put_key_msg(KEY_VOL_DOWN,0);
                            break;


                        case MIC_MUSIC_NEXT:
                            app_task_put_key_msg(KEY_MUSIC_NEXT,0);
                            break;


                        case MIC_MUSIC_PREV:
                            app_task_put_key_msg(KEY_MUSIC_PREV,0);
                            break;

                        case MIC_VOL_START:
                            app_task_put_key_msg(KEY_MIC_VOL_START,0);
                            break;

                        case ECHO_VOL_START:
                            app_task_put_key_msg(KEY_ECHO_VOL_START,0);
                            break;

                        case MUSIC_VOL_START:
                            app_task_put_key_msg(KEY_MUSIC_VOL_START,0);
                            break;

                        case ECHO_VOL_UP:
                            app_task_put_key_msg(KEY_ECHO_DELAY_UP,0);
                            break;

                        case ECHO_VOL_DOWM:
                            app_task_put_key_msg(KEY_ECHO_DELAY_DOWN,0);
                            break;

                        case ECHO_MIC_VOL_MAX:
                            app_task_put_key_msg(KEY_ECHO_MIC_VOL_MAX,0);
                            break;
        }
      }
    }
}


void uart_close(void)
{
    printf("uart_close");
    if (uart_bus) {
        uart_dev_close(uart_bus);
    }
}

void uart_init_test()
{
    struct uart_platform_data_t ut = {0};
    ut.tx_pin = IO_TX_PIN;
    ut.rx_pin = IO_RX_PIN;
    ut.baud = BAUD_RATE;
    ut.rx_timeout = 10;
    ut.isr_cbfun = uart_isr_hook;
    ut.rx_cbuf = uart_cbuf;
    ut.rx_cbuf_size = 64;
    ut.frame_length = 10;
    uart_bus = (uart_bus_t *)uart_dev_open(&ut);
    if (uart_bus == NULL) {
         printf("open uart dev err\n");
         return;
    }

    //需要将串口IO上拉，不可删除，会影响唤醒RX功能
    /* 问题:但同时会导致接收到都是 00 00 ，返回给RX端也是 00 00, -------改到其他位置,保持RX唤醒后在初始化uart*/
    gpio_set_pull_down(ut.tx_pin,0);
    gpio_set_pull_up(ut.tx_pin,1);



}

void pull_down_uart_io(void)
{
    gpio_set_direction(IO_TX_PIN,1);
    gpio_set_pull_up(IO_TX_PIN,0);
    gpio_set_pull_down(IO_TX_PIN,1);
    gpio_set_die(IO_TX_PIN,1);
}




#endif
