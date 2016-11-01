#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include "Pacemaker.h"
#include <string>

class Communications : public Pacemaker {
	private:
		uint8_t i_CommIn[16];
		uint16_t vraw;
		uint16_t f_marker;
		//i_vs:??
		uint8_t o_CommOut;
		//o_vp:??
		uint32_t baudRate;

		bool connectDCM();
		//void transmitDeviceInfo();
		
	public:
		Communications();
		void initEGM();
		
	protected:
		bool sendEGM();
		//string[] recieveDeviceInfo();

};

#endif // COMMUNICATIONS_H