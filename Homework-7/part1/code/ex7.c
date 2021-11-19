#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <string.h>


char i;
int x = -1;
char states[4] = {0xFE, 0xFD, 0xFB, 0xF7};
char keypad[16] = {'7','8','9','/','4','5','6','*','1','2','3','-','','0','=','+'};
char pointerOfKeypad; 

void main(void){

DDRB=0b10000001;
DDRD=0b00001111;
PORTD=0b11110000;

lcd_init(16);
lcd_puts("Enter:");
lcd_gotoxy(0,1);

while (1){
         for(i=0; i<=3; i++){
            PORTD = states[i];
            if(PIND.4==0){
                delay_ms(50);
                x=0; 
            } 
            if(PIND.5==0){
                delay_ms(50);
                x=1; 
            }
            if(PIND.6==0){
                delay_ms(50);
                x=2;
            }
            if(PIND.7==0){ 
                delay_ms(50);
                x=3; 
            } 
            if(x != -1){  
                if(i==3 && x==0){ 
                  lcd_clear(); 
                }else{ 
                    pointerOfKeypad= keypad[(i*4)+x];
                    lcd_putchar(pointerOfKeypad);
                }
                x=-1;
            }
        }
      }
}
