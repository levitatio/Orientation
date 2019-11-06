/*
 * dimming_led.c
 *
 * Created: 2019. 11. 06. 13:37:42
 * Author : CFY
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void init ()
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	TCNT0 = 0;
	
	//DDRD = 1 << PORTD6;
	DDRD = 1 << DDRD6;
	// Set the Fast PWM mode with 
	TCCR0A = 0b10000011;
	TCCR0B = 0b00000010;
	OCR0A = 0;
}
void set_duty(uint8_t duty)
{
	OCR0A = (duty *255) / 100;
	
}


int main(void)
{
	uint8_t duty = 0;
	init();
    /* Replace with your application code */
    while (1) 
    {
		set_duty(duty);
		_delay_ms(100);
		
		duty += 5;
		if (duty > 99){
			duty = 0;
		}
    }
}

