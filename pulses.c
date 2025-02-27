#include "pulses.h"
#include <math.h>

unsigned long zero_pulse(unsigned long frequency)
{
    // if the zero length is ~1us and frequency in Hz we need to divide frequency by 1e6
    return frequency / 1000000;
}

unsigned long one_pulse(unsigned long frequency)
{
    // since the one is double of the zero length we need to divide frequency by 5e5
    return frequency / 500000;
}

unsigned long too_long_pulse(unsigned long frequency)
{
    return frequency / 300000;
}

unsigned long too_short_pulse(unsigned long frequency)
{
    return frequency / 1500000;
}
