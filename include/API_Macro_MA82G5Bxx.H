#ifndef _MACRO_MA82G5Bxx_H
#define _MACRO_MA82G5Bxx_H

#define SFR_SetPage(x)		SFRPI=x

/*
*************************************************************************************
*  INTERRUPT 中断 
*
*************************************************************************************
*/
//中断向量
#define INT_VECTOR_INT0		0
#define INT_VECTOR_T0		1
#define INT_VECTOR_INT1		2
#define INT_VECTOR_T1		3
#define INT_VECTOR_UART0	4
#define INT_VECTOR_T2		5
#define INT_VECTOR_INT2		6
#define INT_VECTOR_INT3		7
#define INT_VECTOR_SPI		8
#define INT_VECTOR_ADC		9
#define INT_VECTOR_PCA		10
#define INT_VECTOR_SF		11
#define INT_VECTOR_UART1	12
#define INT_VECTOR_KB		13
#define INT_VECTOR_TWI0		14
#define INT_VECTOR_TWI1		15
//中断使能/禁止
#define INT_EnAll()			EA=1		// 使能全局中断
#define INT_DisAll()		EA=0		// 禁止全局中断
#define INT_EnINT0()		EX0=1
#define INT_DisINT0()		EX0=0
#define INT_EnTIMER0()		ET0=1
#define INT_DisTIMER0()		ET0=0
#define INT_EnINT1()		EX1=1
#define INT_DisINT1()		EX1=0
#define INT_EnTIMER1()		ET1=1
#define INT_DisTIMER1()		ET1=0
#define INT_EnUART0()		ES0=1
#define INT_DisUART0()		ES0=0
#define INT_EnTIMER2()		ET2=1
#define INT_DisTIMER2()		ET2=0
#define INT_EnINT2()		EX2=1
#define INT_DisINT2()		EX2=0
#define INT_EnINT3()		EX3=1
#define INT_DisINT3()		EX3=0
#define INT_EnSPI()			EIE1=EIE1|ESPI
#define INT_DiSPI()			EIE1=EIE1&(~ESPI)
#define INT_EnADC()			EIE1=EIE1|EADC
#define INT_DisADC()		EIE1=EIE1&(~EADC)
#define INT_EnPCA()			EIE1=EIE1|EPCA
#define INT_DisPCA()		EIE1=EIE1&(~EPCA)
#define INT_EnSF()			EIE1=EIE1|ESF
#define INT_DisSF()			EIE1=EIE1&(~ESF)
#define INT_EnUART1()		EIE1=EIE1|ES1
#define INT_DisUART1()		EIE1=EIE1&(~ES1)
#define INT_EnKBI()			EIE1=EIE1|EKB
#define INT_DisKBI()		EIE1=EIE1&(~EKB)
#define INT_EnTWI0()		EIE1=EIE1|ETWSI
#define INT_DisTWI0()		EIE1=EIE1&(~ETWSI)
#define INT_EnTWI1()		EIE1=EIE1|ETWI1
#define INT_DisTWI1()		EIE1=EIE1&(~ETWI1)

#define INT_EnSF_WDT()		SFIE=SFIE|WDTFIE
#define INT_DisSF_WDT()		SFIE=SFIE&(~WDTFIE)
#define INT_EnSF_BOD0()		SFIE=SFIE|BOF0IE
#define INT_DisSF_BOD0()	SFIE=SFIE&(~BOF0IE)
#define INT_EnSF_BOD1()		SFIE=SFIE|BOF1IE
#define INT_DisSF_BOD1()	SFIE=SFIE&(~BOF1IE)
#define INT_EnSF_RTC()		SFIE=SFIE|RTCFIE
#define INT_DisSF_RTC()		SFIE=SFIE&(~RTCFIE)
#define INT_EnSF_MCD()		SFIE=SFIE|MCDFIE
#define INT_DisSF_MCD()		SFIE=SFIE&(~MCDFIE)
#define INT_EnSF_SID()		SFIE=SFIE|SIDFIE
#define INT_DisSF_SID()		SFIE=SFIE&(~SIDFIE)

// 中断优先级
#define IP_INT0		BIT0
#define IP_T0		BIT1
#define IP_INT1		BIT2
#define IP_T1		BIT3
#define IP_UART0	BIT4
#define IP_T2		BIT5
#define IP_INT2		BIT6
#define IP_INT3		BIT7
#define IPX_SPI		BIT0
#define IPX_ADC		BIT1
#define IPX_PCA		BIT2
#define IPX_SF		BIT3
#define IPX_UART1	BIT4
#define IPX_KB		BIT5
#define IPX_TWI0	BIT6
#define IPX_TWI1	BIT7

#define INT_SetIPHighest(x)			IP0H=IP0H|x;IP0L=IP0L|x
#define INT_SetIPHigh(x)			IP0H=IP0H|x;IP0L=IP0L&(~x)
#define INT_SetIPLow(x)				IP0H=IP0H&(~x);IP0L=IP0L|x
#define INT_SetIPLowest(x)			IP0H=IP0H&(~x);IP0L=IP0L&(~x)

#define INT_SetIPXHighest(x)		EIP1H=EIP1H|x;EIP1L=EIP1L|x
#define INT_SetIPXHigh(x)			EIP1H=EIP1H|x;EIP1L=EIP1L&(~x)
#define INT_SetIPXLow(x)			EIP1H=EIP1H&(~x);EIP1L=EIP1L|x
#define INT_SetIPXLowest(x)			EIP1H=EIP1H&(~x);EIP1L=EIP1L&(~x)

// 清中断标志位
#define INT_ClrINT0()		IE0=0
#define INT_ClrTIMER0()		TF0=0
#define INT_ClrINT1()		IE1=0
#define INT_ClrTIMER1()		TF1=0
#define INT_ClrUART0_Rx()	RI0=0
#define INT_ClrUART0_Tx()	TI0=0
#define INT_ClrTIMER2()		TF2=0
#define INT_ClrINT2()		IE2=0
#define INT_ClrINT3()		IE3=0
#define INT_ClrSPI()		SPSTAT=SPSTAT&(~SPIF)
#define INT_ClrADC()		ADCON0=ADCON0&(~ADCI)
#define INT_ClrPCA_CF()		CF=0
#define INT_ClrPCA_CH0()	CCF0=0
#define INT_ClrPCA_CH1()	CCF1=0
#define INT_ClrPCA_CH2()	CCF2=0
#define INT_ClrPCA_CH3()	CCF3=0
#define INT_ClrPCA_CH4()	CCF4=0
#define INT_ClrPCA_CH5()	CCF5=0
#define INT_ClrUART1_Rx()	SFRPI=1;RI1=0;SFRPI=0
#define INT_ClrUART1_Tx()	SFRPI=1;TI1=0;SFRPI=0
#define INT_ClrSF_WDT()		PCON1=WDTF
#define INT_ClrSF_BOD0()	PCON1=BOF0
#define INT_ClrSF_BOD1()	PCON1=BOF1
#define INT_ClrSF_RTC()		PCON1=RTCF
#define INT_ClrSF_MCD()		PCON1=MCDF
#define INT_ClrKBI()		KBCON=KBCON&(~KBIF)
#define INT_ClrTWI0()		SICON=SICON&(~SI)
#define INT_ClrTWI1()		SFRPI=1;SI1CON=SI1CON&(~SI1);SFRPI=0

// 外部中断 选择中断引脚
#define INT_SetINT0P32()			XICFG=XICFG&(~(INT0IS0|INT0IS1))
#define INT_SetINT0P30()			XICFG=(XICFG&(~INT0IS1))|INT0IS0
#define INT_SetINT0P16()			XICFG=(XICFG&(~INT0IS0))|INT0IS1
#define INT_SetINT0P40()			XICFG=XICFG|(INT0IS0|INT0IS1)

#define INT_SetINT1P33()			XICFG=XICFG&(~(INT1IS0|INT1IS1))
#define INT_SetINT1P31()			XICFG=(XICFG&(~INT1IS1))|INT1IS0
#define INT_SetINT1P17()			XICFG=(XICFG&(~INT1IS0))|INT1IS1
#define INT_SetINT1P41()			XICFG=XICFG|(INT1IS0|INT1IS1)

#define INT_SetINT2P44()			AUXR2=AUXR2&(~(INT2IS0|INT2IS1))
#define INT_SetINT2P20()			AUXR2=(AUXR2&(~INT2IS1))|INT2IS0
#define INT_SetINT2P14()			AUXR2=(AUXR2&(~INT2IS0))|INT2IS1
#define INT_SetINT2P61()			AUXR2=AUXR2|(INT2IS0|INT2IS1)

#define INT_SetINT3P45()			AUXR2=AUXR2&(~(INT3IS0|INT3IS1))
#define INT_SetINT3P21()			AUXR2=(AUXR2&(~INT3IS1))|INT3IS0
#define INT_SetINT3P15()			AUXR2=(AUXR2&(~INT3IS0))|INT3IS1
#define INT_SetINT3P60()			AUXR2=AUXR2|(INT3IS0|INT3IS1)

// 外部中断 设置检测电平/边沿
#define INT_SetINT0_DetectHighLevel()		IT0=0;AUXR0=AUXR0|INT0H
#define INT_SetINT0_DetectLowLevel()		IT0=0;AUXR0=AUXR0&(~INT0H)
#define	INT_SetINT0_DetectFallingEdge()		IT0=1;AUXR0=AUXR0&(~INT0H)
#define	INT_SetINT0_DetectRisingEdge()		IT0=1;AUXR0=AUXR0|INT0H

