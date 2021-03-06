/*
 * [cgome032]_lab[2]_part[3].c
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
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
										// initialize to 0s

	unsigned char tmpA = 0x00; // intermediate variable used for port updates										
	unsigned char tmpC = 0x00; // intermediate variable used for port updates
	unsigned char tmpAB = 0x00; // intermediate variable used for other port updates
	while (1) 
    {
		tmpC = 0x00;
		tmpA = PINA & 0x0F;
		tmpAB = PINA & 0x70;

		if(tmpA == 1 || tmpA == 2){
			tmpC = 0x20;
		}

		else if(tmpA == 3 || tmpA == 4){
			tmpC = 0x30;
		}

		else if(tmpA == 5 || tmpA == 6){
			tmpC = 0x38;
		}

		else if(tmpA == 7 || tmpA == 8 || tmpA == 9){
			tmpC = 0x3C;
		}

		else if( tmpA == 10 || tmpA == 11 || tmpA == 12){
			tmpC = 0x3E;
		}

		else if(tmpA == 13 || tmpA == 14 || tmpA == 15){
			tmpC = 0x3F;
		}
		else{
			tmpC = 0;
		}

		if(tmpA <= 4){
			tmpC = tmpC | 0x40;
		}
		tmpAB = tmpAB >> 4;

		if(tmpAB == 3){
			tmpC = tmpC | 0x80;

		}

		PORTC = tmpC;
	}
}

