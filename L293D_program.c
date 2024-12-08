#define F_CPU 16000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"

#include "DIO_interface.h"
#include "L293D_config.h"
#include "timer_interface.h"

void Motors_Init(){
	DIO_u8setPinDirection(DIO_PORTD,L_EN,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(DIO_PORTD,R_EN,DIO_PIN_OUTPUT);
	// Directions For Motor 1
	DIO_u8setPinDirection(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_OUTPUT);
	// Directions For Motor 2
	DIO_u8setPinDirection(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_OUTPUT);
}
void MoveToFroward(){
	// Control On Motor1
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_HIGH);
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_LOW);
	// Control On Motor2
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_HIGH);
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_LOW);

}
void Car_Speed(f32 LeftMotors_speed,f32 RightMotors_speed){
	SET_Timer1_OCR1A(LeftMotors_speed*39999);
	SET_Timer1_OCR1B(RightMotors_speed*39999);
}
void MoveToBack(){
	// Control On Motor1
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_HIGH);
	// Control On Motor2
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_HIGH);
}
void Turn_Left(){
	// Control On Motor1 (Move Forward)
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_HIGH);
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_LOW);
	// Control On Motor2 (Move Forward)
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_LOW);
}
void Turn_Right(){
	// Control On Motor1 (Stop)
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_LOW);
	// Control On Motor2 (Stop)
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_HIGH);
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_LOW);
}
void Stop(){
	// Control On Motor1
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Left_Motors_Port,Left_Motors_IN2,DIO_PIN_LOW);
	// Control On Motor2			 		 
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN1,DIO_PIN_LOW);
	DIO_u8setPinValue(Right_Motors_Port,Right_Motors_IN2,DIO_PIN_LOW);
}
