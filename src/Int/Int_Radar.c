#include "Int_Radar.h"

// 超声波雷达不能连续测量，测量一次后需要等待至少100ms才能进行下一次测量
static u16 s_allow_count = 0;
static u8 s_is_echo_complete = 0; // 标志位，表示是否完成一次测量
static u16 s_distance = 1000;        // 存储测量得到的距离值

void Int_Radar_Callback(void)
{
    // 每1ms调用一次，允许超声波雷达进行下一次测量
    if (s_allow_count < 100)
    {
        s_allow_count++;
    }
}

void Int_Radar_Init(void)
{
    // 初始化超声波雷达的GPIO引脚
    RADER_ECHO = 0; // 初始状态为低电平
    RADER_TRIG = 0; // 初始状态为低电平

    // 配置定时器0  使用INT0 P32 echo,使用门控模式测量高电平时间
    // 关闭定时器0的溢出中断
    ET0 = 0;
    // 配置定时器0为模式1（16位定时器模式），使用门控模式
    TMOD &= 0xF0; // 清除定时器0的模式位
    TMOD |= 0x09; // 低四位设置为1001（模式1，门控模式）
    // 初始定时器0的计数值为0
    TL0 = 0;
    TH0 = 0;
    // 打开TR0（门控模式下，定时器在INT0为高电平时才计数）
    TR0 = 1;
    // 配置外部中断0为下降沿触发（检测ECHO结束）
    EA = 1;  // 使能总中断
    EX0 = 1; // 使能外部中断0
    IT0 = 1; // 下降沿触发
    // 其他初始化操作，如设置定时器中断优先级等
    PX0 = 1; // 设置外部中断0为高优先级
    // 添加回调函数，定时器0每1ms调用一次，允许超声波雷达进行下一次测量
    Driver_TIM2_RegisterCallback(Int_Radar_Callback);

    s_is_echo_complete = 0; // 初始化标志位
}

u16 Int_Radar_GetDistance(void)
{
    u16 tim0 = 0;
    if (s_allow_count == 100)
    {
        RADER_TRIG = 1;       // 发送高电平信号，触发超声波雷达进行测量
        Com_Util_Delay10us(); // 保持高电平至少10us
        RADER_TRIG = 0;       // 发送低电平信号，结束

        s_allow_count = 0; // 重置计数器，等待下一次测量
    }
    if (s_is_echo_complete == 1)
    {
        
        tim0 = (TH0 << 8) + TL0;
        // 距离计算公式：
        // 系统时钟11.0592MHz，定时器0每12个时钟周期计数一次
        // 定时器频率 = 11.0592MHz / 12 = 921600Hz
        // 每个计数周期时间 = 1/921600 ≈ 1.085μs
        // 超声波速度 = 340m/s = 340000mm/s
        // 距离 = tim0 × 1.085μs × 340000mm/s ÷ 2 ≈ tim0 × 0.184mm
        // 使用整数运算：s_distance = tim0 * 92 / 500
        s_distance = tim0 * 2 / 11;
        TL0 = 0; // 重置定时器0的计数值
        TH0 = 0;
        s_is_echo_complete = 0; // 重置标志位，准备下一次测量
    }
    return s_distance;
}

void Int_Radar_INT0_Handler(void) interrupt 0
{
    s_is_echo_complete = 1; // 标志位置位，表示测量完成
}