#define INT_SetINT1_DetectHighLevel()		IT1=0;AUXR0=AUXR0|INT1H
#define INT_SetINT1_DetectLowLevel()		IT1=0;AUXR0=AUXR0&(~INT1H)
#define	INT_SetINT1_DetectFallingEdge()		IT1=1;AUXR0=AUXR0&(~INT1H)
#define	INT_SetINT1_DetectRisingEdge()		IT1=1;AUXR0=AUXR0|INT1H

#define INT_SetINT2_DetectHighLevel()		IT2=0;INT2H=1
#define INT_SetINT2_DetectLowLevel()		IT2=0;INT2H=0
#define	INT_SetINT2_DetectFallingEdge()		IT2=1;INT2H=0
#define	INT_SetINT2_DetectRisingEdge()		IT2=1;INT2H=1

#define INT_SetINT3_DetectHighLevel()		IT3=0;INT3H=1
#define INT_SetINT3_DetectLowLevel()		IT3=0;INT3H=0
#define	INT_SetINT3_DetectFallingEdge()		IT3=1;INT3H=0
#define	INT_SetINT3_DetectRisingEdge()		IT3=1;INT3H=1

// 外部中断 设置滤波
#define INT_SetINT0Filter_Disable()				XICFG=XICFG&(~X0FLT)
#define INT_SetINT0Filter_Sysclk_x3()			XICFG=XICFG|X0FLT

#define INT_SetINT1Filter_Disable()				XICFG=XICFG&(~X1FLT)
#define INT_SetINT1Filter_Sysclk_x3()			XICFG=XICFG|X1FLT

#define INT_SetINT2Filter_Disable()				XICFG=XICFG&(~X2FLT)
#define INT_SetINT2Filter_Sysclk_x3()			XICFG=XICFG|X2FLT

#define INT_SetINT3Filter_Disable()				XICFG=XICFG&(~X3FLT)
#define INT_SetINT3Filter_Sysclk_x3()			XICFG=XICFG|X3FLT

/*
*************************************************************************************
*/ 



/*
*************************************************************************************
*  IAP 
*
*************************************************************************************
*/
//IAP 命令
#define ISP_STANBY		0
#define ISP_READ		1 	  //读
#define ISP_WRITE 	    2 	  //写
#define ISP_ERASE 	    3 	  //擦除
#define ISP_WRITE_P     4     //写P页寄存器
#define ISP_READ_P     	5     //读P页寄存器


/*
*************************************************************************************
*/


/*
*************************************************************************************
*  CLOCK 
*
*************************************************************************************
*/
// CLOCK IHRCO 是12MHz/11.0592MHz
#define IHRCO_12MHz					0
#define IHRCO_110592MHz				0x80
#define CLK_SelIHRCO12MHz()					CKCON0=CKCON0&(~AFS)				
#define CLK_SelIHRCO110592MHz()				CKCON0=CKCON0|(AFS)	

// CLOCK 设置CPUCLK 
#define CPUCLK_SYSCLK_DIV_1			0
#define CPUCLK_SYSCLK_DIV_2			0x08
#define CLK_SetCpuclkUseSysclk()			CKCON0=CKCON0&(~CCKS)				
#define CLK_SetCpuclkUseSysclkDiv2()		CKCON0=CKCON0|(CCKS)	

// CLOCK 设置SYSCLK
#define SYSCLK_MCKDO_DIV_1			0
#define SYSCLK_MCKDO_DIV_2			1
#define SYSCLK_MCKDO_DIV_4			2
#define SYSCLK_MCKDO_DIV_8			3
#define SYSCLK_MCKDO_DIV_16			4
#define SYSCLK_MCKDO_DIV_32			5
#define SYSCLK_MCKDO_DIV_64			6
#define SYSCLK_MCKDO_DIV_128		7
#define CLK_SetSysclk(x)					CKCON0=(CKCON0&(~0x07))|x

// CLOCK 开启/关闭CKM
#define DISABLE_CKM					0
#define ENABLE_CKM					0x40
#define CLK_DisCKM()						CKCON0=CKCON0&(~ENCKM)
#define CLK_EnCKM()							CKCON0=CKCON0|(ENCKM)

// CLOCK 选择CKM输入源
#define CKM_OSCIN_DIV_1				0x00	// OSCin=5~7MHz
#define CKM_OSCIN_DIV_2				0x10	// OSCin=10~14MHz	
#define CKM_OSCIN_DIV_4				0x20	// OSCin=20~28MHz
#define CKM_OSCIN_DIV_6				0x30	// OSCin=30~42MHz
#define CLK_SetCKMOSCin(x)					CKCON0=(CKCON0&(~0x30))|x

// CLOCK 设置CKCON0
#define CLK_SetCKCON0(x)					CKCON0=x

// CLOCK 设置CKCON2
#define GAIN_FOR_32K				0x00
#define GAIN_FOR_2M_25M				0x40

#define DISABLE_XTAL				0x00
#define ENABLE_XTAL					0x20

#define DISABLE_IHRCO				0x00
#define ENABLE_IHRCO				0x10

#define MCK_OSCin					0x00
#define MCK_CKMI_X4					0x04
#define MCK_CKMI_X533				0x08
#define MCK_CKMI_X8					0x0C

#define OSCIn_IHRCO					0x00
#define OSCIn_XTAL					0x01
#define OSCIn_ILRCO					0x02
#define OSCIn_ECKI_P60				0x03

#define CLK_SetCKCON2(x)			ISPCR=0x80;IFADRH=0x0;IFADRL=CKCON2_P;IFMT=ISP_WRITE_P;IFD=x;SCMD=0x46;SCMD=0xB9;_nop_();IFMT=0;ISPCR=0x0
#define CLK_SetCKCON3(x)			ISPCR=0x80;IFADRH=0x0;IFADRL=CKCON3_P;IFMT=ISP_WRITE_P;IFD=x;SCMD=0x46;SCMD=0xB9;_nop_();IFMT=0;ISPCR=0x0

// CLOCK 设置IAP时基 
#define CLK_SetIAPTimeBase(x)		CKCON1=x-1

// CLOCK 设置P60输出CLK
#define CLK_P60OC_P60()			AUXR0=AUXR0&(~(P60OC0|P60OC1))
#define CLK_P60OC_MCK()			AUXR0=(AUXR0&(~(P60OC0|P60OC1)))|(P60OC0)
#define CLK_P60OC_MCKDiv2()		AUXR0=(AUXR0&(~(P60OC0|P60OC1)))|(P60OC1)
#define CLK_P60OC_MCKDiv4()		AUXR0=AUXR0|((P60OC0|P60OC1))

// CLOCK 外部时钟丢失复位
#define CLK_EnMCD_RST()			SFIE=SFIE|(MCDFIE|MCDRE)
#define CLK_DisMCD_RST()		SFIE=SFIE&(~MCDRE)

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  TIMER0 & TIMER1 
*
*************************************************************************************
*/
// 使能或关闭TIMER
#define TM_DisableT0()			TR0=0					
#define TM_EnableT0()			TR0=1
#define TM_DisableT1()			TR1=0					
#define TM_EnableT1()			TR1=1

// 选择TIMER工作模式
#define TM_SetT0Mode_0_8BIT_PWM()				TMOD=(TMOD&(~(T0M0|T0M1)))
#define TM_SetT0Mode_1_16BIT_TIMER()			TMOD=(TMOD&(~(T0M0|T0M1)))|(T0M0)
#define TM_SetT0Mode_2_8BIT_AUTORELOAD()		TMOD=(TMOD&(~(T0M0|T0M1)))|(T0M1)
#define TM_SetT0Mode_3_TWO_8BIT()				TMOD=(TMOD|(T0M0|T0M1))


#define TM_SetT0Gate_Disable()					TMOD=TMOD&(~T0GATE)
#define TM_SetT0Gate_INT0()						TMOD=TMOD|T0GATE

#define TM_SetT1Mode_0_8BIT_PWM()				TMOD=(TMOD&(~(T1M0|T1M1)))          
#define TM_SetT1Mode_1_16BIT_TIMER()			TMOD=(TMOD&(~(T1M0|T1M1)))|(T1M0)    
#define TM_SetT1Mode_2_8BIT_AUTORELOAD()		TMOD=(TMOD&(~(T1M0|T1M1)))|(T1M1)    
#define TM_SetT1Mode_3_Disable()				TMOD=(TMOD|(T1M0|T1M1))             

#define TM_SetT1Gate_Disable()					TMOD=TMOD&(~T1GATE)
#define TM_SetT1Gate_INT1()						TMOD=TMOD|(T1GATE)

// 选择TIMER时钟源
#define TM_SetT0Clock_SYSCLKDiv12()				AUXR0=(AUXR0&(~T0XL));AUXR2=(AUXR2&(~T0X12));TMOD=(TMOD&(~T0CT))
#define TM_SetT0Clock_SYSCLK()					AUXR0=(AUXR0&(~T0XL));AUXR2=(AUXR2|(T0X12));TMOD=(TMOD&(~T0CT))
#define TM_SetT0Clock_SYSCLKDiv48()				AUXR0=(AUXR0|(T0XL));AUXR2=(AUXR2&(~T0X12));TMOD=(TMOD&(~T0CT))
#define TM_SetT0Clock_SYSCLKDiv192()			AUXR0=(AUXR0|(T0XL));AUXR2=(AUXR2|(T0X12));TMOD=(TMOD&(~T0CT))
#define TM_SetT0Clock_T0Port()					TMOD=(TMOD|(T0CT))

#define TM_SetT1Clock_SYSCLKDiv12()				AUXR2=(AUXR2&(~T1X12));TMOD=(TMOD&(~T1CT))
#define TM_SetT1Clock_T1Port()					TMOD=(TMOD|(T1CT))
#define TM_SetT1Clock_SYSCLK()					AUXR2=(AUXR2|(T1X12));TMOD=(TMOD&(~T1CT))

