#ifndef _LCD_Interface_H_
#define _LCD_Interface_H_

void LCD_Void_Send_Commaned(u8 Copy_U8_Commaned);
void LCD_Void_Init(void);
void LCD_Void_Send_Data(u8 Copy_U8_Message);
void LCD_Void_Send_Data_String(u8 Copy_U8_Message[]);
void LCD_voidSpecificPosition(u8 copy_u8Row, u8 copy_u8colomn);
void LCD_Diriction(void);
void LCD_Clear();

#endif