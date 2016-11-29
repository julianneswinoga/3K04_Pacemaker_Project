#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include "mbed.h"
#include <cstdarg>
#include "Pace.h"

#define UPDATE_DEVICE_INFO		0
#define UPDATE_PARAMS			1
#define DCM_START_STREAM_SIG	2
#define DCM_STOP_STREAM_SIG	3
#define DCM_CONNECT_SIG		4
#define DCM_DISCONNECT_SIG	5

typedef struct {
	uint8_t *fnCode;
	
	PACESTATE *p_pacingState;
	PACEMODE *p_pacingMode;
	uint8_t *p_hysteresis;
	uint16_t *p_hysteresisInterval;
	float *p_vPaceAmp;
	uint16_t *p_vPaceWidth_10x;
	uint16_t *p_VRP;
	uint8_t *p_baseHeartRate;
	uint8_t *p_maxHeartRate;
	
	uint8_t checkSum;
	
	char (*deviceID)[64];
	char (*deviceImplantDate)[64];
	char (*leadImplantDate)[64];
} SERIAL_PACKET;

class Communications {
	private:
		Ticker streamDataTicker;
		bool streaming = false;
		bool DCMConnected = false;
		float dataStreamRate = 0.005;
		float *streamingData;
	
		volatile uint8_t serialBuffer[256];
		volatile SERIAL_PACKET packetStruct;
		uint32_t baudRate;

		uint16_t twoBytesFromBuffer(volatile uint8_t[], uint16_t);
		float floatFromBuffer(volatile uint8_t[], uint16_t);
		void stringsFromBuffer(volatile uint8_t[], uint8_t, ...);
		void serialCallback();
		void transmitDeviceInfo();
		void streamDataTick();
		
	public:
		bool dataInBuffer = false;
		Serial USBSerialConnection;
		
		Communications();
		void setDataPointers(uint8_t*, PACESTATE*, PACEMODE*, uint8_t*, uint16_t*, float*, uint16_t*, uint16_t*, uint8_t*, uint8_t*, char(*)[64], char(*)[64], char(*)[64]);
		void readBuffer();
		void initDataStream(float*);
		void setStreamMode(bool);
};

#endif // COMMUNICATIONS_H