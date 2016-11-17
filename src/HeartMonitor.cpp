#include "HeartMonitor.h"

HeartMonitor::HeartMonitor() {
	VRP = 5;
}

void HeartMonitor::setVRP(uint16_t time) {
	VRP = time;
}

uint8_t HeartMonitor::getVentricleRate() {
	return 0;
}

uint8_t HeartMonitor::getVAtriumRate() {
	return 0;
}
