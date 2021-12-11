#include <mega32.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

unsigned char buttons; 
char temp[32];
 

void stop(void){ 
    PORTD=0b000000;
    lcd_clear();
    lcd_puts("Stop");
    OCR1A=0;
    OCR1B=0; 
}  
void go_left(int speed_left, int speed_right){ 
    lcd_clear();               
    lcd_gotoxy(0,0);
    lcd_putsf("turning LEFT");
    lcd_gotoxy(0,1);
    lcd_putsf("left: ");
    itoa(speed_left,temp);
    lcd_puts(temp);
    lcd_gotoxy(0,2);
    lcd_putsf("rigth: ");
    itoa(speed_right,temp);
    lcd_puts(temp);
                
    PORTD=0b001001;
    OCR1A=speed_right;
    OCR1B=speed_left;
    delay_ms(10); 
}
void go_forward(int speed_forward){ 
    lcd_clear();              
    lcd_gotoxy(0,0);
    lcd_putsf("FORWARD");
    lcd_gotoxy(0,1);
    lcd_putsf("left & right: ");
    itoa(speed_forward,temp);
    lcd_gotoxy(0,2);
    lcd_puts(temp);
                
    PORTD=0b001010;
    OCR1A=speed_forward;
    OCR1B=speed_forward;
    delay_ms(100);
} 
void go_right(int speed_left, int speed_right){ 
    lcd_clear();           
    lcd_gotoxy(0,0);
    lcd_putsf("turning RIGHT");
    lcd_gotoxy(0,1);
    lcd_putsf("left: ");
    itoa(speed_left,temp);
    lcd_puts(temp);
    lcd_gotoxy(0,2);
    lcd_putsf("rigth: ");
    itoa(speed_right,temp);
    lcd_puts(temp); 
                
    PORTD=0b000110;
    OCR1A=speed_right;
    OCR1B=speed_left;
    delay_ms(10);
}

void main(void){

PORTA=0x00; 
DDRA=0x0F;  
PORTD=0x00; 
DDRD=0x0F;  

TCCR1A=0xA3;
TCCR1B=0x03;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1BH=0x00;
OCR1BL=0x00;
TIMSK=0x00;
TIFR=0X00;
   
lcd_init(20);
lcd_gotoxy(0,1);
 
while(1){ 
    buttons=0b00011111; 
    buttons=PINC&buttons;
     
    if(buttons==0b00000000) 
        stop(); 
     
    if(buttons==0b00000100) 
        go_forward(50); 
     
    if(buttons==0b00001110) 
        go_forward(50); 
        
    if(buttons==0b00010000) 
        go_left(20, 50);
        
    if(buttons==0b00011000) 
        go_left(20, 40);
        
    if(buttons==0b00001000) 
        go_left(20, 30);
        
    if(buttons==0b00001100) 
        go_left(20, 25);    
     
    if(buttons==0b00011100) 
        go_left(20, 30); 
     
    if(buttons==0b00000001) 
        go_right(50, 20); 
     
    if(buttons==0b00000011) 
        go_right(40, 20); 
     
    if(buttons==0b00000111) 
        go_right(30, 20); 
     
    if(buttons==0b00000110) 
        go_right(25, 20); 
     
    if(buttons==0b00000010) 
        go_right(30, 20); 
    }; 
} 