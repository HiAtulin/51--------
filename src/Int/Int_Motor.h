#ifndef __INT_MOTOR_H__
#define __INT_MOTOR_H__

#include "Com_Util.h"
#include "Com_GPIO.h"
#include "Dri_tim.h"
#include <MATH.H>

/**
 * @brief  电机初始化函数
 *
 */
void Int_Motor_Init(void);

/**
 * @brief   设置左电机速度函数
 *
 * @param speed  最高40档 正数表示前进，负数表示后退，绝对值越大速度越快 -40-+40
 */
void Int_Motor_SetLeft(char speed);

/**
 * @brief   设置右电机速度函数   
 *
 * @param speed  最高40档 正数表示前进，负数表示后退，绝对值越大速度越快 -40-+40
 */
void Int_Motor_SetRight(char speed);

#endif /* __INT_MOTOR_H__ */