/*
 * Pir_DC.h
 *
 * Created: 5/21/2022 11:55:57 PM
 *  Author: Ekanayaka
 */ 


#ifndef PIR_DC_H_
#define PIR_DC_H_
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#define PIR1_Input		PINA
#define PIR2_Input		PINA



void pir_DC();




#endif /* PIR_DC_H_ */
