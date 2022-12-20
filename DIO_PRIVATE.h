/**********************************************************************************/
/*******************SWC: DIO_DRIVER ***********************************************/
/*******************BY: MOHAMED HUSSIEN *******************************************/
/*******************DATE: 27/8/2022 ***********************************************/
/*******************VERSION: V1.0 ************************************************/
/*********************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// portA
#define PORTA *((volatile u8 *)0x3B)
#define DDRA  *((volatile u8 *)0x3A)
#define PINA  *((volatile u8 *)0x39)
// portB

#define PORTB *((volatile u8 *)0x38)
#define DDRB  *((volatile u8 *)0x37)
#define PINB  *((volatile u8 *)0x36)
// portC

#define PORTC *((volatile u8 *)0x35)
#define DDRC  *((volatile u8 *)0x34)
#define PINC  *((volatile u8 *)0x33)
// portD

#define PORTD *((volatile u8 *)0x32)
#define DDRD  *((volatile u8 *)0x31)
#define PIND  *((volatile u8 *)0x30)


#endif