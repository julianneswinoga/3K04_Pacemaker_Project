#include "Pacemaker.h"

Pacemaker::Pacemaker()  {
	//Initialize Critical State Variables
	setMaxVOut(3.2);
}

//Protected Functions
void Pacemaker::setMaxVOut(float v) {
	maxVOut = v;
}

float Pacemaker::getMaxVOut(){
	return maxVOut;
}

float Pacemaker::voltageTest(float v){
	return 1.0;
}

void Pacemaker::clearCardiacEvents(){

}

float Pacemaker::getLeadImpedance(){
	return leadImpedance;
}

/* enum Pacemaker::getBatteryStatus(){
	//Use batteryVoltage and replaceBatteryVoltage to figure out battery status level
	return one of{BOL,ERN,ERT,ERP}
}*/



