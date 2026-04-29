#include "Dri_UART.h"

void Dri_UART_Init(void)
{
    // 设置串口模式
    SM0 = 0; // 模式0：8位数据，1位停止位，无校验
    SM1 = 1;
    // 设置波特率 为9600bps
    PCON &= 0x7F; // 设置PCON.7 = 0
    // 设置定时器1为模式2（8位自动重载）
    TMOD &= 0x0F; // 0000 1111
    TMOD |= 0x20; // 0010 0000
    // 设置定时器1的重载值
    //  计算公式：重载值 = 256 - (晶振频率 / 12 / 32 / 波特率) = 256 - (11059200 / 12 / 32 / 9600) = 256 - 3 = 253 = 0xFD
    TH1 = 0xFD;
    TL1 = 0xFD;

    // 启动定时器1
    TR1 = 1;

    // 使能串口接收中断
    REN = 1; 
    //不使用系统提供的停止位，使用\n作为结束标志
    SM2 = 0;

    //开启串口中断
    EA = 1; // 全局中断使能
    ES = 1; // 串口中断使能
}

void Dri_UART_TransmitByte(u8 byte)
{
}

void Dri_UART_TransmitBytes(u8 *bytes)
{
}

bit Dri_UART_ReceiveByte(u8 *byte)
{
    return bit();
}

bit Dri_UART_ReceiveBytes(u8 *bytes)
{
    return bit();
}
