#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pace.h"

enum class BATTERYSTATE { BOL, ERN, ERT, ERP };
enum class CHAMBERS { NONE, ATRIUM, VENTRICLE, DUAL };
enum class ACTIVITYRESPONSE { NONE, TRIGGERED, INHIBITED, DUAL };
enum class ACTIVITYTHRESHOLD { V_LOW, LOW, MED_LOW, MED, MED_HIGH, HIGH, V_HIGH };

class Sense : public Pace {
	private:
		PinName leadOneInPin;
		PinName leadTwoInPin;
		PinName leadOneOutPin;
		PinName leadTwoOutPin;
		
		CHAMBERS chambersSensed;
		ACTIVITYRESPONSE activityResponse;
		ACTIVITYTHRESHOLD activityThreshold;		
		float replaceBatteryVoltage = 3.0f;
		
	protected:
		void setChambersSensed(CHAMBERS);
		void setActivityResponse(ACTIVITYRESPONSE);
		void setActivityThreshold(ACTIVITYTHRESHOLD);
		uint16_t maxSensorRate;
		float measureLeadImpedance();
		float measureBatteryVoltage();
		
	public:
		Sense();
		CHAMBERS getChambersSensed();
		ACTIVITYRESPONSE getActivityResponse();
		ACTIVITYTHRESHOLD getActivityThreshold();
		bool getMagnetInPlace();
		BATTERYSTATE getBatteryStatus();
};

#endif // SENSE_H