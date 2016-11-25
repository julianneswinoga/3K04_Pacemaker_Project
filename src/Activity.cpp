#include "Activity.h"

Activity::Activity() : accelerometer (PTE25, PTE24, FXOS8700CQ_SLAVE_ADDR1) /*: magnetometer (PTE25, PTE24, FXOS8700CQ_SLAVE_ADDR1)*/ {
	accelerometer.enable();
	updateActivityTicker.attach(this, &Activity::updateAcc, activityUpdateRate);
}

ACTIVITYSTATE Activity::getPatientActivity() {
	return ACTIVITYSTATE::V_LOW;
}

uint32_t Activity::AccReady() {
	return accelerometer.dataReady();
}

void Activity::updateAcc() {
	accX = getAccX();
	accY = getAccY();
	accZ = getAccZ();
	
	float accMagnitude = 0.0f;
	
	if (accMagnitudeSum <= activitySumMax) {
		accMagnitude =  getAccMagnitude() > activitySumMax - accMagnitudeSum ? activitySumMax - accMagnitudeSum : getAccMagnitude();
	}
	
	// TODO: Paramiter dependant
	accMagnitudeSum += accMagnitude - (accMagnitudeSum >= 0.01f ? 0.1 : 0);
	
	activityTrip = accMagnitudeSum > activitySumThreshold;
}

float Activity::getAccX() {
	float x;
	accelerometer.getX(&x);
	return x;
}

float Activity::getAccY() {
	float y;
	accelerometer.getY(&y);
	return y;
}

float Activity::getAccZ() {
	float z;
	accelerometer.getZ(&z);
	return z;
}

float Activity::getAccMagnitude() {
	return accX*accX + accY*accY + accZ*accZ;
}
