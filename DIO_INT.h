/**********************************************************************************/
///*******************SWC: DIO_DRIVER ***********************************************/
/*******************BY: MOHAMED HUSSIEN *******************************************/
/*******************DATE: 27/8/2022 ***********************************************/
/*******************VERSION: V1.0 ************************************************/
/*********************************************************************************/
#ifndef DIO_INT_H
#define DIO_INT_H
typedef enum 
{
	port_A ,	
	port_B ,
	port_C ,
	port_D 
}et_port ;

typedef enum 
{
	pin0 ,
	pin1 ,
	pin2 ,
	pin3 ,
	pin4 ,
	pin5 ,
	pin6 ,
	pin7 
}et_pin ;

typedef enum 
{
	Input ,
	Output 
}et_Direction ;

typedef enum 
{
	pinLow ,
	pinHigh
}et_Status ;

/*****************************************************************************************/

/*Setting pin directions*/
void DIO_VidSetPinDirections(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8direction);


/*Setting pin value*/
void DIO_VidSetPinValue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value);


/*Getting pin value*/
void DIO_VidGetPinvalue(u8 copy_u8port,u8 copy_u8pin, u8 *pu8Data);

/*****************************************************************************************/

/*Setting port directions*/
void DIO_VidSetportDirections(u8 copy_u8port , u8 copy_u8direction);


/*Setting port(PORT register) value*/
void DIO_VidSetportValue(u8 copy_u8port , u8 copy_u8value);


/*Getting port(PIN register) value*/
void DIO_VidGetportDirections(u8 copy_u8port ,  u8 *pu8Data);


#endif
