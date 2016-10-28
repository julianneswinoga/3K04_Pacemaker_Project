#include "mbed.h"
#include "Pacemaker.h"
#include "Communications.h"
#include "Sense.h"

PwmOut led(D13);
Serial pc(USBTX, USBRX);

int main() {
	pc.baud(9600);
	Pacemaker p();
	
	pc.printf("Pacemaker initialized\n");
	while (true) {
		for (float i = 0.0f;i < 1.0f;i+=0.05f) {
			led.write(i);
			wait(0.1f);
		}
		pc.printf(".");
	}
}