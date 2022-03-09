#include "spi.h"

void spi_delay(u16 n) //1: 1.69us; 2: 2.24us; 4: 3.19us; 10: 6.2us
{
     while(n--);
}

void Init_Spi(void)
{
    // 使能SPI
    SPI_Enable();
	// 设置MASTER
	SPI_SelectMASTERByMSTRbit();
	// 设置SPI时钟 SYSCLK/8
	SPI_SetClock(SPI_CLK_SYSCLK_8);
	// 设置SPICLK初始电平 CPOL=0 低电平
	SPI_SetCPOL_0();	
	// 设置数据传送位序 MSB 高位在前
	SPI_SetDataMSB();
	// 设置采样和改变数据模式 CPHA=0 前沿采样,后沿改变数据
	SPI_SetCPHA_0();
	// 设置IO nSS/P14,MOSI/P15,MISO/P16,SPICLK/P17
	SPI_SetUseP14P15P16P17();
    
    SPI1_CS_H;
}


/***********************************************************************************
函数名称:   u8 SPI1_SendRecv_Data(u8 ToSend)
功能描述:   SPI主机模式收发数据
输入参数:   u8 SPI_DATA: 待发送的数据
返回参数:   u8 :收到的数据  
*************************************************************************************/
u8 SPI1_SendRecv_Data(u8 SPI_DATA)
{
    while(SPSTAT & THRF);
	SPI_SendData(SPI_DATA);							// SPI 发送数据
	while(SPI_ChkCompleteFlag() == 0);				// 等待SPI传送完成
	SPI_ClearCompleteFlag();						// SPI 清完成标志
	return SPI_GetData();							// 返回接收到的数据
}


void ML7345_Write_Reg(u8 addr,u8 dat)
{
    spi_delay(1);
    SPI1_CS_L;
    spi_delay(1);

    addr = (addr << 1) | 0x01;
    SPI1_SendRecv_Data(addr);
    SPI1_SendRecv_Data(dat);

    spi_delay(1);
    SPI1_CS_H;
    spi_delay(1);
}

u8 ML7345_Read_Reg(u8 addr)
{
    xdata u8 read = 0;
    spi_delay(1);
    SPI1_CS_L;
    spi_delay(1);

    addr = addr << 1;
    SPI1_SendRecv_Data(addr);       /* 写地址 */
    read = SPI1_SendRecv_Data(0xFF);/* 读数据 */

    spi_delay(1);
    SPI1_CS_H;
    spi_delay(1);

    return read;
}

void ML7345_Write_Fifo(u8 addr,u8 *pbuf,u8 len)
{
    xdata u8 i = 0;
    spi_delay(1);
    SPI1_CS_L;
    spi_delay(1);

    addr = (addr << 1) | 0x01;
    SPI1_SendRecv_Data(addr);
    SPI1_SendRecv_Data(pbuf[0]);
    for(i=1; i<len; i++)
    {
        spi_delay(2);
        SPI1_SendRecv_Data(pbuf[i]);
    }

    spi_delay(1);
    SPI1_CS_H;
    spi_delay(1);
}

void ML7345_Read_Fifo(u8 addr,u8 *pbuf,u8 len)
{
    xdata u8 i = 0;
    spi_delay(1);
    SPI1_CS_L;
    spi_delay(1);

    addr = addr << 1;
    SPI1_SendRecv_Data(addr);

    for(i=0; i<len; i++)
    {
        pbuf[i] = SPI1_SendRecv_Data(0xFF);
    }

    spi_delay(1);
    SPI1_CS_H;
    spi_delay(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////

