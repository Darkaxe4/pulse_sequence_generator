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

USHORT *default_generator(unsigned int total_pulses)
{
    USHORT* result;
    result = calloc(total_pulses, sizeof(*result));
    unsigned short (*pulses[2])() = {&zero_pulse, &one_pulse};
    for (size_t i = 0u; i < total_pulses; i++)
    {
        result[i] = pulses[rand() % 2]();
    }
    result[total_pulses - 1] = too_long_pulse();
    return result;
}

USHORT *pae_generator(unsigned int total_pulses)
{
    USHORT* result = default_generator(total_pulses);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses - 1];
    return result;
}

USHORT *tsp_generator(unsigned int total_pulses)
{
    USHORT* result;
    result = calloc(total_pulses, sizeof(*result));
    unsigned short (*pulses[3])() = {&zero_pulse, &one_pulse, &too_short_pulse};

    for (size_t i = 0u; i < total_pulses; i++)
    {
        result[i] = pulses[rand() % 3]();
    }
    result[total_pulses - 1] = too_long_pulse();
    return result;
}

USHORT *all_generator(unsigned int total_pulses)
{
    USHORT* result= tsp_generator(total_pulses);
    result[10 + rand() % (total_pulses - 10)] = result[total_pulses - 1];
    return result;
}
