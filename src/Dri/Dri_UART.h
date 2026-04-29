#ifndef __DRI_UART_H__
#define __DRI_UART_H__

#include "Com_Util.h"

/**
 * @brief  初始化UART模块,设置定时器1为波特率发生器，打开串口中断
 * 
 */
void Dri_UART_Init(void);

/**
 * @brief  通过UART发送一个字节数据
 * 
 * @param byte 
 */
void Dri_UART_TransmitByte(u8 byte);


/**
 * @brief  通过UART发送一个字符串
 * 
 * @param str 
 */
void Dri_UART_TransmitBytes(u8* bytes);

/**
 * @brief  通过UART接收一个字节数据
 * 
 * @param byte  接收数据的指针
 * @return bit  如果接收成功返回1，否则返回0
 */
bit Dri_UART_ReceiveByte(u8* byte);

/**
 * @brief  通过UART接收一个字符串 => \n 结束
 * 
 * @param bytes 接收数据的指针
 * @return bit 如果接收成功返回1，否则返回0 
 */
bit Dri_UART_ReceiveBytes(u8* bytes);

#endif /* __DRI_UART_H__ */