#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "mbed.h"

enum class ACTIVITYSTATE { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Activity {
	private:
		uint16_t activityTimeThresholdSeconds = 5;
		
	public:
		Activity();
		
	protected:
		ACTIVITYSTATE getPatientActivity();
};

#endif // ACTIVITY_H