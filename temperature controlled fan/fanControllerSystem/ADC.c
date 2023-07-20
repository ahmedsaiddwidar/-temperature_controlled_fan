/*
 * ADC_DRIVER.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Dwidar
 */

#include "ADC.h"
#include<avr\io.h>
#include "COMMON_MACROS.h"
#include "GPIO.h"
#include "LCD.h"



void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = 0;
	ADCSRA = 0;


	ADMUX = (ADMUX & 0x3F) | (((Config_Ptr ->ref_volt) <<6));
	SET_BIT(ADCSRA,ADEN);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr ->prescaler);


	CLEAR_BIT(ADCSRA,ADIE);

}

uint16 ADC_readChannel(uint8 ch_num)
{

	ch_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX = ADMUX | ch_num;
	SET_BIT	(ADCSRA,ADSC);

	while(!(BIT_IS_SET(ADCSRA,ADIF))){};

	SET_BIT	(ADCSRA,ADIF);
		return ADC;

}
