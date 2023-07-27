/*
 * Heart beat sensor.c
 *
 * Created: 6/9/2022 2:47:23 PM
 * Author : Nuska
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#define LCD PORTC
#define EN 1
#define RS 0
#define RW 1

#endif

#include<avr/io.h>
#include<util/delay.h>

void lcdcmd(unsigned char cmd){
	PORTB &=~(1<<RS);
	PORTB &=~(1<<RW);
	LCD= cmd & 0xF0;
	PORTC|=(1<<EN);
	_delay_ms(1);
	PORTC &= ~(1<<EN);

	LCD = cmd<<4;
	PORTC |=(1<<EN);
	_delay_ms(1);
	PORTC &= ~(1<<EN);
}


void lcddata(unsigned char data){
	
	PORTB |= (1<<RS);
	PORTB &= ~(1<<RW);
	LCD= data & 0xF0;
	PORTC|= (1<<EN);
	_delay_ms(5);
	PORTC &= ~(1<<EN);

	LCD = data<<4;
	PORTC |=(1<<EN);
	_delay_ms(5);
	PORTC &= ~(1<<EN);
	
}

void lcd_Print(const char*str){
	int i;
	for(i=0;str[i]!=0;i++)
	{
		lcddata(str[i]);
	}
}

void lcd_init(){
	DDRC= 0xFF;
	DDRC |=(1<<EN);
	DDRB=0xFF;
	PORTC&= ~(1<<EN);
	lcdcmd(0x33);
	lcdcmd(0x32);
	lcdcmd(0x28);
	lcdcmd(0x0C);
	lcd_Print("CALCULATING  ");
	lcdcmd(0xC0);
}



int main(void)
{
	
	DDRD = DDRD & ~(1<<7); // Heart Sensor
	DDRD = DDRD & ~(1<<6); // External Clock

	DDRD = 0x01; // Beat LED
	
	int i = 0; // I Saves heart beat rate.

	
	int once = 0;
	int once2 = 0;
	
	int last =0; // Saves last BPM.
	int j = 0; // How many seconds elapsed.

	
	lcd_init();
	
	while(1)
	{
		if(PIND & (1<<7)){
			
			if(once==0){
				PORTD = 0x01; //LED ON
				i++;
				once = 1;
			}
			
		}
		else {
			PORTD = 0x00; //LED OFF
			once = 0;
		}
		
		
		
		if(PIND & (1<<6)){
			
			if(once2==0){
				
				j++;
				
				if(j >= 10){
					
					int BPM;
					
					if(last==0){
						BPM = i*6;
						last = BPM;
						}else{
						BPM = ((i*6)+last)/2;
						last = BPM;
					}
					
					char str[16];
					itoa(BPM, str, 10);
					
					
					lcdcmd(0x01);
					
					if(BPM > 10){
						lcd_Print("AVG BPM : ");
						lcd_Print(str);
						lcdcmd(0xC0);
						}else{
						lcd_Print("NOT DETECTED!");
						lcdcmd(0xC0);
					}
					
					
					i=0;
					j=0;
					
					
					}else{
					lcd_Print(".");
				}
				once2 = 1;
			}
			
		}
		else {
			once2 = 0;
		}
		
	}
	
	
	
}



