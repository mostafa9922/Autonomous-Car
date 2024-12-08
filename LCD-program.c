#define F_CPU 16000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD-config.h"
#include "LCD-intrface.h"
#include "LCD-private.h"

static void SEND_ENABLE_PULSE(void)
{
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_E,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_E,DIO_PIN_LOW);
}
static void SEND_4BIT(u8 ShifttedBits)
{
	DIO_u8setPinValue(LCD_Data_Port,LCD_DATA_PIN0,GET_BIT(ShifttedBits,DIO_PIN_0));
	DIO_u8setPinValue(LCD_Data_Port,LCD_DATA_PIN1,GET_BIT(ShifttedBits,DIO_PIN_1));
	DIO_u8setPinValue(LCD_Data_Port,LCD_DATA_PIN2,GET_BIT(ShifttedBits,DIO_PIN_2));
	DIO_u8setPinValue(LCD_Data_Port,LCD_DATA_PIN3,GET_BIT(ShifttedBits,DIO_PIN_3));
}
void LCD_Void_Send_Commaned(u8 Copy_U8_Commaned)
{
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RS,DIO_PIN_LOW);
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RW,DIO_PIN_LOW);
	#if LCD_MODE == LCD_8BIT_MODE
	DIO_u8setPortValue(LCD_Data_Port,Copy_U8_Commaned);
	SEND_ENABLE_PULSE();
	#elif LCD_MODE == LCD_4BIT_MODE
	SEND_4BIT(Copy_U8_Commaned>>4);
	SEND_ENABLE_PULSE();
	SEND_4BIT(Copy_U8_Commaned);
	SEND_ENABLE_PULSE();
	#endif
}
void LCD_Void_Init(void)
{
	//Display ON/OFF Control
	LCD_Void_Send_Commaned(0b00001111);
	#if LCD_MODE == LCD_8BIT_MODE
	_delay_ms(40);
	//Function Set 
	LCD_Void_Send_Commaned(0b00111100);

	#elif LCD_MODE == LCD_4BIT_MODE
	_delay_ms(40);
	//Function Set 
	SEND_4BIT(0b0010);
	SEND_ENABLE_PULSE();
	SEND_4BIT(0b0010);
	SEND_ENABLE_PULSE();
	SEND_4BIT(0b1100);
	SEND_ENABLE_PULSE();
	#endif
		
}
void LCD_Void_Send_Data(u8 Copy_U8_Message)
{
	#if LCD_MODE == LCD_8BIT_MODE
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RS,DIO_PIN_HIGH);
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RW,DIO_PIN_LOW);
	DIO_u8setPortValue(LCD_Data_Port,Copy_U8_Message);
	SEND_ENABLE_PULSE();
	#elif LCD_MODE == LCD_4BIT_MODE
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RS,DIO_PIN_HIGH);
	DIO_u8setPinValue(LCD_Ctrl_port,LCD_Ctrl_Pin_RW,DIO_PIN_LOW);
	SEND_4BIT(Copy_U8_Message>>4);
	SEND_ENABLE_PULSE();
	SEND_4BIT(Copy_U8_Message);
	SEND_ENABLE_PULSE();
	#endif
}
void LCD_Void_Send_Data_String(u8 Message[])
{
	u8 i;
	for(i=0;Message[i]!='\0';i++)
	{
		LCD_Void_Send_Data(Message[i]);
	}
}
void LCD_voidSpecificPosition(u8 copy_u8Row, u8 copy_u8colomn)
{
	u8 Local_u8DDRAM=0;
	Local_u8DDRAM = copy_u8colomn + (copy_u8Row*0x40);
	LCD_Void_Send_Commaned(Local_u8DDRAM+0X80);
}
void LCD_Diriction(void)
{
	DIO_u8setPinDirection(LCD_Ctrl_port,LCD_Ctrl_Pin_RW,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Ctrl_port,LCD_Ctrl_Pin_E,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Ctrl_port,LCD_Ctrl_Pin_RS,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Data_Port,LCD_DATA_PIN0,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Data_Port,LCD_DATA_PIN1,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Data_Port,LCD_DATA_PIN2,DIO_PIN_OUTPUT);
	DIO_u8setPinDirection(LCD_Data_Port,LCD_DATA_PIN3,DIO_PIN_OUTPUT);
}
void LCD_Clear(){
	//Display Clear
	LCD_Void_Send_Commaned(0b00000001);
}