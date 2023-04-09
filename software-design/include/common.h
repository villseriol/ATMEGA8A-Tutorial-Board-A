#pragma once

#ifndef __AVR_ATmega8A__
#define __AVR_ATmega8A__
#endif

#ifndef F_CPU
#warning "F_CPU not defined for <common.h>"
#define F_CPU 16000000UL
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
