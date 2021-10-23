#include <mega32a.h>
#include <stdio.h>
#include <alcd.h>


int main() {

    lcd_init(16);
    lcd_puts("Hello World!");
    
    while(1){

    }
    return 0;
}