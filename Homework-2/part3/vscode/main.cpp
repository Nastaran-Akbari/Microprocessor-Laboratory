#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB =0xFF;
    DDRA=0b00000001;
    while (1) {
        if(PINA & (1<<PA0) == 1){
            PORTB = 0b00000001;
            _delay_ms(500);
            PORTB = 0b00000010;
            _delay_ms(500);
            PORTB = 0b00000100;
            _delay_ms(500);
            PORTB = 0b00001000;
            _delay_ms(500);
            PORTB = 0b00010000;
            _delay_ms(500);
            PORTB = 0b00100000;
            _delay_ms(500);
            PORTB = 0b01000000;
            _delay_ms(500);
            PORTB = 0b10000000;
            _delay_ms(500);
        }
        else{
            PORTB=0;
            _delay_ms(500);
        }
    }
    return 0;
}