#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB =0xFF;
    DDRA =0b00000001;
    while (1) {
        if(PINA & (1<<PA0) == 1){
            PORTB = 0xFF;
            _delay_ms(500);
            PORTB = 0;
            _delay_ms(500);
        }
    }
    return 0;
}