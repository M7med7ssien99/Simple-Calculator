#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_INT.h"
#include "LCD_CONFIG.h"
#include "LCD_INT.h"
#include <util/delay.h>



void LCD_VidSendData(u8  copy_u8Data)
{
DIO_VidSetPinValue(CONTROL_PORT , RS_PIN ,pinHigh) ;	
DIO_VidSetPinValue(CONTROL_PORT , RW_PIN ,pinLow) ;	
DIO_VidSetportValue(DATA_PORT , copy_u8Data ) ;
DIO_VidSetPinValue(CONTROL_PORT , E_PIN ,pinHigh) ;	
_delay_ms(3);
DIO_VidSetPinValue(CONTROL_PORT , E_PIN ,pinLow) ;	
		
}



void LCD_VidSendCmd(u8  copy_u8Cmd)
{
DIO_VidSetPinValue(CONTROL_PORT , RS_PIN ,pinLow) ;	
DIO_VidSetPinValue(CONTROL_PORT , RW_PIN ,pinLow) ;	
DIO_VidSetportValue(DATA_PORT , copy_u8Cmd ) ;
DIO_VidSetPinValue(CONTROL_PORT , E_PIN ,pinHigh) ;	
_delay_ms(3);
DIO_VidSetPinValue(CONTROL_PORT , E_PIN ,pinLow) ;	
		
}



void LCD_VidInit(void)
{
_delay_ms(40);
LCD_VidSendCmd(0b00111100);
LCD_VidSendCmd(0b00001100);
LCD_VidSendCmd(1);

}



void LCD_VidDisplayClear(void)
{
LCD_VidSendCmd(1);
}


void LCD_VidSendInteger(u32 copy_u8Number)
{
	if(copy_u8Number != 0)
	{
		LCD_VidSendInteger( copy_u8Number / 10 );
		LCD_VidSendData(( copy_u8Number % 10) + 48 );
	}
}

void LCD_VidSendString(u8 *pcstring , u8 copy_u8X , u8 copy_u8Y)
{
  u8 i;
  LCD_VidGotoXY( copy_u8X ,  copy_u8Y);
  while(pcstring[i] != '\0')
  {
	  LCD_VidSendData(pcstring[i]);
	  i++;
  }
}


void LCD_VidGotoXY(u8 copy_u8X , u8 copy_u8Y)
{
	if (copy_u8X==1)
	{
	   copy_u8Y	+= 0x40 ;
	}
	LCD_VidSendCmd( copy_u8Y +0b10000000 );
	
}

void LCD_VidSendSpecial(u8 *pattern , u8 pattern_num , u8 copy_u8X , u8 copy_u8Y)
{
		u8 Local_Address = 8 * pattern_num ;
		LCD_VidSendCmd( 0b01000000 + Local_Address  );
		for(u8 i=0 ; i<8 ; i++)
		{
		 LCD_VidSendData(pattern[i]);	
		}
		LCD_VidGotoXY(copy_u8X , copy_u8Y);
		LCD_VidSendData(pattern_num);	

}


















