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

class Sense : public Pacemaker {
	private:
		chambers::CHAMBERS chambersSensed;
		activityresponse::ACTIVITYRESPONSE activityResponse;
		bool magnetInPlace;
		//enum activityThreshold;
	protected:
		void setChambersSensed(chambers::CHAMBERS);
		//void setActivityResponse(enum);
		uint16_t maxSensorRate;
		void setMagnetInPlace(bool);
		void measureLeadImpedance();
		void measureBatteryVoltage();
		
	public:
		Sense();
		chambers::CHAMBERS getChambersSensed();
		activityresponse::ACTIVITYRESPONSE getActivityResponse();
		bool getMagnetInPlace();
};

#endif // SENSE_H