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

PACEMODE Pace::getPaceMode() {
	return pacingMode;
}

PACESTATE Pace::getPaceState() {
	return pacingState;
}

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

void Pace::setPaceState(PACESTATE state) {
	switch (state)
	{
	case PERMANENT:
		pacingState = PERMANENT;
		break;
	case TEMPORARY:
		pacingState =TEMPORARY;
		break;
	case PACE_NOW:
		pacingState =PACE_NOW;
		break;
	case MAGNET:
		pacingState =MAGNET;
		break;
	case POWER_ON_RESET:
		pacingState = POWER_ON_RESET;
		break;
	}
}

void Pace::setPaceMode(PACEMODE mode) {
	switch(mode)
	{
	case OFF:
		pacingMode = OFF;
		break;
	case AAT:
		pacingMode = AAT;
		break;
	case VVT:
		pacingMode = VVT;
		break;
	case AOO:
		pacingMode = AOO;
		break;
	case AAI:
		pacingMode = AAI;
		break;
	case VOO:
		pacingMode = VOO;
		break;
	case VVI:
		pacingMode = VVI;
		break;
	case VDD:
		pacingMode = VDD;
		break;
	case DOO:
		pacingMode = DOO;
		break;
	case DDI:
		pacingMode = DDI;
		break;
	case DDD:
		pacingMode = DDD;
		break;
	case AOOR:
		pacingMode = AOOR;
		break;
	case AAIR:
		pacingMode = AAIR;
		break;
	case VOOR:
		pacingMode = VOOR;
		break;
	case VVIR:
		pacingMode = VVIR;
		break;
	case VDDR:
		pacingMode = VDDR;
		break;
	case DOOR:
		pacingMode = DOOR;
		break;
	case DDIR:
		pacingMode = DDIR;
		break;
	case DDDR:
		pacingMode = DDDR;
		break;
	}
}
