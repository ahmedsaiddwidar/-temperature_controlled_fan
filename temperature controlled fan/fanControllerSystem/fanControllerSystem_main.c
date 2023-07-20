/*
 * fanControllerSystem_main.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Ahmed Dwidar
 */
#include"COMMON_MACROS.h"
#include"DC_Motor.h"
#include"GPIO.h"
#include"LCD.h"
#include"Temp_Sensor.h"
#include"ADC.h"
#include"avr/io.h"



int main(void)
{
	uint8 temperature;
	uint8 motorSpeed;
	uint8 dcMotorState;

	ADC_ConfigType ADC_Configurations = {INTERNAL_VOLTAGE,PRESCALER_8};

	LCD_init();
	ADC_init(&ADC_Configurations);
	DcMotor_Init();

	LCD_moveCursor(0,3);
	LCD_displayString("Fan is  ");

	LCD_moveCursor(1,3);
	LCD_displayString("Temp = ");

	while(1)
	{

		 temperature = LM35_getTemperature();

		if(temperature < 30)
		{
			motorSpeed = 0;
			dcMotorState = DcMotor_stop;
		}
		else if((temperature >= 30) && (temperature < 60))
		{
			motorSpeed = 25;
			dcMotorState = DcMotor_ACW;
		}
		else if((temperature >= 60) && (temperature < 90))
		{
			motorSpeed = 50;
			dcMotorState = DcMotor_ACW;
		}
		else if((temperature >= 90) && (temperature < 120))
		{
			motorSpeed = 75;
			dcMotorState = DcMotor_ACW;
		}
		else if(temperature >= 120)
		{
			motorSpeed = 100;
			dcMotorState = DcMotor_ACW;
		}
		DcMotor_Rotate(dcMotorState,motorSpeed);


		if((dcMotorState == DcMotor_ACW) || (dcMotorState == DcMotor_CW))
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON    ");
		}
		else
		{
			LCD_moveCursor(0,11);
			LCD_displayString("OFF     ");
		}

		LCD_moveCursor(1,10);
		if(temperature >= 100)
		{
			LCD_intgerToString(temperature);
		}
		else
		{
			LCD_intgerToString(temperature);

			LCD_displayCharacter(' ');
		}
	}

}
