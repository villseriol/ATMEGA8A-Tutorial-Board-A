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
    volatile uint8_t current = 0;
} // namespace context

const unsigned char SEGMENT_NUMBER[] PROGMEM = {
    (unsigned char)~0b01110111, // 0
    (unsigned char)~0b00010010, // 1
    (unsigned char)~0b01111100, // 2
    (unsigned char)~0b00111110, // 3
    (unsigned char)~0b00011011, // 4
    (unsigned char)~0b00101111, // 5
    (unsigned char)~0b01101111, // 6
    (unsigned char)~0b00010110, // 7
    (unsigned char)~0b01111111, // 8
    (unsigned char)~0b00011111, // 9
    (unsigned char)~0b01011111, // A
    (unsigned char)~0b01101011, // B
    (unsigned char)~0b01100101, // C
    (unsigned char)~0b01111010, // D
    (unsigned char)~0b01101101, // E
    (unsigned char)~0b01001101, // F
};

void itom(const uint16_t value, uint8_t *buffer)
{
    uint16_t quotient = value;
    uint16_t remainder = 0;

    do
    {
        remainder = quotient % 10;
        *buffer++ = pgm_read_byte(&SEGMENT_NUMBER[remainder]);
        quotient /= 10;
    } while (quotient > 0);
}

void print(const uint16_t number)
{
    uint8_t buffer[] = {0xFF, 0xFF, 0xFF, 0xFF};
    const uint8_t buffer_size = sizeof(buffer) / sizeof(*buffer);
    itom(number, buffer);

    for (uint8_t i = 0; i < buffer_size; i++)
    {
        context::digits[i] = buffer[i];
    }

    context::current = 0;

    // PORTD = digit;
    // PORTC &= ~(_BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3));
}

void clear()
{
    uint8_t buffer[] = {0xFF, 0xFF, 0xFF, 0xFF};
    const uint8_t buffer_size = sizeof(buffer) / sizeof(*buffer);

    for (uint8_t i = 0; i < buffer_size; i++)
    {
        context::digits[i] = buffer[i];
    }
}

int main(void)
{
    common::setup();

    __builtin_avr_cli();
    // setup 256 bit timer as display

    __builtin_avr_sei();

    unsigned counter = 0;

    while (1)
    {
        print(counter++);
        counter %= 10;
        _delay_ms(1000);
    }
}