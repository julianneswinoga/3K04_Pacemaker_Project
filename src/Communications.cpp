#include "Communications.h"

Communications::Communications() : USBSerialConnection(USBTX, USBRX)  {
	//Initialize Critical State Variables
	baudRate = 57600;
	connectDCM();
	serialRecieveMode = SERIAL_RECIEVE_MODE::UPDATE_DEVICE_INFO;
}

uint16_t Communications::twoByteRecieve() {
	uint8_t b[2];
	
	for (uint8_t C = 0;C < 2;C++)
		b[C] = USBSerialConnection.getc();
	
	return (b[1] << 8) | b[0];
}

float Communications::floatRecieve() {
	float f;
	uint8_t b[4];
	
	for (uint8_t C = 0;C < 4;C++)
		b[C] = USBSerialConnection.getc();
	
	memcpy(&f, &b, 4);
	return f;
}

void Communications::stringRecieve(char *outStr) {
	char buf[128];
	char data;
	int i;
	
	for(i = 0;(data = USBSerialConnection.getc()) >= 32;i++)
		buf[i] = data;
	
	buf[i] = '\0'; // Make it a C string
	
	strcpy(outStr, buf);
}

void Communications::serialCallback() {
	switch (serialRecieveMode) {
		case SERIAL_RECIEVE_MODE::UPDATE_PARAMS:
			packetStruct.FnCode				= USBSerialConnection.getc();
			
			packetStruct.p_pacingState		= USBSerialConnection.getc();
			packetStruct.p_pacingMode		= USBSerialConnection.getc();
			packetStruct.p_hysteresis			= USBSerialConnection.getc();
			
			packetStruct.p_hysteresisInterval	= twoByteRecieve();
			packetStruct.p_vPaceAmp			= twoByteRecieve();
			packetStruct.p_vPaceWidth_10x	= twoByteRecieve();
			packetStruct.p_VRP				= twoByteRecieve();
			
			packetStruct.checkSum			= USBSerialConnection.getc();
			
			USBSerialConnection.printf("RECIEVED: %i, %i, %i, %i, %i, %i, %i, %i, %i\n",
				packetStruct.FnCode,
				packetStruct.p_pacingState,
				packetStruct.p_pacingMode,
				packetStruct.p_hysteresis,
				packetStruct.p_hysteresisInterval,
				packetStruct.p_vPaceAmp,
				packetStruct.p_vPaceWidth_10x,
				packetStruct.p_VRP,
				packetStruct.checkSum
			);
			
			break;
			
		case SERIAL_RECIEVE_MODE::UPDATE_DEVICE_INFO:
			
			stringRecieve(deviceID);			
			stringRecieve(deviceImplantDate);			
			stringRecieve(leadImplantDate);
			
			transmitDeviceInfo();
			
			serialRecieveMode = SERIAL_RECIEVE_MODE::UPDATE_PARAMS;
			
			break;
	}
}

bool Communications::sendEGM() {
	//Return true if data sent successfully over serial.
	return true;
}

void Communications::initEGM() {
	
}

bool Communications::connectDCM() {
	USBSerialConnection.baud(baudRate); // Set the baudrate
	USBSerialConnection.attach(this, &Communications::serialCallback); // Add an inturupt
	return true;
}

void Communications::recieveDeviceInfo() {
	
}

void Communications::transmitDeviceInfo() {
	USBSerialConnection.printf("%s\n%s\n%s\n%f\n",
		deviceID,
		deviceImplantDate,
		leadImplantDate,
		batteryVoltage/*,
		cardiac_events*/
	);
}
