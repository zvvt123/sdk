#include "app_main.h"
// #include "xuan_led.h"
#include "gpio.h"
#include "asm/clock.h"
#include "timer.h"
#include "app_task.h"
#include "app_config.h"
#include "audio_config.h"
#include "btstack/avctp_user.h"


#if TCFG_XUAN_LED_ENABLE

#define XUAN_LED_COUNT    5

#define LED_PA3_IO        IO_PORTB_07

#define LED_PA0_INIT()    do{gpio_set_pull_up(LED_PA3_IO,0);gpio_set_pull_down(LED_PA3_IO,0);gpio_set_direction(LED_PA3_IO,0);}while(0)

#define LED_PA0_PA3_OFF() do{gpio_set_pull_up(LED_PA3_IO,0);gpio_set_pull_down(LED_PA3_IO,0);gpio_set_direction(LED_PA3_IO,1);}while(0)


AT(.common)
void  rgb_oneline_4delay(void)///  0.3us    0  h     0.2-0.35
{
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    /*asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");*/
    // asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");
}

AT(.common)
void  rgb_oneline_8delay(void)///0.9us      1  h    0.65 - 1
{
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
}

AT(.common)
void rgb_oneline_16delay(void)   ////   0L       1.6-30
{
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");
}

AT(.common)
void rgb_oneline_12delay(void)   ////   1L       1.15 -30
{
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");


    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");asm volatile("nop");
}

AT(.common)
void  rgb_oneline_reset_delay(void)
{
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();

    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
    rgb_oneline_8delay();
}

AT(.common)
void rgb_all_Hout(void)
{

    gpio_direction_output(LED_PA3_IO,1);
    rgb_oneline_8delay();  //高电平时间维持0.65us   (输入1码时，高电平维持时间)


    gpio_direction_output(LED_PA3_IO,0);
    rgb_oneline_12delay(); //低电平时间维持1.15us-30us  (输入1码时，低电平维持时间)
}
AT(.common)
void rgb_all_Lout(void)
{

    gpio_direction_output(LED_PA3_IO,1);
    rgb_oneline_4delay(); //高电平时间维持0.3us  (输入0码时，高电平维持时间)


    gpio_direction_output(LED_PA3_IO,0);
    rgb_oneline_16delay();//低电平时间维持1.60us-30us   (输入0码时，低电平维持时间)
}

AT(.common)
void rgb_oneline_start(void)   //复位
{

    gpio_direction_output(LED_PA3_IO,0);
    rgb_oneline_reset_delay();

}

AT(.common)
void rgb_oneline_start_head_HIGH(void)  
{
        gpio_direction_output(LED_PA3_IO,0);
        for(u8 i=0; i<10; i++)
           //328us 的高电平----
            {
                rgb_oneline_reset_delay();
                rgb_oneline_reset_delay();
                rgb_oneline_reset_delay();
                rgb_oneline_reset_delay();
                rgb_oneline_reset_delay();
           
    }
}

u16 LedLight[XUAN_LED_COUNT*3]={0};   //一开始默认是0，最后由所需要可传入0-255
u8 LedDataBack[XUAN_LED_COUNT*3];

void LedSelCtrl(void)
{
    u8 i,j,k;
    static u8 DataRestFlg = 1;  // 数据更新标志位：1表示无更新，0表示有更新

    // 遍历所有LED的RGB数据（每个LED有R/G/B三个分量，总长度XUAN_LED_COUNT*3）
    for(k=0; k<=(XUAN_LED_COUNT*3 - 1); k++)
    {
        // 检测当前数据（LedLight）与备份数据（LedDataBack）是否有变化
        if(LedDataBack[k] != LedLight[k])
        {
            DataRestFlg = 0;          // 标记数据有更新
            LedDataBack[k] = LedLight[k];  // 同步备份数据为当前值
           // LedLight[k] = LedDataBack[k]/5;  // （原注释保留）
        }
    }

    // 若数据无更新，直接返回避免重复操作
    if(DataRestFlg)
    {
        return;
    }

    DataRestFlg = 1;  // 重置标志位，准备下一次更新检测

    // 启动LED通信协议：发送起始高电平信号（具体实现由rgb_oneline_start_head_HIGH完成）
    //rgb_oneline_start_head_HIGH();
    //rgb_oneline_start();  // 复位LED通信总线（初始化协议时序）

    // 遍历所有LED的RGB分量（每个分量占1字节，共XUAN_LED_COUNT*3个分量）
    for(j=0; j<=(XUAN_LED_COUNT*3 - 1); j++)
    {
        // 逐位发送当前分量的8位数据（从最高位到最低位）
        for(i=0; i<8; i++)
        {
            // 检测当前位是否为高电平（通过BIT(7)取最高位）
            if(LedLight[j]&BIT(7))
            {
                rgb_all_Hout();  // 发送"1"码（高电平信号）
            }
            else
            {
                rgb_all_Lout();  // 发送"0"码（低电平信号）
            }
            LedLight[j] <<= 1;  // 左移一位，准备处理下一位
        }
    }

   // rgb_oneline_start();  // 复位LED通信总线，结束本次数据发送
}

u32 reset_passkey_cb(void)
{
    u32 newkey = rand32();//��ȡ�����

    newkey &= 0xfffff;
    if (newkey > 999999) {
        newkey = newkey - 999999; //���ܴ���999999
    }
    return newkey;
}

u8 light_mode(void)
{
    static u8 light_mode = 2;

    return light_mode;
}


