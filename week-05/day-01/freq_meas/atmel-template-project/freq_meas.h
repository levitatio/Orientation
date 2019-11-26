#ifndef _FREQ_MEAS_H
#define _FREQ_MEAS_H

#define STEP_TIME 0.0000005
#define OVERFLOW_STEPS 65535

#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

typedef enum freq_meas_state
{
	FIRST_VALUE_MEAS = 0,
	SECOND_VALUE_MEAS,
	CALCULATING
}freq_meas_state_t;

void freq_meas_init();
float get_freq();

#endif // _FREQ_MEAS_H