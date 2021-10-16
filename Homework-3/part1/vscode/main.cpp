#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int i=0;
int sevenSegCothode[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

void set_timer1(void){
    // TCCR1B |= (1<<WGM12) | (1<<CS12);
    // TCCR1A |= (1<<COM1A0);
    // TCNT1=0;
    // OCR1A=31250;

    TCCR1B |= (1<<WGM12) | (1<<CS12);
    TCNT1=0;
    OCR1A=31250;
    TIMSK |= (1<<OCIE1A);
    sei();
}

int main() {
    DDRD =0xFF;
    set_timer1();
    while (1) {
        for(i=0;i<10;i++){
            PORTD = sevenSegCothode[i];
            _delay_ms(500);
        }
    }
    return 0;
}