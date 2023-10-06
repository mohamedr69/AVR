/*
 * CAN_transmitter.c
 *
 * Created: 06/10/2023 16:22:15
 * Author : moham
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "MCP2515_interface.h"

#include "util/delay.h"

int main(void)
{
	MCP2515_voidTXInit();
	u8 msgData[] = {'a','b','c','d','e','f','g','h'};
    /* Replace with your application code */
    while (1) 
    {
		MCP2515_voidSendMessage(0,0x7E1,msgData,8);
		for(u8 i=0;i<8;i++){
			msgData[i]++;
		}
		_delay_ms(1000);
	}
}

