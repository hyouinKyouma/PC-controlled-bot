/*
 * pc_controled_robot.c
 *
 * Created: 2/10/2018 8:13:24 PM
 *  Author: ADITYA
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <atmega/dcmotor.h>
#include <atmega/USART.h>

int main(void)
{	
	DDRD=0XFF;
	
	baudX2;
	RXON;
	TXON;
	initialize_UCSRC;
	baud_rate(4800);
	
	char a;
	while(1)
	{
		a=rx();
		if (a=='w'||a=='W')
		{
			forward();
		}
		else if (a=='a'||a=='A')
		{
			left();
			
		}
		else if (a=='d'||a=='D')
		{
			right();
			
		}
		else if(a=='s'||a=='S')
		{
			backward();
		}
		else  // if(a=='s'||a=='S')
		{
			stop();
		}
		
	}
}