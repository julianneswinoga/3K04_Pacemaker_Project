#include "Pacemaker.h"
#include "pinmap.h"

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
	
	communications.initDataStream(&pace.egramData);
}

void Pacemaker::mainLoop() {
	if (communications.dataInBuffer) {
		communications.USBSerialConnection.printf("");
		communications.readBuffer();
		communications.USBSerialConnection.printf("");
		if (fnCode == 2)
			communications.setStreamMode(true);
		if (fnCode == 3)
			communications.setStreamMode(false);
	}
}
