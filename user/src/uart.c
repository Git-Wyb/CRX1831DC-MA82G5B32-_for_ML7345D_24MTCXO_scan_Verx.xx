#include "uart.h"

#define T1_BRGRL_9600_2X_16000000_1T 0x98

xdata u8 uart0_rx_len = 0;
xdata u8 uart0_tx_len = 0;
bit rx_done = 0;

xdata u8 UartStatus = FrameHeadSataus;
xdata u8 UartLen = 0;
xdata u8 UartCount = 0;
xdata u8 UART_DATA_buffer[UartBuff_MaxLength] = {0};
xdata u8 UART_DATA_ID98[41] = {0};

xdata __Databits_t Databits_t = {0};
xdata __U1Statues U1Statues = {0};
idata u8 ACKBack[3] = {0x02, 0x03, 0x00};
xdata u8 U1AckTimer = 0;

xdata u8 FLAG_testNo91=0;
xdata u8 FLAG_testBEEP=0;
xdata u8 FLAG_testNo91_step=0;
xdata u8 FLAG_testNo91SendUart=0;


/***********************************************************************************
函数名称:   void InitUart0_S1BRG(void)
功能描述:   Uart0初始化
		 使用S1BRG作为波特率来源
输入参数:   
返回参数:     
*************************************************************************************/
/*
void Init_Uart0_S1BRG(void)
{
	//PORT_SetP3QuasiBi(BIT0|BIT1|BIT3|BIT4|BIT5);		// 设置 P30,P31作为准双向口
    
	UART0_SetMode8bitUARTVar();			// 8位 可变波特率
	UART0_EnReception();				// 使能UART1接收数据
	
	UART0_SetBRGFromS1BRG();			// 设置波特率来源为 S1BRG
	UART0_SetS1BRGBaudRateX2();			// 设置2x波特率
	UART1_SetS1BRGSelSYSCLK();			// 设置S1BRG时钟输入为Sysclk

    // 设置波特率
	UART1_SetS1BRGValue(S1BRG_BRGRL_9600_2X_24000000_1T); 
	
	UART1_EnS1BRG();					// 开启S1BRG时钟
}
*/
/*
void Init_Uart0_T1(void)
{
    UART0_SetMode8bitUARTVar();			// 8位 可变波特率
	UART0_EnReception();				// 使能UART0接收数据
	
	UART0_SetBRGFromT1();				// 设置波特率来源为 T1
	UART0_SetT1BaudRateX2();			// 设置2x波特率

	TM_SetT1Mode_2_8BIT_AUTORELOAD();
	TM_SetT1Clock_SYSCLK();
	TM_SetT1Gate_Disable(); 

    // 设置波特率
	TM_SetT1HighByte(T1_BRGRL_9600_2X_24000000_1T);
	TM_SetT1LowByte(T1_BRGRL_9600_2X_24000000_1T);

	TM_EnableT1();
}*/


//P119; 波特率baud: TH1 = 256 - (SYSCLK / (baud / ((2^SMOD1 * 2^(SMOD2*2))/32)))
void Init_Uart0_T1_ODD(void)
{
    UART0_SetMode9bitUARTVar();			// 9位 可变波特率
	UART0_EnReception();				// 使能UART0接收数据
	 
	UART0_SetBRGFromT1();				// 设置波特率来源为 T1
	UART0_SetT1BaudRateX2();			// 设置2x波特率,SMOD1=1,SMOD2=0

	TM_SetT1Mode_2_8BIT_AUTORELOAD();   // 定时器1工作在8位自动重载定时器/计数模式
	TM_SetT1Clock_SYSCLK();             // T1X12=1,
	TM_SetT1Gate_Disable(); 

    // 设置波特率
#if (MCU_SYSCLK == 16000000)
    TM_SetT1HighByte(T1_BRGRL_9600_2X_16000000_1T);
	TM_SetT1LowByte(T1_BRGRL_9600_2X_16000000_1T);
#endif
    
#if (MCU_SYSCLK == 24000000)
	TM_SetT1HighByte(T1_BRGRL_9600_2X_24000000_1T);
	TM_SetT1LowByte(T1_BRGRL_9600_2X_24000000_1T);
#endif

	TM_EnableT1();
}