u8 color_rotation_active = 0;
u16 current_hue_value = 0;   // 三个灯共享同一个色相数据源

void led_one_mode_up(void) {
    if (!color_rotation_active) {
        color_rotation_active = 1;
        // 初始化三个灯的起始颜色位置（相同位置）
        current_hue_value = 0;
    }

    // 获取音频能量值
    int energy = ave_dac_energy_get();
    
    // 根据能量值动态调整步长
    u16 step_value = 5; // 默认步长
    if (energy > 100) {  // 有音频能量时加快速度
        step_value = 10; // 加快的步长
    }

    // 使用简单的HSV色彩空间算法，确保完全闭合的循环
    u16 hue = current_hue_value % 1536; // 1536 = 6 * 256，确保完整循环
    
    // 三个灯同时使用相同的颜色数据
    for (u8 i = 0; i < XUAN_LED_COUNT; i++) {
        // 基于HSV的简单算法，确保颜色过渡平滑无断层
        u16 sector = hue / 256;  // 0-5：红、黄、绿、青、蓝、紫
        u16 fraction = hue % 256; // 0-255：当前扇区内的位置
        
        switch (sector) {
            case 0: // 红 -> 黄：红色保持255，绿色从0到255
                LedLight[i * 3 + 1] = 255;                    // 红色
                LedLight[i * 3 + 0] = fraction;              // 绿色渐变
                LedLight[i * 3 + 2] = 0;                      // 蓝色
                break;
            case 1: // 黄 -> 绿：红色从255到0，绿色保持255
                LedLight[i * 3 + 1] = 255 - fraction;        // 红色渐变
                LedLight[i * 3 + 0] = 255;                    // 绿色
                LedLight[i * 3 + 2] = 0;                      // 蓝色
                break;
            case 2: // 绿 -> 青：绿色保持255，蓝色从0到255
                LedLight[i * 3 + 1] = 0;                      // 红色
                LedLight[i * 3 + 0] = 255;                    // 绿色
                LedLight[i * 3 + 2] = fraction;              // 蓝色渐变
                break;
            case 3: // 青 -> 蓝：绿色从255到0，蓝色保持255
                LedLight[i * 3 + 1] = 0;                      // 红色
                LedLight[i * 3 + 0] = 255 - fraction;        // 绿色渐变
                LedLight[i * 3 + 2] = 255;                    // 蓝色
                break;
            case 4: // 蓝 -> 紫：红色从0到255，蓝色保持255
                LedLight[i * 3 + 1] = fraction;              // 红色渐变
                LedLight[i * 3 + 0] = 0;                      // 绿色
                LedLight[i * 3 + 2] = 255;                    // 蓝色
                break;
            case 5: // 紫 -> 红：红色保持255，蓝色从255到0
                LedLight[i * 3 + 1] = 255;                    // 红色
                LedLight[i * 3 + 0] = 0;                      // 绿色
                LedLight[i * 3 + 2] = 255 - fraction;        // 蓝色渐变
                break;
        }
    }

    // 更新共享的数据源
    current_hue_value += step_value;
    if (current_hue_value >= 1536) {
        current_hue_value = 0; // 完全闭合的循环
    }
}

u8 breathing_start_flag = 1;
u32 white_breathing_value = 0;
u8 breathing_mode_index = 0;

void flash_breathing_init_1(void)      // 呼吸灯
{
    if (breathing_start_flag)
    {
        white_breathing_value = white_breathing_value + 1;
    }
    if (white_breathing_value == 255)
    {
        breathing_start_flag = 0;
    }
    if (!breathing_start_flag)
    {
        white_breathing_value = white_breathing_value - 1;
    }
    if (white_breathing_value == 0)
    {
        breathing_mode_index++;
        breathing_start_flag = 1;
    }
    if (breathing_mode_index > 5)
    {
        breathing_mode_index = 0;
    }

    // 修改为紫色显示逻辑
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  white_breathing_value * 255 / 255;
        LedLight[i*3+0] =  white_breathing_value * 40 / 255;
        LedLight[i*3+2] =  white_breathing_value * 147 / 255;
    }
}


u8 green_breathing_start = 1;
u32 green_breathing_val = 0;
u8 green_breathing_mode = 0;

void flash_breathing_init_green(void)      // 绿色呼吸灯
{
    if (green_breathing_start)
    {
        green_breathing_val = green_breathing_val + 1;
    }
    if (green_breathing_val == 255)
    {
        green_breathing_start = 0;
    }
    if (!green_breathing_start)
    {
        green_breathing_val = green_breathing_val - 1;
    }
    if (green_breathing_val == 0)
    {
        green_breathing_mode++;
        green_breathing_start = 1;
    }
    if (green_breathing_mode > 5)
    {
        green_breathing_mode = 0;
    }

    // 修改为绿色显示逻辑
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  0;
        LedLight[i*3+0] =  green_breathing_val;
        LedLight[i*3+2] =  0;
    }
}


// // 在绿色呼吸灯变量后添加以下全局变量
// u8 green_breathing_start = 1;
// u32 green_breathing_val = 0;
// u8 green_breathing_mode = 0;

// 红色呼吸灯全局变量
u8 red_breathing_start = 1;
u32 red_breathing_val = 0;
u8 red_breathing_mode = 0;

// 橙色呼吸灯全局变量
u8 orange_breathing_start = 1;
u32 orange_breathing_val = 0;
u8 orange_breathing_mode = 0;

// 粉色呼吸灯全局变量
u8 pink_breathing_start = 1;
u32 pink_breathing_val = 0;
u8 pink_breathing_mode = 0;

