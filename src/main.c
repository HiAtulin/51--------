#include <STC89C5xRC.H>
#include "Com_Util.h"
void main()
{
    //测试
    LED_FR = 0; //点亮前右LED
    while (1)
    {
        Com_Util_Delay1ms(1000);
        
    }
}