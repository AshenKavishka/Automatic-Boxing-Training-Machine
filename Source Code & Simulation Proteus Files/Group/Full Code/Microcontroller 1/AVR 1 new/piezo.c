/*
 * piezo.c
 *
 * Created: 5/21/2022 5:16:10 PM
 *  Author: Ekanayaka
 */ 
//insert piezo header file
#include "piezo.h"



void piezo_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);

	// ADC Enable and prescaler of 64
	// 8000000/64 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t piezo_read(unsigned char ch)
{   
	//Select ADC Channel ch must be 0-7
	ch=ch&0b00000111;
	ADMUX|=ch;

	//Start Single conversion
	ADCSRA|=(1<<ADSC);

	//Wait for conversion to complete
	while(!(ADCSRA & (1<<ADIF)));

	//Clear ADIF by writing one to it
	//Note you may be wondering why we have write one to clear it
	//This is standard way of clearing bits in io as said in datasheets.
	//The code writes '1' but it result in setting bit to '0' !!!

	ADCSRA|=(1<<ADIF);
	

	return(ADC);
}

void piezo1()
{   DDRC|=(1<<PC5);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTC|=(1<<PC5);

	while (1)
	{
		piezoValue = piezo_read(2);
		if (piezoValue>0)
		{
			PORTC&=~(1<<PC5);
			break;
			}else{
			PORTC|=(1<<PC5);
		}
	}
}
void piezo2()
{   DDRC|=(1<<PC6);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTC|=(1<<PC6);

	while (1)
	{
		piezoValue = piezo_read(1);
		if (piezoValue>0)
		{
			PORTC&=~(1<<PC6);
			break;
			}else{
			PORTC|=(1<<PC6);
		}
	}
}
void piezo3()
{   DDRC|=(1<<PC7);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTC|=(1<<PC7);

	while (1)
	{
		piezoValue = piezo_read(4);
		if (piezoValue>0)
		{
			PORTC&=~(1<<PC7);
			break;
			}else{
			PORTC|=(1<<PC7);
		}
	}
}
void piezo4()
{   DDRD|=(1<<PD0);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTD|=(1<<PD0);

	while (1)
	{
		piezoValue = piezo_read(5);
		if (piezoValue>0)
		{
			PORTD&=~(1<<PD0);
			break;
			}else{
			PORTD|=(1<<PD0);
		}
	}
}
void piezo5()
{   DDRD|=(1<<PD1);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTD|=(1<<PD1);

	while (1)
	{
		piezoValue = piezo_read(6);
		if (piezoValue>0)
		{
			PORTD&=~(1<<PD1);
			break;
			}else{
			PORTD|=(1<<PD1);
		}
	}
}
void piezo6()
{   DDRD|=(1<<PD2);
	piezo_init();
	 piezoValue;
	/* Replace with your application code */
	PORTD|=(1<<PD2);

	while (1)
	{
		piezoValue = piezo_read(7);
		if (piezoValue>0)
		{
			PORTD&=~(1<<PD2);
			break;
			}else{
			PORTD|=(1<<PD2);
		}
	}
}





