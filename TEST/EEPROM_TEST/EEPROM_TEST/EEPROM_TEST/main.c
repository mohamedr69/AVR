/*
 * EEPROM_TEST.c
 *
 * Created: 07/10/2023 02:09:32
 * Author : moham
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "EEPROM_interface.h"

#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{
    /* Replace with your application code */
	LCD_vidInit8Bit(GPIOD,GPIOC,PIN0,GPIOC,PIN1);

    while (1) 
    {
			EEPROM_voidWriteData(5,'M');
			u8 data = EEPROM_u8ReadData(5);
			LCD_vidWriteCharacter(GPIOD,GPIOC,PIN0,GPIOC,PIN1,data);
    }
}