// void flash_breathing_init_green(void)      // 绿色呼吸灯
// {
//     if (green_breathing_start)
//     {
//         green_breathing_val = green_breathing_val + 1;
//     }
//     if (green_breathing_val == 255)
//     {
//         green_breathing_start = 0;
//     }
//     if (!green_breathing_start)
//     {
//         green_breathing_val = green_breathing_val - 1;
//     }
//     if (green_breathing_val == 0)
//     {
//         green_breathing_mode++;
//         green_breathing_start = 1;
//     }
//     if (green_breathing_mode > 5)
//     {
//         green_breathing_mode = 0;
//     }

//     // 修改为绿色显示逻辑
//     for (u8 i = 0; i < XUAN_LED_COUNT; i++)
//     {
//         LedLight[i*3+1] =  0;       // 中间通道（可能是红色或其他）
//         LedLight[i*3+0] =  green_breathing_val;  // 绿色通道
//         LedLight[i*3+2] =  0;       // 蓝色通道
//     }
// }

void flash_breathing_init_red(void)      // 红色呼吸灯
{
    if (red_breathing_start)
    {
        red_breathing_val = red_breathing_val + 1;
    }
    if (red_breathing_val == 255)
    {
        red_breathing_start = 0;
    }
    if (!red_breathing_start)
    {
        red_breathing_val = red_breathing_val - 1;
    }
    if (red_breathing_val == 0)
    {
        red_breathing_mode++;
        red_breathing_start = 1;
    }
    if (red_breathing_mode > 5)
    {
        red_breathing_mode = 0;
    }

    // 修改为红色显示逻辑
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  red_breathing_val;  // 红色通道
        LedLight[i*3+0] =  0;       // 绿色通道
        LedLight[i*3+2] =  0;       // 蓝色通道
    }
}

void flash_breathing_init_orange(void)      // 橙色呼吸灯
{
    if (orange_breathing_start)
    {
        orange_breathing_val = orange_breathing_val + 1;
    }
    if (orange_breathing_val == 255)
    {
        orange_breathing_start = 0;
    }
    if (!orange_breathing_start)
    {
        orange_breathing_val = orange_breathing_val - 1;
    }
    if (orange_breathing_val == 0)
    {
        orange_breathing_mode++;
        orange_breathing_start = 1;
    }
    if (orange_breathing_mode > 5)
    {
        orange_breathing_mode = 0;
    }

    // 修改为橙色显示逻辑（红+绿的组合）
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  orange_breathing_val;  // 红色通道
        LedLight[i*3+0] =  orange_breathing_val * 100 / 255;  // 适量的绿色分量
        LedLight[i*3+2] =  0;       // 蓝色通道
    }
}

void flash_breathing_init_pink(void)      // 粉色呼吸灯
{
    if (pink_breathing_start)
    {
        pink_breathing_val = pink_breathing_val + 1;
    }
    if (pink_breathing_val == 255)
    {
        pink_breathing_start = 0;
    }
    if (!pink_breathing_start)
    {
        pink_breathing_val = pink_breathing_val - 1;
    }
    if (pink_breathing_val == 0)
    {
        pink_breathing_mode++;
        pink_breathing_start = 1;
    }
    if (pink_breathing_mode > 5)
    {
        pink_breathing_mode = 0;
    }

    // 修改为粉色显示逻辑（红+蓝的组合）
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  pink_breathing_val;  // 红色通道
        LedLight[i*3+0] =  0;       // 绿色通道
        LedLight[i*3+2] =  pink_breathing_val * 150 / 255;  // 适量的蓝色分量
    }
}

// 黄色呼吸灯全局变量
u8 yellow_breathing_start = 1;
u32 yellow_breathing_val = 0;
u8 yellow_breathing_mode = 0;

void flash_breathing_init_yellow(void)      // 黄色呼吸灯
{
    if (yellow_breathing_start)
    {
        yellow_breathing_val = yellow_breathing_val + 1;
    }
    if (yellow_breathing_val == 255)
    {
        yellow_breathing_start = 0;
    }
    if (!yellow_breathing_start)
    {
        yellow_breathing_val = yellow_breathing_val - 1;
    }
    if (yellow_breathing_val == 0)
    {
        yellow_breathing_mode++;
        yellow_breathing_start = 1;
    }
    if (yellow_breathing_mode > 5)
    {
        yellow_breathing_mode = 0;
    }

    // 修改为黄色显示逻辑（红+绿的组合）
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        LedLight[i*3+1] =  yellow_breathing_val;  // 红色通道
        LedLight[i*3+0] =  yellow_breathing_val;  // 绿色通道（与红色等量）
        LedLight[i*3+2] =  0;       // 蓝色通道
    }
}


u8 blue_breathing_start = 1;
u32 blue_breathing_val = 0;
u8 blue_breathing_mode = 0;

void flash_breathing_init_blue(void)      // 蓝色呼吸灯
{
    if (blue_breathing_start)
    {
        blue_breathing_val = blue_breathing_val + 1;
    }
    if (blue_breathing_val == 255)
    {
        blue_breathing_start = 0;
    }
    if (!blue_breathing_start)
    {
        blue_breathing_val = blue_breathing_val - 1;
    }
    if (blue_breathing_val == 0)
    {
        blue_breathing_mode++;
        blue_breathing_start = 1;
    }
    if (blue_breathing_mode > 5)
    {
        blue_breathing_mode = 0;
    }

    // 修改为蓝色显示逻辑
    for (u8 i = 0; i < XUAN_LED_COUNT; i++)
    {
        // 红色分量为0
        LedLight[i * 3 + 0] = 0;
        // 绿色分量为0
        LedLight[i * 3 + 1] = 0;
        // 蓝色分量
        LedLight[i * 3 + 2] = blue_breathing_val;
    }
}

