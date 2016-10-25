#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pacemaker.h"

class Sense : public Pacemaker {
	protected:
		//void setChambersSensed(enum);
		//void setActivityResponse(enum);
		
	public:
		Sense();
		//enum getChambersSensed();
		//enum getActivityResponse();
};

#endif // SENSE_H