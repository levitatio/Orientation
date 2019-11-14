#include "TC74_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
	DDRB |= 1 << PORTB5;
	
	//TODO
	// Call the TWI driver init function
	TWI_init();

	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
	STDIO_init();
	// Interrupts must be enabled as STDIO lib uses interrupts for receive
	sei();
}

int main(void)
{
	// Don't forget to call the init function :)
	system_init();

	printf("System initialized\n");
	uint32_t counter = 0;
	// Infinite loop
	while (counter < 0xffff) {
		//TODO
		//Write the temperature frequently.
		_delay_ms(5);
		if ((counter % 0xff) == 0){
			
			printf("Temp: %d\n", TWI_communicate(TC74_ADDRESS));
			//TODO
			//Advanced: Don't use delay, use timer.
			PORTB ^= (1 << PORTB5);
			//TODO
			//Blink the led to make sure the code is running
		}
		counter++;
	}
}


