#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#define  F_CPU 8000000UL
#include "util/delay.h"

void LCD_vidInit8Bit(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin){
	
	DIO_vidSetPort(Data,Output);
	DIO_vidSetPinMode(RSport,RSpin,Output);
	DIO_vidSetPinMode(Eport,Epin,Output);
	_delay_ms(2);
	
	LCD_vidWriteCommand(Data,RSport,RSpin,Eport,Epin,LCD_Function_8BIT_2Lines);
	
	_delay_ms(1);
	
	LCD_vidWriteCommand(Data,RSport,RSpin,Eport,Epin,LCD_DISP_ON_CURSOR_ON);
	
	_delay_ms(1);
	
	LCD_vidWriteCommand(Data,RSport,RSpin,Eport,Epin,LCD_CLEAR_SCREEN);

	_delay_ms(1);
	
	LCD_vidWriteCommand(Data,RSport,RSpin,Eport,Epin,LCD_ENTRY_MODE);
	
}

void LCD_vidWriteCommand(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 command){
	
	DIO_vidSetPinValue(RSport,RSpin,Low);
	DIO_vidWritePort(Data,command);
	LCD_vidEnablePulse(Eport,Epin);
	
}
static void LCD_vidEnablePulse(_enuPORTx Eport,_enuPINx Epin){
	DIO_vidSetPinValue(Eport,Epin,High);
	_delay_ms(2);
	DIO_vidSetPinValue(Eport,Epin,Low);
}
void LCD_vidWriteCharacter(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 character){
	
	DIO_vidSetPinValue(RSport,RSpin,High);
	DIO_vidWritePort(Data,character);
	LCD_vidEnablePulse(Eport,Epin);
	
}
void LCD_vidWriteString(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u8 *string){
	
	u8 *str = string;
	while(*str!='\0'){
		LCD_vidWriteCharacter(Data,RSport,RSpin,Eport,Epin,*str);
		str++;
	}
	
}
void LCD_vidClearScreen(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin){
	
	LCD_vidWriteCommand(Data,RSport,RSpin,Eport,Epin,LCD_CLEAR_SCREEN);
	_delay_ms(5);
}
void LCD_vidDisplatNumber(_enuPORTx Data,_enuPORTx RSport,_enuPINx RSpin,_enuPORTx Eport,_enuPINx Epin,u32 Number){
	u8 str[8];
	sprintf(str,"%d",Number);
	LCD_vidWriteString(Data,RSport,RSpin,Eport,Epin,str);
}
