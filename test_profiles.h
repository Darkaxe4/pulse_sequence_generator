#ifndef TEST_PROFILES__h
#define TEST_PROFILES__h

#ifndef USHORT
#define USHORT unsigned short
#endif

enum TestProfile
{
    DEFAULT=0,
    PULSES_AFTER_END=1,
    TOO_SHORT_PULSES=2,
    ALL=3
};

/// @brief parses profile name into TestProfile value
/// @param str_profile string containing profile name
/// @return 
enum TestProfile parse_profile(const char* str_profile);


USHORT* default_generator(unsigned int total_pulses, double clock_change_probability);
USHORT* pae_generator(unsigned int total_pulses, double clock_change_probability);
USHORT* tsp_generator(unsigned int total_pulses, double clock_change_probability);
USHORT* all_generator(unsigned int total_pulses, double clock_change_probability);

/* generate a random floating point number from min to max */
double randfrom(double min, double max);

#endif