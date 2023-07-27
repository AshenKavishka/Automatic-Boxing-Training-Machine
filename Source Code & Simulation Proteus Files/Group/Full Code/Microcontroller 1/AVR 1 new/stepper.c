/*
 * stepper.c
 *
 * Created: 5/21/2022 4:53:20 PM
 *  Author: Ekanayaka
 */ 
//import stepper header file
 #include "stepper.h"
 void stepper_motor_clockwise()
 {
	 /* Rotate Stepper Motor clockwise with Half step sequence */

          PORTC = 0x05;
          _delay_ms(300);
          PORTC = 0x06;
          _delay_ms(300);
          PORTC = 0x0A;
          _delay_ms(300);
          PORTC = 0x09;
          _delay_ms(300);
		   PORTC = 0x05;
		   _delay_ms(300);
		 /*PORTC = 0x09;
		 _delay_ms(100);
		 PORTC = 0x08;
		 _delay_ms(100);
		 PORTC = 0x0C;
		 _delay_ms(100);
		 PORTC = 0x04;
		 _delay_ms(100);
		 PORTC = 0x06;
		 _delay_ms(100);
		 PORTC = 0x02;
		 _delay_ms(100);
		 PORTC = 0x03;
		 _delay_ms(100);
		 PORTC = 0x01;
		 _delay_ms(100);
	      PORTC = 0x09;		/ * Last step to initial position * /
	      _delay_ms(100);*/
	 
 }
 void stepper_motor_anticlockwise()
 {
	 /* Rotate Stepper Motor Anticlockwise with half Full step sequence */
	 PORTC = 0x05;
	 _delay_ms(300);
	 PORTC = 0x09;
	 _delay_ms(300);
	 PORTC = 0x0A;
	 _delay_ms(300);
	 PORTC = 0x06;
	 _delay_ms(300);
	 PORTC = 0x05;
	 _delay_ms(300);
		/* PORTC = 0x09;
		 _delay_ms(100);
		 PORTC = 0x01;
		 _delay_ms(100);
		 PORTC = 0x03;
		 _delay_ms(100);
		 PORTC = 0x02;
		 _delay_ms(100);
		 PORTC = 0x06;
		 _delay_ms(100);
		 PORTC = 0x04;
		 _delay_ms(100);
		 PORTC = 0x0C;
		 _delay_ms(100);
		 PORTC = 0x08;
		 _delay_ms(100);
	     PORTC = 0x09;
	    _delay_ms(100);*/
	
 }
