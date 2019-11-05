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



int main(void)
{
    /* Replace with your application code */
	
	DDRB = 0x20;
	
	PCICR = 0b00000001;
	PCMSK0 = 0b10000000;
	sei();
    while (1) 
    {
		
		
    }
}

