#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"

#include "MCP2515_interface.h"
#include "MCP2515_private.h"
#include "MCP2515_config.h"


u8 MCP2515_u8ReadReg(u8 address){
	u8 readValue;
	SPI_voidSlaveSelect(1);
	// read Instruction 
	SPI_MasterTransmit(MCP2515_READ_INST);
	// slave add
	SPI_MasterTransmit(address);
	
	readValue = SPI_MasterTransmit(0);
	SPI_voidSlaveSelect(0);
	return readValue;
}
void MCP2515_voidWriteReg(u8 address, u8 data){
	SPI_voidSlaveSelect(1);
	
	SPI_MasterTransmit(MCP2515_WRITE_INST);
	SPI_MasterTransmit(address);
	SPI_MasterTransmit(data);
	
	SPI_voidSlaveSelect(0);
}
void MCP_2515_voidResetReg(){
	SPI_voidSlaveSelect(1);
	
	SPI_MasterTransmit(MCP2515_RESET_INST);
	
	SPI_voidSlaveSelect(0);
}
void MCP_2515_voidModify(u8 address , u8 mask,u8 data){
		SPI_voidSlaveSelect(1);
		
		SPI_MasterTransmit(MCP2515_MODIFY_INST);
		SPI_MasterTransmit(address);
		SPI_MasterTransmit(mask); // Bits that will be chaged 1
		SPI_MasterTransmit(data);
		
		SPI_voidSlaveSelect(0);
}
void MCP2515_voidSetBitTiming(u8 CNF1_REG,u8 CNF2_REG,u8 CNF3_REG){
	MCP2515_voidWriteReg(MCP2515_CNF1,CNF1_REG);
	MCP2515_voidWriteReg(MCP2515_CNF2,CNF1_REG);
	MCP2515_voidWriteReg(MCP2515_CNF3,CNF1_REG);
}
void MCP2515_voidSetMode(_enuModex MODE){
	 if(MODE == Normal_Mode){
		 //Normal mode
		 MCP_2515_voidModify(MCP2515_CANCTRL,0xE0,0x00);
	 }else if(MODE == Sleep_Mode){
		 //Sleep_Mode
		 MCP_2515_voidModify(MCP2515_CANCTRL,0xE0,0x10);
		 while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x10);
	 }
	 else if(MODE == Loopback_Mode){
		 //Loopback_Mode
		 MCP_2515_voidModify(MCP2515_CANCTRL,0xE0,0x20);
		 while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x20);
	 }
	 else if(MODE == Listen_Mode){
		 //Listen_Mode
		 MCP_2515_voidModify(MCP2515_CANCTRL,0xE0,0x30);
		 while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x30);
	 }
	else if(MODE == CNF_Mode){
		 //CNF Mode
		 MCP_2515_voidModify(MCP2515_CANCTRL,0xE0,0x40);
		 while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x40);
	 }
}
void MCP2515_voidEnableClock(){
	MCP_2515_voidModify(MCP2515_CANCTRL,0xF4,0x04);
}
void MCP2515_voidTXInit(){
	// SPI Initialization
	SPI_MasterInit();
	// MCP Reset Regs
	MCP_2515_voidResetReg();
	// Enter Configration mode
	MCP2515_voidSetMode(CNF_Mode);
	//Enable Clock
	void MCP2515_voidEnableClock();
	// check configration mode
	while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x40);
	
	MCP2515_voidSetBitTiming(0x80,0xB1,0x05);
	
	MCP2515_voidSetMode(Normal_Mode);
}
void MCP2515_voidSendMessage(_enuBUFFERx bufferID,u32 MSGID,u8 DLC, u8* DATA){
	SPI_voidSlaveSelect(1);
	
	SPI_MasterTransmit(MCP2515_WRITE_INST);
	SPI_MasterTransmit(MCP2515_TXB0CTRL);
	
	// Set priority (incremental)
	SPI_MasterTransmit(0x00);
	// Message ID 0b11000001111
	/* ID HIGH*/
	SPI_MasterTransmit((u8)(MSGID >> 3));
	/* ID LOW*/
	SPI_MasterTransmit((u8)(MSGID<<5));
	/*Extended ID*/
	SPI_MasterTransmit(0);
	SPI_MasterTransmit(0);
	//DLC
	SPI_MasterTransmit(DLC & 0x0F);
	//DATA
	for(u8 i=0;i<(DLC & 0X0F);i++){
		SPI_MasterTransmit(DATA[i]);
	}
	/*release BUS*/
	SPI_voidSlaveSelect(0);
		/*request to send*/
	MCP2515_voidSendToReq(bufferID);

}
void MCP2515_voidSendToReq(_enuBUFFERx bufferID){
	
		if(bufferID == Buffer0){
			SPI_voidSlaveSelect(1);
			SPI_MasterTransmit(MCP2515_RTS_BUFF0_INST);
			SPI_voidSlaveSelect(0);
			
		}else if(bufferID == Buffer1){
			SPI_voidSlaveSelect(1);
			SPI_MasterTransmit(MCP2515_RTS_BUFF1_INST);
			SPI_voidSlaveSelect(0);
			
		}else if(bufferID == Buffer2){
			SPI_voidSlaveSelect(1);
			SPI_MasterTransmit(MCP2515_RTS_BUFF2_INST);
			SPI_voidSlaveSelect(0);
		}
}
void MCP2515_voidSetRollOver(){
	MCP_2515_voidModify(MCP2515_RXB0CTRL,1<<3,1<<3);
}
void MCP2515_voidSetMask(u8 maskAddress, u32 maskValue){
	SPI_voidSlaveSelect(1);
	// NO EXTENDED 
	SPI_MasterTransmit(MCP2515_WRITE_INST);
	SPI_MasterTransmit(maskAddress);
	SPI_MasterTransmit((u8)(maskValue>>3));
	SPI_MasterTransmit((u8)(maskValue<<5));
	
	SPI_voidSlaveSelect(0);
}
void MCP2515_voidRXInit(){
	// SPI Initialization
	SPI_MasterInit();
	// MCP Reset Regs
	MCP_2515_voidResetReg();
	// Enter Configration mode
	MCP2515_voidSetMode(CNF_Mode);
	//Enable Clock
	void MCP2515_voidEnableClock();
	// check configration mode
	while(MCP2515_u8ReadReg(MCP2515_CANSTAT>>5) != 0x40);
	
	MCP2515_voidSetBitTiming(0x80,0xB1,0x05);
	
	// SET MASK Accept all
	MCP2515_voidSetMask(MCP2515_RXM0SIDH,0x00000000);
	MCP2515_voidSetMask(MCP2515_RXM1SIDH,0x00000000);
	
	// Interrupt enable
	MCP2515_voidWriteReg(MCP2515_CANINTE,1<<0); 
	
	MCP2515_voidSetMode(Normal_Mode);
	
}
u8 array[14];
void MCP2515_u8RecieveMassage(){
	SPI_voidSlaveSelect(1);
	SPI_MasterTransmit(MCP2515_READ_INST);
	SPI_MasterTransmit(MCP2515_RXB0CTRL);
	
	for(u8 i=0;i<14;i++){
		array[i] = SPI_MasterTransmit(0);
	}
	
	SPI_voidSlaveSelect(0);
	// reset int flag 
	MCP2515_voidWriteReg(MCP2515_CANINTF,0);
	
}