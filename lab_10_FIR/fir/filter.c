#include <at89c5131.h>
#include <stdio.h>
#include "spi.h"
#include "serial.h"
#include "mcp3008.h"

code coeff[8]={0.02058851, 0.06541966, 0.16640878, 0.24758305, 0.24758305, 0.16640878,
               0.06541966, 0.02058851};
char adc_data[10][8] = {0,0,0,0,0,0,0,0};
int output;

void update_array(unsigned int y){
	int i;
	for(i=1;i<8;i++){
		adc_data[i-1]=adc_data[i];
	};
  adc_data[7]=y;
}
int output_cal(void){
	int i;
	for(i=0;i<8;i++){
		output =+ coeff[i]*adc_data[][i]*4.8876;
	};
	return output;
}
int main(void){
	unsigned int x,output;
	char trans_string[10];
	unsigned float rec_float;

	adc_init();
	spi_init();
	uart_init();

  while(1){
	  while(1){
		  x = adc(3);
		  if(rec_data==adc_data[7]){
		  update_array(x);
			break;
		  };
		};
		output = output_cal();
		sprintf(trans_string,"%d",output);
		transmit_string(trans_string);
	}
}