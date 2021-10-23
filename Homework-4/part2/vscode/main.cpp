#include <mega16.h>
#include <lcd.h>
#include <stdio.h>

#define xtal 8000000

#asm
    .equ__lcd_port=0x1b;PORTA
#endasm

unsigned char second, minute, hour;
unsigned char lcd_buff[10];

interrupt [TIM2_OVF] void timer2_ovf_isr(void){
    if(second==59){
        second=0;
        if(minute==59){
            minute=0;
            if(hour==24){
                hour=0;
            }else{
                hour++;
            }
        }else{
               minute++; 
            }
    }else{
        secound++; 
    }
    sprintf(lcd_buff,"Time=%d:%d:%d",hour,minute,second);
    lcd_clear();
    lcd_puts(lcd_buff);
}

void main(void){
    ASSR=0X08;
    TCCR2=0X05;
    TCNT2=0X00;
    OCR2=0X00;
    TIMSK=0X40;
    lcd_init(16);
    #asm("sei");
    while(1);
}