#ifndef __COM_TIM_H__
#define __COM_TIM_H__

#include "Com_Util.h"
#include "STDIO.H"

typedef void (*Timer2_Callback)(void);

#define TIMER2_CALLBACK_NUM 5

/**
 * @brief 定时器2初始化
 * 
 */
void Driver_TIM2_Init(void);

/** 
 * @brief 注册定时器2回调函数
 * @param callback 回调函数指针
 * @return 注册是否成功
 */
bit Driver_TIM2_RegisterCallback(Timer2_Callback callback);


/** 
 * @brief 注销定时器2回调函数
 * @param callback 回调函数指针
 * @return 注销是否成功
 */
bit Driver_TIM2_DeregisterCallback(Timer2_Callback callback);

#endif /* __COM_TIM_H__ */