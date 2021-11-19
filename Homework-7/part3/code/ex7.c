#include <mega32a.h>
#include <delay.h>

//num of steps: 5
int steps = 5;
int i=0;

void turnMotor(void){
    PORTD=5;
    delay_ms(50);
    PORTD=6;
    delay_ms(50);
    PORTD=0x0a;
    delay_ms(50);
    PORTD=0x09;
    delay_ms(50);
}

void main(void){
    DDRA=0X00;
    PORTA=0XFF;
    DDRD=0XFF;
    while (1){ 
        if((!(PINA&0X01)) && i<=steps){   
            delay_ms(30); 
            turnMotor();
            i++;
        }       
      } 
}