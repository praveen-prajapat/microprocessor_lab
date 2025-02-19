/********************
EE337: ADC IC MCP3008 interfacing with pt-51
(1) Complete spi_init() function from spi.h 

*********************/

#include <at89c5131.h>
#include "lcd.h"																				//Driver for interfacing lcd 
#include "mcp3008.h"																		//Driver for interfacing ADC ic MCP3008


char adc_ip_data_ascii[6]={0,0,0,0,0,'\0'};							//string array for saving ascii of input sample
code unsigned char display_msg1[]="Volt: ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]=" mV";								//Display msg on 2nd line of lcd



void main(void)
{
	int j=0;
	unsigned int adc_data=0;
	spi_init();																					
	adc_init();
  lcd_init();
	
	
	
	while(1)
	{
	 	unsigned int x;
		x = adc(4);	
		// 		unsigned int adc(unsigned char channel)
		// ********************
		// adc()

		// Function takes channel number as input and returns sampled
		// 10 bit ADC values. 10 bit is packed as 16 bit unsigned int.
		// MCP3008 have 8 channels, numbered from 0 to 7
		// *******************

 
																						//Read analog value from 0th channel of ADC Ic MCP3008
		adc_data = (unsigned int) (x*3.2258); 							//Converting received 10 bits value to milli volt (3.3*1000*i/p /1023)

		/*
		    Display "Volt: " on first line of lcd
		    Print analog sampled input on lcd using int_to_string function and 
		    Display "XXXXX mV" on second line of LCD
		
		*/	
		lcd_cmd(0x80);													//Move cursor to first line
		msdelay(1000);
		lcd_write_string(display_msg1);
		int_to_string(adc_data,adc_ip_data_ascii);
		lcd_cmd(0xC0);													//Move cursor to 2nd line of LCD
		msdelay(1000);
		lcd_write_string(adc_ip_data_ascii);
	}
}