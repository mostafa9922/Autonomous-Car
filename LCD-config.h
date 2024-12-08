#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_
// LCD_8BIT_MODE
//LCD_4BIT_MODE

#define LCD_MODE LCD_4BIT_MODE

#define LCD_Data_Port DIO_PORTA
#define LCD_Ctrl_port DIO_PORTB
#define LCD_Ctrl_Pin_RS DIO_PIN_1
#define LCD_Ctrl_Pin_RW DIO_PIN_2
#define LCD_Ctrl_Pin_E DIO_PIN_3

#if LCD_MODE == LCD_4BIT_MODE
#define LCD_DATA_PIN0 DIO_PIN_4
#define LCD_DATA_PIN1 DIO_PIN_5
#define LCD_DATA_PIN2 DIO_PIN_6
#define LCD_DATA_PIN3 DIO_PIN_7

#endif 
#endif