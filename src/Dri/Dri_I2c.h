#ifndef __DRI_I2C_H__
#define __DRI_I2C_H__

#include "Com_Util.h"

// 标准的两线I2C接口，SCL和SDA
#define SDA P16
#define SCL P17

/**
 * @brief  发送I2C起始信号
 *
 */
void Dri_I2C_Start(void);

/**
 * @brief  发送I2C停止信号
 *
 */
void Dri_I2C_Stop(void);

/**
 * @brief  发送I2C ACK信号
 * @param  ack ACK信号，0表示ACK，1表示NACK
 */
void Dri_I2C_SendACK(u8 ack);

/**
 * @brief  等待I2C ACK信号
 * @return ACK信号，0表示ACK，1表示NACK
 */
bit Dri_I2C_RecvACK(void);

/**
 * @brief  发送一个字节数据
 * @param  data 要发送的数据
 */
void Dri_I2C_SendByte(u8 data);

/**
 * @brief  从I2C总线上接收一个字节数据
 * @return 接收到的数据
 */
u8 Dri_I2C_ReceiveByte(void);
#endif /* __DRI_I2C_H__ */