#define __AVR_ATmega8A__ ;

#include <avr/builtins.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "common.h"

namespace context
{
    volatile uint8_t digits[] = {0xFF, 0xFF, 0xFF, 0xFF};
    volatile uint16_t frequency = 0;
    const uint8_t digits_size = sizeof(context::digits) / sizeof(*context::digits);
} // namespace context

void print(const uint16_t number)
{
    uint8_t buffer[] = {0xFF, 0xFF, 0xFF, 0xFF};
    const uint8_t buffer_size = sizeof(buffer) / sizeof(*buffer);
    common::uto7(number, buffer);

    for (uint8_t i = 0; i < buffer_size; i++)
    {
        context::digits[i] = buffer[i];
    }
}

int main(void)
{
    common::setup();

    __builtin_avr_cli();

    TIMSK |= _BV(TOIE0);
    TCCR0 = _BV(CS02);

    TCCR1B = _BV(ICES1) | _BV(ICNC1) | _BV(CS11);
    TIMSK |= _BV(TICIE1);

    __builtin_avr_sei();

    while (1)
    {
        print(context::frequency);
        _delay_ms(1000);
    }
}

ISR(TIMER1_CAPT_vect)
{
    context::frequency = (F_CPU / 8) / ICR1;
    TCNT1 = 0;
}

ISR(TIMER0_OVF_vect)
{
    static uint8_t digit_selection_number = 0;

    const uint8_t mask = _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
    const uint8_t digit_selection_mask = (PORTC | mask) & ~_BV(digit_selection_number);
    const uint8_t digit_selection_index = context::digits_size - digit_selection_number - 1;

    PORTD = context::digits[digit_selection_index];
    PORTC = digit_selection_mask;

    digit_selection_number = ++digit_selection_number % context::digits_size;
}