
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

void LM35_vidInit(_ADCchannel channel){
	
	ADC_vidADCinit(channel);
}

u8 LM35u8GetTemp(void){
	
	u16 Read = ADC_u16ADCRead();
	
	/* Calculate Temperature value */
	u8 Temp = (Read * 2.56 / 1024.0) * 100.0;
	return Temp;
}