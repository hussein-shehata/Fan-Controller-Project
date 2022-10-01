/*
 * timer0.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Hussein
 */


#include "timer0.h"
#include "avr/io.h"
/* Description :
 * Make PWM with Duty cycle to the passed Parameter
 */

void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 = 0; // Set Timer Initial Value to 0
	/* the equation to  convert the percantage to the number which will be put into the register*/
	duty_cycle=(duty_cycle/100.0)* MAX_NO_OF_TICKS;


	OCR0  = duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

