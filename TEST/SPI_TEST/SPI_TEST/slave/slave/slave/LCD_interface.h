#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_vidInit8Bit(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin);
void LCD_vidWriteCommand(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 command);
void LCD_vidWriteCharacter(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 character);
void LCD_vidWriteString(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 *string);
void LCD_vidClearScreen(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin);
void LCD_vidDisplatNumber(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u32 Number);
#endif