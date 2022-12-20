/*
 * main.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Wahba
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO_int.h"
#include "LCD_INT.h"
#include "KPD_INT.h"
#include "util/delay.h"
int main()
{
	DIO_VidSetportDirections(port_A , Output);
	DIO_VidSetportDirections(port_B , Output);
	DIO_VidSetportDirections(port_C , Input);
	DIO_VidSetportValue(port_C , 0b11111111);
	DIO_VidSetportDirections(port_D , Output);
	LCD_VidInit();


	u8 num1[6],num2[6];
	u8 z , i=0 , j , op1 , op2 ;
	u32 number1 = 0, number2 = 0 , result ;
	u32 value=0 , num ,number ;
	while(1)
	{

			 u8 z = Kpd_VidGetPressedKey();
			if((z!=101) && (z!='+') && (z!='-') && (z!='*') && (z!='/') && (z!='='))
			{
				LCD_VidSendData(z);
				num1[i]=z;
				num= num1[i] - 48;
				number1= (number1*10) + num ;
				i++;
			}
			else if(z=101)
			{
				LCD_VidSendData(z);
				break;
			}

		}
		  op1=z;



		while(1)
		{
				z = Kpd_VidGetPressedKey();
				if((z!=101) && (z!='+') && (z!='-') && (z!='*') && (z!='/') &&  (z!='=')){
				LCD_VidSendData(z);
				num2[j]=z;
				number= num2[i] - 48;
				number2= (number2*10) + number ;
				j++;
			}
			else if(z=101)
			{
				LCD_VidSendData(z);
				break;
			}
		}
			op2=z;

			if(op1 == 'C' || op2 == 'C'  )
				{
					LCD_VidDisplayClear();
				}
				switch(op1)
				{
					case '+':
								result=number1+number2;
								break;
					case '-':
								result=number1-number2;
								break;
					case '/':
								result=number1/number2;
								break;

					case '*':
								result=number1*number2;
								break;
					case '=':
								result=number1;
								break;
				}

				 if(op1 == '=' || op2 == '='  )
					{
						LCD_VidSendInteger(result);
					}
					u8 x = Kpd_VidGetPressedKey();
					if(x!= 101 && x == 'C')
					{
						LCD_VidDisplayClear();
					}

}












