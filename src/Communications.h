#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include "Pacemaker.h"
#include <string>

typedef struct {
	uint8_t p_pacingState;
	uint8_t p_pacingMode;
	uint16_t p_hysteresis;
	uint16_t p_hysteresisInterval;
	uint16_t p_vPaceAmp;
	uint16_t p_vPaceWidth_10x;
	uint16_t p_VRP;
	float batteryVoltage;
	float leadImpedance;
} RECEV_PACKET;

class Communications : public Pacemaker {
	private:
		RECEV_PACKET packetStruct;
		uint16_t vraw;
		uint16_t f_marker;
		//i_vs:??
		uint8_t o_CommOut;
		//o_vp:??
		uint32_t baudRate;

		uint16_t twoByteRecieve();
		float floatRecieve();
		bool connectDCM();
		//void transmitDeviceInfo();
		void serialCallback();
		
	public:
		Communications();
		void initEGM();
		void startSerial();
		//void debug(string msg, ...);
		
		Serial USBSerialConnection;
		
	protected:
		bool sendEGM();
		//string[] recieveDeviceInfo();

};

#endif // COMMUNICATIONS_H