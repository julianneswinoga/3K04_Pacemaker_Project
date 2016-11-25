#ifndef PACEMAKER_PINMAP_H
#define PACEMAKER_PINMAP_H

#include "mbed.h"

/*=== Analog In ===*/
extern AnalogIn atrialIn;           // Pin A0
extern AnalogIn ventricleIn;        // Pin A1
extern AnalogIn leadImpedence;      // Pin A2
extern AnalogIn atr_rect_signal;    // Pin A3
extern AnalogIn vent_rect_signal;   // Pin A4

/*=== Digital In ===*/
extern DigitalIn atria_cmp_detect;  // Pin D0
extern DigitalIn vent_cmp_detect;   // Pin D1

/*=== PWM Out ===*/
extern DigitalOut pacing_ref_pwm;   // Pin D2
extern PwmOut vent_ref_pwm;         // Pin D3
extern DigitalOut atria_ref_pwm;    // Pin D4


/*=== Digital Out ===*/
extern DigitalOut pace_charge_ctrl; // Pin D5
extern DigitalOut z_atria_ctrl;     // Pin D6
extern DigitalOut z_vent_ctrl;      // Pin D7

extern DigitalOut atr_pace_ctrl;    // Pin D8
extern DigitalOut vent_pace_ctrl;   // Pin D9
extern DigitalOut pace_grnd_ctrl;   // Pin D10
extern DigitalOut atr_grnd_ctrl;    // Pin D11
extern DigitalOut vent_grnd_ctrl;   // Pin D12
extern DigitalOut frontend_ctrl;    // Pin D13

void setPins(void);

#endif // PACEMAKER_PINMAP_H