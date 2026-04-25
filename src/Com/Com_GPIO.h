#ifndef __COM_GPIO_H__
#define __COM_GPIO_H__

//LED
#define LED_FL P24 //前左
#define LED_FR P23 //前右
#define LED_BR P22 //后右
#define LED_BL P21 //后左

//蜂鸣器
#define BUZZER_EN P7

//按键
#define KEY_SW1 P41
#define KEY_SW2 P46

//超声波雷达
#define RADER_TRIG P33
#define RADER_ECHO P32

//电机
#define MOTOR_A1 P11
#define MOTOR_A2 P10
#define MOTOR_B1 P13
#define MOTOR_B2 P12
#define MOTOR_EN P14
#define MOTOR_FAULT P42

//光电反射传感器
#define PATROL_RR P00
#define PATROL_RM P01
#define PATROL_MM P02
#define PATROL_LM P03
#define PATROL_LL P04

#endif /* __COM_GPIO_H__ */