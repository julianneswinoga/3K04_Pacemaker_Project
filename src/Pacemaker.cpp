#include "Pacemaker.h"

Pacemaker::Pacemaker() {
	uint8_t temp1;
	uint16_t temp2;
	
	communications.setDataPointers(
		&FnCode,
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
}

void Pacemaker::mainLoop() {
	activity.updateAcc();
	
	if (communications.dataInBuffer)
		communications.readBuffer();
	
	if (communications.DCMConnected) {
		
	}
}
