#include "gpio.h"


/***********************************************************************************
函数名称:   void InitPort(void)
功能描述:   IO配置
输入参数:   
返回参数:     
*************************************************************************************/
void Init_Port(void)
{ 
    /* CLOSE/STOP/OPEN: P10/P11/P12; TP7: P13 TestMode */
    PORT_SetP1OpenDrain(BIT0|BIT1|BIT2|BIT3);           // 设置P13 为开漏输出
    PORT_SetP1PushPull(BIT0|BIT1|BIT2);                 // 设置P10,P11,P12 为推挽输出
    P13 = 1;                                            // P13设为输入模式
    PORT_EnP10P11P12P13PullHigh();                      // 使能 P10,P11,P12,P13 上拉
    
    /* SPI */
    PORT_SetP1PushPull(BIT4|BIT5|BIT7);					// 设置P15(MOSI),P17(SPICLK)为准双向口
	PORT_SetP1OpenDrain(BIT6);							// 设置P16(MISO)为准双向口
    P16 = 1;                                            // 输入
	PORT_EnP14P15P16P17PullHigh();						// 使能 P14,P15,P16,P17 上拉
    
    /*BEEP:P20; 登录:P21; 无线开关:T->P22,R->P23; 受信/动作/送信LED:P24/P25/P26; ML7345_RESETN:P27 */
	PORT_SetP2OpenDrain(BIT1);                          // 设置P21 为开漏输出
    P21 = 1;                                            // P21设为输入模式
    
#if (NEW_PCB==0)   
    PORT_SetP2PushPull(BIT0|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7); // 设置P20,P22,P23,P24,P25,P26,P27 为推挽输出
#else
    PORT_SetP2PushPull(BIT0|BIT2|BIT3|BIT5|BIT7);       // 设置P20,P22,P23,P25,P27 为推挽输出
    PORT_SetP2OpenDrain(BIT4);
    P24 = 1;
#endif
    
    PORT_EnP20P21P22P23PullHigh();                      // 使能 P20,P21,P22,P23 上拉
	PORT_EnP24P25P26P27PullHigh();			            // 使能 P24,P25,P26,P27 上拉
    P20 = 0;
    
#if (NEW_PCB==0)  
    PORT_SetP3InputOnly(BIT5);
#else
    PORT_SetP3PushPull(BIT4|BIT5);
#endif
 
    /* TP3/TP4: P40/P41 */
    PORT_SetP4OpenDrain(BIT0|BIT1);                     // 设置P40,P41 为开漏输出
    P40 = 1; P41 = 1;                                   // P40/p41 设为输入模式
    PORT_EnP40P41PullHigh();                            // 使能 P40,P41 上拉
    
    //////////////////////test/////////////////////////
    //PORT_SetP6PushPull(BIT0);   //CLK OUT
    //AUXR0 &= ~(P60OC0|P60OC1);
    //AUXR0 |= (0x80|P60FD);
    //////////////////////test/////////////////////////
    
    FG_allow_out = 1;
	FG_NOT_allow_out = 0;
    Receiver_LED_TX = 0;  
    Receiver_LED_RX = 0;  
    Receiver_LED_OUT = 0; 
    Receiver_OUT_OPEN = 0;
    Receiver_OUT_STOP = 0;
    Receiver_OUT_CLOSE = 0;
    ML7345_RESETN = 0;
}

 



/***********************************************************************************
函数名称:   void InitINT0(void)
功能描述:   INT0初始化
输入参数:   
返回参数:  
用于ML7345D 发送接收完成中断。
*************************************************************************************/
void Init_INT0(void)
{
	INT_SetINT0P32();						//设置INT0引脚P32
	INT_SetINT0_DetectFallingEdge();		//设置INT0外部中断检测方式为下降沿检测
	//INT_SetINT0_DetectRisingEdge();
    INT_SetINT0Filter_Sysclk_x3();			//设置INT0滤波为（sysclk）*3
}


/***********************************************************************************
函数名称:   void InitINT1(void)
功能描述:   INT1初始化
输入参数:   
返回参数:   
ML7345D BER测试。
*************************************************************************************/
#if (NEW_PCB==1)
void Init_INT1(void)
{
	INT_SetINT1P33();						//设置INT1引脚P33
	//INT_SetINT1_DetectRisingEdge();		
    INT_SetINT1_DetectFallingEdge();        //设置INT1外部中断检测方式为下降沿检测
	//INT_SetINT1Filter_Sysclk_x3();			//设置INT1滤波为（sysclk）*3
    INT_SetINT1Filter_Disable();
}
#endif

/***********************************************************************************
函数名称:   void INT_INT0(void)	
功能描述:INT0中断服务程序
输入参数:   
返回参数: 

用于ML7345D发送接收完成中断。

*************************************************************************************/
void INT_INT0(void)		interrupt INT_VECTOR_INT0
{
	if(Flag_test_mode == 0) ML7345_TRX_Del();
    else DataReceive();
}


/***********************************************************************************
函数名称:   void INT_INT1(void)	
功能描述:INT1中断服务程序
输入参数:   
返回参数:    

ML7345D BER测试。

*************************************************************************************/
void INT_INT1(void)		interrupt INT_VECTOR_INT1
{
	if(Flag_test_mode == 0) ML7345_TRX_Del();
    else DataReceive();
}


/***********************************************************************************
函数名称:   void InitInterrupt(void)
功能描述:   中断初始化
输入参数:    
返回参数:     
*************************************************************************************/
void Init_Interrupt(void)
{
#if (NEW_PCB==0)
    Init_INT0();
    INT_EnINT0();			//	使能INT0中断
#else
    Init_INT0();
	INT_EnINT0();			//	使能INT1中断
#endif
    INT_EnTIMER0();			//	使能T0中断
	INT_EnUART0();			//	使能串口中断
}


/*
u8 key_scan(void)
{
    if((Receiver_Login==0 | TP3==0 | TP4==0 | Receiver_test==0))
    {
        delay_ms(50);
        if((Receiver_Login==0 | TP3==0 | TP4==0 | Receiver_test==0) && key_flag == 0)
        {
            key_flag = 1;
            if(Receiver_Login==0) return 2;
            else if (Receiver_test==0) return 3;
            else return 1;
        }
        else return 0;
            
    }
    else if(Receiver_Login==1 && TP3==1 && TP4==1 && Receiver_test==1)
    {
        key_flag = 0;
        return 0;
    }
    return 0;    
}*/


