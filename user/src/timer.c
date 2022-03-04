#include "timer.h"

/* PCA定时器为16位,最大计数65536,*/
#if (MCU_SYSCLK == 16000000)
#define PCA_RELOAD		(5926)  //f = PCA_CLK/PCA_RELOAD,PWM输出频率2.7K,PCA时钟为SysClk 16MHz
#define Duty_Cycle      2963       //50%
#endif

#if (MCU_SYSCLK == 24000000)
#define PCA_RELOAD		(8888)  //f = PCA_CLK/PCA_RELOAD,PWM输出频率2.7K,PCA时钟为SysClk 24MHz
#define Duty_Cycle      4444       //50%
#endif

#define PCA_C           (65536)
#define PCA_CL(x)		(u8)((PCA_C-(x))%256) 
#define PCA_CH(x)     	(u8)((PCA_C-(x))/256)

      
//xdata u16 time_ms = 0;
idata u16 Time_Tx_Out = 0;

/***********************************************************************************
函数名称:   void InitTimer0(void)
功能描述:Timer0初始化设置
		 定义T0为16位定时器,时钟为Sysclk/12 
输入参数:   
返回参数:     
*************************************************************************************/
void Init_Timer0(void)
{
	TM_SetT0Mode_1_16BIT_TIMER();			// 设置T0模式为16位模式
    
    TM_SetT0Clock_SYSCLKDiv12();            // 设置T0时钟源为 SYSCLK/12.

	TM_SetT0Gate_Disable();	
		
    TM_SetT0LowByte(TIMER_12T_1ms_TL);		// 设置T0低8位
	TM_SetT0HighByte(TIMER_12T_1ms_TH);		// 设置T0高8位

	TM_EnableT0();							// 使能T0
}


/***********************************************************************************
函数名称:   void INT_T0(void)
功能描述:T0 中断服务程序
		 间隔1ms
输入参数:   
返回参数:     
*************************************************************************************/
void INT_T0(void) interrupt INT_VECTOR_T0
{
	TH0=TIMER_12T_1ms_TH;
	TL0=TIMER_12T_1ms_TL;
    
    if (TIMER1s)
        --TIMER1s;
	if(TIME_power_led)
		--TIME_power_led;
    if (TIMER300ms)
        --TIMER300ms;
    if (TIMER18ms)
        --TIMER18ms;
    if (TIMER250ms_STOP)
        --TIMER250ms_STOP;
    if (TIME_10ms)
        --TIME_10ms;
    else
    { // 10mS FLAG
        TIME_10ms = 10;
        FG_10ms = 1;
    }
    if (U1AckTimer)
        U1AckTimer--;
    if (Time_APP_RXstart)
      --Time_APP_RXstart;
    if(Time_APP_blank_TX)
       --Time_APP_blank_TX;
    if (X_ERRTimer)
        X_ERRTimer--;
	if (TIME_ID_SCX1801_Login)
		--TIME_ID_SCX1801_Login;

    if(Time_Tx_Out)  --Time_Tx_Out;
    if(Time_rf_init) --Time_rf_init;
}


//38K/14 = 2.7kHz;
void Init_PCA_PWM(void)
{
    PCA_SetCLOCK_SYSCLK();          // PCA时钟为SysClk
    PCA_CH6_SetMode_PWM();          // PWM模式
    PCA_CH6_SetPWM_16Bit();         //
    PCA_SetPWM_EdgeAligned();	    // 边沿对齐
    
    // 设置PWM占空比比较值
	PCA_CH6_SetValue(PCA_CH(Duty_Cycle),PCA_CL(Duty_Cycle));
    
    // 设置定时器计数值 PWM频率
	PCA_SetCounter(PCA_C-PCA_RELOAD);
	PCA_SetCounterReload(PCA_C-PCA_RELOAD);
}

void Init_Beep(void)
{
    Init_PCA_PWM();
}

void Beep_On(void)
{
    PCA_EnPCACounter();
}

void Beep_Off(void)
{
    PCA_DisPCACounter();
    P20 = 0;
}


/*************************************************
函数名称:     void DelayXus(u16 xUs)
功能描述:   	延时程序，单位为us
调用函数:        
输入参数:     u8 Us -> *1us  (1~255)
输出参数:     
*************************************************/
void DelayXus(u8 xUs)
{
	while(xUs!=0)
	{
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
        _nop_();
		_nop_();
		xUs--;
	}
}


/*************************************************
函数名称:     void DelayXms(u16 xMs)
功能描述:     延时程序，单位为ms
输入参数:     u16 xMs -> *1ms  (1~65535)
输出参数:     
*************************************************/

void delay_ms(u8 ms) //1约1.2ms
{
    while(ms--)
    {
        DelayXus(200);
        DelayXus(200);
        DelayXus(200);
        DelayXus(200);
    }
}