/***********************************************************************************
函数名称:   void INT_UART0(void)
功能描述:UART0 中断服务程序
		 
输入参数:   
返回参数:     
*************************************************************************************/
void INT_UART0(void) interrupt INT_VECTOR_UART0
{
    idata u8 dat = 0;
	_push_(SFRPI);		   //保护SFRPI寄存器值

	SFR_SetPage(0);		   /*设置0页寄存器*/  //S0CON仅0页操作
	if(TI0)					//发送中断内容
	{ 
	   TI0 = 0;	   
	}
	if(RI0)					//接收中断内容
	{
		RI0 = 0;				//清除中断标志
        dat = S0BUF;
        if(Flag_test_mode == 0) ReceiveFrame(dat);
        else
        {
            if(dat == '(') SIO_cnt = 0;
            SIO_buff[SIO_cnt] = dat;
            SIO_cnt = (SIO_cnt + 1) & 0x1F;
            if (dat == ')')
            {
                for (dat = 0; dat < SIO_cnt; dat++)
                {
                    SIO_DATA[dat] = SIO_buff[dat];
                }
                BIT_SIO = 1; // 标志
                //SIO_TOT = 20;
            }
        }
	}
	_pop_(SFRPI);		   //恢复SFRPI寄存器值
}

/***********************************************************************************
函数名称:void Uart0SendByte(u8 tByte)
功能描述:Uart0发送数据
输入参数:u8 tByte: 待发送的数据
返回参数:     
*************************************************************************************/
void Uart0SendByte(u8 tByte)
{
	bit bES;
	bES = ES0;
	ES0 = 0;
	S0BUF = tByte;
    //TB80 = P;   //校验位
	while(TI0 == 0);
	TI0 = 0;
	ES0 = bES;
}

/* 发送数据 */
void Send_Data(u8 *buff,u8 len)
{
    xdata u8 i = 0;
    for(i=0; i<len; i++)
    {
        Uart0SendByte(buff[i]);
    }
}

unsigned char asc_hex(unsigned char asc) // HEX
{
	xdata u8 i;
	if (asc < 0x3A)
		i = asc & 0x0F;
	else
		i = asc - 0x37;
	return i;
}

unsigned char hex_asc(unsigned char hex)
{
	xdata u8 i;
	hex = hex & 0x0F;
	if (hex < 0x0A)
		i = hex | 0x30;
	else
		i = hex + 0x37;
	return i;
}

unsigned char asc_hex_2(unsigned char asc1, unsigned char asc0)
{
	unsigned char i;
	i = (asc_hex(asc1) << 4) + (asc_hex(asc0) & 0x0F);
	return i;
}


void ReceiveFrame(u8 Cache)
{
	switch (UartStatus)
	{
	case FrameHeadSataus:
	{
		UART_DATA_buffer[0] = UART_DATA_buffer[1];
		UART_DATA_buffer[1] = UART_DATA_buffer[2];
		UART_DATA_buffer[2] = Cache;
		if ((UART_DATA_buffer[0] == FrameHead) &&
			(UART_DATA_buffer[2] == FrameSingnalID))
		{
			U1Statues = ReceivingStatues;
			UartStatus++;
			UartLen = UART_DATA_buffer[1];
            if(UartLen >= UartBuff_MaxLength)    UartStatus = FrameHeadSataus;  //overflow
		}
	}
	break;
	case DataStatus:
	{
		UART_DATA_buffer[UartCount + 3] = Cache;
		UartCount++;
		if (UartCount >= (UartLen - 3))
			UartStatus++;
	}
	break;
	default:
		UartStatus = 0;
		U1Statues = IdelStatues;
		break;
	}
	if (UartStatus == FrameEndStatus) //接收完一帧处理数捿
	{
		//add Opration function
		OprationFrame();
		UartStatus = 0;
		UartCount = 0;
		//        Receiver_LED_OUT_INV = !Receiver_LED_OUT_INV;
		if((Databits_t.No.ID_No == 147)||(Databits_t.No.ID_No == 152)) U1Statues = IdelStatues;
		else
		{ 
			U1Statues = ReceiveDoneStatues;
		    U1AckTimer = U1AckDelayTime;
		}
	}
}

