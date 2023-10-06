#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

void EEPROM_voidWriteData(u16 COPY_u16Address, u8 COPY_u8Data){
	

	EEARL = (u8)COPY_u16Address;
	EEARH = (u8)(COPY_u16Address >> 8);
	EEDR = COPY_u8Data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(GET_BIT(EECR,EEWE) == 1);

}
u8 EEPROM_u8ReadData(u16 COPY_u16Address){
	EEARL = (u8)COPY_u16Address;
	EEARH = (u8)(COPY_u16Address >> 8);
	SET_BIT(EECR,EERE);
	return EEDR;
	
}
