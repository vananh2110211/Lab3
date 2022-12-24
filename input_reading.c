/*
 * input_reading.c
 *
 *  Created on: Nov 9, 2022
 *      Author: ASUS
 */
#include "input_reading.h"

#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET


uint16_t buttonPin[3] = {SEL_BUTTON_Pin, MODI_BUTTON_Pin, SET_BUTTON_Pin};
GPIO_TypeDef* buttonPort[3] = {SEL_BUTTON_GPIO_Port, MODI_BUTTON_GPIO_Port, SET_BUTTON_GPIO_Port};


static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

void button_reading(void){
	for(uint8_t i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){

				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				} else {
					flagForButtonPress1s[i] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
	}
}
unsigned char is_button_pressed(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0;

	if(buttonBuffer[index] == BUTTON_IS_PRESSED){
		return (counterForButtonPress1s[index] == 1);
	}
	return 0;
}
unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xFF;

	return flagForButtonPress1s[index] == 1;
}


