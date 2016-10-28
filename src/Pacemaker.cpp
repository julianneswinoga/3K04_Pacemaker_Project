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

void Pacemaker::setLeadImpedance(float i){
	leadImpedance = i;
}

float Pacemaker::getLeadImpedance(){
	return leadImpedance;
}
