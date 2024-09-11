#include <at89c5131.h>
#include "lcd.h"
#include "math.h"

code unsigned char display_msg1[]="Input 1:        ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="Input 2:        ";					//Display msg on 1st line of lcd
code unsigned char display_msg3[]="P(Class 1):";
code unsigned char display_msg4[]="P(Class 2):";

code float w0=-36;
code float w1=5;
code float w2=7;

void main()
{
	float x1,x2,y,z;
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
	
	y=w0+(x1*w1)+(x2*w2);
	z=1/(1+exp(-y));
	
	lcd_cmd(0x80);													//Move cursor to 1nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg3);
	lcd_float(1-z);
	
	lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	msdelay(4);
	lcd_write_string(display_msg4);
	lcd_float(z);
	msdelay(20000);
		
}