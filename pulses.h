#ifndef PULSES__h
#define PULSES__h

/// @brief calculates length of pulse that encodes binary zero value (~1us)
/// @return Length of pulse in circuit clocks
unsigned short zero_pulse();

/// @brief calculates length of pulse that encodes binary one value (~2us)
/// @return Length of pulse in circuit clocks
unsigned short one_pulse();

/// @brief calculates length of pulse that is too long (>3us) to be processed by circuit
/// @return Length of pulse in circuit clocks
unsigned short too_long_pulse();

/// @brief calculates length of pulse that is too short (<1us) to be processed by circuit
/// @return Length of pulse in circuit clocks
unsigned short too_short_pulse();

#endif