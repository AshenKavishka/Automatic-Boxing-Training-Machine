/*
 * Servo_Motor.c
 *
 * Created: 5/21/2022 5:07:30 PM
 *  Author: Ekanayaka
 */ 
/*
 * 
 *
 * Servo_Motor.c
 * 
 */ 

//import servo motor header file
#include "Servo_Motor.h"
void left_horizontal_arm()
{
	DDRB |= (1<<PB3); //Makes RB3 output pin
	PORTB = 0x00;
	///Rotate Motor 1 to 0 degree
	PORTB |= (1<<PB3);
	_delay_us(1000);
	PORTB &= !(1<<PB3);

	_delay_ms(500);

	//Rotate Motor 1 to 90 degree
	PORTB |= (1<<PB3);
	_delay_us(1500);
	PORTB &= !(1<<PB3);

	_delay_ms(500);


}
void right_vertical_arm()
{
//Rotate Motor 2 to 0 degree
PORTD |= (1<<PD4);
_delay_us(1000);
PORTD &= !(1<<PD4);

_delay_ms(500);

//Rotate Motor 2 to 90 degree
PORTD |= (1<<PD4);
_delay_us(1500);
PORTD &= !(1<<PD4);

_delay_ms(500);	


}
void right_horizontal_arm(){
	//Rotate Motor 3 to 0 degree
PORTD |= (1<<PD5);
	_delay_us(1000);
PORTD &= !(1<<PD5);

	_delay_ms(500);

	//Rotate Motor 3 to 90 degree
PORTD |= (1<<PD5);
	_delay_us(1500);
PORTD &= !(1<<PD5);

	_delay_ms(500);

	

	
}
void lft_vertical_arm()
{
	
	//Rotate Motor 4 to 0 degree
PORTD |= (1<<PD7);
	_delay_us(1000);
PORTD &= !(1<<PD7);
	_delay_ms(500);

	//Rotate Motor 4 to 90 degree
PORTD |= (1<<PD7);
	_delay_us(1500);
PORTD &= !(1<<PD7);

	_delay_ms(500);

}

		
		
		
		
	
