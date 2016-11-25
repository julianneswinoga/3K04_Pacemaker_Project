#include "Pace.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Pace::Pace(bool *aTrip) {
	led1 = 1;
	led2 = 1;
	
	activityTrip = aTrip;
	
	setPaceRate(baseHeartRate);
}

void Pace::setPaceRate(uint8_t BPM) {
	if (prevBPM == BPM)
		return;
	else
		prevBPM = BPM;
	paceTicker.attach(this, &Pace::paceTick, (1.0f/BPM) * 60.0f);
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
			setPaceRate(baseHeartRate);
			paceAtrium();
			egramData = getAtriumVoltage();
			break;
		case PACEMODE::AAI:
			break;
		default:
		case PACEMODE::VOO:
			setPaceRate(baseHeartRate);
			paceVentricle();
			egramData = getVentricleVoltage();
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
			if (*activityTrip)
				setPaceRate(maxHeartRate);
			else
				setPaceRate(baseHeartRate);
			
			paceAtrium();
			egramData = getAtriumVoltage();
			break;
		case PACEMODE::AAIR:
			break;
		case PACEMODE::VOOR:
			if (*activityTrip)
				setPaceRate(maxHeartRate);
			else
				setPaceRate(baseHeartRate);
		
			paceVentricle();
			egramData = getVentricleVoltage();
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
