#ifndef SENSE_H
#define SENSE_H

#include "mbed.h"
#include "Pacemaker.h"

class Sense : public Pacemaker {
	protected:
		void setChambersSensed(void);
		void setActivityResponse(void);
	public:
		Sense();
		void getChambersSensed();
		void getActivityResponse();
};

#endif // SENSE_H