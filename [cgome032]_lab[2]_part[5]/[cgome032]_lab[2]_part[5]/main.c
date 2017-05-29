/*
 * [cgome032]_lab[2]_part[4].c
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
	DDRB = 0xFE; PORTB = 0x01; // Configure port B's 8 pins as outputs
	DDRD = 0x00; PORTD = 0xFF; // Configure port C's 8 pins as outputs
										// initialize to 0s

	unsigned char tmpB = 0x00; // intermediate variable used for port updates										
	unsigned char tmpD = 0x00; // intermediate variable used for port updates
	unsigned char airbag = 0x00;
	while (1) 
    {
		airbag = 0x00;
		tmpB = PINB & 0x01;
		tmpD = PIND;
		if(tmpD >= 70 && tmpB == 0 || tmpD >= 69 && tmpB ==1){
			airbag = 0x02;
		}
		else if(tmpD > 5 && tmpB == 0 || tmpD > 4 && tmpD == 1){
			airbag = 0x04;
		}
		else{
			airbag = 0x00;

		}
		PORTB = tmpB | airbag;
	}
}

