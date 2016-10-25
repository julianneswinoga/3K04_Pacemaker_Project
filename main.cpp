#include "mbed.h"
#include "Pacemaker.h"

DigitalOut led(LED_RED);

Serial pc(USBTX, USBRX);

int main() {
	pc.baud(9600);
	Pacemaker p(5);
	
	pc.printf("Pacemaker initialized\n");
	while (true) {
		led = !led; // toggle led
		pc.printf("><><>%i\n", p.publicThing);
		wait(0.2f);
	}
}