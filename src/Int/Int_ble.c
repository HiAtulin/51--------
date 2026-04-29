#include "Int_ble.h"

void Int_BLE_TransmitByte(u8 byte)
{
    Dri_UART_TransmitByte(byte); // 通过UART发送一个字节数据
}

void Int_BLE_TransmitBytes(u8 *bytes)
{
    Dri_UART_TransmitBytes(bytes); // 通过UART发送一个字符串
}

bit Int_BLE_ReceiveByte(u8 *byte)
{
    return Dri_UART_ReceiveByte(byte); // 通过UART接收一个字节数据
}

bit Int_BLE_ReceiveBytes(u8 *bytes)
{
    return Dri_UART_ReceiveBytes(bytes); // 通过UART接收一个字符串
}