// 设置TIMER值
#define TM_SetT0HighByte(x)			TH0=x
#define TM_SetT0LowByte(x)			TL0=x

#define TM_SetT1LowByte(x)			TL1=x
#define TM_SetT1HighByte(x)			TH1=x


// 设置TIMER输出引脚

// 设置TIMER CKO输出使能/禁止
#define TM_EnT0CKO()				AUXR2=AUXR2|(T0CKOE)
#define TM_EnT1CKO()				AUXR2=AUXR2|(T1CKOE)

#define TM_DisT0CKO()				AUXR2=AUXR2&(~T0CKOE)
#define TM_DisT1CKO()				AUXR2=AUXR2&(~T1CKOE)

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  TIMER2
*
*************************************************************************************
*/
// 使能或关闭TIMER2
#define TM_DisableT2()			TR2=0					
#define TM_EnableT2()			TR2=1

// 选择TIMER2工作模式
// 定时器2为波特率发生器
#define TM_SetT2Mode_BRG()				T2CON=0x30;T2MOD=0x00
// 定时器2为16位捕获
#define TM_SetT2Mode_16BitCapture()		T2CON=0x01;T2MOD=0x00
// 定时器2为16位自动重载,仅向上计数
#define TM_SetT2Mode_16BitAutoRL_UP()	T2CON=0x00;T2MOD=0x00
// 定时器2为16位自动重载,向上或向下计数(T2EX引脚决定)
#define TM_SetT2Mode_16BitAutoRL_T2EX()	T2CON=0x00;T2MOD=DCEN2

// 设置TIMER2输出
#define TM_EnT2CKO()					T2MOD=T2MOD|(T2OE)
#define TM_DisT2CKO()					T2MOD=T2MOD&(~T2OE)

// 选择TIMER2时钟源
#define TM_SetT2Clock_SYSCLKDiv12()		C_T2=0;T2MOD=T2MOD&(~T2X12)
#define TM_SetT2Clock_SYSCLK()			C_T2=0;T2MOD=T2MOD|(T2X12)

// 设置TIMER2引脚中断检测边沿
#define TM_EnableT2EX_DetectFalling()					EXEN2=1
#define TM_DisableT2EX_DetectFalling()					EXEN2=0
#define TM_EnableT2EX_DetectRising()					T2MOD=T2MOD|T2EXH
#define TM_DisableT2EX_DetectRising()					T2MOD=T2MOD&(~T2EXH)

// 设置TIMER2值
#define TM_SetT2HighByte(x)			TH2=x
#define TM_SetT2LowByte(x)			TL2=x

#define TM_SetT2RLHighByte(x)		RCAP2H=x
#define TM_SetT2RLLowByte(x)		RCAP2L=x

/*
*************************************************************************************
*/ 


/*
*************************************************************************************
*  IO PORT 
*
*************************************************************************************
*/
// 设置P3引脚模式
#define PORT_SetP3QuasiBi(x)				P3M0=P3M0&(~(x));P3M1=P3M1&(~(x))
#define PORT_SetP3PushPull(x)				P3M0=P3M0&(~(x));P3M1=P3M1|(x)
#define PORT_SetP3InputOnly(x)				P3M0=P3M0|(x);P3M1=P3M1&(~(x))
#define PORT_SetP3OpenDrain(x)				P3M0=P3M0|(x);P3M1=P3M1|(x)

// 设置P1引脚模式
#define PORT_SetP1PushPull(x)				P1M0=P1M0|(x)
#define PORT_SetP1OpenDrain(x)				P1M0=P1M0&(~(x))
#define PORT_SetP1AInputOnly(x)				P1AIO=P1AIO|(x)
#define PORT_SetP1Digital(x)				P1AIO=P1AIO&(~(x))
#define PORT_EnP10P11P12P13PullHigh()		PUCON0=PUCON0|P1PU0
#define PORT_DisP10P11P12P13PullHigh()		PUCON0=PUCON0&(P1PU0)
#define PORT_EnP14P15P16P17PullHigh()		PUCON0=PUCON0|P1PU1
#define PORT_DisP14P15P16P17PullHigh()		PUCON0=PUCON0&(P1PU1)

// 设置P2引脚模式
#define PORT_SetP2PushPull(x)				P2M0=P2M0|(x)
#define PORT_SetP2OpenDrain(x)				P2M0=P2M0&(~(x))
#define PORT_EnP20P21P22P23PullHigh()		PUCON0=PUCON0|P2PU0
#define PORT_DisP20P21P22P23PullHigh()		PUCON0=PUCON0&(P2PU0)
#define PORT_EnP24P25P26P27PullHigh()		PUCON0=PUCON0|P2PU1
#define PORT_DisP24P25P26P27PullHigh()		PUCON0=PUCON0&(P2PU1)

// 设置P4引脚模式
#define PORT_SetP4PushPull(x)				P4M0=P4M0|(x)
#define PORT_SetP4OpenDrain(x)				P4M0=P4M0&(~(x))
#define PORT_EnP40P41PullHigh()				PUCON0=PUCON0|P4PU0
#define PORT_DisP40P41PullHigh()			PUCON0=PUCON0&(P4PU0)
#define PORT_EnP44P45P47PullHigh()			PUCON0=PUCON0|P4PU1
#define PORT_DisP44P45P47PullHigh()			PUCON0=PUCON0&(P4PU1)
                                                                               
// 设置P6引脚模式
#define PORT_SetP6PushPull(x)				SFRPI=1;P6M0=P6M0|(x);SFRPI=0 
#define PORT_SetP6OpenDrain(x)				SFRPI=1;P6M0=P6M0&(~(x));SFRPI=0
#define PORT_EnP60P61PullHigh()				SFRPI=1;PUCON1=PUCON1|P6PU0;SFRPI=0 
#define PORT_DisP60P61PullHigh()			SFRPI=1;PUCON1=PUCON1&(P6PU0);SFRPI=0 
/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  TWI0 
*
*************************************************************************************
*/
// 清TWI0
#define TWI0_Clear()				SICON=0
// 开启或关闭TWI0
#define TWI0_Disable()						SICON=SICON&(~ENSI)					
#define TWI0_Enable()						SICON=SICON|(ENSI)

// 选择TWI0 的传送速度  主机最高1MHz, 从机同步任何主机的频率,最高支持400KHz
#define TWI0_CLK_SYSCLK_8	0	// SYSCLK/8
#define TWI0_CLK_SYSCLK_16	1	// SYSCLK/16
#define TWI0_CLK_SYSCLK_32	2	// SYSCLK/32
#define TWI0_CLK_SYSCLK_64	3	// SYSCLK/64
#define TWI0_CLK_SYSCLK_128	4	// SYSCLK/128
#define TWI0_CLK_SYSCLK_256	5	// SYSCLK/256
#define TWI0_CLK_T0OF_6		7	// T0OF/6	

#define TWI0_SetClock(x)			SICON=(SICON&B01111100)|((x&0x03)|((x<<5)&B10000000))

#define TWI0_SetSlaveAddr(x)		SIADR=x			// 设置从机地址
#define TWI0_SendACK()				SICON |= AA		// 发送ACK
#define TWI0_SendNOACK()			SICON &= ~AA	// 发送 NO ACK
#define TWI0_SendSTART()			SICON |= STA	// 发送起始位
#define TWI0_ClearSTART()			SICON &= ~STA	// 清除起始标志
#define TWI0_SendSTOP()				SICON |= STO	// 发送停止位，停止标志由硬件清除
#define TWI0_ClearSI()				SICON &= ~SI	// 清楚TWI中断标志

// 选择TWI0 所用的IO口
#define TWI0_SetUseP40P41()			AUXR1=AUXR1&(~(P6TWI))
#define TWI0_SetUseP60P61()			AUXR1=AUXR1|(P6TWI)


/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  TWI1 
*
*************************************************************************************
*/
// 清TWI1
#define TWI1_Clear()				SFRPI=1;SI1CON=0;SFRPI=0
// 开启或关闭TWI0
#define TWI1_Disable()						SFRPI=1;SI1CON=SI1CON&(~ENSI1);SFRPI=0					
#define TWI1_Enable()						SFRPI=1;SI1CON=SI1CON|(ENSI1);SFRPI=0

// 选择TWI0 的传送速度  主机最高1MHz, 从机同步任何主机的频率,最高支持400KHz
#define TWI1_CLK_SYSCLK_8	0	// SYSCLK/8
#define TWI1_CLK_SYSCLK_16	1	// SYSCLK/16
#define TWI1_CLK_SYSCLK_32	2	// SYSCLK/32
#define TWI1_CLK_SYSCLK_64	3	// SYSCLK/64
#define TWI1_CLK_SYSCLK_128	4	// SYSCLK/128
#define TWI1_CLK_SYSCLK_256	5	// SYSCLK/128
#define TWI1_CLK_T0OF_6		7	// T0OF/6	

#define TWI1_SetClock(x)			SFRPI=1;SI1CON=(SI1CON&B01111100)|((x&0x03)|((x<<5)&B10000000));SFRPI=0

#define TWI1_SetSlaveAddr(x)		SFRPI=1;SIADR=x;SFRPI=0
#define TWI1_SendACK()				SFRPI=1;SICON |= AA;SFRPI=0		// 发送ACK
#define TWI1_SendNOACK()			SFRPI=1;SICON &= ~AA;SFRPI=0	// 发送 NO ACK
#define TWI1_SendSTART()			SFRPI=1;SICON |= STA;SFRPI=0	// 发送起始位
#define TWI1_ClearSTART()			SFRPI=1;SICON &= ~STA;SFRPI=0	// 清除起始标志
#define TWI1_SendSTOP()				SFRPI=1;SICON |= STO;SFRPI=0	// 发送停止位，停止标志由硬件清除
#define TWI1_ClearSI()				SFRPI=1;SICON &= ~SI;SFRPI=0	// 清楚TWI中断标志


