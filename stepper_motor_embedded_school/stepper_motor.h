/*
 * stepper_motor.h
 *
 * Created: 2/21/2016 9:11:50 PM
 *  Author: samy
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_


extern void stepper_Init(void);
extern void STEPPER_MOTOR(unsigned char mode,unsigned char direction,unsigned short int speed);



#endif /* STEPPER_MOTOR_H_ */