#ifndef _Ultra_sonic_CONFIG_H_
#define _Ultra_sonic_CONFIG_H_


#define TRIG_PIN DIO_PIN_3
#define ECHO_PIN DIO_PIN_2

#define TRIG_Port DIO_PORTD
#define ECHO_Port DIO_PORTD

#define Max_Distance 25

#define Out_of_Range !( distance <= Max_Distance)

#endif
