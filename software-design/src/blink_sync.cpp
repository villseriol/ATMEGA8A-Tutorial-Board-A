#define __AVR_ATmega8A__ ;

#include <avr/builtins.h>
#include <avr/io.h>
#include <util/delay.h>

#include "common.h"

int main(void)
{
    common::setup();

    while (1)
    {
        PORTB ^= (_BV(PB1) | _BV(PB2));
        _delay_ms(1000);
    }
}