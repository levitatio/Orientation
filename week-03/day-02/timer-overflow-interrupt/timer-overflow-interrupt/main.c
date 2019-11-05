#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// Create a variable which will be a counter variable, initialize it with 0. This time it has to be global.
uint8_t cntr = 0;
// This will be the maximal value of our counter. This time it has to be global.
const uint8_t cntr_max = 30;

// Write here the interrupt handler function. The vector name starts with TIMER ;). Use Ctrl+Space to find the proper vector name!

ISR(TIMER0_OVF_vect)
{
	cntr++;
	if (cntr >= cntr_max){
		PORTB ^= 1 << PORTB5;
		cntr = 0;
	}
}
// Do the same thing in the interrupt handler as before.
// This time you don't have to do anything with the flags, the MCU does it automatically.

void init()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	TCCR0B |= 0b101; 
	// With this you also set the clock source to CLK_io and you will also turn on the timer!

	TCNT0 = 0;

	// Set the PB5 LED pin to output
	DDRB = 1 << PORTB5;
	
	// Enable the TC0 overflow interrupt
	// Set the value that you want to count to

    TIMSK0 |= (1 << TOIE0);    //Set the ISR COMPA vect
	// Enable the interrupts globally
	sei();
}

int main(void)
{
	// Don't forget to call the init function!
	init();
	
	while (1)
	{
		//Nothing to do here, everithing is done in interrupt :)
	}
}