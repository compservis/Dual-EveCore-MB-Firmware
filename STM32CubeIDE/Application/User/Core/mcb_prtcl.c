// prescaler for max 50 MHz

//clock is ideal high



/*

#include "main.h"

//MCB startup Sequance



void EvCore_Reset(void); //Active low







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



typedef enum {

	MCB_STATE_START,
	MCB_STATE_CONFIG,
	MCB_STATE_CYCLIC
}MCB_State_T;






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


Mcb_Config_Frame_Fields_T nextConfigReqToSend;


void fillSpiSendBuff(uint16_t *sendBuff, Mcb_Config_Frame_Fields_T mcbConfigFrame ){


	//address_12bits,command_3bits,pendingFrame, configData_64bits

	//Clear sendFrame
	memset(sendBuff, 0, sizeof(sendBuff));


	sendBuff[0] = ........

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



void mCBSend(nextConfigReqToSend){


	uint16_t sendBuff[6];

    //extract variables from (nextConfigReqToSend) structure and fill them to SPI send buffer

    fillSpiTxBuff(sendBuff, nextConfigReqToSend);
	start spi TX(txBuff);

	clearToSendNewMcbFrameF = false;


}



void mCBSendIdealCommand(){



	Mcb_Config_Frame_Fields_T ConfigReqToSend = nextConfigReqToSend;


	ConfigReqToSend.Header.Command = M_IDEAL_CMD;
	ConfigReqToSend.Header.PendingFrame = 0;
	mCBSend(nextConfigReqToSend);

}



void mCBSendNewConfigReq(){


	mCBSend(nextConfigReqToSend); // start send new config
	CNT =0;
	tempDataclear;
	configFrameComStatus = WAITING_FOR_CONFIG_REPLY;

	return 1;


}




IRQ_ISR_rising(){

	clearToSendNewMcbFrameF = true;


}

IRQ_ISR_falling(){

	clearToSendNewMcbFrameF = false;

}


if(IRQ_PIN_High){



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
		return;
		}
		else{

		//add to temp

		}
	}
	else if(slaveCMD == ERR access){

		....
		configFrameComStatus = CONFIG_COM_READY;

	}


    if(configFrameComStatus == WAITING_FOR_CONFIG_REPLY && ++CNT > 5){

    configFrameComStatus = CONFIG_COM_READY;


	}

}


TX_ISR(){




}



void EvCore_Reset(void){



	HAL_GPIO_WritePin(ST_RST_GPIO_Port, ST_RST_Pin, GPIO_PIN_RESET);

	//wait > 100uS

	HAL_Delay(1);

	// Configure SYNC1 pins as output
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = ST_SYNC11_Pin|ST_SYNC12_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	//Set Low
	HAL_GPIO_WritePin(ST_SYNC11_GPIO_Port,ST_SYNC11_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(ST_SYNC12_GPIO_Port,ST_SYNC12_Pin,GPIO_PIN_SET);

	HAL_Delay(1);

	HAL_GPIO_WritePin(ST_RST_GPIO_Port, ST_RST_Pin, GPIO_PIN_SET);

	// Delay ?

	//make Sync1_input
	GPIO_InitStruct.Pin = ST_SYNC11_Pin|ST_SYNC12_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	// then wait for IRQ signal to send data (Active High)


}




void MCB_COMM_Handler(void){



	if(clearToSendNewMcbFrameF){

		if(configFrameComStatus == WAITING_FOR_CONFIG_REPLY){

			mCBSendIdealCommand();

		}else if(configFrameComStatus == CONFIG_COM_READY){

			mCBSendNewConfigReq();

		}

	}


}

*/
