/********************************************
*
*  Name: Davi Rodrigues Chaves
*  Section: W 3:30 PM - 5:00 PM
*  Assignment: Lab 0 - Blink the LED on Port B, bit 5
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>

void changeNumber(int number) {
    if (number == 0) {
        PORTD |= 0b00111111;
        PORTB |= 0b11110000;
    }
    if (number == 1) {
        PORTD |= 0b11111111;
        PORTB |= 0b11111001;
    }
    if (number == 2) {
        PORTD |= 0b01011111;
        PORTB |= 0b11110010;
    }
    if (number == 3) {
        PORTB |= 0b11110000;
        PORTD |= 0b11011111;
    }
    if (number == 4) {
        PORTB |= 0b11111001;
        PORTD |= 0b10011111;
    }
    if (number == 5) {
        PORTB |= 0b11110100;
        PORTD |= 0b10011111;
    }
    if (number == 6) {
        PORTB |= 0b11110100;
        PORTD |= 0b00011111;
    }
    if (number == 7) {
        PORTB |= 0b11110001;
        PORTD |= 0b11111111;
    }
    if (number == 8) {
        PORTB |= 0b11110000;
        PORTD |= 0b00011111;
    }
    if (number == 9) {
        PORTB |= 0b11110001;
        PORTD |= 0b10011111;
    }
}

int main(void) {
    // Your program goes here
	int i=0;
    DDRB |= ((1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3)); //made output
    DDRD |= ((1 << PD5) | (1 << PD6) | (1 << PD7));
	DDRC &= ((0 << PC4) & (0 << PC2)); //made an input
    PORTC |= 0b00010100;
	~(PORTD &= 0b00011111); //set to zero
    ~(PORTB &= 0b11110000);
    while(1) {
        if((PINC & 0b00000100) == 0){
            while(i<10) {
                ~(PORTD &= 0b00011111); //set to zero
                ~(PORTB &= 0b11110000);
                changeNumber(i);
                _delay_ms(200);
                i+=1;
                if(i > 9) {
                    i=0;
                }
                if((PINC & 0b00010000) == 0){
                    break;
                }
            }
        }
        if((PINC & 0b00010000) == 0){
            while(i > -1) {
                ~(PORTD &= 0b00011111); //set to zero
                ~(PORTB &= 0b11110000);
                changeNumber(i);
                _delay_ms(200);
                i-=1;
                if(i < 0) {
                    i=9;
                }
                if((PINC & 0b00000100) == 0){
                    break;
                }
            }
        }
    }

    return 0;   /* never reached */
}
