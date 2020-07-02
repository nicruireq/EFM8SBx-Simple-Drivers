/*
 * Timer23.h
 *
 *  Created on: 1 Jul 2020
 *      Author: Nicolas
 *
 *  Timer 2/3 functions for EFM8SB2
 *
 *  Previous configuration:
 *		Timer 2 interrupts enabled
 *		Global interrupts enabled
 *		Clock control with HFOSC 24.5MHz
 *		Timer 2 clock source SYSCLK / 12
 *		Timer 2 16bit auto reload mode
 *		Timer 2 target overflow frequency 1000Hz
 *		Timer 2 reload overflow period 1 ms
 *		Timer 2 THL:TLL <- 0xf806
 *
 *	Notes:
 *		This implementation don't avoid data races
 */

#ifndef EFM8SBX_TIMER23_H_
#define EFM8SBX_TIMER23_H_

//#define EFM8BB1

#ifdef EFM8SB1
#include <SI_EFM8SB1_Register_Enums.h>
#endif
#ifdef EFM8SB2
#include <SI_EFM8SB2_Register_Enums.h>
#endif
#ifdef EFM8BB1
#include <SI_EFM8BB1_Register_Enums.h>
#endif

void Timer2_Initialize();

/**
 * pre: Timer 2 is stopped
 */
void delay_ms(uint16_t milliseconds);

#endif /* EFM8SBX_TIMER23_H_ */
