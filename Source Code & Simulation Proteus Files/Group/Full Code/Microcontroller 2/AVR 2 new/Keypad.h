/*
 * Keypad.h
 *
 * Created: 5/22/2022 12:10:42 AM
 *  Author: Ekanayaka
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define KEY_PRT 	PORTC
#define KEY_DDR		DDRC
#define KEY_PIN		PINC

char keySearch();


#endif /* KEYPAD_H_ */