/*
 * LCD Display.c
 * LCD16x2 4 bit ATmega16 interface
 * Created: 5/13/2022 2:05:00 AM
 * Author : Tharushni
 */ 



#define F_CPU 16000000UL			/* Define CPU Frequency e.g. here 16MHz */
#include <avr/io.h>			        /* Include AVR std. library file */
#include <util/delay.h>			    /* Include Delay header file */

#define LCD_Dir  DDRB			    /* Define LCD data port direction */
#define LCD_Port PORTB			    /* Define LCD data port */
#define RS PB0				        /* Define Register Select pin */
#define EN PB1 				        /* Define Enable signal pin */
 

//This function is used to send required commands to the LCD
void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);    /* SEND COMMAND TO DATA PORT */
	LCD_Port &= ~ (1<<RS);		                     /* RS=0 FOR COMMAND */
	LCD_Port |= (1<<EN);		                     /* EN=1 FOR H TO L PULSE */
	_delay_us(1);                                    /* WAIT FOR MAKE ENABLE WIDE*/
	LCD_Port &= ~ (1<<EN);                           /* EN=0 FOR H TO L PULSE */
    _delay_us(200);                                  /* WAIT FOR MAKE ENABLE WIDE*/

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);      /* SEND COMMAND TO DATA PORT */
	LCD_Port |= (1<<EN);                             /* EN=1 FOR H TO L PULSE */
	_delay_us(1);                                    /* WAIT FOR MAKE ENABLE WIDE*/
	LCD_Port &= ~ (1<<EN);                           /* EN=0 FOR H TO L PULSE */
	_delay_ms(2);                                    /* WAIT FOR MAKE ENABLE WIDE*/
}

//This function is used to display a single character on the LCD
void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);     /* SEND DATA TO DATA PORT sending upper nibble */
	LCD_Port |= (1<<RS);		                      /* MAKE RS = 1 FOR DATA */
	LCD_Port|= (1<<EN);                               /* EN=0 FOR H TO L PULSE */
	_delay_us(1);                                     /* WAIT FOR MAKE ENABLE WIDE*/
	LCD_Port &= ~ (1<<EN);                            /* EN=0 FOR H TO L PULSE */
   _delay_us(200);                                    /* WAIT FOR MAKE ENABLE WIDE*/

	LCD_Port = (LCD_Port & 0x0F) | (data << 4);       /* sending lower nibble */
	LCD_Port |= (1<<EN);                              /* EN=0 FOR H TO L PULSE */
	_delay_us(1);                                     /* WAIT FOR MAKE ENABLE WIDE*/
	LCD_Port &= ~ (1<<EN);                            /* EN=0 FOR H TO L PULSE */ 
	_delay_ms(2);                                     /* WAIT FOR MAKE ENABLE WIDE*/
}

// LCD Initialize function
void LCD_Init (void)			
{ 
	LCD_Dir = 0xFF;			                  /* Make LCD port direction as output pins */
	_delay_ms(20);			                  /* LCD Power ON delay always >15ms */
	 
	LCD_Command(0x02);		                  /* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);                        /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);                        /* Display on cursor off*/
	LCD_Command(0x06);                        /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);                        /* Clear display screen*/
	_delay_ms(2);
}


void LCD_String (char *str)		     /* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		    /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

//This function is used to display a character array on LCD
void LCD_String_xy (char row, char pos, char *str)	   /* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	                   /* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	                   /* Command of first row and required position<16 */
	LCD_String(str);		                           /* Call LCD string function */
}

//This function is use to clear the display of the LCD
void LCD_Clear()
{
	LCD_Command (0x01);		                         /* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		                         /* Cursor at home position */
}

//This function is used to blink the cursor and shift the cursor to the right
void LCD_Cursor_Blink(){
	   LCD_Command(0x06);                            /* shift the cursor right */
	   _delay_ms(4.5);
	   LCD_Command(0x0E);                            /* Display on cursor blinking */
	   _delay_ms(4.5);
}
/*

//This function is used to display the 4 values entered by user on the LCD
void LCD_Display_INT_TO_STRING(int value){
	  char display_value[16];
	  itoa(value,display_value,10);
	  
	  LCD_String_xy(1,0,"LED Blinks");
	  LCD_String_xy(1,11,display_value);
}

*/


 
int main()
{

	LCD_Init();			              /* Initialization of LCD*/

	LCD_String("AUTOMATIC BOXING");	  /* Write string on 1st line of LCD*/
	LCD_Command(0xC0);		          /* Go to 2nd line*/
	LCD_String("TRAINING MACHINE");	  /* Write string on 2nd line*/
	while(1);
}






