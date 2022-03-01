#ifndef __GPIO_H__
#define __GPIO_H__

#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include "timer.h"
#include "ram.h"
#include "ML7345.h"

#define LED_G_0		P25
#define LED_R		P26
#define LED_G_1		P27
#define NEW_PCB     1

#if (NEW_PCB==0)
#define Receiver_LED_TX     P26
#define Receiver_LED_RX     P24
#define Receiver_LED_OUT    P25
#define Receiver_OUT_OPEN   P12
#define Receiver_OUT_STOP   P11
#define Receiver_OUT_CLOSE  P10
#define Receiver_Login      P21
#define TP3                 P40
#define TP4                 P41
#define Receiver_test       P13
#define ML7345_RESETN       P27
#define ML7345_DATA         P35

#else

#define Receiver_LED_TX     P27
#define Receiver_LED_RX     P35
#define Receiver_LED_OUT    P25
#define Receiver_OUT_OPEN   P12
#define Receiver_OUT_STOP   P11
#define Receiver_OUT_CLOSE  P10
#define Receiver_Login      P21
#define TP3                 P40
#define TP4                 P41
#define Receiver_test       P13
#define ML7345_RESETN       P34
#define ML7345_DATA         P24
#endif



#define Receiver_vent Receiver_vent_Cache       // Input   受信机换气联动ON/OFF


/********************天线切换 CG2214M6控制引脚寄存器************************/
#define CG2214M6_VC1        P23
#define CG2214M6_VC2        P22

#define CG2214M6_RF1_USE  \
    {                     \
        CG2214M6_VC1 = 0; \
        CG2214M6_VC2 = 1; \
    } 
#define CG2214M6_RF2_USE  \
    {                     \
        CG2214M6_VC1 = 1; \
        CG2214M6_VC2 = 0; \
    }
#define CG2214M6_USE_T CG2214M6_RF1_USE
#define CG2214M6_USE_R CG2214M6_RF2_USE


extern void Init_Port(void);
extern void Init_Interrupt(void); 
//extern u8 key_scan(void);






#endif
