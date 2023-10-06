#ifndef MCP2515_INTERFACE_H
#define MCP2515_INTERFACE_H
typedef enum{
	Normal_Mode,
	Sleep_Mode,
	Loopback_Mode,
	Listen_Mode,
	CNF_Mode, 		
}_enuModex;

typedef enum{
	Buffer0,
	Buffer1,
	Buffer2,
}_enuBUFFERx;


u8 MCP2515_u8ReadReg(u8 address);
void MCP2515_voidWriteReg(u8 address, u8 data);
void MCP_2515_voidResetReg();
void MCP_2515_voidModify(u8 address , u8 mask,u8 data);



void MCP2515_voidSetBitTiming(u8 CNF1_REG,u8 CNF2_REG,u8 CNF3_REG);
void MCP2515_voidSetMode(_enuModex MODE);
void MCP2515_voidEnableClock();
void MCP2515_voidSendToReq(u8 bufferID);
void MCP2515_voidSendMessage(u8 bufferID,u32 MSGID,u8 DLC, u8* DATA);


void MCP2515_voidTXInit();
void MCP2515_voidSetRollOver();
void MCP2515_voidSetMask(u8 maskAddress, u32 maskValue);

void MCP2515_voidRXInit();


#endif