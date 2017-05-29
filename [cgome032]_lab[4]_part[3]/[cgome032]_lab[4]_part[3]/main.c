/*
 * [cgome032]_lab[4]_part[3].c
 *
 * Created: 4/19/2017 12:29:23 PM
 * Author : Carlos
 */ 

#include <avr/io.h>

enum States{Init, wait, nextState, buttonPush}state;

unsigned char tmpA = 0x00;
unsigned char tmpC = 0x00;


unsigned char light(unsigned char C){
	unsigned char output = 0x00;
	switch (C)
	{
		case 0x00:
			output = 0x01;
			break;
		case 0x01:
			output = 0x0A;
			break;
		case 0x0A:
			output = 0x28;
			break;
		case 0x28:
			output = 0x50;
			break;
		case 0x50:
			output = 0xA0;
			break;
		case 0xA0:
			output = 0xFF;
			break;
		case 0xFF:
			output = 0xE7;
			break;
		case 0xE7:
			output = 0xC3;
			break;
		case 0xC3:
			output = 0x81;
			break;
		case 0x81:
			output = 0x00;
			break;
		default:
			output = 0x00;
			break;
			
	}
	return output;
}


void light_tick(){
	
	tmpA = ~PINA & 0x01;
	switch(state){ // Transitions
		case Init:
			state = wait;
			break;
		case wait:
			if(tmpA){
				state = nextState;
			}
			else{
				state = wait;
			}
			break;
		case nextState:
			state = buttonPush;
			break;
		case buttonPush:
			if(tmpA){
				state = buttonPush;
			}
			else{
				state = wait;
			}
			break;
	}
	switch(state){ // State actions
		case Init:
			break;
		case wait:
			break;
		case nextState:
			tmpC = light(tmpC);
			break;
		case buttonPush:
			break;
	}

}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure Port A to inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure Port C to outputs

	state = Init;
	tmpC = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		light_tick();
		PORTC = tmpC;
    }

	return 0;
}

