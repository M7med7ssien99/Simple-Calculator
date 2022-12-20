/**********************************************************************************/
/*******************SWC: DIO_DRIVER ***********************************************/
/*******************BY: MOHAMED HUSSIEN *******************************************/
/*******************DATE: 27/8/2022 ***********************************************/
/*******************VERSION: V1.0 ************************************************/
/*********************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_INT.h"
#include"DIO_PRIVATE.h"



/*Setting pin directions*/
void DIO_VidSetPinDirections(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction)
{

	if(copy_u8direction == Input)	
	{
		switch(copy_u8port)	
		{
			case port_A : CLEAR_BIT(DDRA , copy_u8pin);break;				
			case port_B : CLEAR_BIT(DDRB , copy_u8pin);break;					
			case port_C : CLEAR_BIT(DDRC , copy_u8pin);break;				
			case port_D : CLEAR_BIT(DDRD , copy_u8pin);break;				 
		}
	 
	}
	else if (copy_u8direction==Output)
	{
		switch(copy_u8port)	
		{
			case port_A : SET_BIT(DDRA , copy_u8pin);break;
			case port_B : SET_BIT(DDRB , copy_u8pin);break;					
			case port_C : SET_BIT(DDRC , copy_u8pin);break;					
			case port_D : SET_BIT(DDRD , copy_u8pin);break;				
		}			
	}
	
}





/*Setting pin value*/
void DIO_VidSetPinValue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value)
{
	
	if(copy_u8value==pinHigh)	
	{
		
		switch(copy_u8port)	
		{
			case port_A : SET_BIT(PORTA , copy_u8pin);break;				
			case port_B : SET_BIT(PORTB , copy_u8pin);break;					
			case port_C : SET_BIT(PORTC , copy_u8pin);break;					
			case port_D : SET_BIT(PORTD , copy_u8pin);break;				
		}
	 
	}
	else if (copy_u8value==pinLow)
	{
		switch(copy_u8port)	
		{
			case port_A : CLEAR_BIT(PORTA , copy_u8pin);break;				
			case port_B : CLEAR_BIT(PORTB , copy_u8pin);break;					
			case port_C : CLEAR_BIT(PORTC , copy_u8pin);break;					
			case port_D : CLEAR_BIT(PORTD , copy_u8pin);break;				
		}
	}
	
}






/*Getting pin value*/
void DIO_VidGetPinvalue(u8 copy_u8port,u8 copy_u8pin, u8 *pu8Data)
{
	switch(copy_u8port)
	{
		case port_A : *pu8Data=GET_BIT(PINA , copy_u8pin);break;			
		case port_B : *pu8Data=GET_BIT(PINB , copy_u8pin);break;				
		case port_C : *pu8Data=GET_BIT(PINC , copy_u8pin);break;				
		case port_D : *pu8Data=GET_BIT(PIND , copy_u8pin);break;
	
	}
	
}



/*Setting port directions*/
void DIO_VidSetportDirections(u8 copy_u8port , u8 copy_u8direction)
{
	if(copy_u8direction == Output)	
	{
		switch(copy_u8port)	
		{
			case port_A : DDRA = 0b11111111 ;break;
			case port_B : DDRB = 0b11111111 ;break;
			case port_C : DDRC = 0b11111111 ;break;
			case port_D : DDRD = 0b11111111 ;break;
		}
	}
	else if (copy_u8direction==Input)
	{
		switch(copy_u8port)	
		{
			case port_A : DDRA = 0b00000000 ;break;				
			case port_B : DDRB = 0b00000000 ;break;					
			case port_C : DDRC = 0b00000000 ;break;				
			case port_D : DDRD = 0b00000000 ;break;
		}							
	}
		
		
}


/*Setting port(PORT register) value*/
void DIO_VidSetportValue(u8 copy_u8port , u8 copy_u8value)
{
	
		switch(copy_u8port)	
		{
			case port_A : PORTA = copy_u8value ;break;				
			case port_B : PORTB = copy_u8value ;break;					
			case port_C : PORTC = copy_u8value ;break;			
			case port_D : PORTD = copy_u8value ;break;				 
		}
	 
	
		
}





/*Getting port(PIN register) value*/
void DIO_VidGetportValue(u8 copy_u8port , u8 *pu8value)
{
switch(copy_u8port)	
		{
			case port_A : *pu8value = PINA;break;				
			case port_B : *pu8value = PINB;break;					
			case port_C : *pu8value = PINB;break;			
			case port_D : *pu8value = PINB;break;				 
		}
}
