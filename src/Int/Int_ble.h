#ifndef __INT_BLE_H__
#define __INT_BLE_H__

#include "Com_Util.h"
#include "Dri_UART.h"

/**
 * @brief  通过UART发送一个字节数据
 * 
 */
void Int_BLE_TransmitByte(u8 byte);

/**
 * @brief  通过UART发送一个字符串
 * 
 */
void Int_BLE_TransmitBytes(u8* bytes);

/**
 * @brief  通过UART接收一个字节数据
 * 
 * @param byte  接收数据的指针
 * @return bit  如果接收成功返回1，否则返回0
 */
bit Int_BLE_ReceiveByte(u8* byte);

/**
 * @brief  通过UART接收一个字符串 => \n 结束
 * 
 * @param bytes 接收数据的指针
 * @return bit 如果接收成功返回1，否则返回0 
 */
bit Int_BLE_ReceiveBytes(u8* bytes);

#endif /* __INT_BLE_H__ */