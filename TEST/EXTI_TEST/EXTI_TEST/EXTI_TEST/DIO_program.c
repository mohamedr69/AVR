#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_vidSetPinMode(_enuPORTx enuPORT,_enuPINx enuPIN,_enuMode enuMode){
	
	switch(enuPORT)
	{
		case GPIOA:
		if(enuMode){
			SET_BIT(DDRA,enuPIN);
			}else{
			CLR_BIT(DDRA,enuPIN);
			#if PULL_UP
			SET_BIT(PORTA,High);
			#endif
		}break;
		case GPIOB:
		if(enuMode){
			SET_BIT(DDRB,enuPIN);
			}else{
			CLR_BIT(DDRB,enuPIN);
			#if(PULL_UP)
			SET_BIT(PORTB,High);
			#endif
		}break;
		case GPIOC:
		if(enuMode){
			SET_BIT(DDRC,enuPIN);
			}else{
			CLR_BIT(DDRC,enuPIN);
			#if(PULL_UP)
			SET_BIT(PORTC,High);
			#endif
		}break;
		case GPIOD:
		if(enuMode){
			SET_BIT(DDRD,enuPIN);

			}else{
			CLR_BIT(DDRD,enuPIN);
			#if(PULL_UP)
			SET_BIT(PORTD,High);
			#endif
		}break;
		default:break;
	}
	
}
void DIO_vidSetPinValue(_enuPORTx enuPORT,_enuPINx enuPIN,_enuOutputMode enuOutputMode){
	
	switch(enuPORT)
	{
		case GPIOA:
		if(enuOutputMode){
			SET_BIT(PORTA,enuPIN);
			}else{
			CLR_BIT(PORTA,enuPIN);
		}break;
		case GPIOB:
		if(enuOutputMode){
			SET_BIT(PORTB,enuPIN);
			}else{
			CLR_BIT(PORTB,enuPIN);
		}break;
		case GPIOC:
		if(enuOutputMode){
			SET_BIT(PORTC,enuPIN);
			}else{
			CLR_BIT(PORTC,enuPIN);
		}break;
		case GPIOD:
		if(enuOutputMode){
			SET_BIT(PORTD,enuPIN);
			}else{
			CLR_BIT(PORTD,enuPIN);
		}break;
		default:break;
	}
}
_enuOutputMode DIO_OutpGetPinValue(_enuPORTx enuPORT,_enuPINx enuPIN){
	_enuOutputMode Output;
	
	switch(enuPORT)
	{
		case GPIOA:
		Output = GET_BIT(PINA,enuPIN);
		break;
		case GPIOB:
		Output = GET_BIT(PINB,enuPIN);
		break;
		case GPIOC:
		Output = GET_BIT(PINC,enuPIN);
		break;
		case GPIOD:
		Output = GET_BIT(PIND,enuPIN);
		break;
		default:break;
	}
	return Output;
}
void DIO_vidSetPort(_enuPORTx enuPORT,_enuMode enuMode){
	
	switch(enuPORT)
	{
		case GPIOA:
			if(enuMode == Output){
				DDRA = 0xff;
			}else{
				DDRA = 0x00;
			}
			break;
		case GPIOB:
			if(enuMode == Output){
				DDRB = 0xff;
			}else{
				DDRB = 0x00;
			}
			break;
		case GPIOC:
			if(enuMode == Output){
				DDRC = 0xff;
			}else{
				DDRC = 0x00;
			}
			break;
		case GPIOD:
			if(enuMode == Output){
				DDRD = 0xff;
			}else{
				DDRD = 0x00;
			}
			break;
		default:break;
	}
	
}
void DIO_vidWritePort(_enuPORTx enuPORT,u8 character){
	
		switch(enuPORT)
	{
		case GPIOA:
			PORTA = character;
			break;
		case GPIOB:
			PORTB = character;
			break;
		case GPIOC:
			PORTC = character;
			break;
		case GPIOD:
			PORTD = character;
			break;
		default:break;
	}
}
void DIO_vidSetLowNibbleMode(_enuPORTx enuPortNum, _enuMode enuMODE)
{
    if(enuMODE == Output)
    {
        DIO_vidSetPinMode(enuPortNum, PIN0, Output);
        DIO_vidSetPinMode(enuPortNum, PIN1, Output);
        DIO_vidSetPinMode(enuPortNum, PIN2, Output);
        DIO_vidSetPinMode(enuPortNum, PIN3, Output);
    }
    else
    {
        DIO_vidSetPinMode(enuPortNum, PIN0, Input);
        DIO_vidSetPinMode(enuPortNum, PIN1, Input);
        DIO_vidSetPinMode(enuPortNum, PIN2, Input);
        DIO_vidSetPinMode(enuPortNum, PIN3, Input);
    }
}

void DIO_vidSetHighNibbleMode(_enuPORTx enuPortNum, _enuMode enuMODE)
{
    if(enuMODE == Output)
    {
        DIO_vidSetPinMode(enuPortNum, PIN4, Output);
        DIO_vidSetPinMode(enuPortNum, PIN5, Output);
        DIO_vidSetPinMode(enuPortNum, PIN6, Output);
        DIO_vidSetPinMode(enuPortNum, PIN7, Output);
    }
    else
    {
        DIO_vidSetPinMode(enuPortNum, PIN4, Input);
        DIO_vidSetPinMode(enuPortNum, PIN5, Input);
        DIO_vidSetPinMode(enuPortNum, PIN6, Input);
        DIO_vidSetPinMode(enuPortNum, PIN7, Input);
    }
}

void DIO_vidWriteLowNibble(_enuPORTx enuPortNum, u8 u8OutputValue)
{
    u8OutputValue &= 0x0f;
    switch(enuPortNum)
    {
        case GPIOA:
            PORTA &= 0xf0;
            PORTA |= u8OutputValue;
            break;
        case GPIOB:
            PORTB &= 0xf0;
            PORTB |= u8OutputValue;
            break;
        case GPIOC:
            PORTC &= 0xf0;
            PORTC |= u8OutputValue;
            break;
        case GPIOD:
            PORTD &= 0xf0;
            PORTD |= u8OutputValue;
            break;
        default:
            break;
    }
}

void DIO_vidWriteHighNibble(_enuPORTx enuPortNum, u8 u8OutputValue)
{
    u8OutputValue &= 0xf0;
    switch(enuPortNum)
    {
        case GPIOA:
            PORTA &= 0x0f;
            PORTA |= u8OutputValue;
            break;
        case GPIOB:
            PORTB &= 0x0f;
            PORTB |= u8OutputValue;
            break;
        case GPIOC:
            PORTC &= 0x0f;
            PORTC |= u8OutputValue;
            break;
        case GPIOD:
            PORTD &= 0x0f;
            PORTD |= u8OutputValue;
            break;
        default:
            break;
    }
}

