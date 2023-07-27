/*
 * LCD_16x2_H_file.h
 *
 * Created: 5/22/2022 1:01:58 AM
 *  Author: Ekanayaka
 */ 


#ifndef LCD_16X2_H_FILE_H_
#define LCD_16X2_H_FILE_H_

#define F_CPU 16000000UL

#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>					/* Include Delay header file */
#include <string.h>
#include <stdlib.h>


#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRA			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTA			/* Define LCD data port */
#define RS PA5							/* Define Register Select (data reg./command reg.) signal pin */
#define RW PA6							/* Define Read/Write signal pin */
#define EN PA7							/* Define Enable signal pin */

void LCD_Command (char);				/* LCD command write function */
void LCD_Char (char);					/* LCD data write function */
void LCD_Init (void);					/* LCD Initialize function */
void LCD_String (char*);				/* Send string to LCD function */
void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
void LCD_Clear (void);					/* LCD clear function */



#endif /* LCD_16X2_H_FILE_H_ */