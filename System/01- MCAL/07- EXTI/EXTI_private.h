#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

	#define SREG	*((volatile u8 *)0x5F)	
			#define GIE 7		//GLOBAL INT
	#define MCUCR	*((volatile u8 *)0x55)		//MCU Control Registe
			#define ISC00 0
			#define ISC01 1
			#define ISC10 2
			#define ISC11 3
	#define MCUCSR	*((volatile u8 *)0x54)		//MCU Control and Status Register
			#define ISC2 6
	#define GICR	*((volatile u8 *)0x5B)		//General Interrupt Control Register 
			#define INT1 7		//External Interrupt Request 1 Enable
			#define INT0 6		//External Interrupt Request 0 Enable
			#define INT2 5		// External Interrupt Request 2 Enable
	#define GIFR	*((volatile u8 *)0x5A)		//General Interrupt Flag Registe
			#define INTF1 7		//External Interrupt Flag 1
			#define INTF0 6		//External Interrupt Flag 0
			#define INTF2 5		//External Interrupt Flag 2

#endif