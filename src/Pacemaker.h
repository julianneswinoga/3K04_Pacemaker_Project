#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"

enum class BATTERYSTATE { BOL, ERN, ERT, ERP };

class Pacemaker {
	private:
		PinName leadOneInPin;
		PinName leadTwoInPin;
		PinName leadOneOutPin;
		PinName leadTwoOutPin;
		
		Ticker paceTicker;
		
		float maxVOut;
		uint8_t txRegister;
		uint8_t rxRegister;
		float leadImpedanceThreshold;

	protected:
		char deviceID[64];
		char deviceImplantDate[64];
		char leadImplantDate[64];
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
		BATTERYSTATE getBatteryStatus();
};

#endif // PACEMAKER_H