// // 呼吸灯状态标志
// u8 breathing_increase_flag = 1;
// // 当前呼吸灯颜色值，使用浮点数以实现更细腻的变化
// float current_breathing_value = 0.0;
// // 当前呼吸灯颜色索引
// u8 current_color_index = 0;
// // 亮度变化步长，减小步长以实现更平滑的过渡
// const float step = 1.0;

// void flash_breathing_init_2(void)      // 呼吸灯
// {
//     if (breathing_increase_flag)
//     {
//         current_breathing_value += step;
//     }
//     if (current_breathing_value >= 255.0)
//     {
//         current_breathing_value = 255.0;
//         breathing_increase_flag = 0;
//     }
//     if (!breathing_increase_flag)
//     {
//         current_breathing_value -= step;
//     }
//     if (current_breathing_value <= 0.0)
//     {
//         current_breathing_value = 0.0;
//         current_color_index++;
//         breathing_increase_flag = 1;
//     }
//     if (current_color_index > 4)
//     {
//         current_color_index = 0;
//     }

//     for (u8 i = 0; i < XUAN_LED_COUNT; i++)
//     {
//         switch (current_color_index)
//         {
//             case 0:
//                 LedLight[i * 3 + 1] = 0;
//                 LedLight[i * 3 + 0] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 2] = 0;
//                 break;
//             case 1:
//                 LedLight[i * 3 + 1] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 0] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 2] = 0;
//                 break;
//             case 2:
//                 LedLight[i * 3 + 1] = 0;
//                 LedLight[i * 3 + 0] = 0;
//                 LedLight[i * 3 + 2] = (u8)current_breathing_value;
//                 break;
//             case 3:
//                 LedLight[i * 3 + 1] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 0] = 0;
//                 LedLight[i * 3 + 2] = 0;
//                 break;
//             case 4:
//                 LedLight[i * 3 + 1] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 0] = 0;
//                 LedLight[i * 3 + 2] = (u8)current_breathing_value;
//                 break;
//             case 5:
//                 LedLight[i * 3 + 1] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 0] = (u8)current_breathing_value;
//                 LedLight[i * 3 + 2] = (u8)current_breathing_value;
//                 break;
//         }
//     }
// }

// void fm_les_scan(void) {
//     if(!xuan_led_pp_flag) {
//        for(u8 i=0; i<XUAN_LED_COUNT; i++)
//         {
//             LedLight[i*3+1] =  255;
//             LedLight[i*3+0] =  0;
//             LedLight[i*3+2] =  0;
//         }
//     }else
//     {
//         for(u8 i=0; i<XUAN_LED_COUNT; i++)
//         {
//             LedLight[i*3+1] =  0;
//             LedLight[i*3+0] =  0;
//             LedLight[i*3+2] =  0;
//         }
//     }
    
    
// }




u16 step=0;
u16 data =0;
u16 temp =0;
u16 init_data = 0;
u8 led_one_mode_flag = 0;
u16 led_one_mode_data[XUAN_LED_COUNT] = {0};

void led_one_mode(void) {
    if (!led_one_mode_flag) {
        led_one_mode_flag = 1;
        init_data = 0;
        step = 765 / XUAN_LED_COUNT;

        for (u8 i = 0; i < XUAN_LED_COUNT; i++) {
            led_one_mode_data[i] = init_data;
            init_data += step;
            r_printf("1111111111111111111111111111_led_one_mode_data[i] == %d\n", led_one_mode_data[i]);
            r_printf("2222222222222222_led_one_mode_flag == %d\n", led_one_mode_flag);
        }
    }

    for (u8 i = 0; i < XUAN_LED_COUNT; i++) {
            data = led_one_mode_data[i];
        if (data < 255) {
            LedLight[i * 3 + 1] = 255 - data;
            LedLight[i * 3 + 0] = data;
            LedLight[i * 3 + 2] = 0;
        } else if (data < 510) {
            temp = 510 - data;
            LedLight[i * 3 + 1] = 0;
            LedLight[i * 3 + 0] = temp;
            LedLight[i * 3 + 2] = 255 - temp;
        } else if (data < 765) {
            temp = 765 - data;
            LedLight[i * 3 + 1] = 255 - temp;
            LedLight[i * 3 + 0] = 0;
            LedLight[i * 3 + 2] = temp;
        }

        led_one_mode_data[i] += 10;
        if (led_one_mode_data[i] > 764) {
            led_one_mode_data[i] = 0;
        }
    }
}

#define music_delay 2


// const u8 music_led_one_mode_array[9][XUAN_LED_COUNT] = {
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 1, 0},
//     {0, 0, 1, 1, 0},
//     {0, 1, 1, 1, 0},
//     {1, 1, 1, 1, 0},
//     {1, 1, 1, 1, 1},
//     {1, 1, 1, 1, 1},
//     {1, 1, 1, 1, 1},
//     {1, 1, 1, 1, 1}
// };

// void music_led_one_mode(void) {
//     static u8 music_led_one_mode_num = 0;
//     static u8 music_led_one_mode_num_delay = 0;
//     int music_led_one_mode_energy = ave_dac_energy_get() / 10;

