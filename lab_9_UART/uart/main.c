#include <at89c5131.h>
#include "lcd.h"		// Header file with LCD interfacing functions
#include "serial.h"	// Header file with UART interfacing functions
#include <stdio.h>

void state_a(char acc_no, int balance_1,int balance_2)
{
	char bal_1[6];
	char bal_2[6];
	int_to_string(balance_1, bal_1+6);
	int_to_string(balance_2, bal_2+6);
	switch(acc_no)
			{
				case '1':
	        transmit_string("Account Holder: Steven\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_1);
				  transmit_string("\r\n");
					break;
				
				case '2':
	        transmit_string("Account Holder: Gordon\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_2);
				  transmit_string("\r\n");
					break;
							
				default:
					transmit_string("No such account, please enter valid details\r\n");
					break;
			}
}

void state_w(char acc_no, int *balance_1,int *balance_2)
{
	unsigned char amount_ones=0;
	unsigned char amount_tens=0;
	int amount=0;
	int five;
	int one;
	
	char bal_1[6];
	char bal_2[6];
  char hundred_5[3];
	char hundred_1[4];
	int_to_string(*balance_1, bal_1+6);
	int_to_string(*balance_2, bal_2+6);
	switch(acc_no)
			{
				case '1':
	        transmit_string("Account Holder: Steven\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_1);
				  transmit_string("\r\n");
				  transmit_string("Enter Amount, in hundreds : ");
				  amount_tens = receive_char();
				  amount_ones = receive_char();
				  transmit_string("\r\n");
				  if (amount_tens <'0' || amount_tens >'9'||amount_ones <'0' || amount_ones >'9')
					{ 
						transmit_string("Invalid Amount\r\n");
						break;
					}
					amount = (amount_tens-'0')*1000 +(amount_ones-'0')*100;
					if (amount > *balance_1)
					{
						transmit_string("Insufficient Funds\r\n");
						break;
					}
					five = amount/500;
					one = (amount%500)/100;
			
					sprintf(hundred_5,"%d",five);
					sprintf(hundred_1,"%d",one);
					
					*balance_1 = *balance_1- amount;
					bal_1[0]='0';
					int_to_string(*balance_1, bal_1+6);
					transmit_string("Remaining Balance: ");
					transmit_string(bal_1);
					transmit_string("\r\n");
					transmit_string("500 Notes: ");
					transmit_string(hundred_5);
					transmit_string(", 100 Notes: ");					
					transmit_string(hundred_1);
					transmit_string("\r\n");
					break;
				
				case '2':
	        transmit_string("Account Holder: Gordon\r\n");
				  transmit_string("Account Balance: ");
				  transmit_string(bal_2);
				  msdelay(2000);
				  transmit_string("\r\nEnter Amount, in hundreds : ");
				  amount = receive_char();
				  amount_tens = receive_char();
				  amount_ones = receive_char();
				  if (amount_tens <'0' || amount_tens >'9'||amount_ones <'0' || amount_ones >'9')
					{
						transmit_string("Invalid Amount\r\n");
						break;
					}
					amount = (amount_tens-'0')*1000 +(amount_ones-'0')*100;
					if (amount > *balance_2)
					{
						transmit_string("Insufficient Funds\r\n");
						break;
					}
					five = amount/500;
					one = (amount%500)/100;
					sprintf(hundred_5,"%d",five);
					sprintf(hundred_1,"%d",one);
					
					*balance_2 = *balance_2 - amount;
					bal_2[0] ='0';
	        int_to_string(*balance_2, bal_2+6);
					transmit_string("Remaining Balance: ");
					transmit_string(bal_2);
					transmit_string("500 Notes: ");
					transmit_string(hundred_5);
					transmit_string(", 100 Notes: ");					
					transmit_string(hundred_1);	
          transmit_string("\r\n");					
					break;
							
				default:
					transmit_string("No such account, please enter valid details\r\n");
					break;
			}
}

void main(void)
{
	unsigned char ch=0;
	unsigned char acc_no=0;
	int balance_1 = 10000;
	int balance_2 = 10000;
	
	lcd_init();
	uart_init();

	while(1)
	{
	    transmit_string("Press A for Account display and W for withdrawing cash\r\n");
			ch = receive_char();
			switch(ch)
			{
				case 'a':
	        transmit_string("Hello, Please enter Account Number\r\n");
	        acc_no = receive_char();
					state_a(acc_no,balance_1,balance_2);
					break;
				
				case 'w':
					transmit_string("Withdraw state, enter account number\r\n");
				  acc_no = receive_char();
					state_w(acc_no,&balance_1,&balance_2);
					break;
							
				default:
					transmit_string("Incorrect key pressed\r\n");
					break;
			}
			msdelay(100);
	}
}
