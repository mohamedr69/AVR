#ifndef TIMR0_INTERFACE_H
#define TIMR0_INTERFACE_H

#define TMR0_CLKMC    0x01
#define TMR0_CLK_8    0x02
#define TMR0_CLK_64   0x03 
#define TMR0_CLK_256  0x04
#define TMR0_CLK_1024 0x05
#define TMR0_EVENT_FE 0x06
#define TMR0_EVENT_RE 0x07

void TIMR0_vidTIMRInit(void);


void TIMR0_vidStart(u8 prescaler);
void  TMR0_voidSetStart(u8 copy_u8InitValue);
u32   TMR0_u32Read(void);
void  TMR0_voidSetNormalWithInterrupt( void (*copy_CB)(void));

void  TMR0_voidSetOCR0(u8 InitValue);
void  TMR0_voidSetCTCWithInterrupt( void (*copy_CB)(void));


#endif 