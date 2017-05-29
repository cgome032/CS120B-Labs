/*
 * [cgome032]_lab[2]_part[4].c
 *
 * Created: 4/6/2017 10:31:28 AM
 * Author : Carlos
 */ 

#include <avr/io.h>
enum States{init, inc, dec, zero, wait,wait2} state;

unsigned char button0;
unsigned char button1;

unsigned char tmpC;


void button_Tick(){
	button0 = PINA & 0x01;
	button1 = PINA & 0x02;
		
	switch(state){ // Transitions
		case init:
			if(!button0 && !button1){
				state = init;
			}
			else if(button0 && !button1){
				state = inc;
			}
			else if(!button0 && button1){
				state = dec;
			}
			else if(button0 && button1){
				state = zero;
			}
			break;
		case inc:
			if(button0 && button1){
				state = zero;
			}
			else{
				state = wait2;
			}
			break;
		case dec:
			if(button0 && button1){
				state = zero;
			}
			else{
				state = wait2;
			}
			break;
		case zero:
			if(!button0 && !button1){
				state = init;
			}
			else if (button0 && !button1){
				state = inc;
			}
			else if(!button0 && button1){
				state = dec;
			}
			else if(button0 && button1){
				state = zero;
			}
			break;
		case wait:
			if(button0 && button1){
				state = zero;
			}
			else if(button0 && !button1){
				state = inc;
			}
			else if(!button0 && button1){
				state = dec;
			}
			else{
				state = wait;
			}
			break;
		case wait2:
			if(!button0 && !button1){
				state = wait;
			}
			else if(button0 && button1){
				state = zero;
			}
			else{
				state = wait2;
			}
			break;
			
	}
	switch(state){ // State actions
		case init:
			break;
		case inc:
			if(tmpC < 9){
				tmpC = tmpC + 1;
			}
			break;
		case dec:
			if(tmpC > 0){
				tmpC = tmpC - 1;
			}
			break;
		case zero:
			tmpC = 0;
			break;
	}			
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
										// initialize to 0s
																				
	state = init;
	tmpC = 0x07;

	while (1) 
    {		
		button_Tick();
		PORTC = tmpC;

	}

	return 0;
}

