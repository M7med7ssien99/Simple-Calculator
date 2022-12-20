#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "KPD_INT.h"
#include "LCD_INT.h"
#include "KPD_CONFIG.h"
#include <util/delay.h>

u8 Kpd_VidGetPressedKey(void)
{
u8 KPD_ARR[4][4] = {{ '1'  , '2' , '3' , 'C'},
                    { '4'  , '5' , '6' , '='},
                    { '7'  , '8' ,'9'  , '0'},
                    { '+'  , '-' ,'*'  , '/'}};
					
	u8 Loc_u8PressedKey ;
	u8 Data ;
	u8 Column_Arr[4] = {pin0 , pin1 , pin2 , pin3 };
	u8 Row_Arr[4]    = {pin0 , pin1 , pin2 , pin3 };
		for(u8 col = 0 ; col<4 ; col++ )
		{
			DIO_VidSetPinValue(KPD_COL_PORT , Column_Arr[col] , pinLow ) ;
			for(u8 Row = 0 ; Row<4 ; Row++ )
			{
				DIO_VidGetPinvalue(KPD_ROW_PORT , Row_Arr[Row] , &Data ) ;
				if(Data==0)
				{
					 
					Loc_u8PressedKey = KPD_ARR[Row][col] ;
					while(Data==0)
					{
						DIO_VidGetPinvalue(KPD_ROW_PORT , Row_Arr[Row] , &Data ) ;
					}
					return Loc_u8PressedKey ;

				}	
			}
			DIO_VidSetPinValue(KPD_COL_PORT, Column_Arr[col],pinHigh);
		}
		return 101;
}


u32 U32VidKpdconvertToInt(u8 *pu8number, u8 size)
{
	u32 value=0 , num , i;
		for( i=0 ; i<size ;i++ )
		{
			num=pu8number[i]-48;
			value=value*10+num;
		}
		return value;
}
