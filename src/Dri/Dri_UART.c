#include "Dri_UART.h"


static bit s_is_transmited_byte = 1; // 发送完成标志
static bit s_is_received_byte = 0;  // 接收完成标志


static u8 s_received_bytes[16]; // 接收缓冲区
static u8 s_received_bytes_count = 0; // 接收缓冲区计数器
static bit s_is_received_bytes = 0; 

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
    while (s_is_transmited_byte == 0)
    {

    }
    SBUF = byte; // 将数据写入SBUF寄存器，开始发送
    s_is_transmited_byte = 0; // 发送完成标志清零，等待中断服务函数设置为1
    
}

void Dri_UART_TransmitBytes(u8 *bytes)
{
    u8 ch;
    while (ch = *bytes++) 
    {
        Dri_UART_TransmitByte(ch); // 发送每个字符
    }
}

bit Dri_UART_ReceiveByte(u8 *byte)
{
    if (s_is_received_byte == 1)
    {
        *byte = SBUF; // 读取接收到的数据
        s_is_received_byte = 0; // 清除接收完成标志
        return 1; // 返回接收成功
    }
    return 0; // 返回接收失败
}

bit Dri_UART_ReceiveBytes(u8 *bytes)
{
    u8 i;
    if (s_is_received_bytes == 1)
    {
        for (i = 0; i < s_received_bytes_count; i++)
        {
            bytes[i] = s_received_bytes[i]; // 将接收到的数据复制到用户提供的缓冲区
        }
        bytes[s_received_bytes_count] = '\0'; // 添加字符串结束标志
        s_received_bytes_count = 0; // 清除接收缓冲区计数器
        s_is_received_bytes = 0; // 清除接收完成标志
        return 1; // 返回接收成功
    }
    return 0; // 返回接收失败
    
}


// 串口中断服务函数
void Dri_UART_Handler(void) interrupt 4
{
    if (TI) // 发送完成中断
    {
        TI = 0; // 清除发送完成标志
        // 手动记录，表示发送完成
        s_is_transmited_byte = 1;
    }
    if (RI) // 接收完成中断
    {
        RI = 0; // 清除接收完成标志
        // 手动记录，表示接收完成
        s_is_received_byte = 1;
        if (SBUF !='\n' && s_received_bytes_count < 15){
            s_received_bytes[s_received_bytes_count++] = SBUF; // 将接收到的数据存入缓冲区
        }else{
            s_is_received_bytes = 1;
        }
    }
}