/*
 * adc.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Hussein
 */


#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

float32 ADCrefVoltValue; /*global externed variable to hold the value of Vref in Dynamic configuration*/

/* Description:
 * Initlize the ADC according to the config struct which is passed by address to the function
 */
void ADC_init(const Adc_ConfigType* Config_Ptr){
	ADMUX=(ADMUX & 0x3F) |((Config_Ptr->Vref)<<6); /*configuring the Vref*/
	ADMUX = (ADMUX & 0xDF) | ((Config_Ptr ->Adjust_Result)<<5); /*config Adjust Result Type*/
	ADCSRA=0;  /*Reseting ADCSRA Rigester */
	ADCSRA = (1<<ADEN) ; /*Enable ADC*/
	ADCSRA |=((Config_Ptr->AutoTrigger)<<5); /*ADC AUTO_Trigger_enable option */
	ADCSRA |= Config_Ptr->clock; /*configuring the clock of the ADC */
	SFIOR = (SFIOR & 0x1F) |((Config_Ptr->Auto_Trigger_Source)<<5); /*configuring the Auto Trigger Source*/
	/*putting th variable of the Vref in the externed variable to be used in the sensors equations*/
	switch(Config_Ptr->Vref){
	case AREF:
		ADCrefVoltValue=ADC_AREF_VOLT_VALUE; /* putting the value of the battery connected to the MCU*/
		break;
	case AVCC:
		ADCrefVoltValue=5; /*putting the value of AVCC =5V*/
		break;
	case Internal:
		ADCrefVoltValue=2.56; /* putting 2.56V which is the internal Vref*/
		break;
	}
}
/* Description :
 * return the Digital output after the conversion
 */
uint16 ADC_readChannel(uint8 channel_number){

ADMUX =( ADMUX & (0xE0) ) | (channel_number & 0x07); /*configuring the used channel */
ADCSRA |= (1<<ADSC); /* start the conversion*/
while( BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait till the conversion is complete */
ADCSRA |= (1<<ADIF); /* reseting the flag manually by Setting the Bit*/
return ADC;
}
/* Description :
 * Reseting all the registers of the ADC
 */
void ADC_Deinit(void){
	ADMUX=0;
	ADCSRA=0;
	SFIOR &= 0x1F; /* Reseting the bits responsible for ADC AUTO trigger source ONLY*/
}
