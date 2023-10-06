/*
 * CAN_reciever.c
 *
 * Created: 06/10/2023 16:23:33
 * Author : moham
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "LCD_interface.h"
#include "MCP2515_interface.h"

#include "util/delay.h"

extern u8 array[];
int main(void)
{
	MCP2515_voidRXInit();
	LCD_vidInit8Bit(GPIOA,GPIOC,PIN0,GPIOC,PIN1);
	DIO_vidSetPinMode(GPIOD,PIN2,Input);
	u8 Data =0;
    /* Replace with your application code */
    while (1) 
    {
		if(DIO_OutpGetPinValue(GPIOD,PIN2) == 0){
			MCP2515_u8RecieveMassage();
			for(u8 i=0;i<8;i++){
				Data = array[6+i];
				LCD_vidWriteCharacter(GPIOA,GPIOC,PIN0,GPIOC,PIN1,Data);
			}
		}
    }
}

