#include "Pace.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Pace::Pace() {
	led1 = 0;
	led2 = 0;
	
	setPaceRate(baseHeartRate);
}

void Pace::setPaceRate(uint8_t BPM) {
	paceTicker.attach(this, &Pace::paceTick, 1.0f/BPM);
}

void Pace::paceTick() {
	switch (pacingMode) {
		case PACEMODE::OFF:
			break;
		case PACEMODE::AAT:
			break;
		case PACEMODE::VVT:
			break;
		case PACEMODE::AOO:
			paceAtrium();
			break;
		case PACEMODE::AAI:
			break;
		default:
		case PACEMODE::VOO:
			paceVentricle();
			break;
		case PACEMODE::VVI:
			break;
		case PACEMODE::VDD:
			break;
		case PACEMODE::DOO:
			break;
		case PACEMODE::DDI:
			break;
		case PACEMODE::DDD:
			break;
		case PACEMODE::AOOR:
			break;
		case PACEMODE::AAIR:
			break;
		case PACEMODE::VOOR:
			paceVentricle();
			break;
		case PACEMODE::VVIR:
			break;
		case PACEMODE::VDDR:
			break;
		case PACEMODE::DOOR:
			break;
		case PACEMODE::DDIR:
			break;
		case PACEMODE::DDDR:
			break;
	}
}

void Pace::paceVentricle() {
	led1 = led1 == 1 ? 0 : 1;
}

void Pace::paceAtrium() {
	led2 = led2 == 1 ? 0 : 1;
}

PACEMODE Pace::getPaceMode() {
	return pacingMode;
}

PACESTATE Pace::getPaceState() {
	return pacingState;
}
