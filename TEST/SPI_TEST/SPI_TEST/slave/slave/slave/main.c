/*
 * slave.c
 *
 * Created: 04/10/2023 20:48:16
 * Author : moham
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "SPI_interface.h"

#define F_CPU 8000000
#include "util/delay.h"
int main(void)
{
    /* Replace with your application code */
	SPI_SlaveInit();
	LCD_vidInit8Bit(GPIOD,GPIOC,PIN0,GPIOC,PIN1);
    while (1) 
    {
		_delay_ms(20);
		u8 data = SPI_SlaveReceive();
		LCD_vidWriteCharacter(GPIOD,GPIOC,PIN0,GPIOC,PIN1,data);
		_delay_ms(20);
		
    }
}

