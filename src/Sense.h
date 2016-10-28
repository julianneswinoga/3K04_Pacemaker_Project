#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pacemaker.h"

class Sense : public Pacemaker {
	private:
		//enum chambersSensed;
		//enum activityResponse;
		bool magnetInPlace;
	protected:
		//void setChambersSensed(enum);
		//void setActivityResponse(enum);
		void setMagnetInPlace(bool);
		
	public:
		Sense();
		//enum getChambersSensed();
		//enum getActivityResponse();
		bool getMagnetInPlace();
};

#endif // SENSE_H