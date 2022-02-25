#ifndef __SYS_H__
#define __SYS_H__


#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include "gpio.h"
#include "timer.h"


/*************************************************
定义系统时钟SysClk (MAX.25MHz)
可选: 
	11059200,12000000,
	22118400,24000000,
*************************************************/
#define MCU_SYSCLK		16000000
/*************************************************/
/*************************************************
定义CPU时钟 CpuClk (MAX.25MHz)
	1) CpuCLK=SysCLK
	2) CpuClk=SysClk/2
*************************************************/
#define MCU_CPUCLK		(MCU_SYSCLK)
//#define MCU_CPUCLK		(MCU_SYSCLK/2)





void Init_Clock(void);
void Init_WDT(void);
void ClearWDT(void);

#endif
