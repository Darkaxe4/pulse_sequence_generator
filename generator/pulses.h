#ifndef PULSES__h
#define PULSES__h

#define ZERO 1000
#define ONE 2000
#define TOO_LONG 3500
#define TOO_SHORT 500


/// @brief calculates length of pulse that encodes binary zero value (~1us)
/// @return Length of pulse in nanoseconds
unsigned int zero_pulse();

/// @brief calculates length of pulse that encodes binary one value (~2us)
/// @return Length of pulse in nanoseconds
unsigned int one_pulse();

/// @brief calculates length of pulse that is too long (>3us) to be processed by circuit
/// @return Length of pulse in nanoseconds
unsigned int too_long_pulse();

/// @brief calculates length of pulse that is too short (<1us) to be processed by circuit
/// @return Length of pulse in nanoseconds
unsigned int too_short_pulse();

#endif