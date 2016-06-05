/*
 * BTN.h
 *
 * Created: 1/22/2016 5:55:23 PM
 *  Author: samy
 */ 


#ifndef BTN_H_
#define BTN_H_

#define NUM_OF_BTNS 4

#define BTN_STATE_ACTIVE   0x00
#define BTN_STATE_INACTIVE 0x01

#define MODE_BTN 0
#define DIR_BTN 1
#define SPEED_UP_BTN 2
#define SPEED_DOWN_BTN 3

extern void BTN_Init(void);
extern void BTN_GetBtnState(unsigned char u8BtnId,unsigned char* pu8BtnStatePtr);



#endif /* BTN_H_ */