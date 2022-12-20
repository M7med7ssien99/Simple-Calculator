/**********************************************************************************/
/*******************SWC: LCD_DRIVER ***********************************************/
/*******************BY: MOHAMED HUSSIEN *******************************************/
/*******************DATE: 9/9/2022 ***********************************************/
/*******************VERSION: V1.0 ************************************************/
/*********************************************************************************/
#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_VidSendData(u8 copy_u8Data) ;
void LCD_VidSendCmd(u8  copy_u8Cmd) ;
void LCD_VidInit(void);
void LCD_VidSendInteger(u32 copy_u8Number);
void LCD_VidSendString(u8 *pcstring , u8 copy_u8X , u8 copy_u8Y);
void LCD_VidDisplayClear(void);
void LCD_VidGotoXY(u8 copy_u8X , u8 copy_u8Y);


#endif