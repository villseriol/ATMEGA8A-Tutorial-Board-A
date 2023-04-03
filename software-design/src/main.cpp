#define __AVR_ATmega8A__ ;
#include <avr/builtins.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char const *argv[])
{
    __builtin_avr_cli();
    DDRB = 0xFF;
    __builtin_avr_sei();

    while (true)
    {
        PORTB ^= 0xFF;
        _delay_ms(1000);
    }
}