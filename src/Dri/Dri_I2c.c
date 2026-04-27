#include "Dri_I2c.h"

sbit B7 = 0xF7; // 定义B寄存器的第7位为B7

void Dri_I2C_Start(void)
{
    // 保证SDA和SCL都是高电平
    SDA = 1;
    SCL = 1;
    // SDA在SCL高电平时由高变低，产生起始信号
    SDA = 0;
    // 拉低SCL，准备发送数据
    SCL = 0;
}

void Dri_I2C_SendByte(u8 data)
{
    u8 i = 0;
    // 使用单片机中暂存的通用寄存器来存储数据
    B = data; // 将要发送的数据存储在寄存器B中
    for (i = 0; i < 8; i++)
    {
        SDA = B7; // 取出B寄存器的最高位，发送到SDA线上
        SCL = 1;  // 拉高SCL，数据被从SDA发送
        SCL = 0;  // 拉低SCL，准备发送下一位数据
        B <<= 1;  // 将B寄存器中的数据左移一位，为下一位数据准备好最高位
    }
}

void Dri_I2C_SendACK(u8 ack)
{
    SDA = ack; // 将ACK信号发送到SDA线上，0表示ACK，1表示NACK
    SCL = 1;   // 拉高SCL，发送ACK信号
    SCL = 0;   // 拉低SCL，完成ACK信号的发送
}

bit Dri_I2C_RecvACK(void)
{
    bit ack;
    // 释放SDA线，等待从设备发送ACK信号
    SDA = 1;
    SCL = 1;   // 拉高SCL，准备接收ACK信号
    ack = SDA; // 读取SDA线上的ACK信号
    SCL = 0;   // 拉低SCL，完成ACK信号的接收
    return ack;
}

u8 Dri_I2C_ReceiveByte(void)
{
    u8 i = 0;
    u8 data = 0x00; // 用于存储接收到的数据
    for (i = 0; i < 8; i++)
    {
        SCL = 1;    // 拉高SCL，准备接收数据
        data <<= 1; // 将接收到的数据左移一位，为下一位数据准备好最低位
        if (SDA)    // 读取SDA线上的数据，如果是高电平则在data的最低位上设置为1
        {
            data |= 0x01;
        }
        SCL = 0; // 拉低SCL，准备接收下一位数据
    }
    return data;
}

void Dri_I2C_Stop(void)
{
    // SDA在SCL高电平时由低变高，产生停止信号
    SDA = 0; // 保持SDA为低电平
    SCL = 1; // 拉高SCL，准备发送停止信号
    SDA = 1; // 拉高SDA，产生停止信号
}