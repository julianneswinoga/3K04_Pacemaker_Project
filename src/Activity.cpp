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
	
	if (getAccMagnitude() >= 3.0) { // TODO: Implement low pass filter
		activityCounter++;
	} else {
		activityCounter--;
	}
	
	activity = activityCounter > activityThreshold;
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
