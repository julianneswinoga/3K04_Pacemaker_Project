#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"
#include "Communications.h"
#include "Sense.h"

class Pacemaker : public Communications, public Sense {
	private:		
		float maxVOut;
		uint8_t txRegister;
		uint8_t rxRegister;
		float leadImpedanceThreshold;

	protected:
		//setLeadPins([enum]);
		//[enum] getLeadPins();
		//void setTxRxReg([uint8_t]);
		//[uint8_t] getTxRxReg();
		float voltageTest(float);
		//Object getCardiacEvents();
		void clearCardiacEvents();
		
	public:
		Pacemaker();
};

#endif // PACEMAKER_H