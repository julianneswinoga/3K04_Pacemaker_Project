#ifndef PACEMAKER_H
#define PACEMAKER_H

#include "mbed.h"
#include "Communications.h"
#include "Activity.h"
#include "Logging.h"
#include "Pace.h"

class Pacemaker {
	private:
		Communications communications;
		Activity activity;
		Logging logging;
		Pace pace;
	
		uint8_t fnCode;
		
		char deviceID[64];
		char deviceImplantDate[64];
		char leadImplantDate[64];
		
	protected:

	public:
		Pacemaker();
		void mainLoop();
};

#endif // PACEMAKER_H