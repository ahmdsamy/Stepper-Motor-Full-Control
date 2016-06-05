/*
 * stepper_motor.c
 *
 * Created: 2/21/2016 9:11:29 PM
 *  Author: samy
 */ 
#include "stepper_motor.h"
#include "DIO.h"
#include "LEDS.h"
#include "GPT.h"
#include <avr/io.h>

extern unsigned long int TimeoutCounter_stepper ;

void stepper_Init(void)
{
	DIO_vidWritePortDirection(PA,0x0F,0xFF);
	DIO_vidWritePortData(PA,0x0F,0x00);
	
}

void STEPPER_MOTOR(unsigned char mode,unsigned char direction,unsigned short int speed)
{  
	
  static unsigned char motor_halfmode_state=0;
  static unsigned char motor_fullmode_state=0;
	
	
  if(TimeoutCounter_stepper>speed)
   {
		if(mode==mode_full)
			{ 
			if(direction==right)
				{
			        if(motor_fullmode_state==0)
					{
						DIO_vidWritePortData(PA,0x0F,0x00);
						DIO_vidWritePortData(PA,0x01,0xFF);
						motor_fullmode_state++;
					}
					
					else if(motor_fullmode_state==1)
					{
						DIO_vidWritePortData(PA,0x0F,0x00);
						DIO_vidWritePortData(PA,0x04,0xFF);
						motor_fullmode_state++;
					}
					else if(motor_fullmode_state==2)
					{
						DIO_vidWritePortData(PA,0x0F,0x00);
						DIO_vidWritePortData(PA,0x02,0xFF);
						motor_fullmode_state++;
					}
					else if(motor_fullmode_state==3)
					{
						DIO_vidWritePortData(PA,0x0F,0x00);
						DIO_vidWritePortData(PA,0x08,0xFF);
						motor_fullmode_state=0;
					}
					
				}
		
			else if(direction==left)
				{
			      
				 if(motor_fullmode_state==0)
				  {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x02,0xFF);
					  motor_fullmode_state=3;
				  }
				  
				  
				  else if(motor_fullmode_state==1)
				  {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x08,0xFF);
					  motor_fullmode_state--;
				  }
				  else if(motor_fullmode_state==2)
				  {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x01,0xFF);
					  motor_fullmode_state--;
				  }
				  else if(motor_fullmode_state==3)
				  {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x04,0xFF);
					  motor_fullmode_state--;
				  }
				}
		
			}
	
		else if(mode==mode_half)
			{
			if(direction==right)
				{
			      if(motor_halfmode_state==0)
			      {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x0A,0xFF);
				      motor_halfmode_state++;
			      }
			      
			      else if(motor_halfmode_state==1)
			      {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x08,0xFF);
				      motor_halfmode_state++;
			      }
			      else if(motor_halfmode_state==2)
			      {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x09,0xFF);
				      motor_halfmode_state++;
			      }
			      else if(motor_halfmode_state==3)
			      {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x01,0xFF);
				      motor_halfmode_state++;
			      }
				  else if(motor_halfmode_state==4)
				  {
					  DIO_vidWritePortData(PA,0x0F,0x00);
					  DIO_vidWritePortData(PA,0x05,0xFF);
					  motor_halfmode_state++;
				  }
				  
				  else if(motor_halfmode_state==5)
				  {
					 DIO_vidWritePortData(PA,0x0F,0x00);
					 DIO_vidWritePortData(PA,0x04,0xFF);
					  motor_halfmode_state++;
				  }
				  else if(motor_halfmode_state==6)
				  {
					 DIO_vidWritePortData(PA,0x0F,0x00);
					 DIO_vidWritePortData(PA,0x06,0xFF);
					  motor_halfmode_state++;
				  }
				  else if(motor_halfmode_state==7)
				  {
					 DIO_vidWritePortData(PA,0x0F,0x00);
					 DIO_vidWritePortData(PA,0x02,0xFF);
					  motor_halfmode_state=0;
				  }
				  
				}
		
		
			else if(direction==left)
				{  
					 if(motor_halfmode_state==0)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x06,0xFF);
						 motor_halfmode_state=7;
					 }
					 
					 else if(motor_halfmode_state==1)
					 {
						  DIO_vidWritePortData(PA,0x0F,0x00);
						  DIO_vidWritePortData(PA,0x02,0xFF);
						  motor_halfmode_state--;
					 }
					 else if(motor_halfmode_state==2)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x0A,0xFF);
						 motor_halfmode_state--;
					 }
					 else if(motor_halfmode_state==3)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x08,0xFF);
						 motor_halfmode_state--;
					 }
					 else if(motor_halfmode_state==4)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x09,0xFF);
						 motor_halfmode_state--;
					 }
					 
					 else if(motor_halfmode_state==5)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x01,0xFF);
						 motor_halfmode_state--;
					 }
					 else if(motor_halfmode_state==6)
					 {
						  DIO_vidWritePortData(PA,0x0F,0x00);
						  DIO_vidWritePortData(PA,0x05,0xFF);
						 motor_halfmode_state--;
					 }
					 else if(motor_halfmode_state==7)
					 {
						 DIO_vidWritePortData(PA,0x0F,0x00);
						 DIO_vidWritePortData(PA,0x04,0xFF);
						 motor_halfmode_state--;
					 }
				}				
			}	
  TimeoutCounter_stepper=0; 
  }	         
}