//     music_led_one_mode_num_delay++;
//     if (music_led_one_mode_num_delay > music_delay) {
//         music_led_one_mode_num_delay = 0;

//         if (music_led_one_mode_energy > 1000) {
//             music_led_one_mode_num = 7 + reset_passkey_cb() % 3;
//         } else if (music_led_one_mode_energy > 700) {
//             music_led_one_mode_num = 6 + reset_passkey_cb() % 3;
//         } else if (music_led_one_mode_energy > 500) {
//             music_led_one_mode_num = 4 + reset_passkey_cb() % 3;
//         } else if (music_led_one_mode_energy > 300) {
//             music_led_one_mode_num = 3 + reset_passkey_cb() % 2;
//         } else if (music_led_one_mode_energy > 100) {
//             music_led_one_mode_num = 1 + reset_passkey_cb() % 2;
//         } else if (music_led_one_mode_energy > 50) {
//             music_led_one_mode_num = reset_passkey_cb() % 2;
//         } else {
//             music_led_one_mode_num = 0;
//         }
//     }

//     for (u8 i = 0; i < XUAN_LED_COUNT; i++) {
//         if (music_led_one_mode_array[music_led_one_mode_num][i]) {
//             u16 data = led_one_mode_data[XUAN_LED_COUNT - 1 - i];
//             if (data < 255) {
//                 LedLight[i * 3 + 1] = 255 - data;
//                 LedLight[i * 3 + 0] = data;
//                 LedLight[i * 3 + 2] = 0;
//             } else if (data < 510) {
//                 u16 temp = 510 - data;
//                 LedLight[i * 3 + 1] = 0;
//                 LedLight[i * 3 + 0] = temp;
//                 LedLight[i * 3 + 2] = 255 - temp;
//             } else if (data < 765) {
//                 u16 temp = 765 - data;
//                 LedLight[i * 3 + 1] = 255 - temp;
//                 LedLight[i * 3 + 0] = 0;
//                 LedLight[i * 3 + 2] = temp;
//             }

//             led_one_mode_data[XUAN_LED_COUNT - 1 - i] += 5;
//             if (led_one_mode_data[XUAN_LED_COUNT - 1 - i] > 764) {
//                 led_one_mode_data[XUAN_LED_COUNT - 1 - i] = 0;
//             }
//         } else {
//             LedLight[i * 3 + 1] = 8;
//             LedLight[i * 3 + 0] = 0;
//             LedLight[i * 3 + 2] = 8;
//         }
//     }
// }




// 音乐能量跳动模式全局变量
u8 music_energy_mode_flag = 0;
u8 current_color_index = 0; // 当前颜色索引(0=蓝,1=紫,2=红,3=橙,4=粉)
u16 energy_change_counter = 0; // 计数器控制闪烁速度
u8 last_brightness_level = 0; // 记录上一次的亮度级别

// 音乐能量跳动模式
void music_energy_led_mode(void)
{
    // 增加计数器
    energy_change_counter++;
    
    // 获取音频能量值
    int music_energy = ave_dac_energy_get() / 5;
    
    // 根据能量值调整LED显示
    if (music_energy > 0)
    {
        // 只在计数器达到一定值时才考虑切换颜色（减慢颜色切换速度）
        if (energy_change_counter % 15 == 0) // 每15次调用才检查一次颜色切换
        {
            // 提高颜色切换阈值，使颜色变化更少
            if (music_energy > 400)
            {
                current_color_index = (current_color_index + 1) % 5; // 循环切换5种颜色
            }
        }
        
        // 根据能量值计算亮度级别（使用更少的级别，使亮度变化不那么频繁）
        u8 brightness_level;
        if (music_energy > 500) {
            brightness_level = 4; // 最高亮度
        } else if (music_energy > 300) {
            brightness_level = 3; // 高亮度
        } else if (music_energy > 150) {
            brightness_level = 2; // 中等亮度
        } else if (music_energy > 50) {
            brightness_level = 1; // 低亮度
        } else {
            brightness_level = 0; // 最低亮度
        }
        
        // 只有当亮度级别变化时才更新亮度值，减少不必要的变化
        if (brightness_level != last_brightness_level || energy_change_counter % 10 == 0)
        {
            last_brightness_level = brightness_level;
            
            // 根据亮度级别设置实际亮度值
            u8 brightness;
            switch (brightness_level) {
                case 4: brightness = 255; break;
                case 3: brightness = 200; break;
                case 2: brightness = 120; break;
                case 1: brightness = 60; break;
                default: brightness = 10; break;
            }
            
            // 根据当前颜色索引设置LED颜色
            for (u8 i = 0; i < XUAN_LED_COUNT; i++)
            {
                switch (current_color_index)
                {
                    case 0: // 蓝色
                        LedLight[i*3+1] = 0;
                        LedLight[i*3+0] = 0;
                        LedLight[i*3+2] = brightness;
                        break;
                    case 1: // 紫色
                        LedLight[i*3+1] = brightness;
                        LedLight[i*3+0] = 0;
                        LedLight[i*3+2] = brightness;
                        break;
                    case 2: // 红色
                        LedLight[i*3+1] = brightness;
                        LedLight[i*3+0] = 0;
                        LedLight[i*3+2] = 0;
                        break;
                    case 3: // 橙色
                        LedLight[i*3+1] = brightness;
                        LedLight[i*3+0] = brightness / 2;
                        LedLight[i*3+2] = 0;
                        break;
                    case 4: // 粉色
                        LedLight[i*3+1] = brightness;
                        LedLight[i*3+0] = 0;
                        LedLight[i*3+2] = brightness / 2;
                        break;
                }
            }
        }
    }
    else
    {
        // 无音乐输入时，LED保持微亮的粉色
        for (u8 i = 0; i < XUAN_LED_COUNT; i++)
        {
            // 固定设置为微亮的粉色
            LedLight[i*3+1] = 15; // 红色分量
            LedLight[i*3+0] = 0;  // 绿色分量
            LedLight[i*3+2] = 8;  // 蓝色分量，形成粉色效果
        }
    }
}



