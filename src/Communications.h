#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include "Pacemaker.h"

class Communications : public Pacemaker {
	private:
		uint8_t i_CommIn[16];
		uint16_t vraw;
		uint16_t f_marker;
		int i_magnet;
		//i_vs:??
		uint8_t o_CommOut;
		//o_vp:??
	public:
		Communications();
};

#endif // COMMUNICATIONS_H