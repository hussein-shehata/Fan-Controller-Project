/*
 * lm35.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Hussein
 */

#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"
/*******************************************************************************
 *                               Definitions                                   *
 *******************************************************************************/
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Description :
 * this function responsible for getting the Temperature and return it
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_H_ */
