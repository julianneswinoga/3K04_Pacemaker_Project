#ifndef HEARTMONITOR_H
#define HEARTMONITOR_H

#include "mbed.h"

class HeartMonitor {		
	public:
		HeartMonitor();
		uint16_t VRP;
		
	protected:
		uint8_t getVentricleRate();
		uint8_t getAtriumRate();
};

#endif // HEARTMONITOR_H