/******************************************************************************
 *
 * Module: DCMOTOR
 *
 * File Name: dcmotor.h
 *
 * Description: Header file for DC Motor driver
 *
 * Author: Mahmoud Khaled
 *
*******************************************************************************/
#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT_ID				PORTB_ID
#define MOTOR_FIRST_PIN_ID			PIN0_ID
#define MOTOR_SECOND_PIN_ID			PIN1_ID

/* Motor Speed by setting the duty cycle */
#define MOTOR_STOP					0
#define QUARTER_SPEED				25
#define HALF_SPEED					50
#define THREE_QUARTER_SPEED			75
#define FULL_SPEED					100

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	STOP, CW, ACW
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description
 * The function is used for setup the direction of the two motors
 * Stop the motors at the beginning
 */
void DcMotor_Init(void);

/*
 * Description:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 *
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DCMOTOR_H_ */
