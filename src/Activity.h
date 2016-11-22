#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "mbed.h"
#include "FXOS8700Q.h"

enum class ACTIVITYSTATE { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Activity {
	private:
		uint16_t activityTimeThresholdSeconds = 5;
		FXOS8700Q_acc accelerometer;
		//FXOS8700Q_mag magnetometer;
		
	public:
		Activity();
		
	protected:
		ACTIVITYSTATE getPatientActivity();
};

#endif // ACTIVITY_H