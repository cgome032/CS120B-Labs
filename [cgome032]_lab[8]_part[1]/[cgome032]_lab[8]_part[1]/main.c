 /*
  * cgome032_lab8_part1.c
  * Carlos Gomez cgome032@ucr.edu:
  *	Lab Section: 023
  *	Assignment: Lab 8  Exercise 1
  *	I acknowledge all content contained herein, excluding template or example
  *	code, is my own original work.
  */

#include <avr/io.h>
#include <avr/interrupt.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}



int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Set A to input and initialize to 0xFF
	DDRB = 0xFF; PORTB = 0x00; // Set B to output and initialize to 0x00
	DDRD = 0xFF; PORTD = 0x00; // Set D to output and initialize to 0x00
	//DDRC = 0xFF; PORTC = 0x00; // LCD data lines
	//DDRD = 0xFF; PORTD = 0x00; // LCD control lines
	ADC_init();
	while(1){
		unsigned short x = ADC; //Value of ADC register is now stored in variable x
		unsigned char first8 = (char)x;
		PORTB = first8;
		unsigned char last2 = (char)(x >> 8);
		PORTD = last2;

	}
}
