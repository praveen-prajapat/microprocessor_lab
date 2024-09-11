#include <at89c5131.h>
#include <math.h>
#include <lcd.h>

sbit speaker = P0^7;
code int freq[16] = {240,270,300,0,320,360,400,0,450,480,0,0,0,0,0,0};
code char lookup[4][4][16] = {
    {"Sa", "Re", "Ga", "A"},
    {"Ma", "Pa", "Dha", "B"},
    {"Ni", "Sa", "Silence", "C"},
    {"*", "0", "#", "D"}
};

void delay_20ms(void);
void sq_wave(int freq);

void sq_wave(int freq){
	int count_freq;
	TMOD = 0x10;
	count_freq = (int) (65534 - (1000000/(freq-1)));
	TH1 = count_freq/256;
	TL1 = count_freq%256;
	speaker = 0;
	TR1 = 1;
	while(TF1 != 1);
	speaker = 1;
	TF1 = 0;
	TR1 = 0;
	TH1 = count_freq/256;
	TL1 = count_freq%256;
	TR1 = 1;
	while(TF1 != 1);
	TF1 = 0;
	TR1 = 0;
	return;
}
void delay_20ms(void){
  msdelay(20);
}
void main(){
  unsigned int i=0,j=0,acc;
  while(1){
		P3 = 0x0F;
		while(1){
      lcd_init();			
			while(1){
			if (freq[4*i+j] != 0){
			  sq_wave(freq[4*i+j]);
			};
			lcd_cmd(0x80);													//Move cursor to first line
	    msdelay(4);
		  lcd_write_string(lookup[i][j]);
			acc = P3 & 0x0F;
			if(acc == 0x0F){
				break;
				
			}	
		}
		lcd_cmd(0x01);
		while(1){
			acc = P3 & 0x0F;
			if(acc != 0x0F){
				break;
			}
		}
		delay_20ms();
		acc = P3;
		acc = acc & 0x0F;
		if(acc != 0x0F){
			break;
		}
		}                                  		//row number		
		i = 4;
		while(1){
			i--;
			acc = 0x01;
			acc = acc*pow(2,i+4);
			acc = 0xff - acc;
			P3 = acc;
			acc = P3 & 0x0F;
			if(acc != 0x0F){
				break;
			}
		}
		switch(acc){                           //column number
			case 0x07: j = 0;
									break;
			case 0x0B: j = 1;
									break;
			case 0x0D: j = 2;
									break;
			case 0x0E: j = 3;
									break;
			default: break;
		}
}
}
