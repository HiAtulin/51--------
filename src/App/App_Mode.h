#ifndef __APP_MODE_H__
#define __APP_MODE_H__

#include "Com_Util.h"
#include "Int_Key.h"
#include "Int_OLED.h"
#include "Int_Motor.h"

typedef enum
{
    STOP,
    REMOTE,
    PATROL,
    AVOIDANCE
}Enum_Mode;
void App_Mode_Init(void);
Enum_Mode App_Mode_GetMode(void);

#endif /* __APP_MODE_H__ */