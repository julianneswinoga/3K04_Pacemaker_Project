#include "mbed.h"
#include "Pacemaker.h"
#include "Communications.h"
#include "Sense.h"

float waitTime = 0.1f;
float increase = 0.05f;

int main() {
	Communications comms;
	Pacemaker p();
	
	while (true) {
		//comms.USBSerialConnection.printf("AAAAAAAAAAAAAAAAA\n");
	}
}