// 选择TWI1 所用的IO口
#define TWI1_SetUseP10P11()			AUXR3=AUXR3&(~(P3TWI1))
#define TWI1_SetUseP30P31()			AUXR3=AUXR3|(P3TWI1)


/*
*************************************************************************************
*/ 



/*
*************************************************************************************
*  UART0 
*
*************************************************************************************
*/
// UART0 设置UART0工作模式
#define UART0_SetModeShiftReg()				S0CFG=S0CFG&(~SM30);SM00_FE=0;SM10=0
#define UART0_SetMode8bitUARTVar()			S0CFG=S0CFG&(~SM30);SM00_FE=0;SM10=1
#define UART0_SetMode9bitUART()				S0CFG=S0CFG&(~SM30);SM00_FE=1;SM10=0
#define UART0_SetMode9bitUARTVar()			S0CFG=S0CFG&(~SM30);SM00_FE=1;SM10=1
#define UART0_SetModeSPIMaster()			S0CFG=S0CFG|(SM30);SM00_FE=0;SM10=0

// UART0 开启/关闭自动地址识别功能
#define UART0_EnAutoAddressRecognition()	SM20=1
#define UART0_DisAutoAddressRecognition()	SM20=0

// UART0 开启/关闭接收数据功能
#define UART0_EnReception()					REN0=1
#define UART0_DisReception()				REN0=0

// UART0 设置数据位序(MSB:高位在前,LSB:低位在前)
#define UART0_SetDataMSB()					S0CFG=S0CFG&(~S0DOR)
#define UART0_SetDataLSB()					S0CFG=S0CFG|(S0DOR)

// UART0 开启/关闭响应发送完成中断TI0
#define UART0_EnTI0toS0Interrupt()			S0CFG=S0CFG&(~BTI)
#define UART0_DisTI0toS0Interrupt()			S0CFG=S0CFG|(BTI)

// UART0 开启/关闭系统标志中断响应发送完成中断TI0
#define UART0_EnTI0toSysFlagInterrupt()		S0CFG=S0CFG|(UTIE)
#define UART0_DisTI0toSysFlagInterrupt()		S0CFG=S0CFG&(~UTIE)

// UART0 设置从机地址
#define UART0_SetSlaveAddr(x)				SADDR=x

// UART0 设置从机地址掩码
#define UART0_SetSlaveAddrMask(x)			SADEN=x

// UART0 设置波特率加倍设置 
#define UART0_SetBaudRateX1()				PCON0=PCON0&(~SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetBaudRateX2()				PCON0=PCON0|(SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetBaudRateX4()				PCON0=PCON0&(~SMOD1);S0CFG=S0CFG|(S0MOD2)
#define UART0_SetBaudRateX8()				PCON0=PCON0|(SMOD1);S0CFG=S0CFG|(S0MOD2)

#define UART0_SetT1BaudRateX1()				PCON0=PCON0&(~SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetT1BaudRateX2()				PCON0=PCON0|(SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetT1BaudRateX4()				PCON0=PCON0&(~SMOD1);S0CFG=S0CFG|(S0MOD2)
#define UART0_SetT1BaudRateX8()				PCON0=PCON0|(SMOD1);S0CFG=S0CFG|(S0MOD2)

#define UART0_SetT2BaudRateX1()				S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetT2BaudRateX2()				PCON0=PCON0&(~SMOD1);S0CFG=S0CFG|(S0MOD2)
#define UART0_SetT2BaudRateX4()				PCON0=PCON0|(SMOD1);S0CFG=S0CFG|(S0MOD2)


#define UART0_SetS1BRGBaudRateX1()			PCON0=PCON0&(~SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetS1BRGBaudRateX2()			PCON0=PCON0|(SMOD1);S0CFG=S0CFG&(~S0MOD2)
#define UART0_SetS1BRGBaudRateX4()			PCON0=PCON0&(~SMOD1);S0CFG=S0CFG|(S0MOD2)
#define UART0_SetS1BRGBaudRateX8()			PCON0=PCON0|(SMOD1);S0CFG=S0CFG|(S0MOD2)

// UART 设置波特率来源
#define UART0_SetBRGFromT1()				RCLK=0;TCLK=0;S0CFG=S0CFG&(~URTS)		
#define UART0_SetBRGFromT2()				RCLK=1;TCLK=1
#define UART0_SetBRGFromS1BRG()				RCLK=0;TCLK=0;S0CFG=S0CFG|(URTS)

// UART0 设置SPI MASTER的SPI速度
#define UART0_SetSPIClock_SYSCLKDiv4()		S0CFG=S0CFG|(URM0X3)
#define UART0_SetSPIClock_SYSCLKDiv12()		S0CFG=S0CFG&(~URM0X3)

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  UART1 
*
*************************************************************************************
*/
// UART1 设置UART1工作模式
#define UART1_SetModeShiftReg()				SFRPI=1;S1CFG=S1CFG&(~SM31);SM01=0;SM11=0
#define UART1_SetMode8bitUARTVar()			SFRPI=1;S1CFG=S1CFG&(~SM31);SM01=0;SM11=1
#define UART1_SetMode9bitUART()				SFRPI=1;S1CFG=S1CFG&(~SM31);SM01=1;SM11=0
#define UART1_SetMode9bitUARTVar()			SFRPI=1;S1CFG=S1CFG&(~SM31);SM01=1;SM11=1
#define UART1_SetModeSPIMaster()			SFRPI=1;S1CFG=S1CFG|(SM31);SM01=0;SM11=0


// UART1 开启/关闭接收数据功能
#define UART1_EnReception()					SFRPI=1;REN1=1;SFRPI=0
#define UART1_DisReception()				SFRPI=1;REN1=0;SFRPI=0


// UART1 设置波特率加倍设置 
#define UART1_SetBaudRateX1()				SFRPI=1;S1CFG=S1CFG&(~S1MOD1);SFRPI=0
#define UART1_SetBaudRateX2()				SFRPI=1;S1CFG=S1CFG|(S1MOD1);SFRPI=0

// UART1 开启/关闭波特率发生器
#define UART1_EnS1BRG()						SFRPI=1;S1CFG=S1CFG|(S1TR);SFRPI=0
#define UART1_DisS1BRG()					SFRPI=1;S1CFG=S1CFG&(~S1TR);SFRPI=0

// UART1 设置S1BRG时钟源
#define UART1_SetS1BRGSelSYSCLK()			SFRPI=1;S1CFG=S1CFG|(S1TX12);SFRPI=0
#define UART1_SetS1BRGSelSYSCLKdiv12()		SFRPI=1;S1CFG=S1CFG&(~S1TX12);SFRPI=0

// UART1 设置S1BRG Value
#define UART1_SetS1BRGValue(x)				SFRPI=1;S1BRT=x;S1BRC=x;SFRPI=0//0xB2

// UART1 选择UART1 所用的IO口
#define UART1_SetRxTxP12P13()				AUXR1=AUXR1&(~(P3S1))
#define UART1_SetRxTxP33P34()				AUXR1=AUXR1|(P3S1)

// UART1 设置SPI MASTER的SPI速度
#define UART1_SetSPIClock_SYSCLKDiv4()		SFRPI=1;S1CFG=S1CFG|(S1TX12);SFRPI=0
#define UART1_SetSPIClock_SYSCLKDiv12()		SFRPI=1;S1CFG=S1CFG&(~S1TX12);SFRPI=0


/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  ADC
*
*************************************************************************************
*/
// 开启或关闭ADC
#define ADC_Disable()						ADCON0=ADCON0&(~ADCEN)					
#define ADC_Enable()						ADCON0=ADCON0|(ADCEN)

// 开启或关闭ADC
#define ADC_SoftStart()						ADCON0=ADCON0|(ADCS)					

// 设置ADC的转换时钟源
#define ADC_SetClock_SYSCLKDiv2()				ADCFG0=ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2))
#define ADC_SetClock_SYSCLKDiv4()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS0)
#define ADC_SetClock_SYSCLKDiv8()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS1)
#define ADC_SetClock_SYSCLKDiv16()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS0|ADCKS1)
#define ADC_SetClock_SYSCLKDiv32()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS2)
#define ADC_SetClock_SYSCLKDiv64()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS0|ADCKS2)
#define ADC_SetClock_S1TOFDiv2()			ADCFG0=(ADCFG0&(~(ADCKS0|ADCKS1|ADCKS2)))|(ADCKS1|ADCKS2)
#define ADC_SetClock_T0OFDiv2()				ADCFG0=ADCFG0|(ADCKS0|ADCKS1|ADCKS2)

// 设置ADC的转换通道
#define ADC_SetChannel_AIN0()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))
#define ADC_SetChannel_AIN1()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS0)
#define ADC_SetChannel_AIN2()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS1)
#define ADC_SetChannel_AIN3()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS1|CHS0)
#define ADC_SetChannel_AIN4()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS2)
#define ADC_SetChannel_AIN5()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS2|CHS0)
#define ADC_SetChannel_AIN6()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS2|CHS1)
#define ADC_SetChannel_AIN7()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CHS2|CHS1|CHS0)
#define ADC_SetChannel_GNDA()				ADCON0=(ADCON0&(~(CH3|CHS2|CHS1|CHS0)))|(CH3|CHS2|CHS1)
#define ADC_SetChannel_IVR24()				ADCON0=(ADCON0|((CH3|CHS2|CHS1|CHS0)))

