#include "Communications.h"

Communications::Communications() : USBSerialConnection(USBTX, USBRX)  {
	//Initialize Critical State Variables
	baudRate = 57600;
}

void Communications::serialCallback() {
	char buf[128]; // char array to store serial buffer
	char data; // Actual data byte coming in
	int i;
	for(i = 0; (data = USBSerialConnection.getc()) >= 32; i++) // While there are visible characters (catches both \r and \n)
		buf[i] = data; // Store the data
	
	buf[i] = '\0'; // Make buf a null terminated C string
	
	switch (buf[0]) {
		case 'W':
			/*char* numStr = strtok(buf, ":");
			numStr = strtok(NULL, ":");
			sscanf(numStr, "%f", &waitTime);*/
			break;
	}
}

void Communications::startSerial() {
	USBSerialConnection.baud(baudRate); // Set the baudrate
	USBSerialConnection.attach(this, &Communications::serialCallback); // Add an inturupt
}

/*void Communications::debug(string msg, ...) {
	va_list args;
	USBSerialConnection.vprintf(msg, args);
}*/

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