#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include "Int_OLED.h"
#include "Int_Radar.h"
#include "Int_Motor.h"
#include "App_avoidance.h"

static u16 count = 0;

void main()
{
    u16 distance = 0;
    Driver_TIM2_Init(); // 初始化定时器2，用于产生PWM信号和定时调用回调函数
    Int_OLED_Init(); // 初始化OLED显示屏
    Int_OLED_Clear(); // 清屏
    Int_Radar_Init(); // 初始化超声波雷达
    Int_Buzzer_Init();  // 初始化蜂鸣器
    Int_Motor_Init(); // 初始化电机

    while (1)
    {
        App_Avoidance_Control();    
        Com_Util_Delay1ms(10); // 添加延时，控制避障逻辑执行频率
    }
}