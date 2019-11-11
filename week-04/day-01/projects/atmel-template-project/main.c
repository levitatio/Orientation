#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>

int main(void)
{
	char buffer[32];
	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
	STDIO_init();
	// Interrupts must be enabled as STDIO lib uses interrupts for receive
	sei();
	
	printf("System initialized\n");
	
	while (1)
	{
		gets(buffer);
		puts(buffer);
	}
}

