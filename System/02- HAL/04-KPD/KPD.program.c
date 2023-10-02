
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_vidInit(_enuPORTx enuPortNum, _enuNIBBLE enuOutNibble, _enuNIBBLE enuInNibble)
{
	if (enuOutNibble == LOW_NIBBLE)
	{
		DIO_vidSetLowNibbleMode(enuPortNum, Output);
		DIO_vidSetHighNibbleMode(enuPortNum, Input);
		DIO_vidWriteHighNibble(enuPortNum, 0xF0);
	}
	else
	{
		DIO_vidSetLowNibbleMode(enuPortNum, Input);
		DIO_vidSetHighNibbleMode(enuPortNum, Output);
		DIO_vidWriteLowNibble(enuPortNum, 0x0F);
	}
	
}
u8 KPD_u8GetPressedKey(_enuPORTx enuPortNum, _enuNIBBLE enuOutNibble, _enuNIBBLE enuInNibble)
{
	u8 arr[4][4]={{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'A','0','=','+'}};
	u8 u8Row , u8Coloumn ;
	_enuOutputMode enuReadValue;
	u8 Return_val= NOT_PRESSED;
	if (enuOutNibble == LOW_NIBBLE)
	{
		for (u8Row = 0; u8Row < 4; u8Row++)
		{
			DIO_vidWriteLowNibble(enuPortNum, 0x0F);
			DIO_vidSetPinValue(enuPortNum, u8Row, Low);
			for (u8Coloumn = 0; u8Coloumn < 4; u8Coloumn++)
			{
				enuReadValue = DIO_OutpGetPinValue(enuPortNum,(u8Coloumn+4));
				if (enuReadValue == Low)
				{
					Return_val = arr[u8Row][u8Coloumn];
					break;
				}
				
			}
			if (enuReadValue == Low)
			{
				break;
			}
		}
	}
	else
	{
		for (u8Row = 0; u8Row < 4; u8Row++)
		{
			DIO_vidWriteHighNibble(enuPortNum, 0xF0);
			DIO_vidSetPinValue(enuPortNum, (u8Row+4), Low);
			for (u8Coloumn = 0; u8Coloumn < 4; u8Coloumn++)
			{
				enuReadValue = DIO_OutpGetPinValue(enuPortNum,(u8Coloumn));
				if (enuReadValue == Low)
				{
					Return_val = arr[u8Row][u8Coloumn];
					break;
				}
				
			}
			if (enuReadValue == Low)
			{
				break;
			}
		}
	}
	return Return_val;
	
}