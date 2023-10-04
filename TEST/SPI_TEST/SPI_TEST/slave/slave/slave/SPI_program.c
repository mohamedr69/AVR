/*
	Name: Mohamed Ramdan Rashad
	Date:	4 OCT 2023
	Version:	v01
*/
#include "DIO_interface.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



void SPI_MasterInit(void){
	DIO_vidSetPinMode(GPIOB,MOSI,Output);
	DIO_vidSetPinMode(GPIOB,SCK,Output);
	DIO_vidSetPinMode(GPIOB,MISO,Input);
	DIO_vidSetPinMode(GPIOB,SS,Output);
	
	SET_BIT(SPCR,SPE); // SPI ENABLE
	SET_BIT(SPCR,MSTR); //SPI MASTER
	SET_BIT(SPCR,SPR0); // 16 PRESCALLER
	
	
}

void SPI_SlaveInit(void){
	DIO_vidSetPinMode(GPIOB,MOSI,Input);
	DIO_vidSetPinMode(GPIOB,SCK,Input);
	DIO_vidSetPinMode(GPIOB,MISO,Output);
	DIO_vidSetPinMode(GPIOB,SS,Input);
	
	SET_BIT(SPCR,SPE); // SPI ENABLE
	CLR_BIT(SPCR,MSTR); //SPI SLAVE
	
}

u8 SPI_SlaveReceive(void){
	while(!(SPSR & (1<<SPIF)));
	u8 data = SPDR;
	return data;
	
}

void SPI_MasterTransmit(u8 COPY_u8Data){
	
	SPDR = COPY_u8Data;
	while(!(SPSR&(1<<SPIF)));
	
	
}