#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H
/*options: 	Voltage Reference Selection
			0 		AREF, Internal Vref turned off
			1	 	AVCC with external capacitor at AREF pin
			2 	    Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
		#define V_ref 2
		
/*Prescaler
	0 2
	1 2
	2 4
	3 8
	4 16
	5 32
	6 64
	7 128
	*/
	#define Prescaler 7
	
/*Trigger Source
	0 for low 
	1 for high 
*/	
	#define ADC_STORE 0

	
#endif