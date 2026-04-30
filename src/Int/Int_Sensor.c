#include "Int_Sensor.h"

char Int_Sensor_GetError(void)
{
    char error = 0;
    u8 count = 0;
    if(PATROL_RR){
        error += 4;
        count++;
    }
    if (PATROL_RM)
    {
        error += 2;
        count++;
    }
    if(PATROL_MM){
        error += 0;
        count++;
    }
    if (PATROL_LM)
    {
        error -= 2;
        count++;
    }
    if (PATROL_LL)
    {
        error -= 4;
        count++;
    }
    if (count)
    {
        return error / count;     
    }else{
        return 0;
    }
}