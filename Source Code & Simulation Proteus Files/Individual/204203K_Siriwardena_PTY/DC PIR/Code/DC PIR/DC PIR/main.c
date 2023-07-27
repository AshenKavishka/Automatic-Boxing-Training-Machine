/*
 * DC PIR.c
 *
 * Created: 5/24/2022 8:53:43 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

int main()
{
	
	DDRA &= ~(1<<PA0);
	DDRA &= ~(1<<PA1);
	DDRD = 0xF8;
	
	TCCR2 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	OCR2 = 255;

	while (1)
	{
		if (PINA &(1<<PA0))
		{
			PORTD = 0x28;
			while(PINA &(1<<PA0));
			PORTD = 0x00;
			
			
		}else if(PINA &(1<<PA1))
		{
			PORTD = 0x50;
			while(PINA &(1<<PA1));
			PORTD = 0x00;
		}
		
	}
}