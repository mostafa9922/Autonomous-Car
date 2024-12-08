#ifndef _Ultra_sonic_Private_H_
#define _Ultra_sonic_Private_H_

#define SPEED_OF_SOUND_CM_US 0.0343 // Speed of sound in cm/µs

static void Ultra_SendPulse();
static u16 Ultra_Measure_Pulse_Width();
#endif
