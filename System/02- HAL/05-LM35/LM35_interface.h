#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H
#include "ADC_interface.h"
#define INT_VREF 2560
void LM35_vidInit(_ADCchannel channel);
u8 LM35u8GetTemp(void);
#endif 