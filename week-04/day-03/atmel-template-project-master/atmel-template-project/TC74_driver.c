#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
	// TODO:
	// Set Prescaler to 4
	TWSR |= (1 << 0);

	// TODO:
	// Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40Khz
	//So set the correct register to 0x30
	TWBR |= 0x30;

	// TODO
	//Enable TWI
	TWCR |= (1 << TWEN);
}

void TWI_start(void)
{
	//TODO
	//Send start signal
	TWCR =  (1 << TWEN) | (1 << TWSTA) | (1 << TWINT);

	// TODO:
	// Wait for TWINT Flag set. This indicates that
	//the START condition has been transmitted.
	while (!(TWCR & (1 << TWINT)));
}

void TWI_stop(void)
{
	//TODO
	//Send stop signal
	TWCR = (1 << TWINT) | (1 << TWEN) | ( 1 << TWSTO);
}

uint8_t TWI_read_ack(void)
{
	//TODO
	//Read byte with ACK
	uint8_t temp;
	if (TWSR == 0x19  || TWSR == 0x29 || TWSR == 0x41 || TWSR == 0x51) return 1;
	return 0;
	
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
}


uint8_t TWI_read_nack(void)
{
	//TODO
	//Read byte with NACK
	uint8_t temp;
	if (TWSR == 0x21 || TWSR == 0x31 || TWSR == 0x49 || TWSR == 0x59) temp = 1;
	else temp = 0;
	
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
}

void TWI_write(uint8_t u8data)
{
	//TODO
	//Load DATA into TWDR Register. Clear TWINT
	//bit in TWCR to start transmission of data.
	TWDR = u8data;
	TWCR = (1 << TWEN) | (1 << TWINT);
		
	//Wait for TWINT Flag set. This indicates that
	//the DATA has been transmitted, and ACK/
	//NACK has been received.
	while (!(TWCR & (1 << TWINT)));
	
}

uint8_t TWI_communicate(uint8_t slave_address)
{
	uint8_t temperature = 0;
	
	TWI_start();
	TWI_write(slave_address + TC_WRITE);
	if (!TWI_read_ack()) return 0xff;  /*error_code*/;
	TWI_write(TC74_COMMAND_READ);
	if (!TWI_read_ack()) return 0xff;  /*error_code*/;
	
	TWI_start();
	TWI_write(slave_address + TC_READ);
	if (!TWI_read_ack()) return 0xff;  /*error_code*/;
	
	// Get data
	TWCR |= (1 << TWINT);
	while ( TWSR != 0x59);
	temperature = TWDR;
	if (!TWI_read_nack()) return 0xff;  /*error_code*/;
	TWI_stop();
	
	return temperature;
}
//TODO
//Write a function that communicates with the TC74A0.
//The function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.


//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.