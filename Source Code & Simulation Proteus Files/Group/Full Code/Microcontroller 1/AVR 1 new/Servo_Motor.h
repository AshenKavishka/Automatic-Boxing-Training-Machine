/*
 * Servo_Motor.h
 *
 * Created: 5/21/2022 5:13:41 PM
 *  Author: Ekanayaka
 */ 


#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */
#include <avr/interrupt.h>

void left_horizontal_arm();
void right_vertical_arm();
void right_horizontal_arm();
void lft_vertical_arm();



#endif /* SERVO_MOTOR_H_ */