#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "mbed.h"
#include "filter.h"
#include "FXOS8700Q.h"

enum class ACTIVITYSTATE { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Activity {
	private:
		float filteredOutput;
		Filter inputFilter();
		
		
		const float activityUpdateRate = 0.1f;
	
		uint16_t activityTimeThresholdSeconds = 5;
		float accX, accY, accZ;
		uint64_t activityCounter;
		const uint8_t activityThreshold = 5;
		Ticker updateActivityTicker;
		
	public:
		Activity();
		float getAccX();
		float getAccY();
		float getAccZ();
		void updateAcc();
		uint32_t AccReady();
		float getAccMagnitude();
		bool activity = false;
		
	protected:
		ACTIVITYSTATE getPatientActivity();
		FXOS8700Q_acc accelerometer;
		//FXOS8700Q_mag magnetometer;
		
};

#endif // ACTIVITY_H