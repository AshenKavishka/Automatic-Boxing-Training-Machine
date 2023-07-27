/*
 * bluetooth.h
 *
 * Created: 5/22/2022 12:54:05 AM
 *  Author: Ekanayaka
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "USART_RS232_H_file.h"		/* include USART library */

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED PORTA
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
char *string;
void blueTooth();


#endif /* BLUETOOTH_H_ */