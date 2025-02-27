#include "pulses.h"
#include <math.h>
#include<stdlib.h>

unsigned short zero_pulse()
{
    return 7u + rand() % 7u;
}

unsigned short one_pulse()
{
    // since the one is double of the zero length we need to divide frequency by 5e5
    return 14u + rand() % 7u;
}

unsigned short too_long_pulse()
{
    return 50u;
}

unsigned short too_short_pulse()
{
    return rand() % 7u;
}
