#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "avr/interrupt.h"

void (* CBINT0)(void);
void (* CBINT1)(void);
void (* CBINT2)(void);
void EXTI_voidInit(_enuEXTIx enuEXTIx,_enuEXTICONTROL enuEXTICONTROL){
	SET_BIT(SREG,GIE);
	switch(enuEXTIx){
		case INT0_DIO:	DIO_vidSetPinMode(GPIOD,PIN2,Output);
					if(enuEXTICONTROL == LOW_LEVEL){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							CLR_BIT(MCUCR,ISC00);
							CLR_BIT(MCUCR,ISC01);
							/*Enable INT 0*/
							SET_BIT(GICR,INT0);
						
					}else if(enuEXTICONTROL == LOGICAL_CHANGE){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							SET_BIT(MCUCR,ISC00);
							CLR_BIT(MCUCR,ISC01);
							/*Enable INT 0*/
							SET_BIT(GICR,INT0);
						
					}else if(enuEXTICONTROL == RISING_EDGE){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							SET_BIT(MCUCR,ISC00);
							SET_BIT(MCUCR,ISC01);
							/*Enable INT 0*/
							SET_BIT(GICR,INT0);
						
					}else if(enuEXTICONTROL == FALLING_EDGE){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							CLR_BIT(MCUCR,ISC00);
							SET_BIT(MCUCR,ISC01);
							/*Enable INT 0*/
							SET_BIT(GICR,INT0);
						
					}else{
						/*ERROR*/
					}break;
		case INT1_DIO:	DIO_vidSetPinMode(GPIOD,PIN3,Output);
						if(enuEXTICONTROL == LOW_LEVEL){
							/* Interrupt Sense Control 1 Bit 1 and Bit 0*/
							CLR_BIT(MCUCR,ISC10);
							CLR_BIT(MCUCR,ISC11);
							/*Enable INT 1*/
							SET_BIT(GICR,INT1);
						
					}else if(enuEXTICONTROL == LOGICAL_CHANGE){
							/* Interrupt Sense Control 1 Bit 1 and Bit 0*/
							SET_BIT(MCUCR,ISC10);
							CLR_BIT(MCUCR,ISC11);
							/*Enable INT 1*/
							SET_BIT(GICR,INT1);
						
					}else if(enuEXTICONTROL == RISING_EDGE){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							SET_BIT(MCUCR,ISC10);
							SET_BIT(MCUCR,ISC11);
							/*Enable INT 1*/
							SET_BIT(GICR,INT1);
						
					}else if(enuEXTICONTROL == FALLING_EDGE){
							/* Interrupt Sense Control 0 Bit 1 and Bit 0*/
							CLR_BIT(MCUCR,ISC10);
							SET_BIT(MCUCR,ISC11);
							/*Enable INT 1*/
							SET_BIT(GICR,INT1);
						
					}else{
						/*ERROR*/
					}break;
		case INT2_DIO:DIO_vidSetPinMode(GPIOB,PIN2,Output);
						if(enuEXTICONTROL == FALLING_EDGE){
							/* Interrupt Sense Control 2 Bit 1 and Bit 0*/
							CLR_BIT(MCUCSR,ISC2);
							/*Enable INT 2*/
							SET_BIT(GICR,INT2);
						
					}else if(enuEXTICONTROL == RISING_EDGE){
							/* Interrupt Sense Control 2 Bit 1 and Bit 0*/
							SET_BIT(MCUCSR,ISC2);
							/*Enable INT 2*/
							SET_BIT(GICR,INT2);
					}else{
						/*ERROR*/
					}break;
		default: /*ERROR*/ break;
		
		
	}
	
}
void EXTI_voidSetCallBack(_enuEXTIx enuEXTIx,void (* INT_CB)(void)){
	switch(enuEXTIx){
		case INT0_DIO: 	CBINT0 = INT_CB;break;
		case INT1_DIO: 	CBINT1 = INT_CB;break;
		case INT2_DIO:	CBINT2 = INT_CB;break;
		default: /*ERROR*/ break;
	}
}
ISR(INT0_vect){
	(*CBINT0)();
	
}
ISR(INT1_vect){
	(*CBINT1)();
	
}
ISR(INT2_vect){
	(*CBINT2)();
	
}