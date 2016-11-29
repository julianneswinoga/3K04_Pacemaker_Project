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
		if (fnCode == DCM_START_STREAM_SIG)
			communications.setStreamMode(true);
		if (fnCode == DCM_STOP_STREAM_SIG)
			communications.setStreamMode(false);
	}
	
	pace.updateEgramData();
}
