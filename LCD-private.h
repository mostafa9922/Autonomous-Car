#ifndef _LCD_Private_H_
#define _LCD_Private_H_

#define  LCD_8BIT_MODE 0
#define  LCD_4BIT_MODE 1

static void SEND_ENABLE_PULSE(void);
static void SEND_4BIT(u8 ShifttedBits);
#endif