#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
//#include <stdbool.h> /* For true/false definition                      */
//#include "initial.h"		// ?????  ?????
#include "Type.h"
#include "ram.h"

idata Mark_Un mark0_stu = {0};
idata Mark_Un mark1_stu = {0};

xdata u8 DEF_APP_TX_freq = 3;

xdata uFLAG FLAG_test1 = {0};
xdata volatile uFLAG FLAG0 = {0};
xdata volatile uFLAG FLAG1 = {0};
xdata volatile uFLAG FLAG_test = {0};
xdata volatile uFLAG FLAG2 = {0};
xdata volatile uFLAG FLAG3 = {0};

idata u8 CONST_TXPACKET_DATA_20000AF0[28] = {
	0X95, 0X55, 0X55, 0X55,
	0X55, 0X55, 0X56, 0X55,
	0X95, 0X55, 0X56, 0X55,
	0X95, 0X55, 0X55, 0X55,
	0X95, 0X55, 0X55, 0X55,
	0X95, 0X55, 0X55, 0X55,
	0X95, 0X55, 0X55, 0X55};


xdata u16 X_COUNT = 0;
xdata u16 X_ERR = 0; //记录错误的个�?
xdata u8 X_ERR_CNT = 0;
xdata u16 X_ERRTimer = 0;

xdata u8 SIO_cnt = 0;
xdata u8 SIO_buff[16] = {0};
xdata u8 SIO_DATA[16] = {0};
xdata u8 Tx_Rx_mode = 0;
xdata u16 Time_rf_init = 0;

idata u8 TIME_10ms = 0;
xdata u16 TIMER1s = 0;
xdata u16 TIMER300ms = 0;
idata u16 TIMER18ms = 0;
xdata u16 TIMER250ms_STOP = 0;
xdata u16 TIME_auto_out = 0;
xdata u16 TIME_auto_close = 0;

#if RAM_LARGE == 1
xdata u8 ID_Receiver_DATA[768] = {0};
#else
xdata u32 ID_Receiver_DATA[100] = {0};
#endif

xdata u32 ID_SCX1801_DATA = 0;
xdata u16 ID_DATA_PCS = 0;
xdata u32 DATA_Packet_ID = 0;
xdata u8 DATA_Packet_Control = 0;
xdata u8 DATA_Packet_Contro_buf = 0; //2015.3.24修正
xdata u32 ID_Receiver_Login = 0;

xdata u16 TIME_Receiver_Login_restrict = 0;
xdata u8 COUNT_Receiver_Login = 0;
xdata u16 TIME_Receiver_Login = 0;
xdata u16 TIME_Login_EXIT_rest = 0;
xdata u16 TIME_Receiver_Login_led = 0;
xdata u16 TIME_ID_SCX1801_Login = 0;


xdata u8 TIME_OUT_OPEN_CLOSE = 0;
xdata u16 TIME_Receiver_LED_OUT = 0;
xdata u16 TIME_Login_EXIT_Button = 0;
xdata u16 Manual_override_TIMER = 0;
xdata u16 time_Login_exit_256 = 0;

xdata u16 TIME_TestNo91 = 0;
xdata u16 TIME_power_led = 0;


///**********RSSI*********************/
xdata short RAM_RSSI_AVG = 0;
xdata long RAM_RSSI_SUM = 0;
xdata u8 RSSI_Read_Counter = 0;


xdata u32 PROFILE_CH_FREQ_32bit_200002EC = 426075000ul;
//xdata const u32 PROFILE_CH1_FREQ_32bit_429HighSpeed=429350000;//429350000;//429225000;
//xdata const u32 PROFILE_CH2_FREQ_32bit_429HighSpeed=429550000;//429550000;//429237500;
idata u8 Channels = 1;


xdata Wireless_Body Struct_DATA_Packet_Contro = {0},Struct_DATA_Packet_Contro_buf = {0};
xdata Wireless_Body Uart_Struct_DATA_Packet_Contro = {0},Last_Uart_Struct_DATA_Packet_Contro = {0};
xdata u8 Struct_DATA_Packet_Contro_fno=0;
xdata u16 TIMER_Semi_open = 0;
xdata u16 TIMER_Semi_close = 0;
xdata u8 FLAG__Semi_open_T = 0;
xdata u8 FLAG__Semi_close_T = 0;
xdata u16 TIME_APP_TX_fromOUT = 0;
xdata u8 Time_APP_blank_TX = 0;
xdata u8 Time_APP_RXstart = 0;
bit Flag_TX_ID_load = 0;

xdata u8 TIME_ERROR_Read_once_again = 0;
xdata unsigned char Send_err_com[7] = {0x02, 0x07, 0x11,0x98,0x09,0x52,0x46};
xdata u8 Time_error_read_gap = 0;
xdata u16 Time_error_read_timeout = 0;
xdata u8 ERROR_Read_sendTX_count = 0;
xdata u8 ERROR_Read_sendTX_packet = 0;
xdata u8 Flag_ERROR_Read_once_again = 0;
xdata u8 write_flash_buffer[8] = {0};
xdata u8 retx_cnt = 0;

