#define __AVR_ATmega8A__ ;
#include <avr/builtins.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    __builtin_avr_cli();

    DDRD = _BV(PD0) | _BV(PD1) | _BV(PD2) | _BV(PD3) | _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);
    DDRC = _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);

    __builtin_avr_sei();

    while (1)
    {
        PORTD ^= 0xFF;
        _delay_ms(1000);
    }
}