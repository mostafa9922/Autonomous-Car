#define F_CPU 16000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "timer_register.h"
#include "timer_interface.h"
#include "Servo_config.h"
#include "Ultra_sonic_intrface.h"
#include "Ultra_sonic_config.h"

void Servo_init()
{
	DIO_u8setPinDirection(Servo_port,Servo_pin,DIO_PIN_OUTPUT);
}
void Servo_ResetPositin(){

	SET_Timer1_OCR1B(3000);
	_delay_ms(500);
}
u8 Servo_Search_Left()
{
	u16 i,distance = 0,copy_LeftState = NOT_Left;
	
	for (i = 3000; i <= 5000; i++)
	{
		SET_Timer1_OCR1B(i);
		_delay_ms(1);  // Adjusted delay for smoother motion
		
		// Times Of Measure Distance!
		if (i == 3400 || i == 3800 || i == 4200 || i == 4600 || i == 5000)
		{
			distance = Ultra_Measure_Distance();
		}
		// Check Availability 
		if (Out_of_Range && i == 3400)
		{
			copy_LeftState = First_Left;
		}
		if (Out_of_Range && i == 3800)
		{
			copy_LeftState = Second_Left; 
		}
		if (Out_of_Range && i == 4200)
		{
			copy_LeftState = Third_Left; 
		}
		if (Out_of_Range && i == 4600)
		{
			copy_LeftState = Fourth_Left; 
		}
		if (Out_of_Range && i == 5000)
		{
			copy_LeftState = Sharp_Left;
		}
	}
	Servo_ResetPositin();
	return copy_LeftState;
}
u8 Servo_Search_right(){
	u16 i,distance = 0,copy_RightState = NOT_Right;
	for (i = 3000; i >= 1000; i--)
	{
		SET_Timer1_OCR1B(i); 
		_delay_ms(1);  // Adjusted delay for smoother motion
		
		// Times Of Measure Distance!
		if (i == 2600 || i == 2200 || i == 1800 || i == 1400 || i == 1000)
		{
			distance = Ultra_Measure_Distance();
		}
		// Check Availability 
		if (Out_of_Range && i == 2600)
		{
			copy_RightState = First_Right;
		}
		if (Out_of_Range && i == 2200)
		{
			copy_RightState = Second_Right;
		}
		if (Out_of_Range && i == 1800)
		{
			copy_RightState = Third_Right;
		}
		if (Out_of_Range && i == 1400)
		{
			copy_RightState = Fourth_Right;
		}
		if (Out_of_Range && i == 1000)
		{
			copy_RightState = Sharp_Right;
		}
	}
	Servo_ResetPositin();
	return copy_RightState;
}


