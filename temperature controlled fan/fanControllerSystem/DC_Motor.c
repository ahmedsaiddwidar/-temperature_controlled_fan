/*
 * DC_Motor.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Ahmed Dwidar
 */
#include"DC_Motor.h"
#include"COMMON_MACROS.h"
#include"GPIO.h"
#include"avr/io.h"
#include"PWM.h"




DcMotor_State state;

void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint16 duty_cycle;

	PORTB = PORTB | state;

	if(speed == 100)
	{
		duty_cycle = 256;
	}
	else if(speed == 75)
	{
		duty_cycle = 192;
	}
	else if(speed == 50)
	{
		duty_cycle = 128;
	}
	else if(speed == 25)
	{
		duty_cycle = 64;
	}
	else if(speed == 0)
	{
		duty_cycle = 0;
	}
	if(duty_cycle == 0)
	{
		PORTB = PORTB | DcMotor_stop;

	}
	PWM_Timer0_Init(duty_cycle);

}
