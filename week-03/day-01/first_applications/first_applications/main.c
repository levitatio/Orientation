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
    /* Replace with your application code */
    while (1) 
    {
		DDRB = 1 << DDRB5;
		PORTB = 0 << PORTB5;
		myDelay(500);
		PORTB = 1 << PORTB5;
		myDelay(500);
    }
}

