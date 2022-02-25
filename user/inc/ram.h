#ifndef __RAM_H__
#define __RAM_H__
//CPU?????
//?????ADF030???????
//#define TX_TEST_CARRIER_MODE 0
#include "Type.h" // 

#define ID_Max_PCS   255

#define RAM_LARGE 1

//#define DEF_test_MAX_32pcs
extern xdata u8 DEF_APP_TX_freq;



extern xdata uFLAG FLAG_test1;
//************************************************
#define FLAG_test1_BYTE FLAG_test1.BYTE
//------------------------------------------------
#define BIT_SIO FLAG_test1.BIT.Bit0
#define FG_auto_out FLAG_test1.BIT.Bit1
#define FG_OUT_OPEN_CLOSE FLAG_test1.BIT.Bit2 //锟斤拷史锟斤拷录   锟斤拷锟斤拷锟绞诧拷锟斤拷锟斤拷
#define FG_auto_open_time FLAG_test1.BIT.Bit4
#define FG_auto_manual_mode FLAG_test1.BIT.Bit5 //1=auto,0=manual
#define FG_Receiver_LED_RX FLAG_test1.BIT.Bit6
#define FG_First_auto FLAG_test1.BIT.Bit7
//************************************************
//************************************************
extern xdata volatile uFLAG FLAG_test;
#define FLAG_test_BYTE FLAG_test.BYTE
//------------------------------------------------
#define FLAG_Receiver_Scanning FLAG_test.BIT.Bit0
#define FG_test_tx_1010 FLAG_test.BIT.Bit1
#define X_HIS FLAG_test.BIT.Bit2 //鍘嗗彶璁板綍   �?鐮佺巼娴嬭瘯�?
#define FG_test_tx_on FLAG_test.BIT.Bit3
#define FG_test_tx_off FLAG_test.BIT.Bit4
#define FG_test_mode FLAG_test.BIT.Bit5
#define FG_test1 FLAG_test.BIT.Bit6
#define FG_test_rx FLAG_test.BIT.Bit7
//************************************************
//************************************************
extern xdata volatile uFLAG FLAG0;
#define FLAG0_BYTE FLAG0.BYTE
//------------------------------------------------
#define FLAG_Receiver_IDCheck FLAG0.BIT.Bit0
#define FLAG_Signal_DATA_OK FLAG0.BIT.Bit1
#define FLAG_APP_RX FLAG0.BIT.Bit2
#define FLAG_IDCheck_OK FLAG0.BIT.Bit3
#define FLAG_ID_Erase_Login FLAG0.BIT.Bit4
#define FLAG_ID_Erase_Login_PCS FLAG0.BIT.Bit5
#define FLAG_ID_Login FLAG0.BIT.Bit6
#define FLAG_ID_Login_OK FLAG0.BIT.Bit7
//************************************************
extern xdata volatile uFLAG FLAG1;
#define FLAG1_BYTE FLAG1.BYTE
//------------------------------------------------
#define FLAG_Receiver_BEEP FLAG1.BIT.Bit0
#define FLAG_ID_Login_EXIT FLAG1.BIT.Bit1
#define FLAG_ID_Login_OK_bank FLAG1.BIT.Bit2
#define FG_beep_on FLAG1.BIT.Bit3
#define FG_beep_off FLAG1.BIT.Bit4
#define FG_allow_out FLAG1.BIT.Bit5
#define FG_NOT_allow_out FLAG1.BIT.Bit6
#define FG_10ms FLAG1.BIT.Bit7
//************************************************
extern xdata volatile uFLAG FLAG2;
#define FLAG2_BYTE FLAG2.BYTE
//------------------------------------------------
#define FLAG_ID_SCX1801_Login FLAG2.BIT.Bit0   //用于与集中�?�信机�?�信的ID，只有一个ID
#define FG_ID_SCX1801_Login_BEEP FLAG2.BIT.Bit1
#define FLAG_APP_TX_fromUART FLAG2.BIT.Bit2
#define FLAG_APP_TX_fromOUT FLAG2.BIT.Bit3
#define FLAG_APP_TX FLAG2.BIT.Bit4
#define FLAG_APP_RXstart FLAG2.BIT.Bit5
#define FLAG_APP_TX_once FLAG2.BIT.Bit6
#define FLAG_Key_TP3 FLAG2.BIT.Bit7

//************************************************
extern xdata volatile uFLAG FLAG3;
#define FLAG3_BYTE FLAG3.BYTE
//------------------------------------------------
#define Flag_ERROR_Read FLAG3.BIT.Bit0
//#define  FLAG3.BIT.Bit1
#define Flag_shutter_stopping FLAG3.BIT.Bit2
#define FLAG_APP_TX_fromUART_err_read FLAG3.BIT.Bit3
//#define  FLAG3.BIT.Bit4
//#define  FLAG3.BIT.Bit5
//#define  FLAG3.BIT.Bit6
//#define  FLAG3.BIT.Bit7

//************************************************


extern xdata u16 X_COUNT;
extern xdata u16 X_ERR; //记录错误的个�?
extern xdata u8  X_ERR_CNT;
extern xdata u16 X_ERRTimer;

extern xdata u8 SIO_cnt;
extern xdata u8 SIO_buff[16];
extern xdata u8 SIO_DATA[16];
extern xdata u8 Tx_Rx_mode;

