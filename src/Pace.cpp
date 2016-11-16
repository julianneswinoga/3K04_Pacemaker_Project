#include "Pace.h"

DigitalOut led(LED1);

Pace::Pace() {
	//Initialize Critical State Variables
	setHysteresisInterval(0);
	setvPaceAmp(3.2f);
	setvPaceWidth(0);
	setLowRateInterval(10);
	setMaxHeartRate(180);
	setBaseHeartRate(60);
	paceTime = 0.3;
	led = 0;
	
	paceTicker.attach(this, &Pace::paceTick, paceTime);
}

void Pace::paceTick() {
	led = led == 1 ? 0 : 1;
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
	switch (state) {
		default:
		case PACESTATE::PERMANENT:
			pacingState = PACESTATE::PERMANENT;
			break;
		case PACESTATE::TEMPORARY:
			pacingState =PACESTATE::TEMPORARY;
			break;
		case PACESTATE::PACE_NOW:
			pacingState =PACESTATE::PACE_NOW;
			break;
		case PACESTATE::MAGNET:
			pacingState =PACESTATE::MAGNET;
			break;
		case PACESTATE::POWER_ON_RESET:
			pacingState = PACESTATE::POWER_ON_RESET;
			break;
	}
}

void Pace::setPaceMode(PACEMODE mode) {
	switch(mode) {
		default:
		case PACEMODE::OFF:
			pacingMode = PACEMODE::OFF;
			break;
		case PACEMODE::AAT:
			pacingMode = PACEMODE::AAT;
			break;
		case PACEMODE::VVT:
			pacingMode = PACEMODE::VVT;
			break;
		case PACEMODE::AOO:
			pacingMode = PACEMODE::AOO;
			break;
		case PACEMODE::AAI:
			pacingMode = PACEMODE::AAI;
			break;
		case PACEMODE::VOO:
			pacingMode = PACEMODE::VOO;
			break;
		case PACEMODE::VVI:
			pacingMode = PACEMODE::VVI;
			break;
		case PACEMODE::VDD:
			pacingMode = PACEMODE::VDD;
			break;
		case PACEMODE::DOO:
			pacingMode = PACEMODE::DOO;
			break;
		case PACEMODE::DDI:
			pacingMode = PACEMODE::DDI;
			break;
		case PACEMODE::DDD:
			pacingMode = PACEMODE::DDD;
			break;
		case PACEMODE::AOOR:
			pacingMode = PACEMODE::AOOR;
			break;
		case PACEMODE::AAIR:
			pacingMode = PACEMODE::AAIR;
			break;
		case PACEMODE::VOOR:
			pacingMode = PACEMODE::VOOR;
			break;
		case PACEMODE::VVIR:
			pacingMode = PACEMODE::VVIR;
			break;
		case PACEMODE::VDDR:
			pacingMode = PACEMODE::VDDR;
			break;
		case PACEMODE::DOOR:
			pacingMode = PACEMODE::DOOR;
			break;
		case PACEMODE::DDIR:
			pacingMode = PACEMODE::DDIR;
			break;
		case PACEMODE::DDDR:
			pacingMode = PACEMODE::DDDR;
			break;
	}
}
