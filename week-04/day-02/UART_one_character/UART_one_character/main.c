#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function

void UART_Init()
{
	// Write this function
	// See the datasheet on page 246 for hints and table 25-9.
	//---------------------------------
	// 9600 Baud rate  UBRRn = 103, error = 0.2%  at U2Xn = 1
	// 9600 Baud rate  UBRRn = 207, error = 0.2%  at U2Xn = 0
	//TODO:
	// At first set the baud rate to 9600
	// The CPU clock frequency is 16MHz
	UBRR0 = 103;
	// Set the proper Baud rate
	UCSR0A = 0;
	
	//TODO:
	// Set the following frame format: 8N1
	// Set the one stop bit
	UCSR0C |= (0 << USBS0);
	// Set char size to 8 bit
	UCSR0C |= (0b11 << UCSZ00);
	
	//TODO:
	// Enable receiver and transmitter
	// Enable TX
    UCSR0B |= (1 << TXEN0);
	//TODO:
	// Enable RX
	UCSR0B |= (1 << RXEN0);
	
	// UDR0 will transmit and receive data
}

void UART_SendCharacter(char character)
{
	// Write this function, which can send a character through UART will polling method
	// See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)
	//---------------------------------
	//TODO:
	// Wait for empty buffer
	while (!( UCSR0A & (1<<UDRE0))) { }
	
	//TODO:
	// Put data to buffer
	UDR0 = character;
}

char UART_GetCharacter()
{
	// Write this function, which waits for a character and returns when one is received
	// See page 249 of the datasheet for hints, be aware that the code in the datasheet has a problem :)
	//---------------------------------
	//TODO:
	// Wait for data received
	while (!(UCSR0A & (1<<RXC0))) {}
	//TODO:
	// Get data from buffer
	return (char)UDR0;
}

int main(void)
{
	char character;
	//Don't forget to call the init function :)
	UART_Init();

	// Loop that runs forever
	while (1) {
		// Receive a character
		character = UART_GetCharacter();
		// Send the character back
		if (character == 'b') { 
			UART_SendCharacter(character);
		}
	}
}