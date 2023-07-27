/*
 * bluetooth.c
 *
 * Created: 5/22/2022 12:52:32 AM
 *  Author: Ekanayaka
 */ 

#include "USART_RS232_H_file.h"		/* include USART library */
//import bluetooth header file
#include "bluetooth.h"

void blueTooth()
{   char Data_in[7];
	USART_Init(9600);
	//int val;
	/*dtostrf(Data_in, 3, 2, string);*/
	LCD_String_xy(2, 0, "HeartRate:");
	char x;int i=0;
		//Data_in =USART_RecieveFloat();	/* receive data from Bluetooth device*/
		do{ 
			x=USART_RxFloat();
			//LCD_Char(x);
			Data_in[i]=x;
			//waitTillChar(x);
			//LCD_String_xy(2, 10+i, Data_in);
			i++;
		}while(x!=NULL);
		

	LCD_String_xy(2, 10, Data_in);
/*
	itoa(val,Data_in,10);
*/
	
	_delay_ms(1000);

	
	
	/*if(val >150)
	{
		LED |= (1<<PA2);	/ * Turn ON LED * /
		
	}*/
	
	
}