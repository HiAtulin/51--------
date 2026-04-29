#include "App_avoidance.h"
#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include "Int_Motor.h"
#include "Int_OLED.h"
#include "Int_Radar.h"
#include "Int_ble.h"

static u8 receive_buf[16]; // 接收缓冲区

void main()
{
    u16 distance = 0;
    Driver_TIM2_Init(); // 初始化定时器2，用于产生PWM信号和定时调用回调函数
    Int_OLED_Init();    // 初始化OLED显示屏
    Int_OLED_Clear();   // 清屏
    Int_Radar_Init();   // 初始化超声波雷达
    Int_Buzzer_Init();  // 初始化蜂鸣器
    Int_Motor_Init();   // 初始化电机

    // 使用蓝牙
    Dri_UART_Init();             // 初始化UART模块
    // Int_BLE_TransmitBytes("AT"); // 发送AT命令测试蓝牙模块是否正常工作

    // while (Int_BLE_ReceiveBytes(receive_buf) == 0)
    // { // 等待接收数据
    // }
    // Int_OLED_DisplayString(receive_buf, 0, 0); // 在OLED上显示接收到的数据
    // while (Int_BLE_ReceiveBytes(receive_buf) == 0)
    // { // 等待接收数据
    // }
    // Int_OLED_DisplayString(receive_buf, 0, 1);

    
    while (1)
    {
        App_Remote_Control();
    }
}