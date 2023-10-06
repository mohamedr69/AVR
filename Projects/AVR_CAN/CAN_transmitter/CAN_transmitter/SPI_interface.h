/*
	Name: Mohamed Ramdan Rashad
	Date:	4 OCT 2023
	Version:	v01
*/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void SPI_MasterInit(void);
void SPI_voidSlaveSelect(u8 state);
void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(void);
u8 SPI_MasterTransmit(u8 COPY_u8Data);

#endif