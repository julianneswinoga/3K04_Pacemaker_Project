#ifndef PACE_H
#define PACE_H

#include "mbed.h"
#include "HeartMonitor.h"

enum class PACESTATE { PERMANENT,  TEMPORARY,  PACE_NOW,  MAGNET,  POWER_ON_RESET };
enum class PACEMODE { OFF,  AAT,  VVT,  AOO,  AAI, VOO, VVI, VDD, DOO, DDI, DDD, AOOR, AAIR, VOOR, VVIR, VDDR, DOOR, DDIR, DDDR };

class Pace : public HeartMonitor {
	private:
		Ticker paceTicker;
		Timeout changeVar[6];
		uint8_t prevBPM = 0;
		
		void paceTick();
		void paceVentricle();
		void paceAtrium();
		void paceVentricleStage1();
		void paceVentricleStage2();
		void paceVentricleStage3();
		void paceVentricleStage4();
		void paceVentricleStage5();
		void paceVentricleStage6();
		
	public:
		float egramData = 0.0f;
		float vPaceAmp;
		uint16_t vPaceWidth_milliseconds = 100;
		uint8_t baseHeartRate = 60;
		uint8_t maxHeartRate = 180;
		PACEMODE pacingMode = PACEMODE::VOO;
		PACESTATE pacingState;
		bool *activityTrip;
		
		Pace(bool*);
		void setPaceRate(uint8_t);
		void updateEgramData();
		
	protected:
		PACEMODE getPaceMode();
		PACESTATE getPaceState();
};

#endif // PACE_H