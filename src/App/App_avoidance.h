#ifndef __APP_AVOIDANCE_H__
#define __APP_AVOIDANCE_H__

#include "Com_Util.h"
#include "Int_Motor.h"
#include "Int_Radar.h"
#include "Int_Buzzer.h"
#include "Int_OLED.h"

/**
 * @brief  避障控制函数，根据超声波雷达测量的距离值来控制电机的速度和方向，
 * 以及蜂鸣器的报警
 * 
 */
void App_Avoidance_Control(void);

#endif /* __APP_AVOIDANCE_H__ */