// 设置ADC的转换模式
#define ADC_SetMode_SetADCS()				ADCFG0=ADCFG0&(~(ADTM0|ADTM1))
#define ADC_SetMode_T0Overflow()			ADCFG0=(ADCFG0&(~(ADTM0|ADTM1)))|(ADTM0)
#define ADC_SetMode_FreeRunning()			ADCFG0=(ADCFG0&(~(ADTM0|ADTM1)))|(ADTM1)
#define ADC_SetMode_S1BRGOverflow()			;ADCFG0=ADCFG0|(ADTM0|ADTM1)


// 设置ADC值左对齐(ADCDH[7:0]ADCDL[7:4])/右对齐(ADCDH[3:0]ADCDL[7:0])
#define ADC_SetLeftJustified()				ADCFG0=ADCFG0&(~ADRJ)					
#define ADC_SetRightJustified()				ADCFG0=ADCFG0|(ADRJ)					



// 设置ADC的转换偏移值
#define ADC_SetOffsetAdd(x)				ADCFG1=(ADCFG1&(~(0x1F)))|(x)		// ADC值+x (x=0~15)
#define ADC_SetOffsetSub(x)				ADCFG1=(ADCFG1&(~(0x1F)))|((~x))	// ADC值-x (x=1~16)



// 设置ADCVREF+	
#define ADC_SetVREF_VDDA()					ADCFG0=ADCFG0&(~(VRS0));ADCFG1=(ADCFG1&(~(VRS1|VRS2)))						
#define ADC_SetVREF_AIN1()					ADCFG0=ADCFG0|((VRS0));ADCFG1=(ADCFG1&(~(VRS1|VRS2)))
#define ADC_SetVREF_VDDA_IVR24onAIN1()		ADCFG0=ADCFG0&(~(VRS0));ADCFG1=(ADCFG1&(~(VRS1|VRS2)))	|(VRS1)	
#define ADC_SetVREF_IVR24_IVR24onAIN1()		ADCFG0=ADCFG0|((VRS0));ADCFG1=(ADCFG1&(~(VRS1|VRS2)))	|(VRS1)	
#define ADC_SetVREF_VDDA_VDDAonAIN1()		ADCFG0=ADCFG0&(~(VRS0));ADCFG1=(ADCFG1&(~(VRS1|VRS2)))	|(VRS2|VRS1)	
#define ADC_SetVREF_IVR24()					ADCFG0=ADCFG0|((VRS0));ADCFG1=(ADCFG1|((VRS1|VRS2)))		
/*
*************************************************************************************
*/ 


/*
*************************************************************************************
*  SPI 
*
*************************************************************************************
*/
// 开启或关闭SPI
#define SPI_Disable()						SPCON=SPCON&(~SPEN)					
#define SPI_Enable()						SPCON=SPCON|(SPEN)

// 选择MASTER/SLAVE
#define SPI_SelectMASTERByMSTRbit()			SPCON=SPCON|(SSIG|MSTR)					
#define SPI_SelectSLAVEByMSTRbit()			SPCON=(SPCON|(SSIG))&(~MSTR)						
#define SPI_SelectMASTERSLAVEBynSSpin()		SPCON=SPCON&(~SSIG)

// 选择SPICLK 初始电平 0:SPICLK  初始为低电平 1: SPICLK  初始为低电平
#define SPI_SetCPOL_0()						SPCON=SPCON&(~CPOL)
#define SPI_SetCPOL_1()						SPCON=SPCON|(CPOL)

// 选择数据传送顺序	0:高位在先 1: 低位在先
#define SPI_SetDataMSB()					SPCON=SPCON&(~DORD)
#define SPI_SetDataLSB()					SPCON=SPCON|(DORD)

// 选择SPI 的传送速度
#define SPI_CLK_SYSCLK_4	0	// SYSCLK/4
#define SPI_CLK_SYSCLK_8	1	// SYSCLK/8
#define SPI_CLK_SYSCLK_16	2	// SYSCLK/16
#define SPI_CLK_SYSCLK_32	3	// SYSCLK/32
#define SPI_CLK_SYSCLK_64	4	// SYSCLK/64
#define SPI_CLK_SYSCLK_128	5	// SYSCLK/128
#define SPI_CLK_S1TOF_6		6	// S1TOF/6	
#define SPI_CLK_T0OF_6		7	// T0OF/6	

#define SPI_SetClock(x)						SPCON=(SPCON&B11111100)|(x&0x03);SPSTAT=(x>>2)

// 选择数据采样模式	0:前沿采样,后沿改变数据 1: 前沿改变数据,后沿采样
#define SPI_SetCPHA_0()						SPCON=SPCON&(~CPHA)
#define SPI_SetCPHA_1()						SPCON=SPCON|(CPHA)

// 选择SPI 所用的IO口
#define SPI_SetUseP14P15P16P17()			AUXR1=AUXR1&(~P4SPI)
#define SPI_SetUseP20P21P41P40()			AUXR1=AUXR1|(P4SPI)

// SPI 清/检测SPI完成标志
#define SPI_ClearCompleteFlag()		SPSTAT=SPSTAT|SPIF
#define SPI_ChkCompleteFlag()		(SPSTAT&SPIF)

// SPI 发送/接收数据
#define SPI_SendData(x)		SPDAT=x
#define SPI_GetData()		SPDAT

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  PCA
*
*************************************************************************************
*/
// PCA 开启/关闭计数器
#define	PCA_EnPCACounter()					CR=1
#define	PCA_DisPCACounter()					CR=0

// PCA 设置时钟源, 选择CKMIX16或MCKDO时,必须满足>=SYSCLKx2 & >=CPUCLKx3
#define PCA_SetCLOCK_SYSCLKdiv12()			CMOD=CMOD&(~(CPS2|CPS1|CPS0))
#define PCA_SetCLOCK_SYSCLKdiv2()			CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS0)
#define PCA_SetCLOCK_TO()					CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS1)
#define PCA_SetCLOCK_ECI()					CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS1|CPS0)
#define PCA_SetCLOCK_CKMIX16()				CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS2)
#define PCA_SetCLOCK_SYSCLK()				CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS2|CPS0)
#define PCA_SetCLOCK_S1BRT()				CMOD=(CMOD&(~(CPS2|CPS1|CPS0)))|(CPS2|CPS1)
#define PCA_SetCLOCK_MCKDO()				CMOD=CMOD|(CPS2|CPS1|CPS0)

// PCA 设置计数器值及其重载值
#define PCA_SetCounter(x)					CH=HIBYTE(x);CL=LOBYTE(x)
#define PCA_SetCounterReload(x)				CHRL=HIBYTE(x);CLRL=LOBYTE(x)


// PCA 设置模式
#define PCA_CH0_SetMode_16BitCaptureRising()	CCAPM0=CAPP0		
#define PCA_CH0_SetMode_16BitCaptureFalling()	CCAPM0=CAPN0		
#define PCA_CH0_SetMode_16BitCaptureDaul()		CCAPM0=CAPP0|CAPN0		
#define PCA_CH0_SetMode_16BitSoftwareTimer()	CCAPM0=ECOM0|MAT0		
#define PCA_CH0_SetMode_16BitHighSpeedOutput()	CCAPM0=ECOM0|MAT0|TOG0		
#define PCA_CH0_SetMode_PWM()					CCAPM0=ECOM0|PWM0	

#define PCA_CH1_SetMode_16BitCaptureRising()	CCAPM1=CAPP1		
#define PCA_CH1_SetMode_16BitCaptureFalling()	CCAPM1=CAPN1		
#define PCA_CH1_SetMode_16BitCaptureDaul()		CCAPM1=CAPP1|CAPN1		
#define PCA_CH1_SetMode_16BitSoftwareTimer()	CCAPM1=ECOM1|MAT1		
#define PCA_CH1_SetMode_16BitHighSpeedOutput()	CCAPM1=ECOM1|MAT1|TOG1		
#define PCA_CH1_SetMode_PWM()					CCAPM1=ECOM1|PWM1	

#define PCA_CH2_SetMode_16BitCaptureRising()	CCAPM2=CAPP2		
#define PCA_CH2_SetMode_16BitCaptureFalling()	CCAPM2=CAPN2		
#define PCA_CH2_SetMode_16BitCaptureDaul()		CCAPM2=CAPP2|CAPN2		
#define PCA_CH2_SetMode_16BitSoftwareTimer()	CCAPM2=ECOM2|MAT2		
#define PCA_CH2_SetMode_16BitHighSpeedOutput()	CCAPM2=ECOM2|MAT2|TOG2		
#define PCA_CH2_SetMode_PWM()					CCAPM2=ECOM2|PWM2	

#define PCA_CH3_SetMode_16BitCaptureRising()	CCAPM3=CAPP3		
#define PCA_CH3_SetMode_16BitCaptureFalling()	CCAPM3=CAPN3		
#define PCA_CH3_SetMode_16BitCaptureDaul()		CCAPM3=CAPP3|CAPN3		
#define PCA_CH3_SetMode_16BitSoftwareTimer()	CCAPM3=ECOM3|MAT3		
#define PCA_CH3_SetMode_16BitHighSpeedOutput()	CCAPM3=ECOM3|MAT3|TOG3		
#define PCA_CH3_SetMode_PWM()					CCAPM3=ECOM3|PWM3	

#define PCA_CH4_SetMode_16BitCaptureRising()	CCAPM4=CAPP4		
#define PCA_CH4_SetMode_16BitCaptureFalling()	CCAPM4=CAPN4		
#define PCA_CH4_SetMode_16BitCaptureDaul()		CCAPM4=CAPP4|CAPN4		
#define PCA_CH4_SetMode_16BitSoftwareTimer()	CCAPM4=ECOM4|MAT4		
#define PCA_CH4_SetMode_16BitHighSpeedOutput()	CCAPM4=ECOM4|MAT4|TOG4		
#define PCA_CH4_SetMode_PWM()					CCAPM4=ECOM4|PWM4	

