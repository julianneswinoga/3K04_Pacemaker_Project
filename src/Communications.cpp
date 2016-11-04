#include "Communications.h"

Communications::Communications() : USBSerialConnection(USBTX, USBRX)  {
	//Initialize Critical State Variables
	baudRate = 57600;
}

void Communications::serialCallback() {
	char buf[128];
	char data;
	int i;
	for(i = 0;(data = USBSerialConnection.getc()) >= 32;i++)
		buf[i] = data;
	
	buf[i] = '\0';
	
	USBSerialConnection.printf("LOL%s\n", buf);
	switch (buf[0]) {
		case 'W':
			/*char* numStr = strtok(buf, ":");
			numStr = strtok(NULL, ":");
			sscanf(numStr, "%f", &waitTime);*/
			break;
	}
}

void Communications::startSerial() {
	USBSerialConnection.baud(baudRate);
	USBSerialConnection.attach(this, &Communications::serialCallback);
}

bool Communications::sendEGM() {
	//Return true if data sent successfully over serial.
	return true;
}

void Communications::initEGM() {
	
}

bool Communications::connectDCM() {
	//Returns true if connection successful
	return true;
}

/*string[] Communications::recieveDeviceInfo() {
	return [deviceID]
}

void Communications::transmitDeviceInfo([deviceID]) {

}*/