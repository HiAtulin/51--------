#ifndef __INT_RADAR_H__
#define __INT_RADAR_H__

#include "Com_Util.h"
#include "Com_GPIO.h"
#include "Dri_tim.h"

/**
 * @brief  超声波雷达初始化函数
 * 
 */
void Int_Radar_Init(void);

/**
 * @brief  获取超声波雷达测量距离的函数，单位为mm,100ms测量一次
 * 
 * @return u16 
 */
u16 Int_Radar_GetDistance(void);


#endif /* __INT_RADAR_H__ */