u8 xuan_pwm_star = 1;
u32 xuan_breathing_count = 0;
u8 xuan_breathing_mode = 0;

void xuan_breathing_init(void) {
    // 呼吸灯计数增减逻辑
    if (xuan_pwm_star) {
        if (xuan_breathing_count < 255) {
            xuan_breathing_count += 3;
        } else {
            xuan_pwm_star = 0;
        }
    } else {
        if (xuan_breathing_count > 0) {
            xuan_breathing_count -= 3;
        } else {
            xuan_pwm_star = 1;
            xuan_breathing_mode = (xuan_breathing_mode + 1) % 6;
        }
    }

    // 直接使用呼吸灯计数值作为亮度值
    u8 brightness = xuan_breathing_count;

    // 根据不同模式设置LED颜色
    for (u8 i = 0; i < XUAN_LED_COUNT; i++) {
        switch (xuan_breathing_mode) {
            case 0:
                LedLight[i * 3 + 1] = brightness;
                LedLight[i * 3 + 0] = 0;
                LedLight[i * 3 + 2] = 0;
                break;
            case 1:
                LedLight[i * 3 + 1] = 0;
                LedLight[i * 3 + 0] = brightness;
                LedLight[i * 3 + 2] = 0;
                break;
            case 2:
                LedLight[i * 3 + 1] = 0;
                LedLight[i * 3 + 0] = brightness;
                LedLight[i * 3 + 2] = brightness;
                break;
            case 3:
                LedLight[i * 3 + 1] = 0;
                LedLight[i * 3 + 0] = 0;
                LedLight[i * 3 + 2] = brightness;
                break;
            case 4:
                LedLight[i * 3 + 1] = brightness;
                LedLight[i * 3 + 0] = 0;
                LedLight[i * 3 + 2] = brightness;
                break;
            case 5:
                LedLight[i * 3 + 1] = brightness;
                LedLight[i * 3 + 0] = brightness;
                LedLight[i * 3 + 2] = brightness;
                break;
        }
    }
}

