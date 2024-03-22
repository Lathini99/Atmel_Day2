/*
 * Atmel_Day2.c
 *
 * Created: 3/21/2024 8:42:51 AM
 * Author : Dell
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int toggle = 0;

int main(void)
{
	/* Initializing the timer interrupt 1 */
	TIMSK1 |= 0B00000010; // OC1EA =1
	TCCR1A &= 0B11111100; // WGM11 =0 ,WGM10 =0
	TCCR1B |= 0B00001000; // WGM12 =1
	TCCR1B &= 0B11101111; // WGM13 =0
	TCCR1B |= 0B00000100; // CS12 =1
	TCCR1B &= 0B11111100; // CS11 =0, CS10 =0
	
	//OCR1A =OxF424;
	OCR1AH =0xF4;
	OCR1AL =0x24;
	
	TCNT1L =0x00;
	TCNT1H =0x00;
	
	sei(); //Enabling the Global Interrupt
	
	/* Set Data Direction */
	DDRB = 0B11111110; // Pin 0 as input, rest as output
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

ISR (TIMER1_COMPA_vect)
{
	if(toggle){
		PORTB |= 0B00100000; // set PORTB Pin 5
		
	}
	else{
		PORTB &=0B11011111;
	}
	toggle = 1- toggle;
	
	
}

