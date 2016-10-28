#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"

class Pacemaker {
	private:
		PinName leadOneInPin;
		PinName leadTwoInPin;
		PinName leadOneOutPin;
		PinName leadTwoOutPin;
		
		uint32_t deviceID;
		float batteryVoltage;
		float maxVOut;
		uint8_t txRegister;
		uint8_t rxRegister;
		float leadImpedanceThreshold;

	protected:
		float leadImpedance;

		//setLeadPins([enum]);
		//[enum] getLeadPins();
		void setMaxVOut(float);
		float getMaxVOut();
		//void setTxRxReg([uint8_t]);
		//[uint8_t] getTxRxReg();
		float voltageTest(float);
		//Object getCardiacEvents();
		void clearCardiacEvents();
		void setLeadImpedance(float);
		float getLeadImpedance();

	 
	public:
		Pacemaker();
};

#endif // PACEMAKER_H