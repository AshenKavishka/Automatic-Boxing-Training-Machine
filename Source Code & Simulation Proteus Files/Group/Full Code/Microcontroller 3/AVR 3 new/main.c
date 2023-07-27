/*
 * AVR 3 new.c
 *
 * Created: 5/22/2022 4:24:18 PM
 * Author : Ekanayaka
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>							/* Include AVR std. library file */
#include <stdlib.h>
#include <string.h.>
#include <util/delay.h>


//header files
#include "USART_RS232_H_file.h"		/* include USART library */




int main(void)
{
    /* Replace with your application code */
    
	DDRD = DDRD & ~(1<<7); // Heart Sensor
	DDRD = DDRD & ~(1<<6); // External Clock

	DDRD = 0xC1; // Beat LED
	
	int i = 0; // I Saves heart beat rate.

	
	int once = 0;
	int once2 = 0;
	
	int last =0; // Saves last BPM.
	int j = 0; // How many seconds elapsed.

	

	
	while(1)
	{
		if(PIND & (1<<7)){
			
			if(once==0){
				PORTD = 0x04; //LED ON
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
					/*if(BPM>50 && BPM<150){
						PORTD=0x80;
					}
					else{
						PORTD=0x40;
					}*/
					
					
					if(BPM > 10){
						USART_Init(9600);
						USART_SendFloat(str);
						_delay_ms(1000);
						USART_TxFloat(NULL);
						break;
					}
					else{
						USART_Init(9600);
						USART_SendFloat("N.M");
						_delay_ms(1000);
						USART_TxFloat(NULL);
						break;
						
					}
					
					
					i=0;
					j=0;
					
					
					}else{
					USART_Init(9600);
					USART_SendFloat(".....");
					_delay_ms(1000);
					USART_TxFloat(NULL);
				}
				once2 = 1;
			}
			
		}
		else {
			once2 = 0;
		}
		
	}
}

