#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"

class Pacemaker {
	private:
		PinName leadOneInPin;
		PinName leadTwoInPin;
		PinName leadOneOutPin;
		PinName leadTwoOutPin;
		
		uint16_t maxVOut;
		uint8_t comPort;
		uint8_t txRegister;
		uint8_t rxRegister;
	 
	public:
		Pacemaker();
};

#endif // PACEMAKER_H