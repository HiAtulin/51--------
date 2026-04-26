#include "Com_Util.h"
#include "Dri_tim.h"
#include "Int_Buzzer.h"
#include <STC89C5xRC.H>

static u16 count = 0;

// void LED_callback(void)
// {
//     // 每1ms调用一次，500ms翻转一次LED状态
//     count++;
//     if (count >= 500)
//     {
//        count = 0;
//        LED_FR = ~LED_FR; // 翻转LED状态
//     }
// }

void main()
{
    Driver_TIM2_Init();
    Int_Buzzer_Init();
    Int_Buzzer_Buzz(3000); // 蜂鸣器响起5秒钟
    // Driver_TIM2_RegisterCallback(LED_callback);
    // Com_Util_Delay1ms(3000); // 等待3秒钟，观察LED状态变化
    // Driver_TIM2_DeregisterCallback(LED_callback);
    while (1)
    {
    }
}