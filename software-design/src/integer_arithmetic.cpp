#define __AVR_ATmega8A__ ;
#include "common.h"
#include <avr/io.h>

void sum_blink_asm(unsigned a, unsigned b)
{
    unsigned c = a + b;
    // asm volatile("movw r16, %0"
    //              : "=r"(a));
}

void sum_blink_cpp(unsigned a, unsigned b)
{
    const unsigned c = a + b;
    const bool even = c % 2 == 0;

    if (even)
    {
        PORTB |= _BV(PB2);
    }
    else
    {
        PORTB |= _BV(PB1);
    }
}

int main(void)
{
    // const int a = 1;
    // const int b = 2;
    // const int c = a + b;
    common::setup();

    sum_blink_cpp(4, 5);

    while (1)
    {
        continue;
    }
}
