#include"clock.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

void update_clock(struct Clock *clock, unsigned int elapsed_time)
{
    clock->elapsed_time_ns += elapsed_time;
    if (clock->state)
    {
        clock->state = 0;
        clock->elapsed_time_ns = 0;
    }
    if (clock->elapsed_time_ns >= period_in_ns(clock))
    {
        clock->state = 1;
        clock->frequency_Mhz = (randfrom(0., 1.) < clock->change_probability)?(7u + rand() % 7u):clock->frequency_Mhz;
    }
}

unsigned int period_in_ns(struct Clock *clock)
{
    return (unsigned int)(1./clock->frequency_Mhz * pow(10, 3));
}

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}