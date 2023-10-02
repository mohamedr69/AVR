#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


void ADC_vidADCinit(_ADCchannel channel){
		
		DIO_vidSetPinMode(GPIOA,channel,Input);
		/* Reference Selection Bits*/
		#if V_ref == 0
			CLR_BIT(ADMUX,REFS1);
			CLR_BIT(ADMUX,REFS0);
		#elif V_ref == 1
			CLR_BIT(ADMUX,REFS1);
			SET_BIT(ADMUX,REFS0);
		#else
			SET_BIT(ADMUX,REFS1);
			SET_BIT(ADMUX,REFS0);
		#endif
		/*Prescaler */
		#if   Prescaler == 0
			ADCSRA &= 0xF8;
		#elif Prescaler == 2
			ADCSRA &= 0xF8;
			ADCSRA |= 0x02;
		#elif Prescaler == 3
			ADCSRA &= 0xF8;
			ADCSRA |= 0x03;
		#elif Prescaler == 4
			ADCSRA &= 0xF8;
			ADCSRA |= 0x04;
		#elif Prescaler == 5
			ADCSRA &= 0xF8;
			ADCSRA |= 0x05;
		#elif Prescaler == 6
			ADCSRA &= 0xF8;
			ADCSRA |= 0x06;
		#elif Prescaler == 7
			ADCSRA &= 0xF8;
			ADCSRA |= 0x07;
		#endif
		
		/*store data */
		#if ADC_STORE == 0
			CLR_BIT(ADMUX, ADLAR);
		#else 
			SET_BIT(ADMUX, ADLAR);
		#endif 
		/*enable ADC*/
		SET_BIT(ADCSRA, ADEN);

	}
	
	
u16 ADC_u16ADCRead(){
	u16 returnVal;
	/*start conv*/
	SET_BIT(ADCSRA, ADSC);
	/*pool on flag*/
	while(GET_BIT(ADCSRA, ADIF)==0);
	/*reset flag by putting 1*/
	SET_BIT(ADCSRA, ADIF);
	
	returnVal = ADCL;
	returnVal |= (ADCH << 8);
	return returnVal;
	
	
	
}
