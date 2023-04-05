/**
 * 7-Segment Display
 *
 * Port D (Active Low)
 * D0 - F
 * D1 - C
 * D2 - A
 * D3 - G
 * D4 - B
 * D5 - D
 * D6 - E
 * D7 - DEC
 *
 * PORT C (Active Low)
 * C0:C3 (Least Significant Digit : Most Significant Digit)
 */

/**
 * LED (Active High)
 * B1 - D1
 * B2 - D2
 */

/**
 * Potentiometer (~50K)
 * C4
 */

#define __AVR_ATmega8A__ ;

#include <avr/builtins.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "common.h"

int main(void)
{
    common::setup();

    while (1)
    {
        PORTD ^= 0xFF;
        _delay_ms(1000);
    }
}