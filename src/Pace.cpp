#include "Pace.h"

Pace::Pace()  {
	//Initialize Critical State Variables
	setHysteresisInterval(0);
	setvPaceAmp(getMaxVOut());
	setvPaceWidth(0);
	setLowRateInterval(10);
	setMaxHeartRate(180);
	setBaseHeartRate(60);
}

// Public functions
uint16_t Pace::getHysteresisInterval() {
	return hysteresisInterval;
}

uint16_t Pace::getLowRateInterval() {
	return lowrateInterval;
}

uint16_t Pace::getvPaceAmp() {
	return vPaceAmp;
}

uint16_t Pace::getvPaceWidth() {
	return vPaceWidth;
}

uint16_t Pace::getVRP() {
	return VRP;
}

uint8_t Pace::getMaxHeartRate() {
	return maxHeartRate;
}

uint8_t Pace::getBaseHeartRate() {
	return baseHeartRate;
}

/*enum Pace::getPaceMode() {
	return paceMode;
}

enum Pace::getPaceState() {
	return paceState;
}*/

// Protected functions
void Pace::setHysteresisInterval(uint16_t h) {
	hysteresisInterval = h;
}

void Pace::setLowRateInterval(uint16_t l) {
	lowrateInterval = l;
}

void Pace::setvPaceAmp(uint16_t p) {
	vPaceAmp = p;
}

void Pace::setvPaceWidth(uint16_t p) {
	vPaceWidth = p;
}

void Pace::setVRP(uint16_t p) {
	VRP = p;
}

void Pace::setMaxHeartRate(uint8_t h) {
	maxHeartRate = h;
}

void Pace::setBaseHeartRate(uint8_t h) {
	baseHeartRate = h;
}

/*void Pace::setPaceState(enum state) {
	switch (state)
	{
	
	case PERMANENT:

	case TEMPORARY:

	case PACE_NOW:

	case MAGNET:

	case POWER_ON_INPLACE:

	}
}

void Pace::setPaceMode(enum mode) {
	switch(mode):
	{
	case Off:

	case AAT:

	case VVT:
	
	case AOO:

	case AAI:

	case VVI:

	case VDD:

	case DOO:

	case DDI:

	case DDD:

	case AOOR:

	case AAIR:

	case COOR:

	case VVIR:

	case VDDR:

	case DOOR:

	case DDIR:

	case DDDR:
	
	}
}*/
