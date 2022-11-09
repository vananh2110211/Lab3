/*
 * timer.h
 *
 *  Created on: Nov 9, 2022
 *      Author: ASUS
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

void Set1SecTime(int duration);

void SetBlinkingLightTime(int duration);

void Set7SegTime(int duration);


int Timer1SecFlag();

int Timer7SegFlag();

int TimerLightFlag();

#endif /* INC_TIMER_H_ */
