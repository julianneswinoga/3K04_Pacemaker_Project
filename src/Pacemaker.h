#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"
#include <string>

class Pacemaker {
	private:
		PinName leadOneInPin;
		PinName leadTwoInPin;
		PinName leadOneOutPin;
		PinName leadTwoOutPin;
		
		string deviceID;
		string deviceImplantDate;
		string leadImplantDate;
		float maxVOut;
		uint8_t txRegister;
		uint8_t rxRegister;
		float leadImpedanceThreshold;

	protected:
		float leadImpedance;
		float replaceBatteryVoltage;
		float batteryVoltage;

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
		//enum getBatteryStatus()
};

#endif // PACEMAKER_H