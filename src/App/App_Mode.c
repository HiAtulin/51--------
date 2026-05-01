#include "App_Mode.h"

static Enum_Mode s_current_Mode = REMOTE;
static u16 s_count_down = 3000;
static bit s_oled_clear = 1;

static void App_Mode_Callback(void)
{
    if (s_count_down > 0)
    {
        s_count_down--;
    }
}

void App_Mode_Init(void)
{
    Driver_TIM2_RegisterCallback(App_Mode_Callback);
}
Enum_Mode App_Mode_GetMode(void)
{
    if (Int_Key_IsSw1Pressed() == 1)
    {
        s_current_Mode++;
        if (s_current_Mode > AVOIDANCE)
        {
            s_current_Mode = REMOTE;
        }
        s_count_down = 3000;
        Int_Motor_SetLeft(0);
        Int_Motor_SetRight(0);
    }
    if (s_oled_clear)
    {
        Int_OLED_Clear();
        switch (s_current_Mode)
        {
        case REMOTE:
            Int_OLED_DisplayString("Mode:Remote", 0, 0);
            break;
        case PATROL:
            Int_OLED_DisplayString("Mode:PATROL", 0, 0);
            break;
        case AVOIDANCE:
            Int_OLED_DisplayString("Mode:AVOIDANCE", 0, 0);
            break;
        default:
            break;
        }
        s_oled_clear = 0;
    }
    if (s_count_down > 100)
    {
        Int_OLED_DisplayNum((s_count_down / 1000) +1,0,1);
        return STOP;
    }else if(s_count_down)
    {
        Int_OLED_DisplayString("Go!",0,1);
    }
    return s_current_Mode;
}