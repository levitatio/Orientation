/*
* interrupt.c
*
* Created: 2019. 11. 05. 14:20:10
* Author : CFY
*/

#include <avr/io.h>
#include <avr/interrupt.h>


ISR(PCINT0_vect)
{
PORTB ^= 0x20;
}

ISR(TIMER0_OVF_vect)
{
	PORTB ^= 0x20;
}




void init()
{
	
	TCCR0B |= 0b00000101;	 // Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	TCNT0 = 0;						 // With this you also set the clock source to CLK_io and you will also turn on the timer!

	DDRB = 1 << 5;       // Set the PB5 LED pin to output
	
	
	/*  For interrupts
	PCICR = 0b00000001;
	PCMSK0 = 0b10000000;
	sei();
	*/
}

int main(void)
{
	uint8_t counter = 0;
	// Don't forget to call the init function!
	init();

	while (1)
	{
		// If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
		// (this will clear it, it's confusing, but this is how it works)

		if (TIFR0 & 1){
			counter++;
			TIFR0 |= 1;
		}
		if (counter > 29){
			PORTB ^= 1 << PORTB5;
			counter = 0;
		}

	}
}