/*
 * main.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Hussein
 */

#include "adc.h"
#include "dc_motor.h"
#include "gpio.h"
#include "lcd.h"
#include "std_types.h"
#include "timer0.h"
#include "common_macros.h"
#include "avr/io.h"
#include "lm35.h"
#include "util/delay.h"



int main(){
	/*struct to hold the configurations of the ADC*/
	Adc_ConfigType Adc_Config= {Internal,Disabled,F_CPU_8,Free_Running,Left};
	uint8 Temp;/*Variable to hold the Temperature Value*/
	LCD_init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");

	ADC_init(&Adc_Config);
	DcMotor_init();

	while(1){
		Temp=LM35_getTemperature(); /*now Temp hold the value of the Temperature*/
		LCD_moveCursor(0,10);
		if(Temp < 30){
			LCD_displayString("OFF");
			DcMotor_Rotate(Off,0);/* DC-motor stops rotating*/
		}
		else if ((Temp >= 30) && (Temp <= 60)){
			LCD_displayString("On ");
			DcMotor_Rotate(CW,25); /*DC-motor rotates in clockwise direction with speed = 25% of max speed*/
		}
		else if((Temp > 60) && (Temp <= 90)){
			LCD_displayString("On ");
			DcMotor_Rotate(CW,50);/* DC-motor rotates in clockwise direction with speed = 50% of max speed*/
		}
		else if((Temp >90) && (Temp <= 120)){
			LCD_displayString("On ");
			DcMotor_Rotate(CW,75);/* DC-motor rotates in clockwise direction with speed = 75% of max speed*/
		}
		else
		{
			LCD_displayString("On ");
			DcMotor_Rotate(CW,100);/*DC-motor rotates in clockwise direction with speed = 100% of max speed*/
		}

		LCD_moveCursor(1,3);
		LCD_displayString("Temp = ");
		LCD_intgerToString(Temp);
		LCD_displayString("C ");

	}
}
