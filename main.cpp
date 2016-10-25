#include "mbed.h"
#include "Pacemaker.h"
#include "Communications.h"
#include "Sense.h"

DigitalOut led(LED_RED);

Serial pc(USBTX, USBRX);

int main() {
	pc.baud(9600);
	Pacemaker p();
	
	pc.printf("Pacemaker initialized\n");
	while (true) {
		led = !led; // toggle led
		pc.printf("><><>");
		wait(0.2f);
	}
}