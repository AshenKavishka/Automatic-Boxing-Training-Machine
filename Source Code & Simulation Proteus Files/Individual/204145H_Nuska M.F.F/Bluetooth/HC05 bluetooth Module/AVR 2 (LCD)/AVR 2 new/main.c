/*
 * PIR.c
 *
 * Created: 5/12/2022 11:27:44 PM
 * Author : DELL
 */ 

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


#define LED_OUTPUT		PORTB
#include <string.h>
#include <stdlib.h>
#include "LCD_16x2_H_file.h"	/* Include LCD header file */
#include "Keypad.h"
#include "bluetooth.h"

int main(void)
{  /* char *string;*/

	
    USART_Init(9600);					/* initialize USART with 9600 baud rate */
	
	//DDRB = 0xff;	/* Set the LED port as output port */
		LCD_Init();
   LCD_String_xy(1, 0, "Welcome! ");
	char x='?';
	
	while(1){
	 x=keySearch();
	 if(x!='?'){
		break; 
	 }
	 
	 }

	//dtostrf(x, 1, 0, string);
	LCD_String_xy(1, 9, "Mode:");
	LCD_Char(x);
	/*LCD_String_xy(1, 14, string);*/
    	
	while(1)
	{   

		blueTooth();
		
	}

}
