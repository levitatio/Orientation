/*
 * first_applications.c
 *
 * Created: 2019. 11. 04. 11:08:48
 * Author : CFY
 */ 

#include <avr/io.h>

void myDelay (uint32_t millisec)
{
	uint32_t max = millisec * 512;
	for (uint32_t i = 0; i < max; i++){}
}

int main(void)
{
	DDRB &= 0b01111111;
	PORTB |= 0b10000000; 
	uint32_t temp = PINB & 0x80;
    /* Replace with your application code */
    while (1) 
    {
		DDRB |= 0x20;
		if (temp != (PINB & 0x80)){
			PORTB = PORTB ^ 0X20;
			myDelay(500);
		}
    }
}