void OprationFrame(void)
{
	idata u8 i = 0;;
	for (i = 0; i < 4; i++)
		Databits_t.Data[i] = UART_DATA_buffer[3 + i];
	if (Databits_t.No.ID_No == 146)  //0x92
	{
	    FLAG_APP_TX_fromUART=1;
		if(TIMER1s);
		else Uart_Struct_DATA_Packet_Contro.Fno_Type.UN.fno=0;
		//for(i=0;i<3;i++)Uart_Struct_DATA_Packet_Contro.data[i/2].uc[i%2]=Databits_t.Data[i+1];
		//for(i=3;i<8;i++)Uart_Struct_DATA_Packet_Contro.data[i/2].uc[i%2]=0x00;

		for(i=0;i<2;i++)Uart_Struct_DATA_Packet_Contro.Data[i/2].uc[i%2] = Databits_t.Data[i+1];
		if((Databits_t.No.Statues==3)||(Databits_t.No.Statues==4))  Flag_shutter_stopping=1;
		else Flag_shutter_stopping=0;
		ACKBack[2] = 0;
		switch (Databits_t.No.Mode)
		{
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			break;
		default:
			ACKBack[2] = 1;
			return;
			break;
		}
		switch (Databits_t.No.Statues)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			break;
		default:
			ACKBack[2] = 1;
			return;
			break;
		}
		switch (Databits_t.No.Abnormal)
		{
		case 0x00:
		case 0x04:
		case 0x06:
		case 0x45:
		case 0x46:
		case 0x47:
		case 0x48:
		case 0x49:
		case 0x4A:
		case 0x4B:
		case 0x4C:
		case 0x4D:
			break;
		default:
			ACKBack[2] = 1;
			return;
			break;
		}
	}
	else if (Databits_t.No.ID_No == 152)  //0x98
	{
	   	Flag_ERROR_Read_once_again=0;
		TIME_ERROR_Read_once_again=0;
		for (i = 0; i < 41; i++)UART_DATA_ID98[i]=UART_DATA_buffer[i];
		FLAG_APP_TX_fromUART_err_read=1;
		Time_error_read_timeout=(UART_DATA_ID98[1]+1)*7;
		ERROR_Read_sendTX_count=0;
		ERROR_Read_sendTX_packet=0;
		Time_error_read_gap=38;
	}
	else if (Databits_t.No91.ID_test_No91or93 == 145)  //0x91
	{
	    if((ID_DATA_PCS==0)&&(ID_SCX1801_DATA==0))
	    	{
			ACKBack[2] = 0;
			FLAG_testNo91=1;
				if(FLAG_testNo91_step<3)
			       FLAG_testNo91_step++;
			FLAG_testNo91SendUart=0;
			TIME_TestNo91=1000;
	    	}
		else
			{
			ACKBack[2] = 1;
			FLAG_testNo91=2;
			TIME_TestNo91=1000;
			FLAG_testBEEP=1;
			}
	}
	else if (Databits_t.No91.ID_test_No91or93 == 147)  //0x93
	{
		switch (Databits_t.No91.SWorOUT)
		{
		case 0x01:
			DATA_Packet_Control=0x08;
			TIMER1s = 1000;
			break;
		case 0x02:
			DATA_Packet_Control=0x04;
			TIMER1s = 1000;
			break;
		case 0x04:
			DATA_Packet_Control=0x02;
			TIMER1s = 1000;
			break;
		case 0xFA:
			FLAG_testBEEP=1;
			break;
		case 0xFB:
			FLAG_testBEEP=2;
			break;
		case 0xFC:
			FLAG_testBEEP=3;
			break;
		default:
			break;
		}

	}
	else
	{
		ACKBack[2] = 1;
		return;
	}
}


void TranmissionACK(void)
{
    if ((U1Statues == ReceiveDoneStatues) && (U1AckTimer == 0))
    {
        U1Statues = ACKingStatues;
        Send_Data(ACKBack, 3);
        U1Statues = IdelStatues;
    }

	if((Flag_ERROR_Read_once_again==1)&&(TIME_ERROR_Read_once_again==0))
	{
		Send_Data(Send_err_com, 7);
		Flag_ERROR_Read_once_again=0;
		TIME_ERROR_Read_once_again=0;
	}
}

