//#include "delay.h"

//// For store tick counts in us
//static __IO uint32_t usTicks;

//// SysTick_Handler function will be called every 1 us
//void SysTick_Handler()
//{
//	if (usTicks != 0)
//	{
//		usTicks--;
//	}
//}

//void DelayInit()
//{
//	// Update SystemCoreClock value
//	SystemCoreClockUpdate();
//	// Configure the SysTick timer to overflow every 1 us
//	SysTick_Config(SystemCoreClock / 1000000);
//}

//void DelayUs(uint32_t us)
//{
//	// Reload us value
//	usTicks = us;
//	// Wait until usTick reach zero
//	while (usTicks);
//}

//void DelayMs(uint32_t ms)
//{
//	// Wait until ms reach zero
//	while (ms--)
//	{
//		// Delay 1ms
//		DelayUs(1000);
//	}
//}

#include "stm32f10x.h"
#include "Delay.h"
static u8 fac_us=0;
static u16 fac_ms=0;
void Fn_DELAY_Init (unsigned char _CLK)
{
SysTick->CTRL&=0xfffffffb;
fac_us=_CLK/8;
fac_ms=(u16)fac_us*1000;
}
void Fn_DELAY_ms (unsigned int _vrui_Time)
{
u32 temp;
SysTick->LOAD=(u32)_vrui_Time*fac_ms;
SysTick->VAL =0x00;
SysTick->CTRL=0x01;
do
{
temp=SysTick->CTRL;
}
while((temp&0x01)&&(!(temp&(1<<16))));
SysTick->CTRL=0x00;
SysTick->VAL =0X00;
}
void Fn_DELAY_us (unsigned long _vrui_Time)
{
u32 temp;
SysTick->LOAD=_vrui_Time*fac_us;
SysTick->VAL=0x00;
SysTick->CTRL=0x01 ;
do
{
temp=SysTick->CTRL;
}
while((temp&0x01)&&(!(temp&(1<<16))));
SysTick->CTRL=0x00;
SysTick->VAL =0X00;
}
