/*
 * ultrasonic.h
 *
 * Created: 5/21/2022 5:03:44 PM
 *  Author: Ekanayaka
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */
#include <avr/interrupt.h>
#include <stdlib.h>

#define  Trigger_pin	PA0	/* Trigger pin */



int ultrasonic();



#endif /* ULTRASONIC_H_ */