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

int main(void)
{
    __builtin_avr_cli();

    DDRD = _BV(PD0) | _BV(PD1) | _BV(PD2) | _BV(PD3) | _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);
    DDRC = _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
    DDRB = _BV(PB1) | _BV(PB2);

    // 7-segment and led's initially off
    PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
    PORTD |= _BV(PD0) | _BV(PD1) | _BV(PD2) | _BV(PD3) | _BV(PD4) | _BV(PD5) | _BV(PD6) | _BV(PD7);
    PORTB &= ~(_BV(PB1) | _BV(PB2));

    __builtin_avr_sei();

    while (1)
    {
        PORTD ^= 0xFF;
        _delay_ms(1000);
    }
}