#define PCA_CH5_SetMode_16BitCaptureRising()	CCAPM5=CAPP5		
#define PCA_CH5_SetMode_16BitCaptureFalling()	CCAPM5=CAPN5		
#define PCA_CH5_SetMode_16BitCaptureDaul()		CCAPM5=CAPP5|CAPN5		
#define PCA_CH5_SetMode_16BitSoftwareTimer()	CCAPM5=ECOM5|MAT5		
#define PCA_CH5_SetMode_16BitHighSpeedOutput()	CCAPM5=ECOM5|MAT5|TOG5		
#define PCA_CH5_SetMode_PWM()					CCAPM5=ECOM5|PWM5	

#define PCA_CH6_SetMode_PWM()					SFRPI=1;CCAPM6=PWM6;SFRPI=0	

#define PCA_CH7_SetMode_PWM()					SFRPI=1;CCAPM7=PWM7;SFRPI=0	

#define PCA_CH0_SetPWM_8Bit()					PCAPWM0=PCAPWM0&(~(P0RS0|P0RS1))
#define PCA_CH0_SetPWM_10Bit()					PCAPWM0=(PCAPWM0&(~(P0RS0|P0RS1)))|(P0RS0)
#define PCA_CH0_SetPWM_12Bit()					PCAPWM0=(PCAPWM0&(~(P0RS0|P0RS1)))|(P0RS1)
#define PCA_CH0_SetPWM_16Bit()					PCAPWM0=PCAPWM0|((P0RS0|P0RS1))

#define PCA_CH1_SetPWM_8Bit()					PCAPWM1=PCAPWM1&(~(P1RS0|P1RS1))
#define PCA_CH1_SetPWM_10Bit()					PCAPWM1=(PCAPWM1&(~(P1RS0|P1RS1)))|(P1RS0)
#define PCA_CH1_SetPWM_12Bit()					PCAPWM1=(PCAPWM1&(~(P1RS0|P1RS1)))|(P1RS1)
#define PCA_CH1_SetPWM_16Bit()					PCAPWM1=PCAPWM1|((P1RS0|P1RS1))

#define PCA_CH2_SetPWM_8Bit()					PCAPWM2=PCAPWM0&(~(P2RS0|P2RS1))
#define PCA_CH2_SetPWM_10Bit()					PCAPWM2=(PCAPWM0&(~(P2RS0|P2RS1)))|(P2RS0)
#define PCA_CH2_SetPWM_12Bit()					PCAPWM2=(PCAPWM0&(~(P2RS0|P2RS1)))|(P2RS1)
#define PCA_CH2_SetPWM_16Bit()					PCAPWM2=PCAPWM0|((P2RS0|P2RS1))

#define PCA_CH3_SetPWM_8Bit()					PCAPWM3=PCAPWM0&(~(P3RS0|P3RS1))
#define PCA_CH3_SetPWM_10Bit()					PCAPWM3=(PCAPWM0&(~(P3RS0|P3RS1)))|(P3RS0)
#define PCA_CH3_SetPWM_12Bit()					PCAPWM3=(PCAPWM0&(~(P3RS0|P3RS1)))|(P3RS1)
#define PCA_CH3_SetPWM_16Bit()					PCAPWM3=PCAPWM0|((P3RS0|P3RS1))

#define PCA_CH4_SetPWM_8Bit()					PCAPWM4=PCAPWM0&(~(P4RS0|P4RS1))
#define PCA_CH4_SetPWM_10Bit()					PCAPWM4=(PCAPWM0&(~(P4RS0|P4RS1)))|(P4RS0)
#define PCA_CH4_SetPWM_12Bit()					PCAPWM4=(PCAPWM0&(~(P4RS0|P4RS1)))|(P4RS1)
#define PCA_CH4_SetPWM_16Bit()					PCAPWM4=PCAPWM0|((P4RS0|P4RS1))

#define PCA_CH5_SetPWM_8Bit()					PCAPWM5=PCAPWM0&(~(P5RS0|P5RS1))
#define PCA_CH5_SetPWM_10Bit()					PCAPWM5=(PCAPWM0&(~(P5RS0|P5RS1)))|(P5RS0)
#define PCA_CH5_SetPWM_12Bit()					PCAPWM5=(PCAPWM0&(~(P5RS0|P5RS1)))|(P5RS1)
#define PCA_CH5_SetPWM_16Bit()					PCAPWM5=PCAPWM0|((P5RS0|P5RS1))

#define PCA_CH6_SetPWM_8Bit()					SFRPI=1;PCAPWM6=PCAPWM0&(~(P6RS0|P6RS1));SFRPI=0	
#define PCA_CH6_SetPWM_10Bit()					SFRPI=1;PCAPWM6=(PCAPWM0&(~(P6RS0|P6RS1)))|(P6RS0);SFRPI=0	
#define PCA_CH6_SetPWM_12Bit()					SFRPI=1;PCAPWM6=(PCAPWM0&(~(P6RS0|P6RS1)))|(P6RS1);SFRPI=0	
#define PCA_CH6_SetPWM_16Bit()					SFRPI=1;PCAPWM6=PCAPWM0|((P6RS0|P6RS1));SFRPI=0	

#define PCA_CH7_SetPWM_8Bit()					SFRPI=1;PCAPWM7=PCAPWM0&(~(P7RS0|P7RS1));SFRPI=0	
#define PCA_CH7_SetPWM_10Bit()					SFRPI=1;PCAPWM7=(PCAPWM0&(~(P7RS0|P7RS1)))|(P7RS0);SFRPI=0	
#define PCA_CH7_SetPWM_12Bit()					SFRPI=1;PCAPWM7=(PCAPWM0&(~(P7RS0|P7RS1)))|(P7RS1);SFRPI=0	
#define PCA_CH7_SetPWM_16Bit()					SFRPI=1;PCAPWM7=PCAPWM0|((P7RS0|P7RS1));SFRPI=0	

// PCA 设置各通道值
#define PCA_CH0_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM0=PCAPWM0|0x03;}else{CCAP0L=y;CCAP0H=x;PCAPWM0=PCAPWM0&(~0x03);}		// 0 0,1
#define PCA_CH1_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM1=PCAPWM1|0x03;}else{CCAP1L=y;CCAP1H=x;PCAPWM1=PCAPWM1&(~0x03);}		// 1 0,1
#define PCA_CH2_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM2=PCAPWM2|0x03;}else{CCAP2L=y;CCAP2H=x;PCAPWM2=PCAPWM2&(~0x03);}		// 2 2,3
#define PCA_CH3_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM3=PCAPWM3|0x03;}else{CCAP3L=y;CCAP3H=x;PCAPWM3=PCAPWM3&(~0x03);}		// 3 2,3
#define PCA_CH4_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM4=PCAPWM4|0x03;}else{CCAP4L=y;CCAP4H=x;PCAPWM4=PCAPWM4&(~0x03);}		// 4 4,5
#define PCA_CH5_SetValue(x,y)					if((x==0)&&(y==0)){PCAPWM5=PCAPWM5|0x03;}else{CCAP5L=y;CCAP5H=x;PCAPWM5=PCAPWM5&(~0x03);}		// 5 4,5
#define PCA_CH6_SetValue(x,y)					SFRPI=1;if((x==0)&&(y==0)){PCAPWM6=PCAPWM6|0x03;}else{CCAP6L=y;CCAP6H=x;PCAPWM6=PCAPWM6&(~0x03);};SFRPI=0		// 6 
#define PCA_CH7_SetValue(x,y)					SFRPI=1;if((x==0)&&(y==0)){PCAPWM7=PCAPWM7|0x03;}else{CCAP7L=y;CCAP7H=x;PCAPWM7=PCAPWM7&(~0x03);};SFRPI=0		// 7 

#define PCA_CH0_SetValue_L(x)					CCAP0L=x                        // 0
#define PCA_CH1_SetValue_L(x)					CCAP1L=x                        // 1
#define PCA_CH2_SetValue_L(x)					CCAP2L=x                        // 2
#define PCA_CH3_SetValue_L(x)					CCAP3L=x                        // 3
#define PCA_CH4_SetValue_L(x)					CCAP4L=x                        // 4
#define PCA_CH5_SetValue_L(x)					CCAP5L=x                        // 5
#define PCA_CH6_SetValue_L(x)					SFRPI=1;CCAP6L=x;SFRPI=0		// 6 
#define PCA_CH7_SetValue_L(x)					SFRPI=1;CCAP7L=x;SFRPI=0		// 7 

#define PCA_CH0_SetValue_H(x)					CCAP0H=x						// 0
#define PCA_CH1_SetValue_H(x)					CCAP1H=x                        // 1
#define PCA_CH2_SetValue_H(x)					CCAP2H=x                        // 2
#define PCA_CH3_SetValue_H(x)					CCAP3H=x                        // 3
#define PCA_CH4_SetValue_H(x)					CCAP4H=x                        // 4
#define PCA_CH5_SetValue_H(x)					CCAP5H=x                        // 5
#define PCA_CH6_SetValue_H(x)					SFRPI=1;CCAP6H=x;SFRPI=0		// 6 
#define PCA_CH7_SetValue_H(x)					SFRPI=1;CCAP7H=x;SFRPI=0		// 7 

