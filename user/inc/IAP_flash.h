#ifndef __IAP_FLASH__
#define __IAP_FLASH__

#include "REG_MA82G5Bxx.H"
#include "Type.h"
#include "API_Macro_MA82G5Bxx.H"
#include "API_Uart_BRGRL_MA82G5Bxx.H"
#include <Intrins.h> 
#include <Absacc.h>
#include "ID_Decode.h"
#include "ram.h"
#include "uart.h"
#include "Type.h"

/* 

IAP Flash空间: 1024Byte -> 0x7C00 ~ 0x7FFF.
255个ID: 255 * 3 = 765byte -> 0x7C00 ~ 0x7EFC; 普通ID
Addr_rf_offset -> 0x7FFA; 射频偏移量
ID_SCX1801_DATA -> 0x7FFB ~ 0x7FFD; 通信ID
ID_DATA_PCS -> 0x7FFE ~ 0X7FFF. ID数量

*/

#define ISP_ADDRESS     0x7A00	 //ISP起始地址 
#define IAP_ADDRESS     0x7C00	 //IAP起始地址
#define ERR_CNT_MAX     3 		 // 错误重试计数最大值

#define addr_eeprom_sys IAP_ADDRESS
#define Addr_rf_offset 0x3FA

// 可以使用MOVC的方式读取IAP的数据
#define	IAP_ReadByteByMOVC(x)	CBYTE[x]


void Init_IAP_flash(void);
u8 IAP_ReadPPage(u8 PsfrAddr);
void IAP_WritePPage(u8 PsfrAddr,u8 PsfrData);
void IAP_ErasePage(u8 ByteAddr);
u8 IAP_WriteBuf_With_Protect_Verify(u16 ByteAddr,u8 *pBuf,u16 Cnt);
void ID_EEPROM_write(void);
void ID_learn(void);
void eeprom_sys_load(void);
void ID_Login_EXIT_Initial(void);
void ALL_ID_EEPROM_Erase(void);
void ID_SCX1801_EEPROM_write(u32 id);
void Delete_GeneralID_EEPROM(u32 id);
void IAP_Erase_All_ID(void);
void IAP_Write_Byte(u16 Addr, u8 wdata);

#endif
