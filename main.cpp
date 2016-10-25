#include "mbed.h"
#include "Pacemaker.h"

<<<<<<< HEAD
DigitalOut gpo(D0);
DigitalOut led(LED_BLUE);
=======
DigitalOut led(LED_RED);
>>>>>>> master

Serial pc(USBTX, USBRX);

int main() {
	pc.baud(9600);
    pc.printf("Pacemaker initialized\n");
    while (true) {
        led = !led; // toggle led
		pc.printf("ECH\n");
        wait(0.2f);
    }
}