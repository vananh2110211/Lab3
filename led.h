/*
 * input_processing.h
 *
 *  Created on: Nov 9, 2022
 *      Author: ASUS
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "main.h"
#include "led_7_seg.h"
#include "timer.h"
#include "global.h"

#define PORT_LIGHT				GPIOA

void LightOff(void);

void Blink_Red(void);
void Blink_Amber(void);
void Blink_Green(void);

void UpdateTime_Red(uint8_t duration);
void UpdateTime_Amber(uint8_t duration);
void UpdateTime_Green(uint8_t duration);

void Reset_Light(void);
void Traffic_Light_Run(void);
#endif /* INC_LED_H_ */