#define PCA_CH0_SetValue_9thBit_L_0()			PCAPWM0=PCAPWM0&(~0x01)        	// 0
#define PCA_CH1_SetValue_9thBit_L_0()			PCAPWM1=PCAPWM1&(~0x01)         // 1
#define PCA_CH2_SetValue_9thBit_L_0()			PCAPWM2=PCAPWM2&(~0x01)         // 2
#define PCA_CH3_SetValue_9thBit_L_0()			PCAPWM3=PCAPWM3&(~0x01)         // 3
#define PCA_CH4_SetValue_9thBit_L_0()			PCAPWM4=PCAPWM4&(~0x01)         // 4
#define PCA_CH5_SetValue_9thBit_L_0()			PCAPWM5=PCAPWM5&(~0x01)         // 5
#define PCA_CH6_SetValue_9thBit_L_0()			SFRPI=1;PCAPWM6=PCAPWM6&(~0x01);SFRPI=0		// 6 
#define PCA_CH7_SetValue_9thBit_L_0()			SFRPI=1;PCAPWM7=PCAPWM7&(~0x01);SFRPI=0		// 7 
#define PCA_CH0_SetValue_9thBit_L_1()			PCAPWM0=PCAPWM0|(0x01)        	// 0             
#define PCA_CH1_SetValue_9thBit_L_1()			PCAPWM1=PCAPWM1|(0x01)         // 1             
#define PCA_CH2_SetValue_9thBit_L_1()			PCAPWM2=PCAPWM2|(0x01)         // 2             
#define PCA_CH3_SetValue_9thBit_L_1()			PCAPWM3=PCAPWM3|(0x01)         // 3             
#define PCA_CH4_SetValue_9thBit_L_1()			PCAPWM4=PCAPWM4|(0x01)         // 4             
#define PCA_CH5_SetValue_9thBit_L_1()			PCAPWM5=PCAPWM5|(0x01)         // 5             
#define PCA_CH6_SetValue_9thBit_L_1()			SFRPI=1;PCAPWM6=PCAPWM6|(0x01);SFRPI=0		// 6 
#define PCA_CH7_SetValue_9thBit_L_1()			SFRPI=1;PCAPWM7=PCAPWM7|(0x01);SFRPI=0		// 7 

#define PCA_CH0_SetValue_9thBit_H_0()			PCAPWM0=PCAPWM0&(~0x02)        	// 0             
#define PCA_CH1_SetValue_9thBit_H_0()			PCAPWM1=PCAPWM1&(~0x02)         // 1             
#define PCA_CH2_SetValue_9thBit_H_0()			PCAPWM2=PCAPWM2&(~0x02)         // 2             
#define PCA_CH3_SetValue_9thBit_H_0()			PCAPWM3=PCAPWM3&(~0x02)         // 3             
#define PCA_CH4_SetValue_9thBit_H_0()			PCAPWM4=PCAPWM4&(~0x02)         // 4             
#define PCA_CH5_SetValue_9thBit_H_0()			PCAPWM5=PCAPWM5&(~0x02)         // 5             
#define PCA_CH6_SetValue_9thBit_H_0()			SFRPI=1;PCAPWM6=PCAPWM6&(~0x02);SFRPI=0		// 6 
#define PCA_CH7_SetValue_9thBit_H_0()			SFRPI=1;PCAPWM7=PCAPWM7&(~0x02);SFRPI=0		// 7 
#define PCA_CH0_SetValue_9thBit_H_1()			PCAPWM0=PCAPWM0|(0x02)        	// 0             
#define PCA_CH1_SetValue_9thBit_H_1()			PCAPWM1=PCAPWM1|(0x02)         // 1              
#define PCA_CH2_SetValue_9thBit_H_1()			PCAPWM2=PCAPWM2|(0x02)         // 2              
#define PCA_CH3_SetValue_9thBit_H_1()			PCAPWM3=PCAPWM3|(0x02)         // 3              
#define PCA_CH4_SetValue_9thBit_H_1()			PCAPWM4=PCAPWM4|(0x02)         // 4              
#define PCA_CH5_SetValue_9thBit_H_1()			PCAPWM5=PCAPWM5|(0x02)         // 5              
#define PCA_CH6_SetValue_9thBit_H_1()			SFRPI=1;PCAPWM6=PCAPWM6|(0x02);SFRPI=0		// 6 
#define PCA_CH7_SetValue_9thBit_H_1()			SFRPI=1;PCAPWM7=PCAPWM7|(0x02);SFRPI=0		// 7 

// PCA 设置PWM输出反向
#define PCA_CH0_SetPWM_EnInvert()				PCAPWM0=PCAPWM0|P0INV
#define PCA_CH1_SetPWM_EnInvert()				PCAPWM1=PCAPWM1|P1INV
#define PCA_CH2_SetPWM_EnInvert()				PCAPWM2=PCAPWM2|P2INV
#define PCA_CH3_SetPWM_EnInvert()				PCAPWM3=PCAPWM3|P3INV
#define PCA_CH4_SetPWM_EnInvert()				PCAPWM4=PCAPWM4|P4INV
#define PCA_CH5_SetPWM_EnInvert()				PCAPWM5=PCAPWM5|P5INV
#define PCA_CH6_SetPWM_EnInvert()				SFRPI=1;PCAPWM6=PCAPWM6|P6INV;SFRPI=0	
#define PCA_CH7_SetPWM_EnInvert()				SFRPI=1;PCAPWM7=PCAPWM7|P7INV;SFRPI=0	

#define PCA_CH0_SetPWM_DisInvert()				PCAPWM0=PCAPWM0&(~(P0INV))
#define PCA_CH1_SetPWM_DisInvert()				PCAPWM1=PCAPWM1&(~(P1INV))
#define PCA_CH2_SetPWM_DisInvert()				PCAPWM2=PCAPWM2&(~(P2INV))
#define PCA_CH3_SetPWM_DisInvert()				PCAPWM3=PCAPWM3&(~(P3INV))
#define PCA_CH4_SetPWM_DisInvert()				PCAPWM4=PCAPWM4&(~(P4INV))
#define PCA_CH5_SetPWM_DisInvert()				PCAPWM5=PCAPWM5&(~(P5INV))
#define PCA_CH6_SetPWM_DisInvert()				SFRPI=1;PCAPWM6=PCAPWM6&(~(P6INV));SFRPI=0	
#define PCA_CH7_SetPWM_DisInvert()				SFRPI=1;PCAPWM7=PCAPWM7&(~(P7INV));SFRPI=0	

// PCA 设置PWM额外输出
#define PCA_EnPWM0_P22()						PAOE=PAOE|(P22OP0)
#define PCA_EnPWM0_P20()						PAOE=PAOE|(P20OP0)
#define PCA_EnPWM0_P21()						PAOE=PAOE|(P21OP0)
#define PCA_EnPWM4_P26()						PAOE=PAOE|(P26OP4)
#define PCA_EnPWM2_P24()						PAOE=PAOE|(P24OP2)
#define PCA_EnPWM2_P40()						PAOE=PAOE|(P40OP2)
#define PCA_EnPWM2_P41()						PAOE=PAOE|(P41OP2)
#define PCA_EnPWM4_P47()						PAOE=PAOE|(P47OP4)

#define PCA_DisPWM0_P22()						PAOE=PAOE&(~P22OP0)
#define PCA_DisPWM0_P20()						PAOE=PAOE&(~P20OP0)
#define PCA_DisPWM0_P21()						PAOE=PAOE&(~P21OP0)
#define PCA_DisPWM4_P26()						PAOE=PAOE&(~P26OP4)
#define PCA_DisPWM2_P24()						PAOE=PAOE&(~P24OP2)
#define PCA_DisPWM2_P40()						PAOE=PAOE&(~P40OP2)
#define PCA_DisPWM2_P41()						PAOE=PAOE&(~P41OP2)
#define PCA_DisPWM4_P47()						PAOE=PAOE&(~P47OP4)

// PCA 设置PWM 缓冲模式
#define PCA_CH01_SetPWM_EnBufferMode()				CMOD=CMOD|BME0
#define PCA_CH23_SetPWM_EnBufferMode()				CMOD=CMOD|BME2
#define PCA_CH45_SetPWM_EnBufferMode()				CMOD=CMOD|BME4
#define PCA_CH01_SetPWM_DisBufferMode()				CMOD=CMOD&(~(BME0))
#define PCA_CH23_SetPWM_DisBufferMode()				CMOD=CMOD&(~(BME2))
#define PCA_CH45_SetPWM_DisBufferMode()				CMOD=CMOD&(~(BME4))

// PCA 设置PWM 死区, 必须在缓冲模式下才有效
#define PCA_CH01_SetPWM_EnDeadTime()				CCAPM0=CCAPM0|DTE0
#define PCA_CH23_SetPWM_EnDeadTime()				CCAPM2=CCAPM2|DTE2
#define PCA_CH45_SetPWM_EnDeadTime()				CCAPM4=CCAPM4|DTE4
#define PCA_CH01_SetPWM_DisDeadTime()				CCAPM0=CCAPM0&(~(DTE0))
#define PCA_CH23_SetPWM_DisDeadTime()				CCAPM2=CCAPM2&(~(DTE2))
#define PCA_CH45_SetPWM_DisDeadTime()				CCAPM4=CCAPM4&(~(DTE4))

// PCA 设置死区预分频
#define PCA_SetDeadTimePreScaler_Sysclk()			PDTCR=(PDTCR&(~(DTPS1|DTPS0)))
#define PCA_SetDeadTimePreScaler_SysclkDiv2()		PDTCR=(PDTCR&(~(DTPS1|DTPS0)))|(DTPS0)
#define PCA_SetDeadTimePreScaler_SysclkDiv4()		PDTCR=(PDTCR&(~(DTPS1|DTPS0)))|(DTPS1)
#define PCA_SetDeadTimePreScaler_SysclkDiv8()		PDTCR=(PDTCR|((DTPS1|DTPS0)))

// PCA 设置死区时间周期 PreScaler*(x) 0:DT无效, 1~63:PreScaler*(1~63)
#define PCA_SetDeadTimePeriod(x)					PDTCR=(PDTCR&((DTPS1|DTPS0)))|x

// PCA 设置中断

