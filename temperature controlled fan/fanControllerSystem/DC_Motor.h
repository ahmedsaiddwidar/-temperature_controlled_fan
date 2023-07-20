/*
 * DC_Motor.h
 *
 *  Created on: Jun 27, 2023
 *      Author: Ahmed Dwidar
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"STD_TYPES.h"

#define ON 1
#define OFF 0

#define H_BRIDGE_ENABLE_PORT  PORTB_ID
#define H_BRIDGE_ENABLE_PIN   PIN3_ID

#define H_BRIDGE_INPUT1_PORT  PORTB_ID
#define H_BRIDGE_INPUT1_PIN   PIN0_ID

#define H_BRIDGE_INPUT2_PORT  PORTB_ID
#define H_BRIDGE_INPUT2_PIN   PIN1_ID

typedef enum
{
	DcMotor_stop,DcMotor_ACW,DcMotor_CW
}DcMotor_State;




void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
