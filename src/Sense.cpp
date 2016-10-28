#include "Sense.h"

Sense::Sense()  {
	//Initialize Critical State Variables
	//setChamberSensed(); //Uses values from paceMode
	//setActivityResponse(); //Uses values from activityResponse
	setMagnetInPlace(false);
}

/*void Sense::setChamberSensed(enum c){
	chambersSensed = c;
}

void Sense::setActivityResponse(enum a){
	activityResponse = a;
}

enum Sense::getChamberSensed(){
	return chamberSensed;
}

enum Sense::getActivityResponse(){
	return activityResponse;
}*/

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