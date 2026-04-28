#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include "Int_OLED.h"
#include "Int_Radar.h"
#include "Int_Motor.h"

static u16 count = 0;

void main()
{
    u16 distance = 0;
    Driver_TIM2_Init();
    Int_OLED_Init();
    Int_OLED_Clear(); // 清屏
    Int_Radar_Init(); // 初始化超声波雷达
    Int_Buzzer_Init();
    Int_Motor_Init(); // 初始化电机

    // Int_Motor_SetLeft(5);  // 设置左电机速度为20档，前进
    // Int_Motor_SetRight(5); // 设置右电机速度为20档，


    while (1)
    {
        // distance = Int_Radar_GetDistance(); // 获取距离值
        // Int_OLED_DisplayNum(distance, 0, 0); // 在OLED上显示距离值
    }
}