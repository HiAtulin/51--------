#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include "Int_OLED.h"
#include "Int_Radar.h"

static u16 count = 0;

void main()
{
    u16 distance = 0;
    Driver_TIM2_Init();
    Int_OLED_Init();
    Int_OLED_Clear(); // 清屏
    Int_Radar_Init(); // 初始化超声波雷达
    Int_Buzzer_Init();


    while (1)
    {
        distance = Int_Radar_GetDistance(); // 获取距离值
        Int_OLED_DisplayNum(distance, 0, 0); // 在OLED上显示距离值
    }
}