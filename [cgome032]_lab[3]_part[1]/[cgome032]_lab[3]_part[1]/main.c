/*
 * [cgome032]_lab[2]_part[4].c
 *
 * Created: 4/6/2017 10:31:28 AM
 * Author : Carlos
 */ 

#include <avr/io.h>
enum States{init, led2, wait, led1} state;

unsigned char button;
unsigned char tmpB;


void led_Tick(){
	switch(state){
		case init:
			if(button == 1){
				state = led2;
			}
			else
				state = init;
			break;
		case led2:
			if(button == 1){
				state = led2;
			}
			else
				state = wait;
			break;
		case wait:
			if(button == 1){
				state = led1;
			}
			else
				state = wait;
			break;
		case led1:
			if(button == 1){
				state = led1;
			}
			else
				state = init;
			break;	
	}
	switch(state){
		case init:
			tmpB = 0x01;
			break;
		case led2:
			tmpB = 0x02;
			break;
		case wait:
			tmpB = 0x02;
			break;
		case led1:
			tmpB = 0x01;
			break;
	}			
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
										// initialize to 0s
																				
	state = init;

	while (1) 
    {
		button = PINA & 0x01;
		led_Tick();
		PORTB = tmpB;
	}

	return 0;
}

