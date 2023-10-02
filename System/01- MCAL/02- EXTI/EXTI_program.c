
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#include "avr/interrupt.h"

void (* Global_CBINT0)(void);
void (* Global_CBINT1)(void);
void (* Global_CBINT2)(void);
#define F_CPU 8000000UL
#include "util/delay.h"

void EXTI_vidInit(INTx INT,INTmode mode){
	SET_BIT(SREG, GI);
	switch (INT)
	{
		case INT_0: 
				DIO_vidSetPinMode(GPIOD,PIN2,Input);
				if(mode == LOW_LEVEL){
					CLR_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
				}else if(mode == FALLING_EDGE){
					CLR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				}else if (mode == RISING_EDGE){
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				}else{
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);	
				}
				SET_BIT(GICR,INT0);break;
		case INT_1: 
				DIO_vidSetPinMode(GPIOD,PIN3,Input);
				if(mode == LOW_LEVEL){
					CLR_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
				}else if(mode == FALLING_EDGE){
					CLR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				}else if (mode == RISING_EDGE){
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				}else{
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);	
				}
				SET_BIT(GICR,INT1);break;
		case INT_2: 
				DIO_vidSetPinMode(GPIOB,PIN2,Input);
				if(mode == FALLING_EDGE){
					CLR_BIT(MCUCSR,ISC2);
				}else if(mode == RISING_EDGE){
					SET_BIT(MCUCSR,ISC2);
				}
				SET_BIT(GICR,INT2);break;
		default:break;
	}
}
void EXTI_vidSetCB(INTx INT, void (*INT_CB)(void)){
	switch(INT)
    { 
        case INT_0:
            Global_CBINT0 = INT_CB;

            break;
        case INT_1:
            Global_CBINT1 = INT_CB;
            break;
        case INT_2:
            Global_CBINT2 = INT_CB;
            break;
        default:
            break;
    }
}
ISR(INT0_vect)
{
	(*Global_CBINT0)();
}

ISR(INT1_vect)
{
	(*Global_CBINT1)();
}

ISR(INT2_vect)
{
	(*Global_CBINT2)();
}