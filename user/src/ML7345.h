#ifndef __ML7345_H__
#define __ML7345_H__

#include "spi.h"
#include "ML7345_defs.h"
#include "ML7345_HAL.h"
#include "uart.h"

#define RF_RX_DONE() (ML7345_Read_Reg(ADDR_INT_SOURCE_GRP2) & 0x01)
#define RF_TX_DONE() (ML7345_Read_Reg(ADDR_INT_SOURCE_GRP3) & 0x01)

#define TX_PACKET_COUNT 3

#define FREQ_PLL     12000000 //Extern TCXO / 2 = 24MHz / 2
#define CONST_COEFF  1048576  //常数2^20
#define VCO_LowerLimit_FREQ 400000  //400kHz

void RF_ML7345_Init(u8* freq,u8 sync,u8 rx_len);
void Tx_Data_Test(u8 mode);
void ML7345_MeasurBER_Init(void);
void RF_ML7345_TEST(void);
void DataReceive(void);
void RF_Ber_Test(void);
void ML7345_TRX_Del(void);
void APP_TX_PACKET(void);
void Uart_RF_Ber_Test(void);

void ML7345d_Change_Channel(void);
void ML7345D_Freq_Scanning(void);
void ML7345D_RF_test_mode(void);
void TX_DataLoad_HighSpeed(u32 IDCache, Wireless_Body CtrCmd, u8 *Packet);
void ML7345D_Error_Detect(void);
void Ber_PinExit_Init(void);

extern xdata u8 Fre_426_075[8];
extern xdata u8 Fre_426_750[8];
extern xdata u8 Fre_429_550[8];
extern xdata u8 Fre_429_350[8];
extern xdata u8 Fre_429_175[8];
extern xdata u8 Freq_SetBuff[8];
extern xdata u8 rf_offset;
extern xdata u8 SPI_RECEIVE_BUFF[40];

extern xdata u8 tx_pack_cnt;

extern xdata u8 ADF7030_REST_Cache;
extern xdata u8 Receiver_vent_Cache;
extern xdata u32 SPI_Receive_DataForC[7];

extern xdata u8 Radio_Date_Type;
extern xdata u8 Radio_Date_Type_bak;

#endif


