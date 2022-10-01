/*
 * adc.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Hussein
 */

#ifndef ADC_H_
#define ADC_H_
#include "adc_config.h"
#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

extern float32 ADCrefVoltValue;
/* Description:
 * Initlize the ADC according to the config struct which is passed by address to the function
 */
void ADC_init(const Adc_ConfigType* Config_Ptr);
/* Description :
 * return the Digital output after the conversion
 */
uint16 ADC_readChannel(uint8 Channel);
/* Description :
 * Reseting all the registers of the ADC
 */
void ADC_Deinit(void);

#endif /* ADC_H_ */
