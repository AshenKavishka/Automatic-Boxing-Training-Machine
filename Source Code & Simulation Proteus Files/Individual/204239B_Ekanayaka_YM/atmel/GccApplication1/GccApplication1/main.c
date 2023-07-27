/*
 * GccApplication1.c
 *
 * Created: 5/13/2022 11:26:29 PM
 * Author : YMEkanayaka
 */ 

/*
 * Ultrasonic sensor HC-05 interfacing with AVR ATmega16
 * http://www.electronicwings.com
 */ 


#define F_CPU 16000000UL		/* Define CPU Frequency 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <util/delay.h>
#include <avr/interrupt.h>

#include <string.h>
#include <stdlib.h>


#define  Trigger_pin	PA0	/* Trigger pin */

#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRD			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTD			/* Define LCD data port */
#define RS PD3					/* Define Register Select (data reg./command reg.) signal pin */
#define RW PD4						/* Define Read/Write signal pin */
#define EN PD5							/* Define Enable signal pin */

void LCD_Command (char);				/* LCD command write function */
void LCD_Char (char);					/* LCD data write function */
void LCD_Init (void);					/* LCD Initialize function */
void LCD_String (char*);				/* Send string to LCD function */
void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
void LCD_Clear (void);					/* LCD clear function */

void stepper_motor_clockwise();
void stepper_motor_anticlockwise();
 void height_adjust();
 int ultrasonic();


int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

int main(void)
{
	
	
	DDRA = 0x01;		/* Make trigger pin as output */
	PORTD = 0xFF;		/* Turn on Pull-up */
	DDRC=0xFF;
	
	LCD_Init();
	LCD_String_xy(1, 0, "Ultrasonic");
	
	
	while(1){
		height_adjust();
	}
}
 void stepper_motor_clockwise()
 {
	 /* Rotate Stepper Motor clockwise with Half step sequence */

          PORTC = 0x05;
          _delay_ms(300);
          PORTC = 0x06;
          _delay_ms(300);
          PORTC = 0x0A;
          _delay_ms(300);
          PORTC = 0x09;
          _delay_ms(300);
		   PORTC = 0x05;
		   _delay_ms(300);
		 /*PORTC = 0x09;
		 _delay_ms(100);
		 PORTC = 0x08;
		 _delay_ms(100);
		 PORTC = 0x0C;
		 _delay_ms(100);
		 PORTC = 0x04;
		 _delay_ms(100);
		 PORTC = 0x06;
		 _delay_ms(100);
		 PORTC = 0x02;
		 _delay_ms(100);
		 PORTC = 0x03;
		 _delay_ms(100);
		 PORTC = 0x01;
		 _delay_ms(100);
	      PORTC = 0x09;		/ * Last step to initial position * /
	      _delay_ms(100);*/
	 
 }
 void stepper_motor_anticlockwise()
 {
	 /* Rotate Stepper Motor Anticlockwise with half Full step sequence */
	 PORTC = 0x05;
	 _delay_ms(300);
	 PORTC = 0x09;
	 _delay_ms(300);
	 PORTC = 0x0A;
	 _delay_ms(300);
	 PORTC = 0x06;
	 _delay_ms(300);
	 PORTC = 0x05;
	 _delay_ms(300);
		/* PORTC = 0x09;
		 _delay_ms(100);
		 PORTC = 0x01;
		 _delay_ms(100);
		 PORTC = 0x03;
		 _delay_ms(100);
		 PORTC = 0x02;
		 _delay_ms(100);
		 PORTC = 0x06;
		 _delay_ms(100);
		 PORTC = 0x04;
		 _delay_ms(100);
		 PORTC = 0x0C;
		 _delay_ms(100);
		 PORTC = 0x08;
		 _delay_ms(100);
	     PORTC = 0x09;
	    _delay_ms(100);*/
	
 }
 void height_adjust(){
	 
	int dist=ultrasonic();
	 if(dist>90){
		 while(dist>90){
			 stepper_motor_clockwise();
			 dist=ultrasonic();
			 

		 }
		 
	 }
	 else if(dist<90){
		 while(dist<90){
			 stepper_motor_anticlockwise();
			 dist=ultrasonic();
			 

		 }
		 
	 }
	 
 }
 int ultrasonic(){
	 char string[10];
	 unsigned long count;
	 int distance;
	 sei();			/* Enable global interrupt */
	 TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	 TCCR1A = 0;		/* Set all bit to zero Normal operation */

	 /* Give 10us trigger pulse on trig. pin to HC-SR04 */
	 PORTA |= (1 << Trigger_pin);
	 _delay_us(15);
	 PORTA &= (~(1 << Trigger_pin));
	 
	 TCNT1 = 0;	/* Clear Timer counter */
	 TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
	 TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	 TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

	 /*Calculate width of Echo by Input Capture (ICP) */
	 TimerOverflow = 0;/* Clear Timer overflow count */
	 while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	 TCNT1 = 0;	/* Clear Timer counter */
	 TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
	 TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
	 TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	 

	 while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	 count = ICR1 +(65535 * TimerOverflow);	/* Take count */
	 /* 8MHz Timer freq, sound speed =343 m/s */
	 distance = (int)(count/ 927);

	 dtostrf(distance,4,0, string);/* distance to string */
	 strcat(string, " cm   ");	/* Concat unit i.e.cm */
	 LCD_String_xy(2, 0, "Dis  = ");
	 LCD_String_xy(2, 6, string);	/* Print distance */
	 _delay_ms(1000);
	 return distance;
	 
 }
 void LCD_Command (char cmd)							/* LCD command write function */
 {
	 LCD_Data_Port = cmd;							/* Write command data to LCD data port */
	 LCD_Command_Port &= ~((1<<RS)|(1<<RW));			/* Make RS LOW (command reg.), RW LOW (Write) */
	 LCD_Command_Port |= (1<<EN);					/* High to Low transition on EN (Enable) */
	 _delay_us(1);
	 LCD_Command_Port &= ~(1<<EN);
	 _delay_ms(3);									/* Wait little bit */
 }

 void LCD_Char (char char_data)						/* LCD data write function */
 {
	 LCD_Data_Port = char_data;						/* Write data to LCD data port */
	 LCD_Command_Port &= ~(1<<RW);					/* Make RW LOW (Write) */
	 LCD_Command_Port |= (1<<EN)|(1<<RS);			/* Make RS HIGH (data reg.) and High to Low transition on EN (Enable) */
	 _delay_us(1);
	 LCD_Command_Port &= ~(1<<EN);
	 _delay_ms(1);									/* Wait little bit */
 }

 void LCD_Init (void)								/* LCD Initialize function */
 {
	 LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		/* Make LCD command port direction as o/p */
	 LCD_Data_Dir = 0xFF;							/* Make LCD data port direction as o/p */
	 
	 _delay_ms(20);									/* LCD power up time to get things ready, it should always >15ms */
	 LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	 LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	 LCD_Command (0x06);								/* Auto Increment cursor */
	 LCD_Command (0x01);								/* Clear LCD command */
	 LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
 }

 void LCD_String (char *str)							/* Send string to LCD function */
 {
	 int i;
	 for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	 {
		 LCD_Char (str[i]);							/* Call LCD data write */
	 }
 }

 void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
 {
	 if (row == 1)
	 LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	 else if (row == 2)
	 LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	 LCD_String(str);								/* Call LCD string function */
 }

 void LCD_Clear (void)								/* LCD clear function */
 {
	 LCD_Command (0x01);								/* Clear LCD command */
	 LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
 }



