#include "Int_Motor.h"

// 考虑如何输出正确的PWM信号来控制电机的速度和方向
// 选择周期40ms，频率为25Hz

static u8 motor_count = 0;      // 用于计数定时器中断的次数，以实现PWM信号的占空比控制
static u8 left_speed = 0;       // 左电机速度，范围-40到+40
static u8 right_speed = 0;      // 右电机速度，范围-40到+40
static bit s_left_forward = 1;  // 左电机方向标志，1表示前进，0表示后退
static bit s_right_forward = 1; // 右电机方向标志，1表示前进，0表示后退
static void Int_Motor_Timer2Callback(void)
{
    if (motor_count < left_speed) // 根据左电机速度设置占空比
    {
        MOTOR_A1 = s_left_forward;  // 前进
        MOTOR_A2 = ~s_left_forward; // 后退
    }
    else
    {
        MOTOR_A1 = 0; // 停止
        MOTOR_A2 = 0;
    }
    if (motor_count < right_speed) // 根据右电机速度设置占空比
    {
        MOTOR_B1 = ~s_right_forward;  // 前进
        MOTOR_B2 = s_right_forward; // 后退
    }
    else
    {
        MOTOR_B1 = 0; // 停止
        MOTOR_B2 = 0;
    }
    motor_count++;
    if (motor_count >= 40) // 每40ms重置计数器，开始新一轮PWM周期
    {
        motor_count = 0;
    }
}

void Int_Motor_Init(void)
{
    MOTOR_EN = 1; // 使能电机驱动
    MOTOR_FAULT = 1;
    // 初始化置位电机控制引脚
    MOTOR_A1 = 0;
    MOTOR_A2 = 0;
    MOTOR_B1 = 0;
    MOTOR_B2 = 0;

    // 使用定时器2来产生PWM信号，周期40ms，频率25Hz
    Driver_TIM2_RegisterCallback(Int_Motor_Timer2Callback);
}

void Int_Motor_SetLeft(char speed)
{
    if (speed > 40) speed = 40;   // 限制速度范围
    if (speed < -40) speed = -40;
    s_left_forward = (speed >= 0); // 根据速度正负设置方向标志
    left_speed = (u8)(abs(speed)); // 取速度绝对值作为占空比，范围0-40

}

void Int_Motor_SetRight(char speed)
{
    if (speed > 40) speed = 40;   // 限制速度范围
    if (speed < -40) speed = -40;
    s_right_forward = (speed >= 0); // 根据速度正负设置方向标志
    right_speed = (u8)(abs(speed)); // 取速度绝对值作为占空比，范围0-40
}
