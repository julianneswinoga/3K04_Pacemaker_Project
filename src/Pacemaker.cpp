#include "Pacemaker.h"

float fuck;

Pacemaker::Pacemaker() : pace(&activity.activityTrip) {
	uint8_t histeresits;
	uint16_t histeresisInterval;
	
	communications.setDataPointers(
		&fnCode,
		&pace.pacingState,
		&pace.pacingMode,
		&histeresits,
		&histeresisInterval,
		&pace.vPaceAmp,
		&pace.vPaceWidth_milliseconds,
		&pace.VRP,
		&pace.baseHeartRate,
		&pace.maxHeartRate,
		&deviceID,
		&deviceImplantDate,
		&leadImplantDate
	);
	
	
	
	communications.initDataStream(&fuck);
}

void Pacemaker::mainLoop() {
	if (communications.dataInBuffer) {
		communications.readBuffer();
		if (fnCode == 2)
			communications.setStreamMode(true);
		if (fnCode == 3)
			communications.setStreamMode(false);
	}
	fuck = (float)*pace.activityTrip;
}
