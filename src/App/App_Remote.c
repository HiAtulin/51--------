#include "App_Remote.h"

/**
 * @brief 循环调用 即可实现蓝牙对小车的遥控控制
 *
 */
void App_Remote_Control(void)
{
    u8 ch;
    // 通过接收到的单个字节来判断小车前进后退 左转右转
    Int_BLE_ReceiveByte(&ch);

    switch (ch) {
        case 'U':
            // 小车前进
            Int_Motor_SetLeft(10);
            Int_Motor_SetRight(10);
            break;
        case 'D':
            // 小车后退
            Int_Motor_SetLeft(-10);
            Int_Motor_SetRight(-10);
            break;
        case 'L':
            // 小车左转
            Int_Motor_SetLeft(-10);
            Int_Motor_SetRight(10);
            break;
        case 'R':
            // 小车右转
            Int_Motor_SetLeft(10);
            Int_Motor_SetRight(-10);
            break;
        case 'S':
            // 小车停止
            Int_Motor_SetLeft(0);
            Int_Motor_SetRight(0);
            break;
        default:
            // 小车停止
            Int_Motor_SetLeft(0);
            Int_Motor_SetRight(0);
            break;
    }
#ifdef DEBUG

    Int_OLED_DisplayNum(ch, 0, 0);

#endif // DEBUG
}
