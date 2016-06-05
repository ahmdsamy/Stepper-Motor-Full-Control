/*
 * IncFile1.h
 *
 * Created: 2/21/2016 2:52:52 PM
 *  Author: samy
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define FULL_MODE_LED 0x01
#define HALF_MODE_LED 0x02
#define RIGHT_DIR_LED 0x04
#define LEFT_DIR_LED 0x08

#define right 0x01
#define left 0x02

#define mode_half 0x04
#define mode_full 0x08

#define NUM_OF_LEDS 4

extern void LED_Init(void);

extern void DIR_MODE_LEDS(unsigned char,unsigned char);

extern void MODE_LEDS(unsigned char);




#endif /* LEDS_H_ */