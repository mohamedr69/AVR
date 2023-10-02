#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
#include "DIO_interface.h"
void vidLedInit(_enuPORTx PORTx,_enuPINx PINx);
void vidLedOn(_enuPORTx PORTx,_enuPINx PINx);
void vidLedOff(_enuPORTx PORTx,_enuPINx PINx);
#endif