#define __AVR_ATmega8A__ ;

#include <avr/builtins.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "common.h"

int main(void)
{
    common::setup();

    __builtin_avr_cli();
    TCCR1A = _BV(COM1A0) | _BV(COM1B0);
    TCCR1B = _BV(CS12);
    TIMSK = _BV(OCIE1A) | _BV(OCIE1B);

    OCR1A = 0xFFFF;
    OCR1B = 0xFFFF;

    __builtin_avr_sei();

    while (1)
    {
        continue;
    }
}

ISR(TIMER1_COMPA_vect)
{
}

ISR(TIMER1_COMPB_vect)
{
}