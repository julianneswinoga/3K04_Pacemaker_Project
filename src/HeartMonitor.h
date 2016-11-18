#ifndef HEARTMONITOR_H
#define HEARTMONITOR_H

#include "mbed.h"

class HeartMonitor {
	private:
		
	public:
		HeartMonitor();
		
	protected:
		uint16_t VRP;
		uint8_t getVentricleRate();
		uint8_t getAtriumRate();
};

#endif // HEARTMONITOR_H