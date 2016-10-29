#include "Communications.h"

Communications::Communications()  {
	//Initialize Critical State Variables
	baudRate = 57600;
}

bool Communications::sendEGM() {
	//Return true if data sent successfully over serial.
	return true;
}

void Communications::initEGM() {
	
}

bool Communications::connectDCM(){
	//Returns true if connection successful
	return true;
}

/*string[] Communications::recieveDeviceInfo(){
	return [deviceID]
}

void Communications::transmitDeviceInfo([deviceID]){

}*/