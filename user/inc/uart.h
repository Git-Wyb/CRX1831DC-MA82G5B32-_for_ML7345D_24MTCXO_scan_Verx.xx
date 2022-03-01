#ifndef __UART_H__
#define __UART_H__

#include <Intrins.h>
#include <Absacc.h>

#include <Stdio.h>  // for printf

#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include "sys.h"
#include "ram.h"
#include "IAP_flash.h"

#define UART0_TX_BUFF_SIZE 8
#define UART0_RX_BUFF_SIZE 8

#define FrameHeadSataus 0x00 //帧头
#define DataStatus 0x01      //数据位置
#define FrameEndStatus 0x02  //桢结板
#define FrameHead 0x02       //数据弿姿
#define FrameSingnalID 0x11  //信号ID
#define UartBuff_MaxLength  41

#define U1AckDelayTime 2

extern xdata u8 U1AckTimer;
extern xdata u8 UartStatus;
extern xdata u8 UartLen;
extern xdata u8 UartCount;
extern xdata u8 UART_DATA_buffer[UartBuff_MaxLength];
extern xdata u8 UART_DATA_ID98[41];

typedef union {
    unsigned char Data[4];
    struct
    {
        unsigned char ID_No : 8;
        unsigned char Statues : 4;
        unsigned char Mode : 4;
        unsigned char Abnormal : 8;
        unsigned char Standby : 8;
    }No;
    struct
    {
        unsigned char ID_No98: 8;
        unsigned char SW_Info : 8;
        unsigned char AbnormalOut1 : 8;
        unsigned char AbnormalOut2 : 8;
    }No98;
    struct
    {
        unsigned char ID_test_No91or93: 8;
        unsigned char SWorOUT : 8;
        unsigned char prep1 : 8;
        unsigned char prep2 : 8;
    }No91;

} __Databits_t;

typedef enum {
    IdelStatues = 0,
    ReceivingStatues,
    ReceiveDoneStatues,
    ACKingStatues,
    ACKDoneStatues,
} __U1Statues;
extern xdata __U1Statues U1Statues;

extern bit rx_done;
extern xdata u8 uart0_rx_len;
extern idata u8 ACKBack[3];
extern xdata u8 FLAG_testNo91;
extern xdata u8 FLAG_testBEEP;
extern xdata u8 FLAG_testNo91_step;
extern xdata u8 FLAG_testNo91SendUart;

void Init_Uart0_S1BRG(void);
void Uart0_Send_Data(u8 *buff,u8 len); 
//void Init_Uart0_T1(void);
void Init_Uart0_T1_ODD(void);
void Send_Data(u8 *buff,u8 len);
void TranmissionACK(void);
void ReceiveFrame(u8 Cache);
void OprationFrame(void);
void PC_PRG(void);

#endif
