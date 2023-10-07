#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
	INT0_DIO = 0,
	INT1_DIO,
	INT2_DIO
}_enuEXTIx;

typedef enum{
	LOW_LEVEL = 0,
	LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}_enuEXTICONTROL;
void EXTI_voidInit(_enuEXTIx enuEXTIx,_enuEXTICONTROL enuEXTICONTROL);
void EXTI_voidSetCallBack(_enuEXTIx enuEXTIx,void (*INT_CB)(void));

#endif