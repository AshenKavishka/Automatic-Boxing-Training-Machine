/*
 * Keypad.c
 *
 * Created: 5/22/2022 12:09:27 AM
 *  Author: Ekanayaka
 */ 
/*
 * 
 * Keypad.c
 * 
 * 
 */ 

//import keypad header file
#include "Keypad.h"



//This Function Returns the Character Entered through the KeyPad
unsigned char key_pad[4][4] = {	{'7','4','1','.'},
{'8','5','2','0'},
{'9','6','3','E'},
{'P','O','D','C'}};

unsigned char colloc, rowloc;
char keySearch()
{
	
	
	while(1)
	{
		KEY_DDR = 0xF0;           /* set port direction as input-output */
		KEY_PRT = 0xFF;

		do
		{
			KEY_PRT &= 0x0F;       //ground all rows of keyboard at once
			colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc != 0x0F);			//keep checking until all keys released
		
		do
		{
			do
			{
				_delay_ms(20);					/* 20ms key debounce time */
				colloc = (KEY_PIN & 0x0F);		 // check if any key is pressed
			}while(colloc == 0x0F);			 //continuous checking for key press
			
			_delay_ms (20);				 /* 20 ms key debounce time */
			colloc = (KEY_PIN & 0x0F);		//read the columns
		}while(colloc == 0x0F);				// wait for the key press


		/* now check for rows */
		KEY_PRT = 0xEF;						//ground row 0 of keyboard
		colloc = (KEY_PIN & 0x0F);			//read  a columns
		if(colloc != 0x0F)					//column is detected
		{
			rowloc = 0;						 //save the row location
			break;							//exit while loop
		}

		KEY_PRT = 0xDF;				/* check for pressed key in 2nd row */
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 1;
			break;
		}
		
		KEY_PRT = 0xBF;				/* check for pressed key in 3rd row */
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
		{
			rowloc = 2;
			break;
		}

		KEY_PRT = 0x7F;				/* check for pressed key in 4th row */
		colloc = (KEY_PIN & 0x0F);
		if(colloc != 0x0F)
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

