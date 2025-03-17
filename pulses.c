#include"pulses.h"
#include<math.h>
#include<stdlib.h>

unsigned short zero_pulse(unsigned short frequency)
{
    // if the zero length is ~1us and frequency in Hz we need to divide frequency by 1e6
    return frequency;
}

unsigned short one_pulse(unsigned short frequency)
{
    // since the one is double of the zero length we need to divide frequency by 5e5
    return frequency * 2;
}

unsigned short too_long_pulse(unsigned short frequency)
{
    return frequency * 5;
}

unsigned short too_short_pulse(unsigned short frequency)
{
    return 1 + rand() % 6;
}
