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
	
	atr_grnd_ctrl  = 0;
	vent_grnd_ctrl = 0;
	pacing_ref_pwm = 1;
	changeVar[0].attach(this, &Pace::paceVentricleStage1, 0.01f);
	changeVar[1].attach(this, &Pace::paceVentricleStage2, 0.02f);
	changeVar[2].attach(this, &Pace::paceVentricleStage3, 0.02f+(vPaceWidth_milliseconds/1000.0f));
	changeVar[3].attach(this, &Pace::paceVentricleStage4, 0.02f+(vPaceWidth_milliseconds/1000.0f)+0.05f);
	changeVar[4].attach(this, &Pace::paceVentricleStage5, 0.02f+(vPaceWidth_milliseconds/1000.0f)+0.05f+0.1f);
	changeVar[5].attach(this, &Pace::paceVentricleStage6, 0.02f+(vPaceWidth_milliseconds/1000.0f)+0.05f+0.1f+0.01f);
}

void Pace::paceVentricleStage1() {
	pace_charge_ctrl = 1;
}

void Pace::paceVentricleStage2() {
	vent_pace_ctrl = 1;
}

void Pace::paceVentricleStage3() {
	vent_pace_ctrl = 0;
	atr_pace_ctrl =  0;
	vent_pace_ctrl = 0;
	atr_grnd_ctrl  = 1;
	vent_grnd_ctrl = 1;	
}

void Pace::paceVentricleStage4() {
	pacing_ref_pwm = 0;
}

void Pace::paceVentricleStage5() {
	pace_charge_ctrl = 0;
}

void Pace::paceVentricleStage6() {
	atr_grnd_ctrl  = 0;
	vent_grnd_ctrl = 0;
}

void Pace::paceAtrium() {
	led2 = led2 == 1 ? 0 : 1;
	
	atr_grnd_ctrl  = 0;
	vent_grnd_ctrl = 0;
	pacing_ref_pwm = 1;
}

PACEMODE Pace::getPaceMode() {
	return pacingMode;
}

PACESTATE Pace::getPaceState() {
	return pacingState;
}
