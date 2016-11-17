#include "Pacemaker.h"

Pacemaker::Pacemaker() {
	setDataPointers(
		&FnCode,
		&pacingState,
		&pacingMode,
		NULL,
		NULL,
		&vPaceAmp,
		&vPaceWidth_milliseconds,
		&VRP,
		&deviceID,
		&deviceImplantDate,
		&leadImplantDate
	);
}

void Pacemaker::mainLoop() {
	
}
