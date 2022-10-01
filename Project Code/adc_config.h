/*
 * adc_config.h
 *
 *  Created on: Oct 6, 2021
 *      Author: Hussein
 */

#ifndef ADC_CONFIG_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_CONFIG_H_
#define ADC_MAXIMUM_VALUE    1023
#define ADC_AREF_VOLT_VALUE   2.56    /*volt of the battery connected to the AREF Pin*/
#include "std_types.h"


/*******************************************************************************
 *                         The members of the config struct                    *
 *******************************************************************************/

typedef enum{
	AREF,AVCC,Reserved,Internal
}Adc_Vref;

typedef enum{
	Disabled,Enabled
}Adc_AutoTrigger_Enable;

typedef enum{
	F_CPU_1 , F_CPU_2, F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}Adc_Freq;

typedef enum{
	Free_Running,Analog_Comparator,External_interrupt_0,Timer0_CMP,Timer0_OVF,Timer1_CMP,Timer1_OVF,Timer1_Capture
}Adc_Auto_Trigger_Source;

typedef enum{
	Left,Right
}Adc_Adjust_Result;

typedef struct{
	Adc_Vref Vref;
	Adc_AutoTrigger_Enable AutoTrigger;
	Adc_Freq clock;
	Adc_Auto_Trigger_Source Auto_Trigger_Source;
	Adc_Adjust_Result Adjust_Result;
} Adc_ConfigType;

#endif /* ADC_CONFIG_H_ */
