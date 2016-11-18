#include "Communications.h"

Communications::Communications() : USBSerialConnection(USBTX, USBRX)  {
	//Initialize Critical State Variables
	baudRate = 57600;
	connectDCM();
	serialRecieveMode = SERIAL_RECIEVE_MODE::UPDATE_DEVICE_INFO;
}

void Communications::setDataPointers(
		uint8_t *FnCode,
		PACESTATE *p_pacingState,
		PACEMODE *p_pacingMode,
		uint8_t *p_hysteresis,
		uint16_t *p_hysteresisInterval,
		float *p_vPaceAmp,
		uint16_t *p_vPaceWidth_10x,
		uint16_t *p_VRP,
		char (*deviceID)[64],
		char (*deviceImplantDate)[64],
		char (*leadImplantDate)[64]
	) {
				
	packetStruct.FnCode = FnCode;
	
	packetStruct.p_pacingState = p_pacingState;
	packetStruct.p_pacingMode = p_pacingMode;
	packetStruct.p_hysteresis = p_hysteresis;
	packetStruct.p_hysteresisInterval = p_hysteresisInterval;
	packetStruct.p_vPaceAmp = p_vPaceAmp;
	packetStruct.p_vPaceWidth_10x = p_vPaceWidth_10x;
	packetStruct.p_VRP = p_VRP;
	
	packetStruct.deviceID = deviceID;
	packetStruct.deviceImplantDate = deviceImplantDate;
	packetStruct.leadImplantDate = leadImplantDate;
}

uint16_t Communications::twoBytesFromBuffer(volatile uint8_t buffer[], uint16_t position) {
	return (buffer[position + 1] << 8) | buffer[position];
}

float Communications::floatFromBuffer(volatile uint8_t buffer[], uint16_t position) {
	union {
	    float f;
	    unsigned long ul;
	 } floatConv;
	
	floatConv.ul = (buffer[position + 3] << 24) | (buffer[position + 2] << 16) | (buffer[position + 1] << 8) | buffer[position];
	return floatConv.f;
}

void Communications::stringsFromBuffer(volatile uint8_t buffer[], uint8_t numStrings ...) {
	va_list strings;
	
	va_start(strings, numStrings);
	char (*tempStr)[64];
	uint16_t bufferPos = 0, stringPos;
	
	for (uint8_t C = 0; C < numStrings; C++) {
		tempStr = va_arg(strings, char(*)[64]);
		stringPos = 0;
		while(buffer[bufferPos] != '\n') {
			(*tempStr)[stringPos] = buffer[bufferPos];
			stringPos++;
			bufferPos++;
		}
		(*tempStr)[stringPos] = '\0'; // Make C string
		bufferPos++;
	}
	
	va_end(strings);
}

void Communications::serialCallback() {
	uint16_t bufferPosition = 0;
	
	switch (serialRecieveMode) {
		case SERIAL_RECIEVE_MODE::UPDATE_PARAMS:
		
			for (bufferPosition = 0; bufferPosition < 15; bufferPosition++)
				serialBuffer[bufferPosition] = USBSerialConnection.getc();
			
			break;
			
		case SERIAL_RECIEVE_MODE::UPDATE_DEVICE_INFO:
			
			uint8_t newlineCount = 0;
			
			while (newlineCount < 3) {
				serialBuffer[bufferPosition] = USBSerialConnection.getc();
				newlineCount += serialBuffer[bufferPosition] == '\n';
				bufferPosition++;
			}
			
			break;
	}
	dataInBuffer = true;
}

void Communications::readBuffer() {	
	switch (serialRecieveMode) {
		case SERIAL_RECIEVE_MODE::UPDATE_PARAMS:
			
			*packetStruct.FnCode					= serialBuffer[0];
			
			*packetStruct.p_pacingState			= (PACESTATE) serialBuffer[1];
			*packetStruct.p_pacingMode			= (PACEMODE) serialBuffer[2];
			*packetStruct.p_hysteresis				= serialBuffer[3];
			
			*packetStruct.p_hysteresisInterval		= twoBytesFromBuffer(serialBuffer, 4);
			*packetStruct.p_vPaceAmp				= floatFromBuffer(serialBuffer, 6);
			*packetStruct.p_vPaceWidth_10x		= twoBytesFromBuffer(serialBuffer, 10);
			*packetStruct.p_VRP					= twoBytesFromBuffer(serialBuffer, 12);
			
			packetStruct.checkSum					= serialBuffer[14];
			
			USBSerialConnection.printf("RECIEVED: %i, %i, %i, Hist:%i, hInt:%i, PAmp:%f, PWid:%i, VRP:%i, Chk:%i\n",
				*packetStruct.FnCode,
				*packetStruct.p_pacingState,
				*packetStruct.p_pacingMode,
				*packetStruct.p_hysteresis,
				*packetStruct.p_hysteresisInterval,
				*packetStruct.p_vPaceAmp,
				*packetStruct.p_vPaceWidth_10x,
				*packetStruct.p_VRP,
				packetStruct.checkSum
			);
			
			break;
			
		case SERIAL_RECIEVE_MODE::UPDATE_DEVICE_INFO:
			stringsFromBuffer(serialBuffer, 3, packetStruct.deviceID, packetStruct.deviceImplantDate, packetStruct.leadImplantDate);
			
			transmitDeviceInfo();
			
			serialRecieveMode = SERIAL_RECIEVE_MODE::UPDATE_PARAMS;
			
			break;
	}
	
	dataInBuffer = false;
}

bool Communications::sendEGM() {
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
		*packetStruct.deviceID,
		*packetStruct.deviceImplantDate,
		*packetStruct.leadImplantDate
		//batteryVoltage,
		//cardiac_events
	);
}
