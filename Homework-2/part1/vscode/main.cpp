#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRA =0xFF;
    PORTA = 0;
    while (1) {
        PORTA = 0xFF;
        _delay_ms(500);
        PORTA = 0;
        _delay_ms(500);
    }
    return 0;
}