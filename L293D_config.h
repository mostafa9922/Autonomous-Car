#ifndef _L293D_CONFIG_H_
#define _L293D_CONFIG_H_


#define R_EN     DIO_PIN_4 // control on speed for Right motors
#define L_EN     DIO_PIN_5 // control on speed for left motors

// Define motors pins
#define Left_Motors_Port   DIO_PORTC
#define Right_Motors_Port  DIO_PORTC 
  
#define Left_Motors_IN1    DIO_PIN_3
#define Left_Motors_IN2    DIO_PIN_4
			     
#define Right_Motors_IN1   DIO_PIN_5
#define Right_Motors_IN2   DIO_PIN_6
#endif
