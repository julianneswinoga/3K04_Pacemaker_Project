#ifndef HEARTMONITOR_H
#define HEARTMONITOR_H

#include "mbed.h"

class HeartMonitor {
	private:
		uint16_t VRP;
		
	public:
		HeartMonitor();
		
	protected:
		void setVRP(uint16_t);
		uint8_t getVentricleRate();
		uint8_t getVAtriumRate();
};

#endif // HEARTMONITOR_H