// 修改数组为5个灯
const u8 case3_led_pattern_array[10][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

// 定义颜色结构体，将名字修改为 LEDColor
typedef struct {
    u8 red;
    u8 green;
    u8 blue;
} LEDColor;

// 定义每种模式下的颜色组合，结构体类型同步修改
const LEDColor case3_mode_colors[6][2] = {
    // 模式0: 点亮和未点亮的颜色
    {{0, 255, 255}, {0, 255, 0}},
    // 模式1: 点亮和未点亮的颜色
    {{0, 0, 255}, {0, 255, 255}},
    // 模式2: 点亮和未点亮的颜色
    {{255, 0, 255}, {0, 0, 255}},
    // 模式3: 点亮和未点亮的颜色
    {{255, 0, 0}, {255, 0, 255}},
    // 模式4: 点亮和未点亮的颜色
    {{255, 255, 0}, {0, 255, 0}},
    // 模式5: 点亮和未点亮的颜色
    {{0, 255, 0}, {255, 255, 0}}
};

void case3_led_mode_initialization(void)
{
    static u8 current_pattern_index = 0;
    static u8 frame_counter = 0;
    static u8 current_mode_index = 0;

    frame_counter++;
    if (frame_counter > 3)
    {
        frame_counter = 0;
        current_pattern_index++;
        if (current_pattern_index > 9)
        {
            current_pattern_index = 0;
            current_mode_index++;
            if (current_mode_index > 5)
            {
                current_mode_index = 0;
            }
        }
    }

    for (u8 led_index = 0; led_index < 5; led_index++)
    {
        // 根据是否点亮选择颜色，结构体类型同步修改
        const LEDColor *selected_color = &case3_mode_colors[current_mode_index][case3_led_pattern_array[current_pattern_index][led_index]];
        LedLight[led_index * 3 + 0] = selected_color->red;
        LedLight[led_index * 3 + 1] = selected_color->green;
        LedLight[led_index * 3 + 2] = selected_color->blue;
    }
}


       // 修改数组为5个灯
    const u8 case4_led_pattern_array[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };

    // 定义颜色结构体，将名字修改为 LightColor
    typedef struct {
        u8 red;
        u8 green;
        u8 blue;
    } LightColor;

    // 定义每种模式下的颜色组合，结构体类型同步修改
    const LightColor case4_mode_colors[6] = {
        // 模式0: 红色
        {0, 255, 0},
        // 模式1: 紫色
        {0, 255, 255},
        // 模式2: 蓝色
        {0, 0, 255},
        // 模式3: 青色
        {255, 255, 0},
        // 模式4: 绿色
        {255, 0, 0},
        // 模式5: 黄色
        {255, 255, 0}
    };

    void case4_led_mode_setup(void)
    {
        static u8 current_pattern_index = 0;
        static u8 counter = 0;
        static u8 current_mode_index = 0;
        static u8 mode_delay_counter = 0;
        int energy_level = ave_dac_energy_get() / 10;

        mode_delay_counter++;
        if (mode_delay_counter > music_delay)
        {
            mode_delay_counter = 0;
            if (energy_level > 750)
            {
                current_pattern_index = reset_passkey_cb() % 5;
            }
            else if (energy_level > 500)
            {
                current_pattern_index = reset_passkey_cb() % 4;
            }
            else if (energy_level > 250)
            {
                current_pattern_index = reset_passkey_cb() % 3;
            }
            else if (energy_level > 50)
            {
                current_pattern_index = reset_passkey_cb() % 2;
            }
            else
            {
                current_pattern_index = 0;
            }
        }

        counter++;
        if (counter > 50)
        {
            counter = 0;
            current_mode_index++;
            if (current_mode_index > 5)
            {
                current_mode_index = 0;
            }
        }

        for (u8 led_index = 0; led_index < 5; led_index++)
        {
            if (case4_led_pattern_array[current_pattern_index][led_index])
            {
                // 根据模式选择颜色，结构体类型同步修改
                const LightColor *selected_color = &case4_mode_colors[current_mode_index];
                LedLight[led_index * 3 + 0] = selected_color->red;
                LedLight[led_index * 3 + 1] = selected_color->green;
                LedLight[led_index * 3 + 2] = selected_color->blue;
            }
            else
            {
                LedLight[led_index * 3 + 1] = 8;
                LedLight[led_index * 3 + 0] = 0;
                LedLight[led_index * 3 + 2] = 8;
            }
        }
    }

const u8 bt_dconn_xuan_led_mode_array[XUAN_LED_COUNT] = {0,2,1,0,2,1,0,1};
void bt_dconn_xuan_led_mode_init(void)
{
    static u8 bt_led_dconn_flag = 0;   
    static u8 bt_led_dconn_cnt = 0;   

    bt_led_dconn_cnt++;
    if(bt_led_dconn_cnt == 15)
    {
        bt_led_dconn_cnt = 0;
        bt_led_dconn_flag = !bt_led_dconn_flag;
    }

    if(bt_led_dconn_flag)
    {
        for(u8 i=0; i<XUAN_LED_COUNT; i++)
        {
            if(bt_dconn_xuan_led_mode_array[i] == 1)
            {
                LedLight[i*3+1] =  255/light_mode();
                LedLight[i*3+0] =  0;
                LedLight[i*3+2] =  0;
            }else if(bt_dconn_xuan_led_mode_array[i] == 2)
            {
                LedLight[i*3+1] =  0;
                LedLight[i*3+0] =  0;
                LedLight[i*3+2] =  255/light_mode();
            }else
            {
                LedLight[i*3+1] =  0;
                LedLight[i*3+0] =  255/light_mode();
                LedLight[i*3+2] =  0;
            }
        }
    }
    else
    {
        for(u8 i=0; i<XUAN_LED_COUNT; i++)
        {
            LedLight[i*3+1] =  0;
            LedLight[i*3+0] =  0;
            LedLight[i*3+2] =  0;
        }
    }
}


void xuan_led_tws(void)
{
    led_one_mode_flag = 0;
    data =0;
    temp =0;
    step =0;
    init_data =0;
    for (u8 i = 0; i < XUAN_LED_COUNT; i++) 
    {
     led_one_mode_data[i] = 0;
    }

    blue_breathing_start = 1;
    blue_breathing_val = 0;
    blue_breathing_mode = 0;

    breathing_start_flag = 1;
    white_breathing_value = 0;
    breathing_mode_index = 0;

    // 红色呼吸灯全局变量
    red_breathing_start = 1;
    red_breathing_val = 0;
    red_breathing_mode = 0;

    // 橙色呼吸灯全局变量
    orange_breathing_start = 1;
    orange_breathing_val = 0;
    orange_breathing_mode = 0;

    // 粉色呼吸灯全局变量
    pink_breathing_start = 1;
    pink_breathing_val = 0;
    pink_breathing_mode = 0;


    // 黄色呼吸灯全局变量
    yellow_breathing_start = 1;
    yellow_breathing_val = 0;
    yellow_breathing_mode = 0;

    color_rotation_active = 0;
    current_hue_value = 0;

    music_energy_mode_flag = 0;
    current_color_index = 0; // 当前颜色索引(0=蓝,1=紫,2=红,3=橙,4=粉)
    energy_change_counter = 0; // 计数器控制闪烁速度
    last_brightness_level = 0; // 记录上一次的亮度级别


    green_breathing_start = 1;
    green_breathing_val = 0;
    green_breathing_mode = 0;

}


extern u8 xuan_poweron_flag;
u8 bt_conn_led_flag = 0;
bool xuan_poweroff_flag = false;
extern u8 rgb_count = 0;
u8 xuan_led_mode = 0;
extern u8 xuan_led_pp_flag = 0;
extern u8 xuan_led_power_on = 0;
extern u8 led_power_off_flag=0;
void led_xuan_scan(void)
{
    if(!power_mute_up)
    {
        return;
    }

    if(xuan_poweroff_flag)
    {
        for(u8 i=0; i<XUAN_LED_COUNT; i++)
        {
            LedLight[i*3+1] =  0;
            LedLight[i*3+0] =  0;
            LedLight[i*3+2] =  0;
        }
        LedSelCtrl();
        return;
    }

    switch(xuan_led_mode)
    {

            case 0:
                    led_one_mode();
                    break;


            case 1:
                    flash_breathing_init_blue(); //蓝色
                    break;

            case 2:
                    flash_breathing_init_1(); //紫色
                break;
            case 3:
                    flash_breathing_init_red(); //红色
                break;
            case 4:
                    flash_breathing_init_orange(); //橙色
                    break;
                            
            case 5:
                    flash_breathing_init_pink();//粉色
                break;     
            case 6:
                    flash_breathing_init_yellow(); //黄色
                break; 

            case 7:
                    flash_breathing_init_green(); //绿色
            break;
            case 8:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //蓝色
                    {
                        LedLight[i*3+1] =  0;    // 红色分量为0
                        LedLight[i*3+0] =  0;    // 绿色分量为0
                        LedLight[i*3+2] =  255;  // 蓝色分量为255（最大亮度）
                    }
                    break; 
            case 9:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //紫色
                    {
                        LedLight[i*3+1] =  255;  // 红色分量为255
                        LedLight[i*3+0] =  0;    // 绿色分量为0
                        LedLight[i*3+2] =  255;  // 蓝色分量为255
                    }
                    break; 
            case 10:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //红色
                    {
                        LedLight[i*3+1] =  255;  // 红色分量为255
                        LedLight[i*3+0] =  0;    // 绿色分量为0
                        LedLight[i*3+2] =  0;    // 蓝色分量为0
                    }
                break;              
            case 11:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //橙色
                    {
                        LedLight[i*3+1] =  255;  // 红色分量为255
                        LedLight[i*3+0] =  128;  // 绿色分量为128（中等亮度）
                        LedLight[i*3+2] =  0;    // 蓝色分量为0
                    }
                break; 
            case 12:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //粉色
                    {
                        LedLight[i*3+1] =  255;  // 红色分量为255
                        LedLight[i*3+0] =  0;    // 绿色分量为0
                        LedLight[i*3+2] =  128;  // 蓝色分量为128（中等亮度）
                    }
                break; 

                case 13:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //黄色
                    {
                        LedLight[i*3+1] =  255;  // 红色分量为255
                        LedLight[i*3+0] =  255;    // 绿色分量为0
                        LedLight[i*3+2] =  0;  // 蓝色分量为128（中等亮度）
                    }
                break; 

                case 14:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++) //绿色
                    {
                        LedLight[i*3+1] =  0;  // 红色分量为255
                        LedLight[i*3+0] =  255;    // 绿色分量为0
                        LedLight[i*3+2] =  0;  // 蓝色分量为128（中等亮度）
                    }
                break; 

                case 15:
                music_energy_led_mode();
                break; 


                case 16:
                led_one_mode_up();
                break; 


                case 17:
                    for(u8 i=0; i<XUAN_LED_COUNT; i++)
                    {
                        LedLight[i*3+1] =  0;  
                        LedLight[i*3+0] =  0;    
                        LedLight[i*3+2] =  0;  
                    }
                break;

                
    }
    LedSelCtrl();
}


