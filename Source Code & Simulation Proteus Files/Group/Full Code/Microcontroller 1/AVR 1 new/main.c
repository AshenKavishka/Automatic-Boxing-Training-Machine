/*
 * GccApplication1.c
 *
 * Created: 11/25/2021 10:53:59 AM
 * Author : YMEkanayaka*/
	#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
	#include <avr/io.h>		/* Include AVR std. library file */
	#include <util/delay.h>		/* Include delay header file */
	#include <avr/interrupt.h>
	#include <stdlib.h>
	
	void height_adjust();
	
	
   
	//Header files
	#include "stepper.h"
	#include "ultrasonic.h"
	#include "Servo_Motor.h"
	#include "Keypad.h"
	#include "piezo.h"
	int main(void)
	{   
		
		
		DDRD = 0xBF; //Makes RD4,RD5 and RD7 output pins/* Make PORTD lower pins as output */
		PORTD = 0x00;
		
		/* Make PORTD lower pins as output */
				/* Set period in between two steps */
		DDRC=0xFF;
	    DDRA |= (1<<PA0);		/* Make trigger pin as output */
/*
		PORTD = 0xFF;		/ * Turn on Pull-up * /
*/
		height_adjust();
				char x='?';

		while(1){
		 x=keySearch();
		 if(x!='?'){break;}
		}
		//REALTIME COMBINATIONS
		switch(x)
		{
			case '1':
			while(1){
			piezo1();
			piezo2();
			left_horizontal_arm();
			piezo4();
			right_horizontal_arm();
			}
			
			case '7':
			while(1){
				    piezo3();
					piezo4();
					lft_vertical_arm();
					piezo6();
					piezo3();
					right_horizontal_arm();
					piezo6();
					
				
				
			}
			case '4':
			while(1){
				piezo5();
				piezo6();
				piezo3();
				right_horizontal_arm();
				piezo3();
				piezo6();
				piezo4();
				
			}
			
		}
	
		
		
		
		
	}
void height_adjust(){
	
	     int dist=ultrasonic();
		if(dist>90){
			while(dist>90){
				stepper_motor_clockwise();
					     dist=ultrasonic();
						

			}
			
		}
		else if(dist<90){
			while(dist<90){
				 stepper_motor_anticlockwise();
				 	     dist=ultrasonic();
						  

			}
			
		}	
		
}	




