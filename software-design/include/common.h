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
#pragma once

#ifndef __AVR_ATmega8A__
#define __AVR_ATmega8A__
#endif

#include <avr/builtins.h>
#include <avr/io.h>

#define S_CYCLES(s, scale) s *(F_CPU / scale)
#define MS_CYCLES(ms, scale) ms *((F_CPU / 1000) / scale)
#define US_CYCLES(us, scale) us *((F_CPU / 1000000) / scale)

#define HZ_CYCLES(hz, scale) F_CPU / (hz * scale)

namespace common
{
    void setup();
} // namespace common
