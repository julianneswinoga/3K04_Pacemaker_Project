#include "Sense.h"

Sense::Sense()  {
	//Initialize Critical State Variables
	//setChamberSensed(); //Uses values from paceMode
	//setActivityResponse(); //Uses values from activityResponse
	setMagnetInPlace(false);
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

void Sense::setMagnetInPlace(bool inPlace) {
	magnetInPlace = inPlace;
}

bool Sense::getMagnetInPlace() {
	return magnetInPlace;
}

void Sense::measureLeadImpedance() {
	//Measure currentLeadImpedance
	leadImpedance = 100;
}

void Sense::measureBatteryVoltage() {
	//Measure battery voltage
	batteryVoltage = 3.3;
}