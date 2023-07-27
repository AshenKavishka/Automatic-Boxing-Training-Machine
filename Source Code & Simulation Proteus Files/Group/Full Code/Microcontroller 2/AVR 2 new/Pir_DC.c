/*
 * Pir_DC.c
 *
 * Created: 5/21/2022 11:54:28 PM
 *  Author: Ekanayaka
 */ 
//import pir and dc motor header file
#include "Pir_DC.h"
void pir_DC(){
	/*DDRA &= (0<<PA0);	/ * Set the PIR port as input port * /
	DDRA &= (0<<PA1);
	DDRD=0xF8;
	TCCR2 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);
	OCR2 = 200;*/

	if (PIR1_Input &(1<<PA0))
	{
		PORTD = 0x28;
		while(PIR1_Input &(1<<PA0));
		PORTD = 0x00;
		
		
	}else if(PIR2_Input &(1<<PA1))
	{
		PORTD = 0x50;
		while(PIR2_Input &(1<<PA1));
		PORTD = 0x00;
	}
	
}