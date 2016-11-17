#include "Pacemaker.h"

Pacemaker::Pacemaker() {
	uint8_t temp1;
	uint16_t temp2;
	
	setDataPointers(
		&FnCode,
		&pacingState,
		&pacingMode,
		&temp1,
		&temp2,
		&vPaceAmp,
		&vPaceWidth_milliseconds,
		&VRP,
		&deviceID,
		&deviceImplantDate,
		&leadImplantDate
	);
}

void Pacemaker::mainLoop() {
	if (dataInBuffer)
		readBuffer();
}
