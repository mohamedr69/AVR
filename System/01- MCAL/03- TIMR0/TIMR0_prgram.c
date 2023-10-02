/* LIB include */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

/* Driver Include */
#include "TIMR0_interface.h"
#include "TIMR0_config.h"
#include "TIMR0_private.h"

#include "avr/interrupt.h"
u8 flag;
u32 TOV_Counter = 0;
void (*Global_CBTOV)(void);
void (*Global_CBCTC)(void);

void TIMR0_vidTIMRInit(void){
		SET_BIT(SREG , 7);
	#if mode == 0
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	#elif mode == 1
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
		#if COM_phase_corrct == 0
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM00);
		#elif COM_phase_corrct == 2
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#else 
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#endif
	#elif mode== 2
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		#if COM_Non_pwm == 0
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM00);
		#elif COM_Non_pwm == 1
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM00);
		#elif COM_Non_pwm == 2
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#else
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#endif
	#else
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		#if COM_Fast_pwm == 0
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM00);
		#elif COM_Fast_pwm == 2
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#else 
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM00);
		#endif
	#endif
	
	#if TMR0_FOC0 == 0
		CLR_BIT(TCCR0,FOC0);
	#else
		SET_BIT(TCCR0,FOC0);
	#endif
	
	#if TMR0_TOVINTERRUPT == 0
		CLR_BIT(TIMSK,TOIE0);
	#else
		SET_BIT(TIMSK,TOIE0);
	#endif
	#if TMR0_TOCINTERRUPT == 0
		CLR_BIT(TIMSK,OCIE0);
	#else
		SET_BIT(TIMSK,OCIE0);
	#endif
}

void TIMR0_vidStart(u8 prescaler){
	flag = 0;
	TCCR0 &= 0xf8;
	TCCR0 |= prescaler;
}
void  TMR0_voidSetStart(u8 copy_u8InitValue){
	TCNT0 = copy_u8InitValue;
}
u32   TMR0_u32ReadTMR0(void){
	u32 Value;
	Value = (TOV_Counter * 256)+TCCR0;
	return Value;
}
void  TMR0_voidSetNormalWithInterrupt( void (*copy_CB)(void))
{
	if(copy_CB != 0)
	{
		flag =1;
		Global_CBTOV = copy_CB;
	}
}

void  TMR0_voidSetOCR0(u8 InitValue)
{
	OCR0 = InitValue;
}
void  TMR0_voidSetCTCWithInterrupt( void (*copy_CB)(void))
{
	Global_CBCTC = copy_CB;
}


ISR(TIMER0_OVF_vect)
{
	TOV_Counter++;
	if(flag !=0)
	{
		(*Global_CBTOV)();
	}
}

ISR(TIMER0_COMP_vect)
{
	(*Global_CBCTC)();
	SET_BIT(TIFR,OCF0);
	
}

































