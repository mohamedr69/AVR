#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "DIO_interface.h"

void vidLedInit(_enuPORTx PORTx,_enuPINx PINx){
	
	DIO_vidSetPinMode(PORTx,PINx,Output);
	
}
void vidLedOn(_enuPORTx PORTx,_enuPINx PINx){
	
	DIO_vidSetPinValue(PORTx,PINx,High);
	
}
void vidLedOff(_enuPORTx PORTx,_enuPINx PINx){
	
	DIO_vidSetPinValue(PORTx,PINx,Low);
}
