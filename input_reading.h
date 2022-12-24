/*
 * input_reading.h
 *
 *  Created on: Nov 9, 2022
 *      Author: ASUS
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 				       3

#define DURATION_FOR_AUTO_INCREASING	   100


void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
