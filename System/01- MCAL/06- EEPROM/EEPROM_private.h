#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H

	#define EEARH 		*((volatile u8  *)0x3F)		//The EEPROM Address Register
	#define EEARL		*((volatile u8 *)0x3E)		//The EEPROM Address Register
	#define EEDR		*((volatile u8 *)0x3D)		//The EEPROM Data Register
	#define EECR		*((volatile u8 *)0x3C)		//The EEPROM Control Register
			#define EERIE 3 //EEPROM Ready Interrupt Enable
			#define EEMWE 2 //EEPROM Master Write Enable
			#define EEWE  1 //EEPROM Write Enable
			#define EERE  0 //EEPROM Read Enable
	
#endif 