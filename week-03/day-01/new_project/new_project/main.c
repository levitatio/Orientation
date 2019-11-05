/*
 * new_project.c
 *
 * Created: 2019. 11. 04. 16:19:53
 * Author : CFY
 */ 

#include <avr/io.h>


int main(void)
{
	uint8_t counter = 0;
	uint8_t butten_toggling_flag = 0;
	
	DDRB = 0x20;
    /* Replace with your application code */
    while (1) 
    {
		if ((PINB & 0x80) && butten_toggling_flag){
				butten_toggling_flag = 0;
			}
		if (!(PINB & 0x80) && !butten_toggling_flag && counter < 5){
			counter++;
			butten_toggling_flag = 1;
		}
		
		if (counter == 5 && PORTB == 0x0) {
			PORTB = 0x20;
			counter = 0;
		}else if (counter == 5 && PORTB == 0x20){
			PORTB = 0x0;
			counter = 0;
		}
    }
}

