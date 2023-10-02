#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}_ADCchannel;
void ADC_vidADCinit(_ADCchannel channel);
u16 ADC_u16ADCRead();
#endif