/*
 * CFile1.c
 *
 * Created: 2/21/2016 2:52:17 PM
 *  Author: samy
 */ 

#include "LEDS.h"
#include "DIO.h"
#include "GPT.h"
#include <avr/io.h>

static unsigned long int TimeoutCounter ;
unsigned long int TimeoutCounter_stepper;

static void TimeoutInc(void)
{
	TimeoutCounter ++;
	TimeoutCounter_stepper ++;
}


typedef struct
{
	unsigned char LEDPort;
	unsigned char LEDMask;
}LEDConfigType;

static const LEDConfigType LEDConfigData[NUM_OF_LEDS] =
{
	{
		PC,FULL_MODE_LED
	}
	,
	{
		PC,HALF_MODE_LED
	}
	,
	{
		PC,RIGHT_DIR_LED
	}
	,
	{
		PC,LEFT_DIR_LED
	}
};

void LED_Init(void)
{
	
	unsigned char LoopIndex;
	unsigned char LEDPort;
	unsigned char LEDMask;
	for(LoopIndex = 0 ; LoopIndex < NUM_OF_LEDS ; LoopIndex ++)
	{
		LEDPort = LEDConfigData[LoopIndex].LEDPort;
		LEDMask = LEDConfigData[LoopIndex].LEDMask;
		DIO_vidWritePortDirection(LEDPort,LEDMask,0xFF);
	}
	GPT_Init_Timer(TimeoutInc);
	GPT_TimerStart();
}

void DIR_MODE_LEDS(unsigned char direction,unsigned char mode)
{   
	
	
	if(TimeoutCounter>250)
	  {	
	   if(direction==right)
	    {  
			
			DIO_vidWritePortData(PC,LEFT_DIR_LED,0x00);
			DIO_vidToggle_port(PC,RIGHT_DIR_LED);
		}
		
	   else if(direction==left)
		{
		
		DIO_vidWritePortData(PC,RIGHT_DIR_LED,0x00);
		DIO_vidToggle_port(PC,LEFT_DIR_LED);
		
	     }
	

		if(mode==mode_full)
			{   
			
			DIO_vidWritePortData(PC,HALF_MODE_LED,0x00);
			DIO_vidToggle_port(PC,FULL_MODE_LED);
			}		   
	
		else if(mode==mode_half)
		   {
			
			 DIO_vidWritePortData(PC,FULL_MODE_LED,0x00); 
			 DIO_vidToggle_port(PC,HALF_MODE_LED);
		  }
	TimeoutCounter=0;
	}
}