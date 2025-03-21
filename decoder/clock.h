
#ifndef CLOCK__h
#define CLOCK__h

#include<stdbool.h>

struct Clock {
    unsigned int frequency_Mhz;
    unsigned int elapsed_time_ns;
    double change_probability;
    bool state;
};

/// @brief Updates state of clock. Turns it on after ti
/// @param clock CLock to update
/// @param elapsed_time time in ns elapsed from last update
void update_clock(struct Clock *clock, unsigned int elapsed_time);

/* calculate period using frequency*/
unsigned int period_in_ns(struct Clock *clock);

/* generate a random floating point number from min to max */
double randfrom(double min, double max);

#endif 