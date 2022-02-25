#ifndef __SPI_H__
#define __SPI_H__

#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include <Intrins.h> 
#include <Absacc.h>
#include "timer.h"


#define SPI_CS    P14
#define SPI1_CS_L (SPI_CS = 0)
#define SPI1_CS_H (SPI_CS = 1)





void Init_Spi(void);
void RF_ML7345_Init(u8* freq,u8 sync,u8 rx_len);
void ML7345_Write_Reg(u8 addr,u8 dat);
u8 ML7345_Read_Reg(u8 addr);
void ML7345_Write_Fifo(u8 addr,u8 *pbuf,u8 len);
void ML7345_Read_Fifo(u8 addr,u8 *pbuf,u8 len);

#endif
