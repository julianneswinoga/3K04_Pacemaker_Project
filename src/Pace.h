#ifndef PACE_H
#define PACE_H

#include "mbed.h"
#include "Sense.h"

class Pace : public Sense {
	private:
		//pacingState: enum
		//pacingMode: enum
		bool hysteresis;
		uint16_t hysteresisInterval;
		uint16_t lowrateInterval;
		uint16_t vPaceAmp;
		uint16_t vPaceWidth;
		uint16_t VRP;
		
	public:
		Pace();
		//enum getPaceMode();
		//enum getPaceState();
		uint16_t getHysteresisInterval();
		uint16_t getLowRateInterval();
		uint16_t getvPaceAmp();
		uint16_t getvPaceWidth();
		uint16_t getVRP();
		
	protected:
		//void setPaceMode(enum);
		//void setPaceState(enum);
		void setHysteresisInterval(uint16_t);
		void setLowRateInterval(uint16_t);
		void setvPaceAmp(uint16_t);
		void setvPaceWidth(uint16_t);
		void setVRP(uint16_t);
		
		
		
		
		
		


};

#endif // PACE_H