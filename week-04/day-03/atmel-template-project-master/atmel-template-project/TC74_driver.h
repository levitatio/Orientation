// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#define F_CPU 16000000UL
#include <avr/delay.h>
#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1
#define TC74_ADDRESS 0b10010000
#define TC74_COMMAND_READ 0
//TODO
//Define the TC74A0 address

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);
uint8_t TWI_communicate(uint8_t slave_address);

#endif // _TC74_DRIVER_H