/*
 * stepper.h
 *
 * Created: 5/21/2022 4:55:32 PM
 *  Author: Ekanayaka
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>
	#include <avr/interrupt.h>


void stepper_motor_clockwise();
void stepper_motor_anticlockwise();


#endif /* STEPPER_H_ */