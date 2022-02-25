#ifndef __TIMER_H__
#define __TIMER_H__

#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include <Intrins.h> 
#include <Absacc.h>
#include "ram.h"
#include "sys.h"
#include "uart.h"


#define TIMER_1T_1ms_TH	((65536-(u16)(float)(1000*((float)(MCU_SYSCLK)/(float)(1000000)))) /256) 			
#define TIMER_1T_1ms_TL	((65536-(u16)(float)(1000*((float)(MCU_SYSCLK)/(float)(1000000)))) %256)

#define TIMER_12T_1ms_TH	((65536-(u16)(float)(1000*((float)(MCU_SYSCLK)/(float)(12000000)))) /256) 			
#define TIMER_12T_1ms_TL	((65536-(u16)(float)(1000*((float)(MCU_SYSCLK)/(float)(12000000)))) %256)  

//extern xdata u16 time_ms;
extern idata u16 Time_Tx_Out;

void Init_Timer0(void);
void DelayXus(u8 xUs);
void Init_PCA_PWM(void);
void Init_Beep(void);
void Beep_On(void);
void Beep_Off(void);
void delay_ms(u8 ms);

#endif
