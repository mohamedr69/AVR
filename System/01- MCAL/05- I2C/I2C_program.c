/*
	Name: Mohamed Ramdan Rashad
	Date:	4 OCT 2023
	Version:	v01
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

void I2C_voidStartCond(u8 SLA_W){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //Send START condition
	while (!(TWCR & (1<<TWINT)));Wait for //TWINT Flag set. This indicates that the START condition has been transmitted
	
	TWDR = SLA_W; 					//Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while (!(TWCR & (1<<TWINT))); //Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.
	
	SET_BIT(TWCR,TWEN); //ENABLE BIT
	TWDR = DATA;			//Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	
	while (!(TWCR & (1<<TWINT)));	//Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received.
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); //Transmit STOP condition
	
}
u8 I2C_u8RecieveMode(u8 SLA_W){
	
	TWAR = SLA_W;
	SET_BIT(TWCR,TWEN);//ENABLE I2C
	SET_BIT(TWCR,TWEA);//ENABLE ACK
	while (!(TWCR & (1<<TWINT)));
	
}