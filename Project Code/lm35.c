/*
 * lm35.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Hussein
 */


#include "lm35.h"
#include "adc.h"

/* Description :
 * this function responsible for getting the Temperature and return it
 */

uint8 LM35_getTemperature(void){
	uint8 Temp_value;/*variable to hold the Temperature value*/
	uint16 digital_out=ADC_readChannel(SENSOR_CHANNEL_ID);
	/*equation to calculate the Temperature value from the digital output from the ADC*/
	Temp_value = (uint8)(((uint32)digital_out*SENSOR_MAX_TEMPERATURE* ADCrefVoltValue )/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return Temp_value;
}
