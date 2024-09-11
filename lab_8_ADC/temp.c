/********************
EE337: ADC IC MCP3008 interfacing with pt-51
(1) Complete spi_init() function from spi.h 

*********************/

#include <at89c5131.h>
#include "lcd.h"																				//Driver for interfacing lcd 
#include "mcp3008.h"																		//Driver for interfacing ADC ic MCP3008
#include "stdio.h"

char adc_ip_data_ascii[6]={'0','0','0','0','0','\0'};							//string array for saving ascii of input sample
char temperature[6]={'0','0','0','0','0','\0'};	
code unsigned char display_msg1[]="Volt.: ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]=" mV";								//Display msg on 2nd line of lcd
code unsigned char display_msg3[]="Temp.: ";
code unsigned char display_msg4[]=" oC";

void main(void)
{
	unsigned int adc_data_volt=0;
  float adc_data_temp=0;
	
	spi_init();																					
	adc_init();
  lcd_init();
	
	while(1)
	{
	 	unsigned int x,y;
		x = adc(4);																					//Read analog value from 4th channel of ADC Ic MCP3008
		adc_data_volt = (unsigned int) (x*3.2258); 							//Converting received 10 bits value to milli volt (3.3*1000*i/p /1023)

		lcd_cmd(0x80);													//Move cursor to first line
	  msdelay(3);
		lcd_write_string(display_msg1);
		int_to_string(adc_data_volt,adc_ip_data_ascii);
//		sprintf(adc_ip_data_ascii,"%d",adc_data_volt);
		lcd_write_string(adc_ip_data_ascii);
		lcd_write_string(display_msg2);
		msdelay(1000);
		
		y = adc(3);	
  	adc_data_temp = (y*0.32258);
	  lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
	  msdelay(4);
    lcd_write_string(display_msg3);
		sprintf(temperature,"%f",adc_data_temp);
//		int_to_string_temp(adc_data_temp,temperature);
		lcd_write_string(temperature);
		lcd_write_string(display_msg4);
		msdelay(4);
	}
}