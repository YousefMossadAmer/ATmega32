

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_


#define FUNCTIONSET_EIGHT_BITS                    0x38 

#define CLCD_MODE 8

#define lcd_DisplayOn_CursorOff       0x0c          // display on, cursor off, don't blink character 
#define lcd_DisplayOn_CursorOn        0x0e          // display on, cursor on, don't blink character 
#define lcd_DisplayOff_CursorOff      0x08          // turn display off
#define lcd_Clear                     0x01          //replace all characters with ASCII 'space'  
#define lcd_EntryMode                 0x06          // shift cursor from left to right on read/write
#define lcd_Home                      0x02          // return cursor to first position on first line 
#define lcd_CGRAM                     0x40          // the first Place/Address at CGRAM
#define lcd_DDRAM					  0X80
#define lcd_SetCursor                 0x80          // set cursor position
#define lcd_FunctionReset             0x30          // reset the LCD



void CLCD_voidinit (void);
void CLCD_voidsenddata (uint8_t addressofdata);
void CLCD_voidsendcommand (uint8_t data);
void CLCD_voidsetposition (uint8_t raw ,uint8_t coulm);
void CLCD_voidsendextracharacter(uint8_t row ,uint8_t coulm,uint8_t *array);
void CLCD_voidclear(void);
void CLCD_voidsendstring (uint8_t *arr);








#endif