#include "App_Patrol.h"

#define PID_KP 1000
#define PID_KI 1
#define PID_KD 600

static int s_sum_error = 0;
static int s_last_error = 0;


static int App_Patrol_GetPID(void){
    int result = 0;
    int error = Int_Sensor_GetError();
    int diff_error;
    s_sum_error += error;
    if (s_sum_error > 2000)
    {
        s_sum_error = 2000;
    }else if (s_sum_error < -2000)
    {
        s_sum_error = -2000;
    }
    
    
    diff_error = error - s_last_error;
    result = error *PID_KP +s_sum_error *PID_KI + diff_error * PID_KD; 
    result /= 50;
    if (result > 80)
    {
        result = 80;
    }else if (result < -80)
    {
        result = -80;
    }
    s_last_error = error;
    return result;
     
}

void App_Patrol_Control(void)
{   
    int pid = App_Patrol_GetPID();

#ifdef DEBUG
    Int_OLED_DisplayNum(pid, 0, 0); // 在OLED上显示提示信息
#endif
    Int_Motor_SetLeft(40 + pid);
    Int_Motor_SetRight(40 - pid);

}