/*
	Name: Mohamed Ramdan Rashad
	Date:	4 OCT 2023
	Version:	v01
*/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H
	#define SS		4
	#define MOSI 	5
	#define MISO	6
	#define SCK		7
	
	#define SPCR 		*((u8 *)0x2D)
					#define SPIE	7
					#define SPE 	6
					#define DORD 	5
					#define MSTR	4
					#define CPOL	3
					#define CPHA    2
					#define SPR1	1
					#define SPR0	0
	#define SPSR		*((u8 *)0x2E)
					#define SPIF 	7
					#define WCOL	6
					#define SPI2X	0
	#define SPDR		*((u8 *)0x2F)
#endif