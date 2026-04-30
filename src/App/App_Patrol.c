#include "App_Patrol.h"

void App_Patrol_Control(void)
{
    char error = Int_Sensor_GetError();

#ifdef DEBUG
    Int_OLED_DisplayNum(error, 0, 0); // 在OLED上显示提示信息
#endif
    Int_Motor_SetLeft(40 + error*20);
    Int_Motor_SetRight(40 - error*20);

}