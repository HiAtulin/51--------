#include <STC89C5xRC.H>
#include "Com_Util.h"
#include "Com_tim.h"

static u16 count = 0;

void LED_callback(void)
{
    // 每1ms调用一次，500ms翻转一次LED状态
    count++;
    if (count >= 500)
    {
       count = 0;
       LED_FR = ~LED_FR; // 翻转LED状态
    }
}


void main()
{
    Driver_TIM2_Init();
    Driver_TIM2_RegisterCallback(LED_callback);
    while (1)
    {
        
        
    }
}