#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "timer_register.h"
#include "timer_interface.h"
#include "Ultra_sonic_config.h"
#include "Ultra_sonic_intrface.h"
#include "Servo_private.h"
extern u16 overflow_count;

void Ultra_sonic_init()
{
	DIO_u8setPinDirection(TRIG_Port,TRIG_PIN,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(ECHO_Port,ECHO_PIN,DIO_PIN_INPUT);
}
static void Ultra_SendPulse()
{
	DIO_u8setPinValue(TRIG_Port,TRIG_PIN,DIO_PIN_LOW);
	_delay_us(2);
	DIO_u8setPinValue(TRIG_Port,TRIG_PIN,DIO_PIN_HIGH);
	_delay_us(10);
	DIO_u8setPinValue(TRIG_Port,TRIG_PIN,DIO_PIN_LOW);
}
static u16 Ultra_Measure_Pulse_Width()
{
	u16 pulse_width = 0;
	u8 ECHO_State = 0 ; // Low
	overflow_count = 0;
	// Wait for Echo pin to go HIGH
	while (!ECHO_State)
	{
		DIO_u8getPinValue(ECHO_Port,ECHO_PIN,&ECHO_State);
	}
	Timer0_Start();
	// Wait for Echo pin to go LOW
	while (ECHO_State)
	{
		DIO_u8getPinValue(ECHO_Port,ECHO_PIN,&ECHO_State);
	}
	Timer0_Stop();
	pulse_width = (overflow_count * 256) + TCNT0;
	return pulse_width * 4; // Pulse width in µs
}
u16 Ultra_Measure_Distance(){
	u16 distance = 0;
	Ultra_SendPulse();
	u16 pulse_width = Ultra_Measure_Pulse_Width();
	// Convert pulse width to distance in cm
	distance = (pulse_width * 0.0343) / 2;
	return distance;
}