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
#include <avr/pgmspace.h>

#define S_CYCLES(s, scale) s *(F_CPU / scale)
#define MS_CYCLES(ms, scale) ms *((F_CPU / 1000) / scale)
#define US_CYCLES(us, scale) us *((F_CPU / 1000000) / scale)

#define HZ_CYCLES(hz, scale) F_CPU / (hz * scale)

namespace common
{
    const uint8_t SEVEN_SEGMENT_MAP[] PROGMEM = {
        0x88, // 0
        0xED, // 1
        0x83, // 2
        0xC1, // 3
        0xE4, // 4
        0xD0, // 5
        0x90, // 6
        0xE9, // 7
        0x80, // 8
        0xE0, // 9
        0xA0, // A
        0x94, // B
        0x9A, // C
        0x85, // D
        0x92, // E
        0xB2, // F
    };

    void uto7(const uint16_t value, uint8_t *buffer);
    void ito7(const uint16_t value, uint8_t *buffer);
    void hto7(const uint16_t value, uint8_t *buffer);

    void setup();
} // namespace common
