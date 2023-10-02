#ifndef TIMR0_CONFIG_H
#define TIMR0_CONFIG_H
	/*options 
		0 Normal
		1 PWM, Phase Correct
		2 CTC
		3 Fast PWM
		
	*/
	#define mode 0
	/*non-PWM Mode
		0 Normal port operation, OC0 disconnected.
		1 Toggle OC0 on compare match
		2 Clear OC0 on compare match
		3 Set OC0 on compare match
	*/
	#define COM_Non_pwm 0
	/*Compare Output Mode, Fast PWM Mode
		0 Normal port operation, OC0 disconnected.
		2 Clear OC0 on compare match, set OC0 at BOTTOM,
		(nin-inverting mode)
		3 Set OC0 on comp
	*/
	#define COM_Fast_pwm 0
	
	/* phase correct
		0 Normal port operation, OC0 disconnected.
		2 Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
		3 Set OC0 on compare match */
		
	#define COM_phase_corrct 0
	
	/* Options : 
		0 for Disable FOC0
		1 for Enable  FOC0
	*/
	#define  TMR0_FOC0  0
	
	/* Options : 
		0 for Disable Overflow Interrupt
		1 for Enable  Overflow Interrupt
	*/
	#define TMR0_TOVINTERRUPT   0

	/* Options : 
		0 for Disable Compare match Interrupt
		1 for Enable  Compare match Interrupt
	*/
	#define TMR0_TOCINTERRUPT 0
	
	
	
#endif


