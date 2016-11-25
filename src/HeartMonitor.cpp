#include "HeartMonitor.h"

HeartMonitor::HeartMonitor() {
	VRP = 5;
}

float HeartMonitor::getAtriumVoltage() {
	return V_REF * atrialIn;
}

float HeartMonitor::getVentricleVoltage() {
	return V_REF * ventricleIn;
}

uint8_t HeartMonitor::getVentricleRate() {
	return 0;
}

uint8_t HeartMonitor::getAtriumRate() {
	return 0;
}
