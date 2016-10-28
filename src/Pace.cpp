#include "Pace.h"

Pace::Pace()  {
	
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
