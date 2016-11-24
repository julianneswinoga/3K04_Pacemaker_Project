#include "Pacemaker.h"

float acc;

Pacemaker::Pacemaker() {
	uint8_t temp1;
	uint16_t temp2;
	
	communications.setDataPointers(
		&fnCode,
		&pace.pacingState,
		&pace.pacingMode,
		&temp1,
		&temp2,
		&pace.vPaceAmp,
		&pace.vPaceWidth_milliseconds,
		&pace.VRP,
		&deviceID,
		&deviceImplantDate,
		&leadImplantDate
	);
	
	communications.initDataStream(&activity.accMagnitudeSum);
}

void Pacemaker::mainLoop() {
	if (communications.dataInBuffer) {
		communications.readBuffer();
		if (fnCode == 2)
			communications.setStreamMode(true);
		if (fnCode == 3)
			communications.setStreamMode(false);
	}
	
	acc = activity.getAccMagnitude();
}
