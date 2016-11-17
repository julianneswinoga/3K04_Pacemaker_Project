#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"
#include "Communications.h"
#include "Activity.h"
#include "Logging.h"
#include "Pace.h"

class Pacemaker : public Communications, public Activity, public Logging, public Pace {
	private:
		uint8_t FnCode;
		
		char deviceID[64];
		char deviceImplantDate[64];
		char leadImplantDate[64];
	protected:

	public:
		Pacemaker();
		void mainLoop();
};

#endif // PACEMAKER_H