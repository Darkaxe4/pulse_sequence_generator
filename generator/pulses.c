#include"pulses.h"
#include<math.h>
#include<stdlib.h>


unsigned int zero_pulse()
{
    // if the zero length is ~1us and frequency in Hz we need to divide frequency by 1e6
    return ZERO;
}

unsigned int one_pulse()
{
    // since the one is double of the zero length we need to divide frequency by 5e5
    return ONE;
}

unsigned int too_long_pulse()
{
    return TOO_LONG;
}

unsigned int too_short_pulse()
{
    return TOO_SHORT;
}
