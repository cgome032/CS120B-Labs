/*
 * [cgome032]_lab[1]_part[3].c
 *
 * Created: 4/5/2017 12:20:46 PM
 * Author : Carlos
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs,
								// initialize to 0s
	//unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char cntavail = 0x00; // Temporary variable to hold the number of available spaces

    /* Replace with your application code */
    while (1) 
    {
		// 1) Read input
		tmpA = PINA & 0x0F;
		// 2) Perform computation
		// if PA0 is 1, set PB1PB0=01, else =10
		if (tmpA == 0x01 || tmpA == 0x02 || tmpA == 0x04 || tmpA == 0x08) { // True if PA0 is 1
    		cntavail = 3;
		}
		else if(tmpA == 0x03 || tmpA == 0x06 || tmpA == 0x0C || tmpA == 0x05 || tmpA == 0x0A || tmpA == 0x09 ) {
			cntavail = 2;
		}
		else if(tmpA == 0x07 || tmpA == 0x0E || tmpA == 0x0D || tmpA == 0x0B ){
			cntavail = 1;
		}
		else if(tmpA == 0x0F){
			cntavail = 128;
		}
		else{
			cntavail = 4;
		}
		PORTC = cntavail;

    }
	return 0;
}

