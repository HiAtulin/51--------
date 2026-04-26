#include "Com_tim.h"

// 定时器2回调函数数组
static Timer2_Callback s_timer2_callback[TIMER2_CALLBACK_NUM];
// 当前注册的回调函数数量
static u8 s_callback_count = 0;

void Driver_TIM2_Init(void)
{
    // 打开中断
    EA = 1;  // 总中断开关
    ET2 = 1; // 定时器2中断允许
    // 配置定时器2时钟源和工作模式
    C_T2 = 0; // 定时器2使用内部时钟
    RCLK = 0;
    TCLK = 0;
    CP_RL2 = 1; // 定时器2自动重载
    EXEN2 = 0;  // 定时器2不使用外部事件触发
    // 配置定时器2的初始值和重载值
    // 计算出定时器加1的时间为11.0592MHz/12=921600Hz，即每1.085微秒
    // 中断溢出时间1ms=1000微秒/1.085微秒=921.6个计数周期，取整数922
    TL2 = 65536 - 922;
    TH2 = (65536 - 922) >> 8;
    RCAP2H = (65536 - 922) >> 8; // 重载高8位
    RCAP2L = 65536 - 922;        // 重载低8位
    // 开始计数
    TR2 = 1; // 启动定时器2
    // 设置定时器2中断优先级(default:0)
}

/**
 * @brief 注册定时器2回调函数
 * @param callback 回调函数指针
 * @return 注册是否成功
 */
bit Driver_TIM2_RegisterCallback(Timer2_Callback callback)
{
    if (s_callback_count >= TIMER2_CALLBACK_NUM)
    {
        return 0; // 注册失败，回调函数数组已满
    }
    // 检查是否已经注册过相同的回调函数
    u8 i;
    for (i = 0; i < s_callback_count; i++)
    {
        if (s_timer2_callback[i] == callback)
        {
            return 1; // 注册成功，回调函数已存在
        }
    }
    s_timer2_callback[s_callback_count++] = callback; // 注册回调函数并增加计数
    return 1;                                         // 注册成功
}

/**
 * @brief 注销定时器2回调函数
 * @param callback 回调函数指针
 * @return 注销是否成功
 */
bit Driver_TIM2_DeregisterCallback(Timer2_Callback callback)
{
    // 如何删除回调函数：将数组中对应的函数指针置空，并将后续的函数指针前移
    u8 i;
    u8 j;
    for (i = 0; i < s_callback_count; i++)
    {
        if (s_timer2_callback[i] == callback)
        {
            // 找到要注销的回调函数，进行删除

            for (j = i; j < s_callback_count - 1; j++)
            {
                s_timer2_callback[j] = s_timer2_callback[j + 1]; // 前移后续函数指针
            }
            s_timer2_callback[--s_callback_count] = 0; // 最后一个位置置空并减少计数
            return 1;                                  // 注销成功
        }
    }
    return 0; // 注销失败，未找到对应的回调函数
}