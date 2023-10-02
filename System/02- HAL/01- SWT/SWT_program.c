#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SWT_interface.h"
#include "SWT_private.h"
#include "SWT_config.h"

#include "DIO_interface.h"

void vidSWTinit(_enuPORTx PORTx,_enuPINx PINx){
	
	DIO_vidSetPinMode(PORTx,PINx,Input);
}



_enuOutputMode SWTread(_enuPORTx PORTx,_enuPINx PINx){
	return DIO_OutpGetPinValue(PORTx,PINx);
}