/*
 * fsm_mode.h
 *
 *  Created on: Nov 24, 2022
 *      Author: ASUS
 */


#ifndef INC_FSM_MODE_H_
#define INC_FSM_MODE_H_

#include "main.h"
#include "input_reading.h"
#include "led_7_seg.h"
#include "led.h"
#include "global.h"

void init_fsm_mode(void);

uint8_t isLightNormal(void);
uint8_t isBlinkRed(void);
uint8_t isBlinkAmber(void);
uint8_t isBlinkGreen(void);



void fsm_mode(void);

#endif /* INC_FSM_MODE_H_ */
