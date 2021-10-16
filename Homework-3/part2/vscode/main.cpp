#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void set_timer0(char value)
{
	TIMSK=(1<<TOIE0);
	TCNT0 = value;
	TCCR0 = (1<<CS02) | (1<<CS00);
}

void set_timer1(){ 

    TCCR1B |= (1<<WGM12) | (1<<CS12);
    TCNT1=0;
    OCR1A=31250;
    TIMSK |= (1<<OCIE1A);
    sei();

//    TIFR |= 0x01;
//    TCCR1B |= (1 << WGM12)|(1<<CS12)|(0<<CS11)|(0<<CS10);
//    OCR1A = 31249;
//    TCCR1A = 0x00;
//    TCNT1 = 0;
//    TIMSK |= (1<<OCIE1A);
//     sei();
}

ISR(val){
   TCCR1A= 0;
   PORTD &= ~(1<<5);
   TCCR1A=(1 << COM1A1) | (1 << COM1A0);
}

int main() {

    DDRC=0xFF;
    DDRD=0xFF;

    int sevenSegCothode[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
    int count_1=1, count_2=1, count_3=1, count_4 = 1;

    PORTC=0b11110111;
	set_timer0(0xC2);

    while(1){
        for(int h=0;h<10;h++){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        PORTC=0b11110111;
                        PORTD = sevenSegCothode[count_1];
                        count_1++;
                        _delay_ms(100);
                        }
                    PORTC=0b11111011;
                    PORTD = sevenSegCothode[count_2];
                    count_2++;
                    count_1=0;
                    _delay_ms(100);
                }   
                PORTC=0b11111101;
                PORTD = sevenSegCothode[count_3];
                count_3++;
                count_2=0;
                _delay_ms(100);         
            }
            PORTC=0b11111110;
            PORTD = sevenSegCothode[count_3];
            count_4++;
            count_3=0;
            _delay_ms(100);
        }

        // for(int i=0;i<10000;i++){

        //     PORTC=0b11110000;
        //     PORTD = sevenSegCothode[0];
        //     _delay_ms(50);

        //     PORTC=0b11111000;
        //     PORTD = sevenSegCothode[1];
        //     _delay_ms(50);

        //     PORTC=0b11110100;
        //     PORTD = sevenSegCothode[2];
        //     _delay_ms(50);

        //     PORTC=0b11111110;
        //     PORTD = sevenSegCothode[3];
        //     _delay_ms(50);
        // }

    }

}