/*
 * CODE.c
 *
 * Created: 5/20/2022 12:46:07 AM
 * Author : DELL
 */ 
#include <avr/io.h>
static volatile float piezoValue;
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

int main(void)
{
	DDRA|=(1<<PA1);
	piezo_init();
	piezoValue;
	/* Replace with your application code */
	while (1)
	{
		piezoValue = piezo_read(0);
		if (piezoValue>0)
		{
			PORTA|=(1<<PA1);
			}else{
			PORTA&=~(1<<PA1);
		}
	}
}




