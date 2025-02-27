#include<stdlib.h>
#include <string.h>

#include "pulses.h"
#include "test_profiles.h"

enum TestProfile parse_profile(const char* str_profile)
{
    if (strcmp(str_profile, "pulses_after_end"))
        return PULSES_AFTER_END;
    if (strcmp(str_profile, "too_short_pulses"))
        return TOO_SHORT_PULSES;
    if (strcmp(str_profile, "all"))
        return ALL;
    return DEFAULT;
}

unsigned int *default_generator(unsigned int total_pulses, unsigned long long frequency)
{
    unsigned int* result;
    result = calloc(total_pulses, sizeof(*result));
    result[0] = zero_pulse(frequency);
    result[1] = one_pulse(frequency);
    for (unsigned int i = 2u; i < total_pulses; i++)
    {
        result[i] = result[rand() % 2];
    }
    result[total_pulses] = too_long_pulse(frequency);
    return result;
}

unsigned int *pae_generator(unsigned int total_pulses, unsigned long long frequency)
{
    unsigned int* result = default_generator(total_pulses, frequency);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses];
    result[total_pulses] = result[rand() % 2];
    return result;
}

unsigned int *tsp_generator(unsigned int total_pulses, unsigned long long frequency)
{
    unsigned int* result;
    result = calloc(total_pulses, sizeof(*result));
    result[0] = zero_pulse(frequency);
    result[1] = one_pulse(frequency);
    result[2] = too_short_pulse(frequency);
    for (unsigned int i = 3u; i < total_pulses; i++)
    {
        result[i] = result[rand() % 3];
    }
    result[total_pulses] = too_long_pulse(frequency);
    return result;
}

unsigned int *all_generator(unsigned int total_pulses, unsigned long long frequency)
{
    unsigned int* result= tsp_generator(total_pulses, frequency);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses];
    result[total_pulses] = result[rand() % 2];
    return result;
}
