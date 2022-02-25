#include "spi.h"


void Init_Spi(void)
{
    // ʹ��SPI
    SPI_Enable();
	// ����MASTER
	SPI_SelectMASTERByMSTRbit();
	// ����SPIʱ�� SYSCLK/16
	SPI_SetClock(SPI_CLK_SYSCLK_8);
	// ����SPICLK��ʼ��ƽ CPOL=0 �͵�ƽ
	SPI_SetCPOL_0();	
	// �������ݴ���λ�� MSB ��λ��ǰ
	SPI_SetDataMSB();
	// ���ò����͸ı�����ģʽ CPHA=0 ǰ�ز���,���ظı�����
	SPI_SetCPHA_0();
	// ����IO nSS/P14,MOSI/P15,MISO/P16,SPICLK/P17
	SPI_SetUseP14P15P16P17();
    
    SPI1_CS_H;
}


/***********************************************************************************
��������:   u8 SPI1_SendRecv_Data(u8 ToSend)
��������:   SPI����ģʽ�շ�����
�������:   u8 SPI_DATA: �����͵�����
���ز���:   u8 :�յ�������  
*************************************************************************************/
u8 SPI1_SendRecv_Data(u8 SPI_DATA)
{
    while(SPSTAT & THRF);
	SPI_SendData(SPI_DATA);							// SPI ��������
	while(SPI_ChkCompleteFlag()==0);				// �ȴ�SPI�������
	SPI_ClearCompleteFlag();						// SPI ����ɱ�־
    while(SPSTAT & SPIBSY);
	return SPI_GetData();							// ���ؽ��յ�������
}


void ML7345_Write_Reg(u8 addr,u8 dat)
{
    DelayXus(1);
    SPI1_CS_L;
    DelayXus(1);

    addr = (addr << 1) | 0x01;
    SPI1_SendRecv_Data(addr);
    SPI1_SendRecv_Data(dat);

    DelayXus(1);
    SPI1_CS_H;
    DelayXus(1);
}

u8 ML7345_Read_Reg(u8 addr)
{
    xdata u8 read = 0;
    DelayXus(1);
    SPI1_CS_L;
    DelayXus(1);

    addr = addr << 1;
    SPI1_SendRecv_Data(addr);       /* д��ַ */
    read = SPI1_SendRecv_Data(0xFF);/* ������ */

    DelayXus(1);
    SPI1_CS_H;
    DelayXus(1);

    return read;
}

void ML7345_Write_Fifo(u8 addr,u8 *pbuf,u8 len)
{
    xdata u8 i = 0;
    DelayXus(1);
    SPI1_CS_L;
    DelayXus(1);

    addr = (addr << 1) | 0x01;
    SPI1_SendRecv_Data(addr);
    SPI1_SendRecv_Data(pbuf[0]);
    for(i=1; i<len; i++)
    {
        DelayXus(2);
        SPI1_SendRecv_Data(pbuf[i]);
    }

    DelayXus(1);
    SPI1_CS_H;
    DelayXus(1);
}

void ML7345_Read_Fifo(u8 addr,u8 *pbuf,u8 len)
{
    xdata u8 i = 0;
    DelayXus(1);
    SPI1_CS_L;
    DelayXus(1);

    addr = addr << 1;
    SPI1_SendRecv_Data(addr);

    for(i=0; i<len; i++)
    {
        pbuf[i] = SPI1_SendRecv_Data(0xFF);
    }

    DelayXus(1);
    SPI1_CS_H;
    DelayXus(1);
}
//////////////////////////////////////////////////////////////////////////////////////////////

