/*
 * stepper_motor_embedded_school.c
 *
 * Created: 2/21/2016 2:32:38 PM
 *  Author: Samy
 */ 

#include "GPT.h"
#include "LEDS.h"
#include "BTN.h"
#include "DIO.h"
#include "stepper_motor.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	unsigned char x=0;
	unsigned char mode_flag=0;
	unsigned char dir_flag=0;
	unsigned char state_mode_flag=0;
	unsigned char state_direction_flag=0;
	unsigned short int speed=1000;
	unsigned short int speed_array[5]={3000,2000,1000,500,200};
	signed char i=2;
	LED_Init();
	BTN_Init();
	stepper_Init();
	sei();
		
    while(1)
    {  
       BTN_GetBtnState(MODE_BTN,&x);
	   if(x==BTN_STATE_ACTIVE)
	   { 
		  if (state_mode_flag==0)
		    { mode_flag=mode_full;
			  state_mode_flag=1;	
			}
		  else
		  {
			 mode_flag=mode_half; 
			 state_mode_flag=0; 	
		  }							
	   }
	   
	 
	  
	  BTN_GetBtnState(DIR_BTN,&x);
	  if(x==BTN_STATE_ACTIVE)
	  {
		  if (state_direction_flag==0)
		  { 
			  dir_flag=right;
			  state_direction_flag=1;
		  }
		  else
		  {
			  dir_flag=left;
			  state_direction_flag=0;
		  }
	  }
	   
	  
	   BTN_GetBtnState(SPEED_UP_BTN,&x);
	   if(x==BTN_STATE_ACTIVE)
	   {
		   i++;
		   if(i==5)
		   {
			  i=0;
		   }
		   speed=speed_array[i];
		   
		   
		   
	   }
	   
	   BTN_GetBtnState(SPEED_DOWN_BTN,&x);
	    if(x==BTN_STATE_ACTIVE)
	     {
		     
			 i--;
			 if(i==-1)
			 {
				 i=4;
			 }
			  speed=speed_array[i]; 
			
			
	     }
	 
	 
	 
	  DIR_MODE_LEDS(dir_flag,mode_flag);
	  STEPPER_MOTOR(mode_flag,dir_flag,speed);
	
  }	  
}