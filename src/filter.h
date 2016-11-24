#ifndef FILTER_H
#define FILTER_H

#include "mbed.h"

enum class FILTERTYPE { LOWPASS, HIGHPASS };

class Filter {
	private:
		float *rawInput;
		float *output;
		float inputHistory[];
		
	public:
		Filter(float*, float*);
	
};

#endif // FILTER_H