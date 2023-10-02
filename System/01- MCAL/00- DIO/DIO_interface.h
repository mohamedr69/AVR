#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD
}_enuPORTx;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}_enuPINx;

typedef enum{
	Input,
	Output
}_enuMode;

typedef enum{
	Low,
	High
}_enuOutputMode;
typedef enum
{
    LOW_NIBBLE = 0,
    HIGH_NIBBLE
}_enuNIBBLE;

void DIO_vidSetPinMode(_enuPORTx enuPORT,_enuPINx enuPIN,_enuMode enuMode);
void DIO_vidSetPinValue(_enuPORTx enuPORT,_enuPINx enuPIN,_enuOutputMode enuOutputMode);
_enuOutputMode DIO_OutpGetPinValue(_enuPORTx enuPORT,_enuPINx enuPIN);

void DIO_vidSetPort(_enuPORTx enuPORT,_enuMode enuMode);
void DIO_vidWritePort(_enuPORTx enuPORT,u8 character);

void DIO_vidSetLowNibbleMode(_enuPORTx enuPortNum, _enuMode enuMODE);
void DIO_vidSetHighNibbleMode(_enuPORTx enuPortNum, _enuMode enuMODE);
void DIO_vidWriteLowNibble(_enuPORTx enuPortNum, u8 _enuOutputMode);
void DIO_vidWriteHighNibble(_enuPORTx enuPortNum, u8 _enuOutputMode);
#endif