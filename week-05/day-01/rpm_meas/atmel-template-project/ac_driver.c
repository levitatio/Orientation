#include <avr/io.h>
#include "ac_driver.h"
#include "freq_meas.h"

ISR(ANALOG_COMP_vect) {}

void ac_driver_init()
{
	/*************
	 * AC CONFIG *
	 *************/
	// Disable the digital input buffers on AN0 and AN1 to reduce power consumption.
	// See the DIDR1 register description for more info.
	DIDR1 |= (1 << AIN0D) | (1 << AIN1D) ;
	
	//DDRE |= (1 << 0);

	// Connect the AC output to the AC0 pin.
	// The datasheet if screwed up. It says "Analog Comparator Control and Status Register C", meanwhile the name of this register is "ACSR0",
	// but in the avr/io.g header this register can be reached with the "ACSRB" macro.
	ACSRB |= (1 << ACOE);

	// AC output connected to TC1 input capture
	// Enable ACO (Analog comparator output), ACIC (Analog comparator input capture) and ACIS1 (AC interrupt on falling edge)
	ACSR = (1 << ACO) |(1 << ACIC) | (1 << ACIS1) | (1 << ACIE);
}

float get_rpm()
{
	return 60 * (get_freq() / 7.0);
}