#include <avr/io.h>


void init()
{
	ADMUX = 0b00100000;
    ADCSRA = 0b11100010;
    ADCSRB = 0;
   
   // Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
   
   // With this you also set the clock source to CLK_io and you will also turn on the timer!
   // set compare A mode
   TIFR0 = 0b00000001;
   TCNT0 = 0;
   OCR0A = 0;
   DDRD = 1 << DDRD6;

  
   TCCR0A = 0b10000011;
   TCCR0B = 0b00000010;
	
  
}

void set_duty (uint8_t duty) // duty start for 0 to 255
{
	OCR0A = duty;
}


int main(void)
{
    init();
    
    uint8_t low;
    uint8_t high;
    
    uint16_t combination_result;
    
    while (1) 
    {
		low = ADCL;
        high= ADCH;
        
		set_duty(high);
        
    }
}
