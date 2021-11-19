#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <string.h>
#define degree_sysmbol 0xdf
#include "LCD.h"

int min_temp=20;
int max_temp=25;

void timer0_init()
{
    TCCR0 |= (1 << CS02)|(1 << CS00);
    TCNT0 = 0;
}

int ADC_Configuration(char channel){
	ADMUX = 0x40 | (channel & 0x07);
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF); 
	_delay_ms(1);
	return ADCW;
}
void ADC_Init(){										
	DDRA = 0x00;
	ADCSRA = 0x87;
	ADMUX = 0x40;
}

int main(){
	char Temp[10];
	LCD_Init();
	ADC_Init();
    float c;
	timer0_init();
	while(1){
	   LCD_String_xy(1,0,"Temp: ");
	   c = (ADC_Configuration(0)*4.88);
	   c = (c/10.00);
	   sprintf(Temp,"%d%cC  ", (int)c, degree_sysmbol);
	   LCD_String_xy(2,0,Temp);
	   if (TCNT0 >= 100){
            memset(Temp,0,10);
            TCNT0 = 0;
        }
	   if(c>max_temp){
	   		PORTD=0b00000001;
	   }else if(c<min_temp){
			PORTD=0;
	   }
	}
}