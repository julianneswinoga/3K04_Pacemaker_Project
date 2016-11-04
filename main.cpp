#include "mbed.h"
#include "Pacemaker.h"
#include "Communications.h"
#include "Sense.h"

using namespace std;

PwmOut pwmPort(D13);
DigitalOut led_red(LED_RED);

float waitTime = 0.1f;
float increase = 0.05f;

int main() {	
	Communications comms;
	comms.startSerial();
	
	Pacemaker p();
	led_red = 0;
	
	while (true) {		
		for (float i = 0.0f;i < 1.0f;i += increase) {			
			pwmPort.write(i);
			comms.USBSerialConnection.printf("%f\n", i);
			wait(waitTime);
		}
	}
}