xdata u32 PROFILE_CH_FREQ_32bit_200002EC_uart = 0;
void PC_PRG(void) // 串口命令
{
	xdata u8 send_dat[10] = {0};
    xdata u8 send_ok[4] = {'(','O','K',')'};
    xdata uni_rom_id UART_ID_data;
    xdata u8 re_byte = 0;

    if (BIT_SIO)
	{
		BIT_SIO = 0;
		//SIO_TOT = 20;
        if(SIO_DATA[1] == 'T' && SIO_DATA[2] == 'E' && SIO_DATA[3] == 'S' && SIO_DATA[4] == 'T' && SIO_DATA[5]==')')
        {
            Flag_test_pc = 1;
            Flag_test_rssi = 0;
            Flag_test_fm = 0;
            Receiver_LED_OUT = 0;
            Receiver_LED_TX = 0;
            Receiver_LED_RX = 0;
            Receiver_OUT_STOP = 0;
            Receiver_OUT_CLOSE = 0;
            Receiver_OUT_OPEN = 0;
            X_COUNT = 0;
            X_ERR = 0;
            X_ERR_CNT = 0;
            ML7345_SetAndGet_State(Force_TRX_OFF);
            Send_Data(send_ok,4);
        }
        if(Flag_test_pc == 1)
        {
            switch(SIO_DATA[1])
            {
                case 'S':
                    if(SIO_DATA[2] == ')')
                    {
                        if(Flag_test_rssi == 1) Receiver_LED_RX = 0;
                        Flag_test_rssi = 0;
                        Flag_test_fm = 0;
                        CG2214M6_USE_T;
                        ML7345_SetAndGet_State(Force_TRX_OFF);
                        ML7345_Frequency_Set(Fre_429_175,1);
                        Tx_Data_Test(0);    //发载波
                        Send_Data(send_ok,4);
                    }
                    break;
                case 'E':
                    if(SIO_DATA[2]=='N' && SIO_DATA[3]=='D' && SIO_DATA[4]==')')
                    {
                        Flag_test_pc = 0;
                        Flag_test_rssi = 0;
                        Flag_test_fm = 0;
                        Receiver_LED_OUT = 0;
                        Receiver_LED_TX = 0;
                        Receiver_LED_RX = 0;
                        Receiver_OUT_STOP = 0;
                        Receiver_OUT_CLOSE = 0;
                        Receiver_OUT_OPEN = 0;
                        X_COUNT = 0;
                        X_ERR = 0;
                        X_ERR_CNT = 0;
                        ML7345_SetAndGet_State(Force_TRX_OFF);
                        Send_Data(send_ok,4);
                    }
                    else if(SIO_DATA[2]=='H' && SIO_DATA[3]==')')
                    {
                        ID_DATA_PCS = 0;
                        ALL_ID_EEPROM_Erase();
                        ID_SCX1801_DATA = 0;
                        ID_SCX1801_EEPROM_write(0x00);
                        Send_Data(send_ok,4);
                    }
                    break;
                case 'F':
                    if(SIO_DATA[2]=='M' && SIO_DATA[3]==')')  //载波+调制
                    {
                        if(Flag_test_rssi == 1) Receiver_LED_RX = 0;
                        Flag_test_rssi = 0;
                        Flag_test_fm = 1;
                        CG2214M6_USE_T;
                        ML7345_SetAndGet_State(Force_TRX_OFF);
                        ML7345_Frequency_Set(Fre_429_175,1);
                        Tx_Data_Test(1);
                        Send_Data(send_ok,4);
                    }
                    else if(SIO_DATA[2]=='C' && SIO_DATA[3]=='?' && SIO_DATA[4]==')')
                    {
                        send_dat[0] = '(';
                        send_dat[1] = 'F';
                        send_dat[2] = 'C';
                        send_dat[3] = hex_asc(rf_offset / 16);
                        send_dat[4] = hex_asc(rf_offset % 16);
                        send_dat[5] = ')';
                        Send_Data(send_dat,6);
                    }
                    else if (SIO_DATA[2]=='C' && SIO_DATA[5]==')' && Flag_test_fm == 1)
                    {
                        Flag_test_rssi = 0;
                        re_byte = asc_hex_2(SIO_buff[3],SIO_buff[4]);
                        ML7345_SetAndGet_State(Force_TRX_OFF);
                        CG2214M6_USE_T;
                        if(re_byte <= 10) //frequency +
                        {
                            rf_offset = re_byte;
                            IAP_WriteBuf_With_Protect_Verify(addr_eeprom_sys+Addr_rf_offset,&rf_offset,1);
                            PROFILE_CH_FREQ_32bit_200002EC_uart = 429175000 + 150 * re_byte;
                            ML7345_Frequency_Calcul(PROFILE_CH_FREQ_32bit_200002EC_uart,Fre_429_175);
                            ML7345_Frequency_Set(Fre_429_175,1);
                            PROFILE_CH_FREQ_32bit_200002EC_uart = 426750000 + 150 * re_byte;
                            ML7345_Frequency_Calcul(PROFILE_CH_FREQ_32bit_200002EC_uart,Fre_426_750);
                            Send_Data(send_ok,4);
                        }
                        else if(10 < re_byte && re_byte <= 20) //frequency -
                        {
                            rf_offset = re_byte;
                            IAP_WriteBuf_With_Protect_Verify(addr_eeprom_sys+Addr_rf_offset,&rf_offset,1);
                            re_byte = re_byte - 10;
                            PROFILE_CH_FREQ_32bit_200002EC_uart = 429175000 - 150 * re_byte;
                            ML7345_Frequency_Calcul(PROFILE_CH_FREQ_32bit_200002EC_uart,Fre_429_175);
                            ML7345_Frequency_Set(Fre_429_175,1);
                            PROFILE_CH_FREQ_32bit_200002EC_uart = 426750000 - 150 * re_byte;
                            ML7345_Frequency_Calcul(PROFILE_CH_FREQ_32bit_200002EC_uart,Fre_426_750);
                            Send_Data(send_ok,4);
                        }
                        Tx_Data_Test(1);
                    }
                    break;

                case 'R':
                    if(SIO_DATA[2]=='S' && SIO_DATA[3]=='S' && SIO_DATA[4]=='I' && SIO_DATA[5]==')' && Flag_test_rssi==1)
                    {
                        send_dat[0] = '(';
                        send_dat[1] = 'R';
                        send_dat[2] = 'S';
                        send_dat[3] = 'S';
                        send_dat[4] = 'I';
                        send_dat[5] = hex_asc((X_ERR_CNT & 0xff) / 16);
                        send_dat[6] = hex_asc((X_ERR_CNT & 0xff)% 16);
                        send_dat[7] = ')';
                        Send_Data(send_dat,8);
                    }
                    else if(SIO_DATA[2]=='S' && SIO_DATA[3]==')')
                    {
                        Receiver_LED_RX = 0;
                        Flag_test_fm = 0;
                        X_COUNT = 0;
                        X_ERR = 0;
                        X_ERR_CNT = 0;
                        CG2214M6_USE_R;
                        ML7345_SetAndGet_State(Force_TRX_OFF);
                        PROFILE_CH_FREQ_32bit_200002EC = 426750000;
                        ML7345_Frequency_Set(Fre_426_750,1);
                        ML7345_MeasurBER_Init();
                        ML7345_SetAndGet_State(RX_ON);
                        Flag_test_rssi = 1;
                        Send_Data(send_ok,4);
                    }
                    else if(SIO_DATA[2]=='N' && SIO_DATA[3]==')')
                    {
                        if(ID_SCX1801_DATA != 0) re_byte = ID_DATA_PCS + 1;
                        else re_byte = ID_DATA_PCS;
                        send_dat[0] = '(';
                        send_dat[1] = 'R';
                        send_dat[2] = 'N';
                        send_dat[3] = hex_asc((re_byte & 0xff) / 16);
                        send_dat[4] = hex_asc((re_byte & 0xff) % 16);
                        send_dat[5] = ')';
                        re_byte = 0;
                        Send_Data(send_dat,6);
                    }
                    else if(SIO_DATA[2]=='G' && SIO_DATA[5]==')')
                    {
                        if(SIO_DATA[3]=='0' && SIO_DATA[4]=='0')
                        {
                            UART_ID_data.IDB[0] = 0;
                            UART_ID_data.IDB[1] = IAP_ReadByteByMOVC(addr_eeprom_sys + 0x3FB);
                            UART_ID_data.IDB[2] = IAP_ReadByteByMOVC(addr_eeprom_sys + 0x3FC);
                            UART_ID_data.IDB[3] = IAP_ReadByteByMOVC(addr_eeprom_sys + 0x3FD);
                            if ((UART_ID_data.IDC == 0) || (UART_ID_data.IDC == 0xFFFFFF))  ID_SCX1801_DATA=0;
                            else ID_SCX1801_DATA = UART_ID_data.IDC;
                            send_dat[0] = '(';
                            send_dat[1] = 'R';
                            send_dat[2] = 'G';
                            send_dat[3] = hex_asc(UART_ID_data.IDB[1] / 16);
                            send_dat[4] = hex_asc(UART_ID_data.IDB[1] % 16);
                            send_dat[5] = hex_asc(UART_ID_data.IDB[2] / 16);
                            send_dat[6] = hex_asc(UART_ID_data.IDB[2] % 16);
                            send_dat[7] = hex_asc(UART_ID_data.IDB[3] / 16);
                            send_dat[8] = hex_asc(UART_ID_data.IDB[3] % 16);
                            send_dat[9] = ')';
                            Send_Data(send_dat,10);
                        }
                    }
                    break;
                case 'K':
                    if(SIO_DATA[2]=='Y' && SIO_DATA[3]==')')
                    {
                        send_dat[0] = '(';
                        send_dat[1] = 'K';
                        send_dat[2] = 'Y';
                        send_dat[7] = 0;
                        send_dat[7] = send_dat[7] | Receiver_Login;
                        send_dat[3] = hex_asc((send_dat[7] & 0xff) / 16);
                        send_dat[4] = hex_asc((send_dat[7] & 0xff) % 16);
                        send_dat[5] = ')';
                        Send_Data(send_dat,6);
                    }
                    break;
                case 'P':
                    if(SIO_DATA[2]=='H' && SIO_DATA[6]==')')
                    {
                        if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='1')         {Receiver_LED_OUT = 1;  Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='2')    {Receiver_LED_TX = 1;   Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='3')    {Receiver_LED_RX = 1;   Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='1')    {Receiver_OUT_STOP = 1; Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='2')    {Receiver_OUT_CLOSE = 1;Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='3')    {Receiver_OUT_OPEN = 1; Send_Data(send_ok,4);}
                    }
                    else if(SIO_DATA[2]=='L' && SIO_DATA[6]==')')
                    {
                        if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='1')         {Receiver_LED_OUT = 0;  Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='2')    {Receiver_LED_TX = 0;   Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='B' && SIO_DATA[4]=='0' && SIO_DATA[5]=='3')    {Receiver_LED_RX = 0;   Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='1')    {Receiver_OUT_STOP = 0; Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='2')    {Receiver_OUT_CLOSE = 0;Send_Data(send_ok,4);}
                        else if(SIO_DATA[3]=='D' && SIO_DATA[4]=='0' && SIO_DATA[5]=='3')    {Receiver_OUT_OPEN = 0; Send_Data(send_ok,4);}
                    }
                    break;
                case 'W':
                    if(SIO_DATA[2]=='G' && SIO_DATA[9]==')')
                    {
                        UART_ID_data.IDB[0]=0;
                        UART_ID_data.IDB[1] = asc_hex_2(SIO_buff[3],SIO_buff[4]);
                        UART_ID_data.IDB[2] = asc_hex_2(SIO_buff[5],SIO_buff[6]);
                        UART_ID_data.IDB[3] = asc_hex_2(SIO_buff[7],SIO_buff[8]);
                        IAP_WriteBuf_With_Protect_Verify(addr_eeprom_sys+0x3FB,&UART_ID_data.IDB[1],3);
                        
                        ID_SCX1801_DATA = UART_ID_data.IDC;
                        Send_Data(send_ok,4);
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if(Flag_test_rssi == 1) Uart_RF_Ber_Test();
}
