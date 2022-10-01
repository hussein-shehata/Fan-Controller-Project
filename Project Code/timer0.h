/*
 * timer0.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Hussein
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"
/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define MAX_NO_OF_TICKS 255
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Description :
 * Make PWM with Duty cycle to the passed Parameter
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* TIMER0_H_ */
