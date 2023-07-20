/*
 * LCD_DRIVER.c
 *
 *  Created on: Jun 13, 2023
 *      Author: Ahmed Dwidar
 */
#include "LCD.h"
#include<avr\io.h>
#include<util/delay.h>
#include<stdlib.h>
#include "COMMON_MACROS.h"
#include "GPIO.h"

void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);
	_delay_us(1);

	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_us(1);

	GPIO_writePort(LCD_DATA_PORT_ID, command);
	_delay_us(1);

	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_us(1);
}
void LCD_displayCharacter(uint8 character)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);
	_delay_us(1);

	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH);
	_delay_us(1);

	GPIO_writePort(LCD_DATA_PORT_ID, character);
	_delay_us(1);

	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW);
	_delay_us(1);
}
void LCD_init(void)
{
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

	GPIO_setupPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

	_delay_ms(20);


	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);

}
void LCD_displayString(const char *ptr)
{
	uint8 i;
	for (i = 0; ptr[i] != '\0'; i++)
	{
		LCD_displayCharacter(ptr[i]);
	}
}
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_adress;

	switch(row)
	{
	case 0:
		lcd_memory_adress = col;
		break;
	case 1:
		lcd_memory_adress = col + 0x40;
		break;
	case 2:
		lcd_memory_adress = col + 0x10;
		break;
	case 3:
		lcd_memory_adress = col + 0x50;
		break;
	}
	LCD_sendCommand(lcd_memory_adress | LCD_SET_CURSOR_LOCATION);

}
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *ptr)
{
	LCD_moveCursor(row,col);
	LCD_displayString(ptr);
}
void LCD_intgerToString(int data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_displayString(buff);
}
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
