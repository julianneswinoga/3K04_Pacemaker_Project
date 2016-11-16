#include "mbed.h"
#include "Pacemaker.h"
#include "Communications.h"
#include "Sense.h"
#include "Pace.h"

int main() {
	Communications comms;
	Pacemaker p();
	Pace pacer;
	
	while (true) {
		//comms.USBSerialConnection.printf("AAAAAAAAAAAAAAAAA\n");
	}
}