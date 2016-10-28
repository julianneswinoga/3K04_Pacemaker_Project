#include "Pacemaker.h"

Pacemaker::Pacemaker()  {
	
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
