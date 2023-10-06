#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidWriteData(u16 COPY_u16Address, u8 COPY_u8Data);
u8 EEPROM_u8ReadData(u16 COPY_u16Address);
#endif