#include "Sense.h"

Sense::Sense()  {
	//Initialize Critical State Variables
	//setChamberSensed(); //Uses values from paceMode
	//setActivityResponse(); //Uses values from activityResponse
	setMagnetInPlace(false);
}

void Sense::setChambersSensed(chambers::CHAMBERS c){
	chambersSensed = c;
}


void Sense::setActivityResponse(activityresponse::ACTIVITYRESPONSE a){
	activityResponse = a;
}

chambers::CHAMBERS Sense::getChambersSensed(){
	return chambersSensed;
}

activityresponse::ACTIVITYRESPONSE Sense::getActivityResponse(){
	return activityResponse;
}

void Sense::setActivityThreshold(ACTIVITYTHRESHOLD t){
	activityThreshold = t;
}

ACTIVITYTHRESHOLD Sense::getActivityThreshold(){
	return activityThreshold;
}

void Sense::setMagnetInPlace(bool m){
	magnetInPlace = m;
}

bool Sense::getMagnetInPlace(){
	return magnetInPlace;
}

void Sense::measureLeadImpedance(){
	//Measure currentLeadImpedance
	leadImpedance = 100;
}

void Sense::measureBatteryVoltage(){
	//Measure battery voltage
	batteryVoltage = 3.3;
}