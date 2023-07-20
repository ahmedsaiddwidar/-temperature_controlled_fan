/*
 * ADC_DRIVER.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef ADC_H_
#define ADC_H_


#include "STD_TYPES.h"

typedef enum
{
	AREF_VOLTAGE,AVCC_VOLTAGE,RESERVED,INTERNAL_VOLTAGE
}ADC_ReferenceVolatge;


typedef enum
{
	PRESCALER_2,PRESCALER_2_again,PRESCALER_4,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128,
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;



#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

void ADC_init(const ADC_ConfigType * Config_Ptr);


uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
