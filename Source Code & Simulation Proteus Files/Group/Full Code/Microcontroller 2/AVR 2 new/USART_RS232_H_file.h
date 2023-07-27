/*
 * USART_RS232_H_file.h
 *
 * Created: 5/22/2022 12:59:28 AM
 *  Author: Ekanayaka
 */ 


#ifndef USART_RS232_H_FILE_H_
#define USART_RS232_H_FILE_H_

#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>							/* Include AVR std. library file */
#include <stdlib.h>

#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	/* Define prescale value */

void USART_Init(unsigned long);				/* USART initialize function */
char USART_RxFloat();						/* Data receiving function */
void USART_TxFloat(char);					/* Data transmitting function */
void USART_SendFloat(char*);				/* Send string of USART data function */
char* USART_RecieveFloat();
unsigned char readCharFromNode();
void waitTillChar(char ch);



#endif /* USART_RS232_H_FILE_H_ */