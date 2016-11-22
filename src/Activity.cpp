#include "Activity.h"

Activity::Activity() : accelerometer (PTE25, PTE24, FXOS8700CQ_SLAVE_ADDR1) {
	
}

ACTIVITYSTATE Activity::getPatientActivity() {
	return ACTIVITYSTATE::V_LOW;
}
