/***********************************************************************/
/***********************************************************************/
/********************  Author: Mostafa Abd El-Rasheed      *************************/
/********************  SWC: Timer               *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE: 15/10/2024         *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef _timer_CONFIG_H_
#define _timer_CONFIG_H_

/*
CTC
NORMAL
PMW
FAST_PWM

*/
#define timer0_wave_generation_mode CTC
#define timer1_wave_generation_mode FAST_PWM

/*
prscalar_0     
prscalar_1     
prscalar_8     
prscalar_64    
prscalar_256   
prscalar_1024  
*/
#define timer0_prescalar prescalar_64
#define timer1_prescalar prescalar_8

/*
normal
toggle
clear
set
*/
#define timer0_hardware_action normal
#define timer1_hardware_action clear

#endif