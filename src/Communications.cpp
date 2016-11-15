#include "Communications.h"

Communications::Communications() : USBSerialConnection(USBTX, USBRX)  {
	//Initialize Critical State Variables
	baudRate = 57600;
	connectDCM();
}

uint16_t Communications::twoByteRecieve() {
	uint8_t b[2];
	
	for (uint8_t C = 0;C < sizeof(b);C++)
		b[C] = USBSerialConnection.getc();
	
	return (b[1] << 8) | b[0];
}

float Communications::floatRecieve() {
	float f;
	uint8_t b[4];
	
	for (uint8_t C = 0;C < sizeof(b);C++)
		b[C] = USBSerialConnection.getc();
	
	memcpy(&f, &b, 4);
	return f;
}

void Communications::serialCallback() {
	packetStruct.FnCode						= USBSerialConnection.getc();
	
	packetStruct.p_pacingState			= USBSerialConnection.getc();
	packetStruct.p_pacingMode			= USBSerialConnection.getc();
	packetStruct.p_hysteresis				= twoByteRecieve();
	packetStruct.p_hysteresisInterval	= twoByteRecieve();
	packetStruct.p_vPaceAmp				= twoByteRecieve();
	packetStruct.p_vPaceWidth_10x	= twoByteRecieve();
	packetStruct.p_VRP						= twoByteRecieve();
	//packetStruct.batteryVoltage			= floatRecieve();
	//packetStruct.leadImpedance			= floatRecieve();
	
	packetStruct.checkSum					= USBSerialConnection.getc();
	
	while (USBSerialConnection.getc() >= 32)
		; // Wait for null/endline termination
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
	USBSerialConnection.printf("%s\0%s\0%s\0%f\0",
		deviceID,
		deviceImplantDate,
		leadImplantDate,
		batteryVoltage/*,
		cardiac_events*/
	);
}
