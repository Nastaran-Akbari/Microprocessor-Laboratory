#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

void timer0_init()
{
    TCCR0 |= (1 << CS02)|(1 << CS00);
    TCNT0 = 0;
}

int main() {

    DDRC = 0b00000100;
    DDRB = 0b00001111;
    timer0_init();
    while(1)
    {
        if(PINC&(1<<2)){
            if (TCNT0 >= 5){
                PORTB =0b00001100; 
                TCNT0 = 0;
            }if (TCNT0 >= 5){
                PORTB = 0b00000011;
                TCNT0 = 0; 
            }if (TCNT0 >= 5){
                PORTB = 0b00000110;
                TCNT0 = 0;
            }if (TCNT0 >= 5){
                PORTB = 0b00001001;
                TCNT0 = 0;
            }
        }   
        else if(!PINC){
            if (TCNT0 >= 5){
                PORTB =0b00001001; 
                TCNT0 = 0;
            }if (TCNT0 >= 5){
                PORTB = 0b00000110;
                TCNT0 = 0; 
            }if (TCNT0 >= 5){
                PORTB = 0b00000011;
                TCNT0 = 0;
            }if (TCNT0 >= 5){
                PORTB = 0b00001100;
                TCNT0 = 0;
            }
        }     
    }
    return 0;
}
