/*
 * EXTI_TEST.c
 *
 * Created: 07/10/2023 03:09:05
 * Author : moham
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TIMR0_interface.h"
#include "util/delay.h"
void LED_ON(void);
int main(void)
{
	DIO_vidSetPinMode(GPIOD,PIN1,Output);
	DIO_vidSetPinValue(GPIOD,PIN1,Low);
	EXTI_voidInit(INT0_DIO,RISING_EDGE);
	 void (*ptr)() = &LED_ON;
	EXTI_voidSetCallBack(INT0_DIO,ptr );
    while (1) 
    {
		
    }
}
void LED_ON(void){
	DIO_vidSetPinValue(GPIOD,PIN1,High);
}