extern idata u8 TIME_10ms;
extern xdata u16 TIMER1s;
extern xdata u16 TIMER300ms;
extern idata u16 TIMER18ms;
extern xdata u16 TIMER250ms_STOP;
extern xdata u16 TIME_auto_out;
extern xdata u16 TIME_auto_close;
extern xdata u16 time_3sec;

#if RAM_LARGE == 1
extern xdata u8 ID_Receiver_DATA[768]; //ID
#else
extern xdata u32 ID_Receiver_DATA[100]; //ID
#endif

extern xdata u32 ID_SCX1801_DATA;
extern xdata u16 ID_DATA_PCS;
extern xdata u32 DATA_Packet_ID;
extern xdata u8 DATA_Packet_Control;
extern xdata u8 DATA_Packet_Contro_buf; //2015.3.24�?�?
extern xdata u32 ID_Receiver_Login;

extern xdata u16 INquiry;
extern xdata u16 TIME_Receiver_Login_restrict;
extern xdata u8 COUNT_Receiver_Login;
extern xdata u16 TIME_Receiver_Login;
extern xdata u16 TIME_Login_EXIT_rest;
extern xdata u16 TIME_Receiver_Login_led;
extern xdata u16 TIME_ID_SCX1801_Login ;


extern xdata u8 TIME_OUT_OPEN_CLOSE;
extern xdata u16 TIME_Receiver_LED_OUT;
extern xdata u16 TIME_Login_EXIT_Button;
extern xdata u16 Manual_override_TIMER;
extern xdata u16 time_Login_exit_256;

extern xdata u16 TIME_TestNo91;
extern xdata u16 TIME_power_led;
extern xdata u8 write_flash_buffer[8];



/**********RSSI*********************/
extern xdata short RAM_RSSI_AVG;
extern xdata long RAM_RSSI_SUM;
extern xdata u8 RSSI_Read_Counter;

#define SPI_REV_BUFF_LONG 40

extern idata u8 CONST_TXPACKET_DATA_20000AF0[28];

extern xdata u32 PROFILE_CH_FREQ_32bit_200002EC;
//extern xdata const u32 PROFILE_CH1_FREQ_32bit_429HighSpeed;
//extern xdata const u32 PROFILE_CH2_FREQ_32bit_429HighSpeed;
extern idata u8 Channels;

void SCAN_RECEIVE_PACKET(void);
u32 ConfigurationLen(void);

extern xdata Wireless_Body Struct_DATA_Packet_Contro,Struct_DATA_Packet_Contro_buf;
extern xdata Wireless_Body Uart_Struct_DATA_Packet_Contro,Last_Uart_Struct_DATA_Packet_Contro;
extern xdata u8 Struct_DATA_Packet_Contro_fno;
extern xdata u16 TIMER_Semi_open;
extern xdata u16 TIMER_Semi_close;
extern xdata u8 FLAG__Semi_open_T;
extern xdata u8 FLAG__Semi_close_T;
extern xdata u16 TIME_APP_TX_fromOUT;
extern xdata u8 Time_APP_blank_TX;
extern xdata u8 Time_APP_RXstart;

extern bit Flag_TX_ID_load;
extern xdata u8 TIME_ERROR_Read_once_again;
extern xdata unsigned char Send_err_com[7] ;
extern xdata u8 Time_error_read_gap;
extern xdata u16 Time_error_read_timeout;
extern xdata u8 ERROR_Read_sendTX_count;
extern xdata u8 ERROR_Read_sendTX_packet;
extern xdata u8 Flag_ERROR_Read_once_again;
extern xdata u16 Time_rf_init;
extern xdata u8 retx_cnt;

//-----------------------------------------------------------------------------------------------

typedef union
{
    u8 un_var;
    struct
    {
        u8 un_var_bit0 : 1;
        u8 un_var_bit1 : 1;
        u8 un_var_bit2 : 1;
        u8 un_var_bit3 : 1;
        u8 un_var_bit4 : 1;
        u8 un_var_bit5 : 1;
        u8 un_var_bit6 : 1;
        u8 un_var_bit7 : 1;
    }Flag;
}Mark_Un;

extern idata Mark_Un mark0_stu;

#define key_sta     mark0_stu.Flag.un_var_bit0
#define Key1_press  1
#define Key2_press  2
#define Key3_press  3
#define Flag_FREQ_Scan   mark0_stu.Flag.un_var_bit1
#define Flag_rx_pream    mark0_stu.Flag.un_var_bit2
#define Flag_set_freq    mark0_stu.Flag.un_var_bit3
#define Flag_rx_data     mark0_stu.Flag.un_var_bit4
#define Flag_tx_en       mark0_stu.Flag.un_var_bit5
#define Flag_TxDone      mark0_stu.Flag.un_var_bit6
#define Flag_RxDone      mark0_stu.Flag.un_var_bit7

extern idata Mark_Un mark1_stu;
#define Flag_test_mode   mark1_stu.Flag.un_var_bit0
#define Flag_test_fm     mark1_stu.Flag.un_var_bit1
#define Flag_test_rssi   mark1_stu.Flag.un_var_bit2
#define Flag_test_pc     mark1_stu.Flag.un_var_bit3
#define key_flag         mark1_stu.Flag.un_var_bit4   


#endif
