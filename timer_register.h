/***********************************************************************/
/***********************************************************************/
/********************  Author: Mostafa Abd El-Rasheed      *************************/
/********************  SWC: TIMER               *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE: 15/10/2024         *************************/
/***********************************************************************/
/***********************************************************************/
#ifndef _timer_REGISTER_H_
#define _timer_REGISTER_H_


#define OCR0  (*((volatile u8*)0x5C))
#define TIMSK (*((volatile u8*)0x59))
#define TIFR  (*((volatile u8*)0x58))
#define TCCR0 (*((volatile u8*)0x53))
#define TCNT0 (*((volatile u8*)0x52))

#define TCCR1A (*((volatile u8*)0x4F))
#define TCCR1B (*((volatile u8*)0x4E))
#define TCNT1 (*((volatile u16*)0x4C))
#define OCR1A (*((volatile u16*)0x4A))
#define OCR1B (*((volatile u16*)0x48))
#define ICR1  (*((volatile u16*)0x46))

#endif
