/*
 * Temp_Sensor.h
 *
 *  Created on: Jun 25, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);




#endif /* TEMP_SENSOR_H_ */
