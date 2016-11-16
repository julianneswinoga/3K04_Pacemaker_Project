#include "Sense.h"

Sense::Sense()  {
	//Initialize Critical State Variables
	//setChamberSensed(); //Uses values from paceMode
	//setActivityResponse(); //Uses values from activityResponse
}

void Sense::setChambersSensed(CHAMBERS c) {
	chambersSensed = c;
}


void Sense::setActivityResponse(ACTIVITYRESPONSE a) {
	activityResponse = a;
}

CHAMBERS Sense::getChambersSensed() {
	return chambersSensed;
}

ACTIVITYRESPONSE Sense::getActivityResponse() {
	return activityResponse;
}

void Sense::setActivityThreshold(ACTIVITYTHRESHOLD t) {
	activityThreshold = t;
}

ACTIVITYTHRESHOLD Sense::getActivityThreshold() {
	return activityThreshold;
}

bool Sense::getMagnetInPlace() {
	return false;
}

float Sense::measureLeadImpedance() {
	//Measure currentLeadImpedance
	return 100;
}

float Sense::measureBatteryVoltage() {
	//Measure battery voltage
	return 3.3;
}

BATTERYSTATE Sense::getBatteryStatus() {
	float batteryVoltage = measureBatteryVoltage();
	
	if (batteryVoltage <= replaceBatteryVoltage)
		return BATTERYSTATE::ERT;
	else if (batteryVoltage >= 0.70 * replaceBatteryVoltage)
		return BATTERYSTATE::BOL;
	else if (batteryVoltage > replaceBatteryVoltage && batteryVoltage < 0.70 * replaceBatteryVoltage)
		return BATTERYSTATE::ERN;
	else
		return BATTERYSTATE::ERP;
}
