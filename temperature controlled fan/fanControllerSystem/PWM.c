/*
 * PWM.c
 *
 *  Created on: Jun 27, 2023
 *      Author: Ahmed Dwidar
 */
#include<avr/io.h>
#include"PWM.h"
#include"DC_Motor.h"
#include"GPIO.h"
#include"COMMON_MACROS.h"

void PWM_Timer0_Init(uint16 duty_cycle)
{



	TCNT0 = 0;

	OCR0  = duty_cycle;

	GPIO_setupPinDirection(H_BRIDGE_ENABLE_PORT,H_BRIDGE_ENABLE_PIN,PIN_OUTPUT);

	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);
	SET_BIT(TCCR0,CS01);

}
