#define F_CPU 16000000
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD-intrface.h"
#include "timer_interface.h"
#include "L293D_intrface.h"
#include "Servo_intrface.h"
#include "Servo_config.h"
#include "Ultra_sonic_intrface.h"
#include "Ultra_sonic_config.h"

int main(void)
{
	// Messages! 
	u8 message1[] = "Move To Front";
	u8 message2[] = "Search To Right";
	u8 message3[] = "Search To Left";
	u8 message4[] = "Move To Right1";
	u8 message5[] = "Move To Right2";
	u8 message6[] = "Move To Right3";
	u8 message7[] = "Move To Right4";
	u8 message8[] = "Move To Right5";
	u8 message9[] = "Move To Left1";
	u8 message10[] = "Move To Left2";
	u8 message11[] = "Move To Left3";
	u8 message12[] = "Move To Left4";
	u8 message13[] = "Move To Left5";
	LCD_Diriction();
	LCD_Void_Init();
	timer0_init(); // To Generate Signal For Ultra_Sonic Sensor
	timer1_init(); // To Generate PWM Signal For Car motors(50Hz) and Servo Motor
	Motors_Init(); 
	Ultra_sonic_init();
	Servo_init();
	u8 Right_Stata,Left_State;
	u16 distance; 
    while (1) 
    {
		LCD_Clear();
		LCD_Void_Send_Data_String(message1);
		Servo_ResetPositin();
		MoveToFroward();
		Car_Speed(1,1);
		distance = Ultra_Measure_Distance();
		while(Out_of_Range) 
		{
			distance = Ultra_Measure_Distance();
		}
		Stop();
		MoveToBack();
		Car_Speed(1,1);
		_delay_ms(1000);
		Stop();
		LCD_Clear();
		LCD_Void_Send_Data_String(message2);
		Right_Stata = Servo_Search_right();
		switch (Right_Stata)
		{
			default: // NOT_Right
				Stop();
				break;
				
			case First_Right:
				LCD_Clear();
				LCD_Void_Send_Data_String(message4);
				Turn_Right();
				Car_Speed(1,1);
				_delay_ms(100);
				break;
			
			case Second_Right:
				LCD_Clear();
				LCD_Void_Send_Data_String(message5);
				Turn_Right();
				Car_Speed(1,1);
				_delay_ms(200);
				break;
			
			case Third_Right:
				LCD_Clear();
				LCD_Void_Send_Data_String(message6);
				Turn_Right();
				Car_Speed(1,1);
				_delay_ms(300);
				break;
				
			case Fourth_Right:
				LCD_Clear();
				LCD_Void_Send_Data_String(message7);
				Turn_Right();
				Car_Speed(1,1);
				_delay_ms(400);
				break;
			
			case Sharp_Right:
				LCD_Clear();
				LCD_Void_Send_Data_String(message8);
				Turn_Right();
				Car_Speed(1,1);
				_delay_ms(600);
				break;
		}
		if (Right_Stata == NOT_Right)
		{
			LCD_Clear();
			LCD_Void_Send_Data_String(message3);
			Left_State = Servo_Search_Left();
			switch (Left_State)
			{
				default:
					Stop();
					break;
				
				case First_Left:
					LCD_Clear();
					LCD_Void_Send_Data_String(message9);
					Turn_Left();
					Car_Speed(1,1);
					_delay_ms(100);
					break;
				
				case Second_Left:
					LCD_Clear();
					LCD_Void_Send_Data_String(message10);
					Turn_Left();
					Car_Speed(1,1);
					_delay_ms(200);
					break;
				
				case Third_Left:
					LCD_Clear();
					LCD_Void_Send_Data_String(message11);
					Turn_Left();
					Car_Speed(1,1);
					_delay_ms(300);
					break;
				
				case Fourth_Left:
					LCD_Clear();
					LCD_Void_Send_Data_String(message12);
					Turn_Left();
					Car_Speed(1,1);
					_delay_ms(400);
					break;
				
				case Sharp_Left:
					LCD_Clear();
					LCD_Void_Send_Data_String(message13);
					Turn_Left();
					Car_Speed(1,1);
					_delay_ms(600);
					break;
			}
		}
    }
}

