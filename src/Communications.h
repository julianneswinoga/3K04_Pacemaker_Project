#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"

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
	
	char deviceID[64];
	char deviceImplantDate[64];
	char leadImplantDate[64];
} SERIAL_PACKET;

enum class SERIAL_RECIEVE_MODE {
	UPDATE_PARAMS = 0,
	UPDATE_DEVICE_INFO = 1
};

class Communications {
	private:
		SERIAL_RECIEVE_MODE serialRecieveMode;
		SERIAL_PACKET packetStruct;
		uint16_t vraw;
		uint16_t f_marker;
		uint8_t o_CommOut;
		uint32_t baudRate;

		uint16_t twoByteRecieve();
		float floatRecieve();
		void stringRecieve(char *);
		
		bool connectDCM();
		void transmitDeviceInfo();
		void serialCallback();
	
	protected:
		bool sendEGM();
		void recieveDeviceInfo();
		
	public:
		Communications();
		void initEGM();
		Serial USBSerialConnection;
};

#endif // COMMUNICATIONS_H