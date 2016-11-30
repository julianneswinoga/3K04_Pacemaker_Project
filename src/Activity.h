#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "mbed.h"
#include "FXOS8700Q.h"

enum class ACTIVITYSTATE { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Activity {
	private:
		const float activityUpdateRate = 0.1f;
		const float activitySumMax = 30.0f;
		const float activitySumThreshold = 20.0f;
		
		uint16_t activityTimeThresholdSeconds = 5;
		float accX, accY, accZ;
		Ticker updateActivityTicker;
		
		void updateAcc();
		
	public:
		float accMagnitudeSum = 0.0f;
		bool activityTrip = false;
		uint64_t activityCounter;
		
		Activity();
		float getAccX();
		float getAccY();
		float getAccZ();
		uint32_t AccReady();
		float getAccMagnitude();
		
	protected:
		ACTIVITYSTATE getPatientActivity();
		FXOS8700Q_acc accelerometer;
		//FXOS8700Q_mag magnetometer;
		
};

#endif // ACTIVITY_H