#define PCA_CF_EnInterrupt()				CMOD=CMOD|ECF
#define PCA_CF_DisInterrupt()				CMOD=CMOD&(~(ECF))

#define PCA_CH0_EnInterrupt()				CCAPM0=CCAPM0|ECCF0
#define PCA_CH1_EnInterrupt()				CCAPM1=CCAPM1|ECCF1
#define PCA_CH2_EnInterrupt()				CCAPM2=CCAPM2|ECCF2
#define PCA_CH3_EnInterrupt()				CCAPM3=CCAPM3|ECCF3
#define PCA_CH4_EnInterrupt()				CCAPM4=CCAPM4|ECCF4
#define PCA_CH5_EnInterrupt()				CCAPM5=CCAPM5|ECCF5

#define PCA_CH0_DisInterrupt()				CCAPM0=CCAPM0&(~(ECCF0))
#define PCA_CH1_DisInterrupt()				CCAPM1=CCAPM1&(~(ECCF1))
#define PCA_CH2_DisInterrupt()				CCAPM2=CCAPM2&(~(ECCF2))
#define PCA_CH3_DisInterrupt()				CCAPM3=CCAPM3&(~(ECCF3))
#define PCA_CH4_DisInterrupt()				CCAPM4=CCAPM4&(~(ECCF4))
#define PCA_CH5_DisInterrupt()				CCAPM5=CCAPM5&(~(ECCF5))

// PCA 设置PWM对齐方式
#define PCA_SetPWM_EdgeAligned()			PWMCR=PWMCR&(~PCAE)
#define PCA_SetPWM_CenterAligned()			PWMCR=PWMCR|(PCAE)

// PCA 设置Break
#define PCA_SetBreak_Disable()				PWMCR=PWMCR&(~(PFCS0|PFCS1|PFCS2))
#define PCA_SetBreak_nINT0()				PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS0)
#define PCA_SetBreak_nINT1()				PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS1)
#define PCA_SetBreak_nINT0nINT1()			PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS1|PFCS0)	
#define PCA_SetBreak_nINT2()				PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS2)
#define PCA_SetBreak_nINT0nINT2()			PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS2|PFCS0)	
#define PCA_SetBreak_nINT1nINT2()			PWMCR=(PWMCR&(~(PFCS0|PFCS1|PFCS2)))|(PFCS2|PFCS1)	
#define PCA_SetBreak_nINT0nINT1nINT2()		PWMCR=PWMCR|((PFCS0|PFCS1|PFCS2))	

// PCA 设置Break 模式
#define PCA_SetBreakMode_Latched()			PWMCR=PWMCR&(~PFCM)
#define PCA_SetBreakMode_CyclebyCycle()		PWMCR=PWMCR|(PFCM)

// PCA 引脚设置
#define PCA_SetCEX1CEX3CEX5_P23P25P27()		AUXR1=AUXR1&(~P3CEX)
#define PCA_SetCEX1CEX3CEX5_P33P34P35()		AUXR1=AUXR1|(P3CEX)

/*
*************************************************************************************
*/ 


/*
*************************************************************************************
*  WDT 
*
*************************************************************************************
*/
#define WDT_SetClock_32K_DIV_1_16ms()		WDTCR=(WDTCR&(~0x07))
#define WDT_SetClock_32K_DIV_2_32ms()		WDTCR=(WDTCR&(~0x07))|0x01	
#define WDT_SetClock_32K_DIV_4_64ms()		WDTCR=(WDTCR&(~0x07))|0x02
#define WDT_SetClock_32K_DIV_8_128ms()		WDTCR=(WDTCR&(~0x07))|0x03
#define WDT_SetClock_32K_DIV_16_256ms()		WDTCR=(WDTCR&(~0x07))|0x04
#define WDT_SetClock_32K_DIV_32_512ms()		WDTCR=(WDTCR&(~0x07))|0x05
#define WDT_SetClock_32K_DIV_64_1024ms()	WDTCR=(WDTCR&(~0x07))|0x06
#define WDT_SetClock_32K_DIV_128_2048ms()	WDTCR=(WDTCR|(0x07))

#define WDT_EnReset()		WDTCR|=WREN
#define WDT_Enable_OnPD()	WDTCR|=NSW
#define WDT_Enable_OnIDLE()	WDTCR|=WIDL
#define WDT_Clear()			WDTCR|=CLW
#define WDT_Enable()		WDTCR|=ENW

#define CLRWDT()	WDTCR|=CLW
#define ENWDT()		WDTCR|=ENW
/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  RTC  
*
*************************************************************************************
*/
// RTC 使能或禁止
#define RTC_Enable()			RTCCR=RTCCR|RTCE
#define RTC_Disable()			RTCCR=RTCCR&(~RTCE)

// RTC 使能或禁止RTCO输出到P4.5 
#define RTC_EnRTCO_OutP45()			RTCCR=RTCCR|RTCO
#define RTC_DisRTCO_OutP45()		RTCCR=RTCCR&(~RTCO)

// RTC 设置重载值 x=0~63 
#define RTC_SetReload(x)		RTCCR=(RTCCR&(0xC0))|(x)

// RTC 设置计数值 x=0~63
#define RTC_SetCounter(x)		RTCTM=(RTCTM&(0xC0))|(x)


// RTC 设置时钟来源
#define RTC_SetClock_ECKI_P60_Div_16384()		RTCTM=(RTCTM&(~(RTCCS0|RTCCS0)))
#define RTC_SetClock_ECKI_P60_Div_32768()		RTCTM=(RTCTM&(~(RTCCS0|RTCCS0)))|(RTCCS0)
#define RTC_SetClock_SYSCLK_Div_12()			RTCTM=(RTCTM&(~(RTCCS0|RTCCS0)))|(RTCCS1)
#define RTC_SetClock_SYSCLK_Div_32768()			RTCTM=(RTCTM|((RTCCS0|RTCCS0)))

// RTC 清标志位RTCF
#define RTC_ClearRTCF()				PCON1=RTCF

// RTC 使能/禁止RTC中断
#define RTC_EnInterrupt()			SFIE=SFIE|RTCFIE
#define RTC_DisInterrupt()			SFIE=SFIE&(~RTCFIE)

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  SID  I2C START/STOP 侦测
*
*************************************************************************************
*/

/*
*************************************************************************************
*/ 

/*
*************************************************************************************
*  BEEPER  
*
*************************************************************************************
*/
// BEEPER 设置IO口
#define BEEP_SetP44_IOPort()						AUXR3=AUXR3&(~(BPOC0|BPOC1))
#define BEEP_SetP44_OutILRCODiv32_1KHz()			AUXR3=(AUXR3&(~(BPOC0|BPOC1)))|(BPOC0)
#define BEEP_SetP44_OutILRCODiv16_2KHz()			AUXR3=(AUXR3&(~(BPOC0|BPOC1)))|(BPOC1)
#define BEEP_SetP44_OutILRCODiv8_4KHz()				AUXR3=AUXR3|((BPOC0|BPOC1))

/*
*************************************************************************************
*/ 


/*
*************************************************************************************
*  KBI  
*
*************************************************************************************
*/
// KBI 设置IO口
#define KBI_SetKBI4567_P22P23P24P26()			AUXR1=AUXR1&(~(P1KBIH))		
#define KBI_SetKBI4567_P10P11P12P13()			AUXR1=AUXR1|((P1KBIH))	

#define KBI_SetKBI0123_P20P21P25P27()			AUXR1=AUXR1&(~(P3KBIL))		
#define KBI_SetKBI0123_P30P31P34P35()			AUXR1=AUXR1|((P3KBIL))	

// KBI 设置比较值
#define KBI0_1	0x01
#define KBI1_1	0x02
#define KBI2_1	0x04
#define KBI3_1	0x08
#define KBI4_1	0x10
#define KBI5_1	0x20
#define KBI6_1	0x40
#define KBI7_1	0x80
#define KBI0_0	0x00
#define KBI1_0	0x00
#define KBI2_0	0x00
#define KBI3_0	0x00
#define KBI4_0	0x00
#define KBI5_0	0x00
#define KBI6_0	0x00
#define KBI7_0	0x00
#define KBI_SetKBPattern(x)					KBPATN=x

// KBI 选择使能KBI通道
#define KBI0	0x01
#define KBI1	0x02
#define KBI2	0x04
#define KBI3	0x08
#define KBI4	0x10
#define KBI5	0x20
#define KBI6	0x40
#define KBI7	0x80
#define KBI_SetKBMask(x)					KBMASK=x

// KBI 选择等于比较值还不等于比较值
#define KBI_SetPatternNotEqual()			KBCON=KBCON&(~PATNS)
#define KBI_SetPatternEqual()				KBCON=KBCON|(PATNS)

/*
*************************************************************************************
*/ 


/*
*************************************************************************************
*  POWER 电源控制
*
*************************************************************************************
*/
#define POW_BOD1_Enable_OnPD		BIT7
#define POW_BOD1_Disable_OnPD		0x00

#define POW_BOD1_Set20V			0x00
#define POW_BOD1_Set24V			B00010000
#define POW_BOD1_Set37V			B00100000
#define POW_BOD1_Set42V			B00110000

#define POW_BOD1_Enable			BIT2
#define POW_BOD1_Disable		0x00

#define POW_BOD1_EnReset		BIT3
#define POW_BOD1_DisReset		0x00

#define POW_BOD0_EnReset		BIT1
#define POW_BOD0_DisReset		0x00

#define POW_SetMode_PD()			PCON0|=PD;
#define POW_SetMode_IDLE()			PCON0|=IDL;

#define POW_ResetToAP()			ISPCR=SRST
#define POW_ResetToISP()		ISPCR=BS|SRST

/*
*************************************************************************************
*/ 



#endif



