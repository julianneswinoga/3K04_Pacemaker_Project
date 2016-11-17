#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include "Pace.h"

typedef struct {
	uint8_t *FnCode;
	
	PACESTATE *p_pacingState;
	PACEMODE *p_pacingMode;
	uint16_t *p_hysteresis;
	uint16_t *p_hysteresisInterval;
	float *p_vPaceAmp;
	uint16_t *p_vPaceWidth_10x;
	uint16_t *p_VRP;
	
	uint8_t checkSum;
	
	char (*deviceID)[64];
	char (*deviceImplantDate)[64];
	char (*leadImplantDate)[64];
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
		void setDataPointers(uint8_t*, PACESTATE*, PACEMODE*, uint16_t*, uint16_t*, float*, uint16_t*, uint16_t*, char(*)[64], char(*)[64], char(*)[64]);
		void initEGM();
		Serial USBSerialConnection;
};

#endif // COMMUNICATIONS_H