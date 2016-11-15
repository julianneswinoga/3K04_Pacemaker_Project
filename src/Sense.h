#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pacemaker.h"

namespace chambers{
	typedef enum {NONE,ATRIUM,VENTRICLE,DUAL} CHAMBERS;
}

namespace activityresponse{
	typedef enum {NONE,TRIGGERED,INHIBITED,DUAL} ACTIVITYRESPONSE;
}

typedef enum {V_LOW,LOW,MED_LOW,MED,MED_HIGH,HIGH,V_HIGH} ACTIVITYTHRESHOLD;

class Sense : public Pacemaker {
	private:
		chambers::CHAMBERS chambersSensed;
		activityresponse::ACTIVITYRESPONSE activityResponse;
		bool magnetInPlace;
		ACTIVITYTHRESHOLD activityThreshold;
	protected:
		void setChambersSensed(chambers::CHAMBERS);
		void setActivityResponse(activityresponse::ACTIVITYRESPONSE);
		void setActivityThreshold(ACTIVITYTHRESHOLD);
		uint16_t maxSensorRate;
		void setMagnetInPlace(bool);
		void measureLeadImpedance();
		void measureBatteryVoltage();
		
	public:
		Sense();
		chambers::CHAMBERS getChambersSensed();
		activityresponse::ACTIVITYRESPONSE getActivityResponse();
		ACTIVITYTHRESHOLD getActivityThreshold();
		bool getMagnetInPlace();
};

#endif // SENSE_H