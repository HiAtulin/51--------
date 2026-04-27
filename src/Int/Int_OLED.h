
#ifndef __INT_OLED_H__
#define __INT_OLED_H__

#include "Com_Util.h"
#include "Dri_I2c.h"
#include "STRING.h"
#include "STDIO.H"

#define DEV_ADDR 0x78 // OLED设备地址

/**
 * @brief  OLED显示屏初始化函数
 *
 */
void Int_OLED_Init(void);

/**
 * @brief  OLED显示屏清屏函数
 *
 */
void Int_OLED_Clear(void);

/**
 * @brief  OLED显示屏显示字符串函数
 *
 * @param  str: 要显示的字符串
 * @param  x: 显示字符串的起始x坐标 0-15
 * @param  y: 显示字符串的起始y坐标 0-3 
 */
void Int_OLED_DisplayString(u8 *str, u8 x, u8 y);

/**
 * @brief  OLED显示屏显示数字函数
 *
 * @param  num: 要显示的数字
 * @param  x: 显示数字的起始x坐标 0-15
 * @param  y: 显示数字的起始y坐标 0-3 
 */
void Int_OLED_DisplayNum(u32 num, u8 x, u8 y);

#endif /* __INT_OLED_H__ */