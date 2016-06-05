/*
 * GPT.h
 *
 * Created: 1/22/2016 6:00:05 PM
 *  Author: samy
 */ 


#ifndef GPT_H_
#define GPT_H_


typedef void (*IsrCallBackFnType)(void);

extern void GPT_Init_Timer(IsrCallBackFnType IsrCbkFun);


extern void GPT_TimerStart(void);
extern void GPT_TimerStop(void);



#endif /* GPT_H_ */