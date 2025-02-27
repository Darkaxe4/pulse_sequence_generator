#include<stdlib.h>
#include <string.h>

#include "pulses.h"
#include "test_profiles.h"

#define USHORT unsigned short

enum TestProfile parse_profile(const char* str_profile)
{
    if (strcmp(str_profile, "pulses_after_end") == 0)
        return PULSES_AFTER_END;
    if (strcmp(str_profile, "too_short_pulses") == 0)
        return TOO_SHORT_PULSES;
    if (strcmp(str_profile, "all") == 0)
        return ALL;
    return DEFAULT;
}

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

USHORT *default_generator(unsigned int total_pulses, double clock_change_probability)
{
    USHORT* result;
    unsigned short current_clock_rate_mHz = 7 + rand() % 7;
    result = calloc(total_pulses, sizeof(*result));
    unsigned short (*pulses[2])(unsigned short) = {&zero_pulse, &one_pulse};
    for (size_t i = 0u; i < total_pulses; i++)
    {
        result[i] = pulses[rand() % 2](current_clock_rate_mHz);
        current_clock_rate_mHz = (randfrom(0., 1.) > clock_change_probability)?(7u + rand() % 7u):current_clock_rate_mHz;
    }
    result[total_pulses - 1] = too_long_pulse(current_clock_rate_mHz);
    return result;
}

USHORT *pae_generator(unsigned int total_pulses, double clock_change_probability)
{
    USHORT* result = default_generator(total_pulses, clock_change_probability);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses - 1];
    return result;
}

USHORT *tsp_generator(unsigned int total_pulses, double clock_change_probability)
{
    USHORT* result;
    result = calloc(total_pulses, sizeof(*result));
    unsigned short (*pulses[3])(unsigned short) = {&zero_pulse, &one_pulse, &too_short_pulse};

    unsigned short current_clock_rate_mHz = 7 + rand() % 7;

    for (size_t i = 0u; i < total_pulses; i++)
    {
        result[i] = pulses[rand() % 3](current_clock_rate_mHz);
        current_clock_rate_mHz = (randfrom(0., 1.) > clock_change_probability)?(7u + rand() % 7u):current_clock_rate_mHz;
    }
    result[total_pulses - 1] = too_long_pulse(current_clock_rate_mHz);
    return result;
}

USHORT *all_generator(unsigned int total_pulses, double clock_change_probability)
{
    USHORT* result= tsp_generator(total_pulses, clock_change_probability);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses - 1];
    return result;
}
