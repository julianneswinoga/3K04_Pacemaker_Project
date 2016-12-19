#include "mbed.h"
#include "Pacemaker.h"

int main() {
	Pacemaker p;
	
	while (true) {
		p.mainLoop();
	}
}
