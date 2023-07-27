/*
 * Keypad.h
 *
 * Created: 5/21/2022 5:22:16 PM
 *  Author: Ekanayaka
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define KEY_PRT1	PORTA
#define KEY_PRT2	PORTB
#define KEY_DDR1	DDRA
#define KEY_DDR2	DDRB
#define KEY_PIN1	PINA
#define KEY_PIN2	PINB

char keySearch();


#endif /* KEYPAD_H_ */
