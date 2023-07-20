/*
 * LCD_DRIVER.h
 *
 *  Created on: Jun 13, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 PORTD_ID
#define LCD_RS_PIN_ID                  PIN0_ID

#define LCD_E_PORT_ID                  PORTD_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void LCD_sendCommand(uint8 command);

void LCD_displayCharacter(uint8 character);

void LCD_init(void);

void LCD_displayString(const char *ptr);

void LCD_moveCursor(uint8 row,uint8 col);

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *ptr);

void LCD_intgerToString(int data);

void LCD_clearScreen(void);

#endif /* LCD_H_ */
