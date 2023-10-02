#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#include "DIO_interface.h"
#define NOT_PRESSED 0xFF
void KPD_vidInit(_enuPORTx enuPortNum, _enuNIBBLE enuOutNibble, _enuNIBBLE enuInNibble);
u8 KPD_u8GetPressedKey(_enuPORTx enuPortNum, _enuNIBBLE enuOutNibble, _enuNIBBLE enuInNibble);
#endif