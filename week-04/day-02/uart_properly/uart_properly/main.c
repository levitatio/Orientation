#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function


#define RX_CIRC_BUFF_LEN 25
//TODO: Create the circular buffer with the length of RX_CIRC_BUFF_LEN
char c_buffer[RX_CIRC_BUFF_LEN];


//TODO: Create the head pointer of the buffer
char* g_head_p;
//TODO: Create the tail pointer of the buffer
char* g_tail_p;
//TODO: Create the write pointer of the buffer
char* g_write_p;
//TODO: Create the read pointer of the buffer
char* g_read_p;

ISR(USART_RX_vect) {
	//TODO:
	// Put received character into the circular buffer
	if ((g_write_p != g_read_p - 1) && !((g_write_p == g_tail_p) && (g_read_p == g_head_p))){
		*g_write_p = UDR0;
		
		//TODO:
		// Increment the write ptr
		// Be aware that the write ptr might point to the end of the buffer.
		// In this case you have to set it back to the start of the buffer
		if (g_write_p < g_tail_p) g_write_p++;
		else g_write_p = c_buffer;
	}
	UCSR0A |= (1<<UDRE0);
}

void UART_Init() {
	//TODO:
	// Write this function
	// See the datasheet on page 246 for hints and table 25-9.

	//TODO:
	// At first set the baud rate to 9600
	// The CPU clock frequency is 16MHz
	UBRR0 = 103;
	// Set the proper Baud rate
	UCSR0A = 0;
	
	//TODO:
	// Set the following frame format: 8N1
	// It's set by default to 8N1
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

	//TODO:
	// Enable RX interrupt
	UCSR0B |= (1 << RXCIE0); 

	//TODO:
	// Initialize circular buffer pointers, they should point to the head of the buffer
	g_write_p = c_buffer + 1;
	g_read_p = c_buffer;
	g_head_p = c_buffer;
	g_tail_p = c_buffer + RX_CIRC_BUFF_LEN - 1;

	// Enable interrupts globally
	sei();
	
	// UDR0 will transmit and receive data
}

void UART_SendCharacter(char character) {
	//TODO:
	// Write this function, which can send a character through UART will polling method
	// See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)

	//TODO:
	// Wait for empty USART buffer register
	while (!( UCSR0A & (1<<UDRE0))) { }
		
	//TODO:
	// Put data to USART buffer register	
	UDR0 = character;
}

char UART_GetCharacter() {
	//TODO:
	// Wait for data in the circular buffer, this can be detected if the write and read pointers are pointing to the same memory block
	while ((g_read_p == g_write_p - 1) || ((g_read_p == g_tail_p) && (g_write_p == g_head_p))) {}
	//TODO:
	// Save the data to a temporary variable
	char temp = *g_read_p; 

	//TODO:
	// Increment the read ptr
	if (g_read_p < g_tail_p) g_read_p++;
	else g_read_p = c_buffer;
	
	// Be aware that the read ptr might point to the end of the buffer.
	// In this case you have to set it back to the start of the buffer

	//TODO:
	// Return the read character
	return temp;
}

int main(void) {
	char buffer[255];

	//Don't forget to call the init function :)
	UART_Init();

	// Setting up STDIO input and output buffer
	// You don't have to understand this!
	//----- START OF STDIO IO BUFFER SETUP
	FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
	stdout = &UART_output;
	FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
	stdin = &UART_input;
	//----- END OF STDIO IO BUFFER SETUP

	// Try printf
	//printf("Startup...\r\n");

	// Loop that runs forever
	while (1) {
		// With gets and puts create a loopback, use the buffer variable!
		gets(buffer);
		_delay_ms(50);
		puts(buffer);
		_delay_ms(50);
	}
}