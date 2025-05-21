// prescaler for max 50 MHz

//clock is ideal high

#include "main.h"

//MCB startup Sequance

//make Sync1_Otput and set low

reset(); //Active low

//wait 100uS

Sync1_setHigh();

//wait 100uS
resetReleas(); //High

//make Sync1_input

// then wait for IRQ sifnal to send data (Active High)


// data feild : Data 1311768467463790320 (0x123456789ABCDEF0) is sent in this order through data field: 0xDEF0 9ABC 5678 1234 ????

// Most Needed registers

//0x00F - Last error
//0x010 - Control word
//0x014 - Operation mode
//0x020 - Position set-point
// 0x153 - Reference feedback sensor  1
//0x360 -  Velocity feedback sensor    1
// 0x361 - Position feedback sensor   1
// 0x364 - Position to velocity sensor ratio
// 0x36F - Primary Absolute Slave 1 - Protocol 0
// 0x370 - Primary Absolute Slave 1 - Frame size
// 0x374 - Primary Absolute Slave 1 - Frame type
// 0x375 - Primary Absolute Slave 1 - Position bits
// 0x376 - Primary Absolute Slave 1 - Single-turn bits
// 0x377 - Primary Absolute Slave 1 - Position start bit
// This register indicates the total number of bits of the frame. These include position bits, special bits, warning, error and CRC bits, etc
// 0x386 - Primary Absolute Slave 1 - Baudrate
// 0x398 - Primary Absolute - Maximum refresh rate
// 0x408 - Primary Absolute Slave 1 - CRC polynomial
// 0x409 - Primary Absolute Slave 1 - CRC number of bits
// 0x40C - Primary Absolute Slave 1 - CRC seed
// 0x011 - Status word





typedef struct {
	
	uint16_t SwitchOn : 1;      //0
	uint16_t EnableVoltage : 1;  //1
	uint16_t QuickStop : 1;     //2
	uint16_t EnableOperation : 1;   //3
	uint16_t RunSetPointManager : 1;  //4
	uint16_t Reserved1 : 2;   //56
  uint16_t FaultReset : 1; // 7
	uint16_t Halt : 1; // 8
	uint16_t NewSetpoint : 1;  //9
	uint16_t Unused : 1;	  //10
	uint16_t Abs_Rel : 1;  //11	
}ControlWord_T;






 enum MasterCmd_T{
	
	READ_ACCESS = 0b001,
	WRITE_ACCESS = 0b010,
	GET_INFO = 0b000,
	M_IDEAL_CMD = 0b111
	
};


 enum SlaveCmd_T{
	
	ACK_ACCESS = 0b011,
	ERR_READ = 0b101,
	ERR_WRITE = 0b110,
	S_IDEAL_CMD = 0b111
	
};

typedef struct {
	
	uint16_t Address : 12;
    uint16_t Command : 3;
	uint16_t PendingFrame : 1;
	
	
}MCB_Header_Bitfeild_T;

typedef struct  {
	
	MCB_Header_Bitfeild_T Header; 
	uint64_t ConfigData;
	uint16_t CRCVal;  
}Mcb_Config_Frame_Fields_T;



void fillSendbufferArray(*sendBuff){
	
	clearSendBuff
	
	sendBuff[0] = Mcb_Config_Frame_Fields_T.Header
	
	for i=1.. i<5
	sendBuff[i] = (uint16_t)(0xFFFF)&(Mcb_Config_Frame_Fields_T.ConfigData>>(64-(16*i)));
	
	sendBuff[5] = generateCRC(sendBuff)
	
	
}

uint16_t recBuff[6];

void getReceivedFrameData(){
	
	Mcb_Config_Frame_Fields_T.ConfigData =0;
	
	Mcb_Config_Frame_Fields_T.Header = recBuff[0];
	int i;
	
	for (i=1 ; i<5 ;i++)
	//sendBuff[i] = (uint16_t)(0xFFFF)&(Mcb_Config_Frame_Fields_T.ConfigData>>(64-(16*i)));
	
	Mcb_Config_Frame_Fields_T.ConfigData |= ((uint64_t)recBuff[i])<<(64-(16*i))
	if(generateCRC(recBuff) ==  recBuff[5]){
		
		sucess
		process fram......
		
	}
	
	
}





void mCBSendIdealCommand(){
	
	if(configFrameComStatus == CONFIG_COM_READY){
	
	
	mCBSend(.....); // start send new config
	configFrameComStatus = CONFIG_REQ_SENT;
	
	return 1;
	
	
}
	
	
 return 0;	
}




void mCBSend(address_12bits,command_3bits,pendingFrame, configData_64bits ){
	
	
	uint16_t sendBuff[6];
    fillSendbufferArray(sendBuff, data?);
	start spi TX(txBuff);
	
	clearToSendNewMcbFrameF = false;
	
	
	
}

if(clearToSendNewMcbFrameF && configFrameComStatus != CONFIG_COM_READY){
	
	mCBSendIdealCommand();
	
}

void mCBSendIdealCommand(){
	
	mCBSend(address_12bits,IdealCMD,pendingFrame, 0 );
	configFrameComStatus = IDEAL_CMD_SENT;
	
}


IRQ_ISR_rising(){
	
	clearToSendNewMcbFrameF = true;
	
	
}
	

	


RX_ISR(){
	
	if(CRC Not Ok){
		
		// crc error
		return;
			
		
	}
	
	//process reply
	if(slaveCMD == IdealCMD){
		
		
		
			//Display timr out Error msg
			
		
	}
	if(slaveCMD == ACK access){
		
		//update temp data
		
		if(there is notPendingFrame){
			
			
		
		//update data / or from temp
		configFrameComStatus = CONFIG_COM_READY;
		CNT = 0;
		tempDataclear;
		return;
		}
		else{
			
		//add to temp
			
		}
	}
	else if(slaveCMD == ERR access){
		
		....
		
		
	}
	
	
    if(configFrameComStatus == IDEAL_CMD_SENT && ++CNT > 5){
	
    configFrameComStatus = CONFIG_COM_READY;
    CNT = 0;
	tempDataclear;
	
	}
	
}


TX_ISR(){
	
	
	
	
}