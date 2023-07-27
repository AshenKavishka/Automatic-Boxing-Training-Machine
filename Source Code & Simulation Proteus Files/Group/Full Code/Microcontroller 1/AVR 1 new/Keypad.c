/*
 * Keypad.c
 *
 * Created: 5/21/2022 5:20:43 PM
 *  Author: Ekanayaka
 */ 
//keypad header file

#include "Keypad.h"

//This Function Returns the Character Entered through the KeyPad
char keySearch()
{
	unsigned char key_pad[4][4] = {	{'7','4','1','.'},
	{'8','5','2','0'},
	{'9','6','3','E'},
	{'P','O','D','C'}};
	
	unsigned char colloc, rowloc;
	
	while(1)
	{
		
		KEY_DDR1 &=!(1<<PA3) ;           /* set port direction as input-output */
		KEY_PRT1 |=(1<<PA3);
		KEY_DDR2 = 0xF0;           /* set port direction as input-output */
		KEY_PRT2 = 0xF7;

		do
		{
			KEY_PRT1 &= 0x08;		//ground all rows of keyboard at once
			KEY_PRT2 &= 0x07;
			colloc = ((KEY_PIN1|KEY_PIN2) & 0x0F); /* read status of column */
		}while(colloc !=0x0F);			//keep checking until all keys released
		
		do
		{
			do
			{
				_delay_ms(20);					/* 20ms key debounce time */
				colloc =((KEY_PIN1|KEY_PIN2) & 0x0F);		 // check if any key is pressed
			}while(colloc ==0x0F);			 //continuous checking for key press
			
			_delay_ms (40);				 /* 40 ms key debounce time */
			colloc = ((KEY_PIN1|KEY_PIN2) & 0x0F);		//read the columns
		}while(colloc ==0x0F);				// wait for the key press


		/* now check for rows */
		KEY_PRT1 = 0x08;					//ground row 0 of keyboard
		KEY_PRT2 = 0xE7;
		colloc = ((KEY_PIN1|KEY_PIN2) & 0x0F);			//read  a columns		(KEY_PIN1 & 0x40)&&(KEY_PIN2 & 0x67)
		if(colloc !=0x0F)					//column is detected
		{
			rowloc = 0;						 //save the row location
			break;							//exit while loop
		}

		KEY_PRT1 = 0x08;				/* check for pressed key in 2nd row */
		KEY_PRT2 = 0xD7;
		colloc = ((KEY_PIN1|KEY_PIN2) & 0x0F);
		if(colloc !=0x0F)
		{
			rowloc = 1;
			break;
		}
		
		KEY_PRT1 = 0x08;				/* check for pressed key in 3rd row */
		KEY_PRT2 = 0xB7;
		colloc = ((KEY_PIN1|KEY_PIN2) & 0x0F);
		if(colloc !=0x0F)
		{
			rowloc = 2;
			break;
		}

		KEY_PRT1 = 0x08;				/* check for pressed key in 4th row */
		KEY_PRT2 = 0x77;
		colloc =  ((KEY_PIN1|KEY_PIN2) & 0x0F);
		if(colloc !=0x0F)
		{
			rowloc = 3;
			break;
		}
	}
	//check the column and send its result to Port A
	if(colloc == 0x0E)
	return(key_pad[rowloc][0]);
	else if(colloc == 0x0D)
	return(key_pad[rowloc][1]);
	else if(colloc == 0x0B)
	return(key_pad[rowloc][2]);
	else
	return(key_pad[rowloc][3]);
}


