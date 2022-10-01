/*
 * Lcd.c
 *
 *  Created on: Oct 7, 2021
 *      Author: Hussein
 */
#include "Lcd.h"
#include "gpio.h"
#include "Lcd_Config.h"
#include <util/delay.h>
#include <stdlib.h>

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}
void LCD_displayCharacter(uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	GPIO_writePort(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}

void LCD_init(){
	/* Configure the direction for RS, RW and E pins as output pins */
		GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);

		/* Configure the data port as output port */
		GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

		LCD_sendCommand(LCD_OPERATING_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */

		LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */

		LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_displayString(const char* str){
	uint8 i=0;
	while(str[i] !='\0'){
		LCD_displayCharacter(str[i]);
		i++;
	}
}

void LCD_moveCursor(uint8 row,uint8 col){
	uint8 memory_address;
	switch(row){
	case 0:
		memory_address=col;
		break;
	case 1:
		memory_address= 0x40+col;
		break;
	case 2:
		memory_address=0x10+col;
		break;
	case 3:
		memory_address=0x50+col;
		break;
	}
	LCD_sendCommand(memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_clearScreen(){
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_intgerToString(uint32 data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}
