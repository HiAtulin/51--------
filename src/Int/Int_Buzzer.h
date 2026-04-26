#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "Com_Util.h"
#include "Com_GPIO.h"
#include "Dri_tim.h"

/**
 * @brief  蜂鸣器初始化
 * 
 */
void Int_Buzzer_Init(void);

/**
 * @brief  蜂鸣器响起
 * 1ms切换一次状态,2ms一个周期，频率为500Hz
 * @param ms  响起的时间，单位为毫秒
 */
void Int_Buzzer_Buzz(u16 ms);


#endif /* __INT_BUZZER_H__ */