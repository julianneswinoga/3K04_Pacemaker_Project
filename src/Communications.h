#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include "Pacemaker.h"
#include <string>

typedef struct {
	uint8_t FnCode;
	
	uint8_t p_pacingState;
	uint8_t p_pacingMode;
	uint16_t p_hysteresis;
	uint16_t p_hysteresisInterval;
	uint16_t p_vPaceAmp;
	uint16_t p_vPaceWidth_10x;
	uint16_t p_VRP;
	float batteryVoltage;
	float leadImpedance;
	
	uint8_t checkSum;
} RECEV_PACKET;

enum class SERIAL_RECIEVE_MODE { UPDATE_PARAMS, UPDATE_DEVICE_INFO };

class Communications : public Pacemaker {
	private:
		SERIAL_RECIEVE_MODE serialRecieveMode
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
		void transmitDeviceInfo();
		void serialCallback();
		
	public:
		Communications();
		void initEGM();
		
		Serial USBSerialConnection;
		
	protected:
		bool sendEGM();
		void recieveDeviceInfo();

};

#endif // COMMUNICATIONS_H