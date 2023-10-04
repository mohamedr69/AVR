/*
 * SPI_TEST.c
 *
 * Created: 04/10/2023 20:43:52
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
	SPI_MasterInit();

	
    while (1) 
    {
		_delay_ms(20);
		SPI_MasterTransmit('m');
		_delay_ms(20);
    }
}

