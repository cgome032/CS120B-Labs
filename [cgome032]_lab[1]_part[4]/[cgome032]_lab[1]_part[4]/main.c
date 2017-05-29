/*
 * [cgome032]_lab[1]_part[4].c
 *
 * Created: 4/5/2017 12:33:46 PM
 * Author : Carlos
 */ 

#include <avr/io.h>
#include <stdlib.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0x00; // Configure port B's 8 pins as inputs,
	DDRC = 0x00; PORTC = 0x00; // Configure port C's 8 pins as inputs,
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs,
								// initialize to 0s
	//unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	unsigned char totWeight = 0x00; // Temporary variable to hold the total weight


    while (1) 
    {
		// 1) Read input
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		totWeight = tmpA + tmpB + tmpC;
		tmpD = 0x00;
		//totWeight = totWeight<<2;


		if(tmpA+tmpB+tmpC>= 140){
			tmpD = tmpD | 0x01;
		}
		if(abs(tmpA-tmpC) > 80){
			tmpD = tmpD | 0x02;
		}

		totWeight = totWeight & 0xFC;

		tmpD = totWeight + tmpD;


		PORTD = tmpD;
	}
	return 0;
}

