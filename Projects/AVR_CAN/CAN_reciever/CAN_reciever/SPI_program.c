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
	//DIO_vidSetPinMode(GPIOB,SS,Output);
	
	SET_BIT(SPCR,SPE); // SPI ENABLE
	CLR_BIT(SPCR,DORD); //MSB FIRST
	
	DIO_vidSetPinMode(GPIOB,SS,Output);
	DIO_vidSetPinValue(GPIOB,SS,High);
	
	SET_BIT(SPCR,MSTR); //SPI MASTER
	
	CLR_BIT(SPCR,CPOL); //CLOCK PLARITY, LEADING RISING EDGD
	CLR_BIT(SPCR,CPHA);//CLOCK PHASE AT RISING EDGE 
	// CLOCK OSCILLATOR F/4
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPSR,0);
}
void SPI_voidSlaveSelect(u8 state){
	if(state == 1){
		DIO_vidSetPinValue(GPIOB,SS,Low);
	}else{
		DIO_vidSetPinValue(GPIOB,SS,High);

	}
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
	return SPDR;
	
}

u8 SPI_MasterTransmit(u8 COPY_u8Data){
	
	SPDR = COPY_u8Data;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
	
}