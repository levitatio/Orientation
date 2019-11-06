/*
 * dimming_led.c
 *
 * Created: 2019. 11. 06. 13:37:42
 * Author : CFY
 */ 
#define FAST 0
#define PHASE_CORRECT 1
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t g_duty = 0;
uint8_t direction_duty_change = 1;

ISR(TIMER2_OVF_vect)
{		
		if (g_duty > 99){
			direction_duty_change = 0;
		}else if (g_duty < 1){
			direction_duty_change = 1;
		}
	
		if (direction_duty_change) {
			g_duty += 5;	
			
		}else {
			g_duty -= 5;
		}
		set_duty(g_duty);
}

void init (uint8_t mode)
{
	// Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
	
	// With this you also set the clock source to CLK_io and you will also turn on the timer!
	// set compare A mode
	TIFR0 = 0b00000010;
	TCNT0 = 0;
	OCR0A = 0;
	DDRD = 1 << DDRD6;

	if (mode == FAST){ 
		// set mode and set prescalse
		TCCR0A = 0b10000011;
		TCCR0B = 0b00000010;
	}else if (mode == PHASE_CORRECT){
		// set mode and set prescalse
		TCCR0A = 0b10000001;
		TCCR0B = 0b00000010;
	}else {}
		
	// Set second timer to interrupt process
	TCCR2A = 0;
	// Set prescale to 1024
	TCCR2B = 0b00000111;
	// Init counter to 0
	TCNT2 = 0;
	// Set interrupt option to overflow
	TIMSK2 = 1;
		
	sei();
	
}
void set_duty(uint8_t duty)
{
	OCR0A = (duty *255) / 100;
	
}


int main(void)
{
	init(FAST);
    /* Replace with your application code */
    while (1) 
    {
    }
}
