/*
 * USART_RS232_H_file.c
 *
 * Created: 5/22/2022 12:57:02 AM
 *  Author: Ekanayaka
 */ 
#include "USART_RS232_H_file.h"						/* Include USART header file */

void USART_Init(unsigned long BAUDRATE)				/* USART initialize function */
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);				/* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	/* Write USCRC for 8 bit data and 1 stop bit */
	UBRRL = BAUD_PRESCALE;							/* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (BAUD_PRESCALE >> 8);					/* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxFloat()									/* Data receiving function */
{
	while( (UCSRA & (1 << RXC)) == 0 );
	return(UDR);									/* Get and return received data */
}
char* USART_RecieveFloat()					/* Send string of USART data function */
{
	static char str[10];
	char num;
	while (USART_RxFloat() != 255);
	for (char i = 0; i < 10; i++)
	{
		if(num = USART_RxFloat())
		str[i] = num;
		if(num == '\0')
		break;
	}
	return str;
}
unsigned char readCharFromNode()	{
	return USART_RxFloat();
}
void waitTillChar(char ch){
	while(readCharFromNode() != ch);
}



void USART_TxFloat(char data)						/* Data transmitting function */
{
	while( !(UCSRA & (1 << UDRE)) );  /* Wait for empty transmit buffer*/
	UDR = data ;				/* Wait until data transmit and buffer get empty */
}


void USART_SendFloat(char *str)					/* Send string of USART data function */
{
	int i=0;
	while (str[i]!=0)
	{
		USART_TxFloat(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}