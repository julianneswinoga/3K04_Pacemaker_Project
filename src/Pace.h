#ifndef PACE_H
#define PACE_H

#include "mbed.h"
#include "HeartMonitor.h"

enum class PACESTATE { PERMANENT,  TEMPORARY,  PACE_NOW,  MAGNET,  POWER_ON_RESET };
enum class PACEMODE { OFF,  AAT,  VVT,  AOO,  AAI, VOO, VVI, VDD, DOO, DDI, DDD, AOOR, AAIR, VOOR, VVIR, VDDR, DOOR, DDIR, DDDR };

class Pace : public HeartMonitor {
	private:
		Ticker paceTicker;
		void setPaceRate(uint8_t);
		void paceTick();
		
		uint8_t baseHeartRate = 60;
		uint8_t maxHeartRate = 180;
		
		void paceVentricle();
		void paceAtrium();
		
	public:
		Pace();
		PACEMODE pacingMode = PACEMODE::VOO;
		PACESTATE pacingState;
		float vPaceAmp;
		uint16_t vPaceWidth_milliseconds;
		
	protected:
		PACEMODE getPaceMode();
		PACESTATE getPaceState();
		
};

#endif // PACE_H