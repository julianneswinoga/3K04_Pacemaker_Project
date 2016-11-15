#ifndef PACE_H
#define PACE_H

#include "mbed.h"
#include "Sense.h"

typedef enum {PERMANENT,TEMPORARY,PACE_NOW,MAGNET,POWER_ON_RESET} PACESTATE;
typedef enum {OFF,AAT,VVT,AOO,AAI,VOO,VVI,VDD,DOO,DDI,DDD,AOOR,
			  AAIR,VOOR,VVIR,VDDR,DOOR,DDIR,DDDR} PACEMODE;

class Pace : public Sense {
	private:
		PACESTATE pacingState;
		PACEMODE pacingMode;
		bool hysteresis;
		uint16_t hysteresisInterval;
		uint16_t lowrateInterval;
		uint16_t vPaceAmp;
		uint16_t vPaceWidth;
		uint16_t VRP;
		uint8_t maxHeartRate;
		uint8_t baseHeartRate;
		
	public:
		Pace();
		PACEMODE getPaceMode();
		PACESTATE getPaceState();
		uint16_t getHysteresisInterval();
		uint16_t getLowRateInterval();
		uint16_t getvPaceAmp();
		uint16_t getvPaceWidth();
		uint16_t getVRP();
		uint8_t getMaxHeartRate();
		uint8_t getBaseHeartRate();
		
	protected:
		void setPaceMode(PACEMODE);
		void setPaceState(PACESTATE);
		void setHysteresisInterval(uint16_t);
		void setLowRateInterval(uint16_t);
		void setvPaceAmp(uint16_t);
		void setvPaceWidth(uint16_t);
		void setVRP(uint16_t);
		void setMaxHeartRate(uint8_t);
		void setBaseHeartRate(uint8_t);

};

#endif // PACE_H