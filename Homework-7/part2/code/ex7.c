#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <string.h>


//PASSWORD: 1234

char i, digit, valid;
int x = -1;
char states[4] = {0xFE, 0xFD, 0xFB, 0xF7};
char keypad[16] = {'7','8','9','/','4','5','6','*','1','2','3','-','','0','=','+'}; 
char password[4] = {'1', '2', '3', '4'};
char keypadInput[4] = {'', '', '', ''};
char pointerOfKeypad;

void passwordValidation(void){
    valid = 1;
    for(i=0; i<=3; i++){
        if(password[i] != keypadInput[i]){
            valid=0;
        }
    }
    if(valid == 1){
        lcd_clear();
        lcd_puts("VALID! welcome");
        PORTB.0=1;
        delay_ms(1000);
        PORTB.0=0;
    }else{
        lcd_clear();
        lcd_puts("WRONG!!");
        PORTB.7=1;
        delay_ms(2000);
        PORTB.7=0;
    }
}


void ReadKeypad(void){
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
                  memset(keypadInput, 0, 4); 
                  digit=0;
                }else{ 
                    pointerOfKeypad= keypad[(i*4)+x];
                   lcd_putchar(pointerOfKeypad);
                   keypadInput[digit]=pointerOfKeypad;
                   digit++;
                   if(digit==4){
                    passwordValidation();
                   }
                }
                x=-1;
            }
        }
}

void main(void){

DDRB=0b10000001;
DDRD=0b00001111;
PORTD=0b11110000;

lcd_init(16);
lcd_puts("Enter Password:");
lcd_gotoxy(0,1);

while (1){
          ReadKeypad();
      }
}
