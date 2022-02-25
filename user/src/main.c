/*********************************************************************
    项目名称:MA82G5Bxx-DEMO
			测试板使用 MA82G5B32	LQFP32_V10 EV Board (TH156A)
			CpuCLK=12MHz, SysCLK=12MHz
	功能描述：

	注意事项：

    建立时间:
    修改日志:
    
*********************************************************************/
#include "gpio.h" 
#include "timer.h"
#include "uart.h"
#include "IAP_flash.h"
#include "spi.h"  
#include "ML7345.h"
#include "ID_Decode.h"


void main()
{
    Init_WDT();    
    Init_Clock();
    ClearWDT();
    Init_IAP_flash();
    eeprom_sys_load();
    Init_Port();
	Init_Timer0(); 
    Init_Uart0_T1_ODD();       
    Init_Beep();
    Init_Spi();  
    ClearWDT();
    PROFILE_CH_FREQ_32bit_200002EC = 426075000;
    RF_ML7345_Init(Fre_426_075,0x15,12);    //约10ms
    TIME_power_led = 500;
    ClearWDT();
    Init_Interrupt();
    INT_EnAll();  // 使能全局中断
    ML7345D_RF_test_mode();
    FLAG_APP_RX = 1;
    FG_Receiver_LED_RX = 0;
    FLAG_testNo91=0;
	FLAG_testBEEP=0; 
    ML7345_SetAndGet_State(RX_ON);
    CG2214M6_USE_R;

    while(1) 
    {
        ClearWDT(); // Service the WDT
        if(FLAG_testBEEP != 0)    TEST_beep();
        
        if (time_Login_exit_256 == 0)
            ID_Decode_OUT();
        ID_learn();
        if(ID_SCX1801_DATA != 0)  APP_TX_PACKET();
        if(FLAG_APP_RX == 1)
        {
    		  ML7345D_Freq_Scanning();
			  SCAN_RECEIVE_PACKET(); 
        }
        TranmissionACK();
        if (FG_Receiver_LED_RX == 1)
            Receiver_LED_RX = 1;
        else if (FG_Receiver_LED_RX == 0)
            Receiver_LED_RX = 0;
    }
}


