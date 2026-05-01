#include "App_avoidance.h"
#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include "Int_Motor.h"
#include "Int_OLED.h"
#include "Int_Radar.h"
#include "Int_ble.h"
#include "App_Remote.h"
#include "Int_Sensor.h"
#include "App_Patrol.h"
#include "Int_Key.h"
#include "App_Mode.h"

static u8 receive_buf[16]; // 接收缓冲区

void main()
{
    u8 key1_status,key2_status;
    Driver_TIM2_Init(); // 初始化定时器2，用于产生PWM信号和定时调用回调函数
    Int_OLED_Init();    // 初始化OLED显示屏
    Int_OLED_Clear();   // 清屏
    Int_Radar_Init();   // 初始化超声波雷达
    Int_Buzzer_Init();  // 初始化蜂鸣器
    Int_Motor_Init();   // 初始化电机

    // 使用蓝牙
    Dri_UART_Init();             // 初始化UART模块
    Int_Key_Init();
    App_Mode_Init();
    while (1)
    {
        switch (App_Mode_GetMode())
        {
        case REMOTE:
            App_Remote_Control();
            break;
        case PATROL:
            App_Patrol_Control();
            break;
        case AVOIDANCE:
            App_Avoidance_Control();
            break;
        
        default:
            break;
        }
    }
}