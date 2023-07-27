/*
 * piezo.h
 *
 * Created: 5/21/2022 5:17:40 PM
 *  Author: Ekanayaka
 */ 


#ifndef PIEZO_H_
#define PIEZO_H_

#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>		/* Include delay header file */




uint16_t piezo_read(unsigned char ch);
void piezo_init();
void piezo1();
void piezo2();
void piezo3();
void piezo4();
void piezo5();
void piezo6();
static volatile float piezoValue;



#endif /* PIEZO_H_ */