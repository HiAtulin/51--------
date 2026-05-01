#include "Int_Key.h"

static u8 s_key1_sampling = 0xff;
static bit s_key1_pressed = 1;
static u8 s_key2_sampling = 0xff;
static bit s_key2_pressed = 1;

static void Int_Key_Callback(void){
    s_key1_sampling <<= 1;
    s_key1_sampling |= KEY_SW1;
    s_key2_sampling <<= 1;
    s_key2_sampling |= KEY_SW1;
}


void Int_Key_Init(void)
{
    Driver_TIM2_RegisterCallback(Int_Key_Callback);
}

u8 Int_Key_IsSw1Pressed(void)
{
    if (s_key1_pressed == 1 && s_key1_sampling == 0x00)
    {
        s_key1_pressed = 0;
        return 1;
    }
    if (s_key1_pressed == 0 && s_key1_sampling == 0xff)
    {
        s_key1_pressed = 1;
        return 2;
    }
    return 0;
    
}
u8 Int_Key_IsSw2Pressed(void)
{
    if (s_key2_pressed == 1 && s_key2_sampling == 0x00)
    {
        s_key2_pressed = 0;
        return 1;
    }
    if (s_key2_pressed == 0 && s_key2_sampling == 0xff)
    {
        s_key2_pressed = 1;
        return 2;
    }
    return 0;
}
