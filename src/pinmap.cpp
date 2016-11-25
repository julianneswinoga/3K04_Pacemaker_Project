#include "pinmap.h"

/*=== Analog In ===*/
AnalogIn atrialIn				(A0);
AnalogIn ventricleIn			(A1);
AnalogIn leadImpedence		(A2);
AnalogIn atr_rect_signal		(A3);
AnalogIn vent_rect_signal		(A4);

/*=== Digital In ===*/
DigitalIn atria_cmp_detect	(PTC16);   // Pin D0
DigitalIn vent_cmp_detect	(PTC17);   // Pin D1

/*=== PWM Out ===*/
/* DigitalOut is used for the REF Signal
 * due to absence of PWM capabilities of Pins D2 and D4
 * on the FRDM-K64F Board
 */
DigitalOut pacing_ref_pwm		(PTB9);    // Pin D2 (PTB9)
PwmOut vent_ref_pwm			(PTA1);    // Pin D3
DigitalOut atria_ref_pwm		(PTB23);  // Pin D4

/*=== Digital Out ===*/
DigitalOut pace_charge_ctrl	(PTA2);    // Pin D5
DigitalOut z_atria_ctrl			(PTC2);    // Pin D6
DigitalOut z_vent_ctrl			(PTC3);    // Pin D7

DigitalOut atr_pace_ctrl		(PTC12);   // Pin D8
DigitalOut vent_pace_ctrl		(PTC4);    // Pin D9
DigitalOut pace_grnd_ctrl		(PTD0);    // Pin D10
DigitalOut atr_grnd_ctrl		(PTD2);    // Pin D11
DigitalOut vent_grnd_ctrl		(PTD3);    // Pin D12
DigitalOut frontend_ctrl			(PTD1);    // Pin D13
