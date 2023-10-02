#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
typedef enum{
	INT_0,
	INT_1,
	INT_2
}INTx;
typedef enum{
	LOW_LEVEL,
	FALLING_EDGE,
	RISING_EDGE,
	LOGICAL_CHANG
}INTmode;

void EXTI_vidInit(INTx INT,INTmode mode);
void EXTI_vidSetCB(INTx INT, void (*INT_CB)(void));
#endif 