#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "Com_Util.h"
#include "Com_GPIO.h"
#include "Dri_tim.h"

void Int_Key_Init(void);

u8 Int_Key_IsSw1Pressed(void);

u8 Int_Key_IsSw2Pressed(void);

#endif /* __INT_KEY_H__ */