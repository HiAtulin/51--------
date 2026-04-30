#ifndef __INT_SENSOR_H__
#define __INT_SENSOR_H__

#include "Com_Util.h"
#include "Com_GPIO.h"

/**
 * @brief  获取偏差值
 * 1. MM 和 LM 黑  -1
 * 2.LM 黑         -2
 * 3.LL LM 黑      -3
 * 4.LL 黑         -4
 * 
 * -4 -2 0 2 4
 * 
 * 正数 左偏  负数 右偏
 * @return char 
 */
char Int_Sensor_GetError(void);
#endif /* __INT_SENSOR_H__ */