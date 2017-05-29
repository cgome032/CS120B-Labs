/*
 * [cgome032]_lab[2]_part[1].c
 *
 * Created: 4/6/2017 10:31:28 AM
 * Author : Carlos
 */ 

#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b){
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k))!= 0);
}


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
										// initialize to 0s

	unsigned char tmpA = 0x00; // intermediate variable used for port updates										
	unsigned char tmpB = 0x00; // intermediate variable used for port updates
	unsigned char button = 0x00;
	while (1) 
    {
		// 1) Read inputs and assign to variables
		tmpA = PINA; // Read PINA
		tmpB = PINB; // Read PINB
		// 2) Perform computation
		// if PA0 is 1, set PB1PB0=01, else=10
		button = 0x00;
		for(int i = 0; i < 8; i++){
			if(GetBit(tmpA, i)){
				button++;
			}
		}
		for(int i = 0; i < 8; i++){
			if(GetBit(tmpB, i)){
				button++;
			}
		}

		// 3) write results to port
		PORTC = button;
	}
}

