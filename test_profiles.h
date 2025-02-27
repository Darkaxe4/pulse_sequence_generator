#ifndef TEST_PROFILES__h
#define TEST_PROFILES__h

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


unsigned int* default_generator(unsigned int total_pulses, unsigned long long frequency);
unsigned int* pae_generator(unsigned int total_pulses, unsigned long long frequency);
unsigned int* tsp_generator(unsigned int total_pulses, unsigned long long frequency);
unsigned int* all_generator(unsigned int total_pulses, unsigned long long frequency);

#endif