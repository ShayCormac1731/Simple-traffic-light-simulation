
#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f10x.h"

//void DelayInit(void);
//void DelayUs(uint32_t us);
//void DelayMs(uint32_t ms);

void Fn_DELAY_Init(unsigned char _CLK);
void Fn_DELAY_ms (unsigned int _vrui_Time);
void Fn_DELAY_us (unsigned long _vrui_Time);

#ifdef __cplusplus
}
#endif

#endif
