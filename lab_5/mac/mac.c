#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="Input 1:        ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="Input 2:        ";					//Display msg on 1st line of lcd
code unsigned char display_msg3[]="Prediction:     ";
code unsigned char display_msg4[]="Class 1         ";
code unsigned char display_msg5[]="Class 2         ";

code float w0=-36;
code float w1=5;
code float w2=7;

void main()
{
	float x1,x2,y;
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	msdelay(4);
	lcd_write_string(display_msg1);
	msdelay(5000);
	P1=0x0F;
	x1 = P1;
	
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg2);
	msdelay(5000);
	P1=0x0F;
	x2 = P1;
	
	lcd_cmd(0x80);                         //cursor to first line
	msdelay(4);
	lcd_write_string(display_msg3);
	lcd_cmd(0xC0);
	msdelay(4);
	
	y=w0+(x1*w1)+(x2*w2);
		if (y<0 ){
	   lcd_write_string(display_msg4);
		}else{
	   lcd_write_string(display_msg5);
		}
	while(1);
		
}