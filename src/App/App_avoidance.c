#include "App_avoidance.h"

void App_Avoidance_Control(void)
{
    u8 str[17];
    u16 distance = Int_Radar_GetDistance(); // 获取距离值

    sprintf(str, "%dmm ", distance);   
    Int_OLED_DisplayString(str, 0, 0); // 在OLED上显示距离值     
    if (distance > 100) // 如果距离小于300mm（30厘米），认为前方有障碍物
    {
        Int_Buzzer_Buzz(100);                      // 蜂鸣器报警
        Int_Motor_SetLeft(20);                    //  左电机前进
        Int_Motor_SetRight(20);                   // 右电机后退
        Int_OLED_DisplayString("TURN RIGHT!", 0, 1); // 在OLED上显示提示信息
    }
    else
    {
        Int_Motor_SetLeft(0);                 // 左电机前进
        Int_Motor_SetRight(0);                // 右电机前进
        Int_OLED_DisplayString("GO FORWARD!", 0, 1); // 在OLED上显示提示信息
    }
}