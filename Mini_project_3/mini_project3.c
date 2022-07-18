/*****************************************************************************************
 *	File Name: mini_project3.c
 *
 *	Description: Temperature controller fan by using Atmega16 micro-controller
 *
 *	Author: Mahmoud Khaled
 *
 *	Date : 23/05/2022
 *****************************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dcmotor.h"
#include "pwm.h"

uint8 g_temp = 0;

int main(void)
{
	LCD_init();				/* initialize LCD driver */
	ADC_ConfigType ADC_Config = {InternalVoltage,F_CPU_8};
	ADC_init(&ADC_Config);				/* initialize ADC driver */
	DcMotor_Init();			/* initialize DC Motor driver */

	/* Display this string "ADC Value = " only once on LCD at the first row */
	LCD_displayStringRowColumn(0,3,"FAN is ");

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayStringRowColumn(1,3,"Temp =     C");
	while(1)
	{
		g_temp = LM35_getTemperature();
		LCD_moveCursor(0,10);
		if(g_temp<30)
		{
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP, MOTOR_STOP);
		}
		else if( (g_temp >= 30) && (g_temp < 60) )
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, QUARTER_SPEED);
		}
		else if( (g_temp >= 60) && (g_temp < 90) )
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, HALF_SPEED);
		}
		else if( (g_temp >= 90) && (g_temp < 120) )
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, THREE_QUARTER_SPEED);
		}
		else if( (g_temp >= 120) )
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, FULL_SPEED);
		}
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,10);
		if(g_temp >= 100)
		{
			LCD_intgerToString(g_temp);
		}
		else
		{
			LCD_intgerToString(g_temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}



}
