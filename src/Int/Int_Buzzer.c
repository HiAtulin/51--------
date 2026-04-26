#include "Int_Buzzer.h"

static u16 s_buzz_time = 0; // 蜂鸣器响起的剩余时间，单位为毫秒

static void Buzzer_Timer_Callback(void)
{
    if (s_buzz_time > 0)
    {
        BUZZER_EN = ~BUZZER_EN; // 切换蜂鸣器状态
        s_buzz_time--;          // 剩余时间减少1ms
    }
    else
    {
        BUZZER_EN = 0; // 关闭蜂鸣器
    }
}

void Int_Buzzer_Init(void)
{
    // 将蜂鸣器运行函数注册到定时器2中断回调函数数组中
    Driver_TIM2_RegisterCallback(Buzzer_Timer_Callback);
}

void Int_Buzzer_Buzz(u16 ms)
{
    s_buzz_time = ms; // 设置蜂鸣器响起的时间    
}
