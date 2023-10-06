/*
	Name: Mohamed Ramdan Rashad
	Date:	4 OCT 2023
	Version:	v01
*/

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define TWBR	*((u8 *)0x20)	//TWI Bit Rate Register– TWBR
#define TWCR	*((u8 *)0x56)	//TWI Control Register –TWCR
	#define TWINT 7 //interrupt flag
	#define TWEA  6 // TWI Enable Acknowledge Bit
	#define TWSTA 5 //TWI START Condition Bit
	#define TWSTO 4 //TWI STOP Condition Bit
	#define TWWC 3 //TWI Write Collision Flag
	#define TWEN 2 // TWI Enable Bit
	#define TWIE 0 //TWI Interrupt Enable
#define TWSR 	*((u8 *)0x21)	//TWI Status Register –TWSR
#define TWDR 	*((u8 *)0x23)	//TWI Data Register –TWDR
#define TWAR	*((u8 *)0x22)	//TWI (Slave) Address Register
	#define TWGCE	0	//TWI General Call Recognition Enable Bit

#endif 