static const u32 timer_div[] =
{
    /*0000*/    1,
    /*0001*/    4,
    /*0010*/    16,
    /*0011*/    64,
    /*0100*/    2,
    /*0101*/    8,
    /*0110*/    32,
    /*0111*/    128,
    /*1000*/    256,
    /*1001*/    4 * 256,
    /*1010*/    16 * 256,
    /*1011*/    64 * 256,
    /*1100*/    2 * 256,
    /*1101*/    8 * 256,
    /*1110*/    32 * 256,
    /*1111*/    128 * 256,
};

#define USER_TIMER              JL_TIMER2
#define USER_TIMER_IDX          IRQ_TIME2_IDX
#define APP_TIMER_CLK           clk_get("timer")
#define MAX_TIME_CNT            0x7fff
#define MIN_TIME_CNT            0x100

#define TIMER_UNIT_MS           60
#define MAX_TIMER_PERIOD_MS     (1000/TIMER_UNIT_MS)

struct timer_hdl
{
    u32 ticks;
    int index;
    int prd;
    u32 fine_cnt;
    void *power_ctrl;
    struct list_head head;
};

static struct timer_hdl hdl;
void led_xuan_two_scan(void);

#define __this  (&hdl)

___interrupt
static void led3_timer_isr()
{
    static u32 cnt = 0;
    USER_TIMER->CON |= BIT(14);
    ++cnt;
    if ((cnt % 5) == 0)
    {
    }

    led_xuan_scan();

    if (cnt == 500)
    {
        cnt = 0;
    }
}

static int led3_timer_init()
{
    u32 prd_cnt;
    u8 index;

    printf("USER_TIMER->CON : 0x%x / %d", USER_TIMER->CON, clk_get("timer"));

    for (index = 0; index < (sizeof(timer_div) / sizeof(timer_div[0])); index++)
    {
        prd_cnt = TIMER_UNIT_MS * (APP_TIMER_CLK / 2000) / timer_div[index];
        if (prd_cnt > MIN_TIME_CNT && prd_cnt < MAX_TIME_CNT)
        {
            break;
        }
    }
    __this->index   = index;
    __this->prd     = prd_cnt;

    USER_TIMER->CNT = 0;
    USER_TIMER->PRD = prd_cnt;
    request_irq(USER_TIMER_IDX, 3, led3_timer_isr, 0);
    USER_TIMER->CON = (index << 4) | BIT(0) | BIT(3);

    printf("PRD : 0x%x / %d", USER_TIMER->PRD, clk_get("timer"));

    return 0;
}

void led_xuan_init(void)
{
    led3_timer_init();
}

#endif



