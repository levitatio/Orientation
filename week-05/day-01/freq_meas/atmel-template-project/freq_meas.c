#include "freq_meas.h"

freq_meas_state_t g_freq_meas_state = 0;
uint8_t g_number_overflows = 0;
int g_first_timer_value = 0;
int g_second_timer_value = 0;
float g_last_freq_value = 0;

ISR(TIMER1_OVF_vect)
{
	if (g_freq_meas_state != CALCULATING) g_number_overflows++;
}

ISR(TIMER1_CAPT_vect)
{
	switch (g_freq_meas_state){
		case FIRST_VALUE_MEAS  : {
			g_first_timer_value = ICR1; 
			g_number_overflows = 0;
			g_freq_meas_state = SECOND_VALUE_MEAS;
			break;
		}
		case SECOND_VALUE_MEAS : {
			g_second_timer_value = ICR1; 
			g_freq_meas_state = CALCULATING;
			break;
		}
		default: break;
	}
}

void freq_meas_init()
{
	// Configure the TC1 timer properly :)
	TCCR1A = 0;
	// Enable input capture noise canceler and input capture edge select 
	TCCR1B |= (1 << ICNC1) | (1 << ICES1);
	
	// Set TC1 prescaler to 8
	TCCR1B |= 0b010;

	// Enable Input capture and overflow interrupt
	TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);
}

float get_freq()
{
	if (g_freq_meas_state == CALCULATING){
		cli();
		uint32_t number_of_steps = g_second_timer_value - g_first_timer_value + (uint32_t)g_number_overflows * OVERFLOW_STEPS;
		g_last_freq_value = 1 / (float)(number_of_steps * STEP_TIME);
		g_freq_meas_state = FIRST_VALUE_MEAS;
		sei();
	}
	return g_last_freq_value;
}