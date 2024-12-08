#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EER_STATE.h"
#include "timer_register.h"
#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"
#include "GIE_interface.h"

volatile u16 overflow_count = 0;

void timer0_init(void)
{
	#if timer0_wave_generation_mode == CTC
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#elif timer0_wave_generation_mode == NORMAL
 	CLR_BIT(TCCR0,3);
 	CLR_BIT(TCCR0,6);
	#elif timer0_wave_generation_mode == PWM
	 CLR_BIT(TCCR0,3);
	 SET_BIT(TCCR0,6);
	 CLR_BIT(TCCR0,7);
	#elif timer0_wave_generation_mode == FAST_PWM
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,7);
	#endif
	
 	#if timer0_hardware_action == normal 
 	CLR_BIT(TCCR0,4);
 	CLR_BIT(TCCR0,5);
 	#elif timer0_hardware_action == toggle
 	SET_BIT(TCCR0,4);
 	CLR_BIT(TCCR0,5);
 	#elif timer0_hardware_action == clear //(non-inverting mode) for PWM or Fast
 	CLR_BIT(TCCR0,4);
 	SET_BIT(TCCR0,5);
 	#elif timer0_hardware_action == set // (inverting mode) for PWM or Fast
 	SET_BIT(TCCR0,4);
 	SET_BIT(TCCR0,5);
 	#endif
	// Enable Interrupt
	SET_BIT(TIMSK,1);
	// Enable Global Interrupts
	GIE_Enable();
	OCR0 = 255;
}
void Timer0_Start() {
	TCNT0 = 0; // Reset Timer Counter
	overflow_count = 0; // Reset overflow count
	
	// PreScaler  (Start Timer)
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
    TCCR0 |= timer0_prescalar;
}
void Timer0_Stop() {
	TCCR0 = 0x00; // Stop the timer by clearing the PreScaler
}
void SET_Timer0_compareValue(u8 value)
{
		OCR0 = value;
}
void __vector_10(void) __attribute__((signal)); // Declare the interrupt function with the signal attribute
void __vector_10(void)
{
	overflow_count++;
}
void timer1_init(void)
{
	
	#if timer1_wave_generation_mode == CTC
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif timer1_wave_generation_mode == NORMAL
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	#elif timer1_wave_generation_mode == PWM
	SET_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	// Force Output Compare
	CLR_BIT(TCCR1A,2);
	CLR_BIT(TCCR1A,3);
	#elif timer1_wave_generation_mode == FAST_PWM
	CLR_BIT(TCCR1A,0);
	SET_BIT (TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	// Force Output Compare
	CLR_BIT(TCCR1A,2);
	CLR_BIT(TCCR1A,3);
	#endif
	
	#if timer1_hardware_action == normal
	// for PIN_A
	CLR_BIT(TCCR1A,6);
	CLR_BIT(TCCR1A,7);
	// for PIN_B
	CLR_BIT(TCCR1A,4);
	CLR_BIT(TCCR1A,5);
	#elif timer1_hardware_action == toggle
	// for PIN_A
	SET_BIT(TCCR1A,6);
	CLR_BIT(TCCR1A,7);
	// for PIN_B
	SET_BIT(TCCR1A,4);
	CLR_BIT(TCCR1A,5);
	#elif timer1_hardware_action == clear //(non-inverting mode) for PWM or Fast PWM
	// for PIN_A
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	// for PIN_B
	CLR_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
	#elif timer1_hardware_action == set // (inverting mode) for PWM or Fast PWM
	// for PIN_A
	SET_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	// for PIN_B
	SET_BIT(TCCR1A,4);
	SET_BIT(TCCR1A,5);
	#endif
	
	//  Input Capture Noise Canceler
	SET_BIT(TCCR1B,7);
	
	// prescalar
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	TCCR1B |= timer1_prescalar;
	// Input Capture Register (Top Value)
	ICR1 = 39999  ;

}
void SET_Timer1_OCR1B(u16 value)
{
	OCR1B = value;
}
void SET_Timer1_OCR1A(u16 value)
{
	OCR1A = value;
}

