#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pacemaker.h"

enum class CHAMBERS { NONE, ATRIUM, VENTRICLE, DUAL };
enum class ACTIVITYRESPONSE { NONE, TRIGGERED, INHIBITED, DUAL };
enum class ACTIVITYTHRESHOLD { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Sense : public Pacemaker {
	private:
		CHAMBERS chambersSensed;
		ACTIVITYRESPONSE activityResponse;
		bool magnetInPlace;
		ACTIVITYTHRESHOLD activityThreshold;
		void measureBatteryVoltage();
	protected:
		void setChambersSensed(CHAMBERS);
		void setActivityResponse(ACTIVITYRESPONSE);
		void setActivityThreshold(ACTIVITYTHRESHOLD);
		uint16_t maxSensorRate;
		void setMagnetInPlace(bool);
		void measureLeadImpedance();
		
	public:
		Sense();
		CHAMBERS getChambersSensed();
		ACTIVITYRESPONSE getActivityResponse();
		ACTIVITYTHRESHOLD getActivityThreshold();
		bool getMagnetInPlace();
};

#endif // SENSE_H