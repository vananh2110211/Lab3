/*
 * ouput_display.c
 *
 *  Created on: Nov 9, 2022
 *      Author: ASUS
 */
#include "led_7_seg.h"

static uint8_t led7SegBuffer[4]		= { 0, 0, 0, 0 };

void Enable7Seg(uint8_t index){
	if(index >= NO_OF_7SEG) return;

	switch(index){
	case 0:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en1_Pin | en2_Pin | en3_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en1_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en2_Pin | en3_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en2_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en1_Pin | en3_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_7SEG_PORT, en3_Pin, RESET);
		HAL_GPIO_WritePin(LED_7SEG_PORT, en0_Pin | en1_Pin | en2_Pin, SET);
		break;
	default:
		break;
	}
}

void Display7Seg(uint8_t num){
	if(num > 9) return;
	switch(num){
		case 0:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
			break;

		case 1:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, SET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
			break;

		case 2:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, SET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 3:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 4:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, SET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 5:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, SET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 6:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, SET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 7:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
			break;

		case 8:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;

		case 9:
			HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
			HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
			HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
			HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
			HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
			HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
			HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
			break;
		default:
			break;
	}
}

void UpdateLed7SegBuffer(uint8_t time1, uint8_t time2){
	if(time1 >= 0 && time1 <= 99){
		led7SegBuffer[0] = time1 / 10;
		led7SegBuffer[1] = time1 % 10;
	}

	if(time2 >= 0 && time2 <= 99){
		led7SegBuffer[2] = time2 / 10;
		led7SegBuffer[3] = time2 % 10;
	}
}

void Update7Seg(uint8_t index){
	if(index >= 0 && index <= 3){
		Enable7Seg(index);
		Display7Seg( led7SegBuffer[index] );
	}
}
