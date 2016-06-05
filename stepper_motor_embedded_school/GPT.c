/*
 * GPT.c
 *
 * Created: 1/22/2016 6:00:14 PM
 *  Author: samy
 */ 
#include <avr/io.h>
#include "GPT.h"
#include <avr/interrupt.h>
#define TIMER_START_MASK 0x02
#define TIMER_STOP_MASK 0xf8

static IsrCallBackFnType CallBackPtr;


void GPT_Init_Timer(IsrCallBackFnType IsrCbkFun)
{
	TCCR0 = 0x00;
	TCCR0 |= 1<<WGM01;
	OCR0 = 124;
	TIMSK |= 1 <<OCIE0;	
	CallBackPtr = IsrCbkFun; 
	
}



 void GPT_TimerStart(void)
 {
	 TCCR0 |= TIMER_START_MASK;
 }
 void GPT_TimerStop(void)
 {
	 TCCR0 &= TIMER_STOP_MASK;
	 TCNT0 = 0x00;
 }
 

 
 ISR(TIMER0_COMP_vect)
 {
	
	 CallBackPtr();
 }
 
 