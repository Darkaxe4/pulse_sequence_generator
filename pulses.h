#ifndef PULSES__h
#define PULSES__h

/// @brief calculates length of pulse that encodes binary zero value (~1us)
/// @param frequency work frequency of circuit in MHz
/// @return Length of pulse in circuit clocks
unsigned short zero_pulse(unsigned short frequency);

/// @brief calculates length of pulse that encodes binary one value (~2us)
/// @param frequency work frequency of circuit in MHz
/// @return Length of pulse in circuit clocks
unsigned short one_pulse(unsigned short frequency);

/// @brief calculates length of pulse that is too long (>3us) to be processed by circuit
/// @param frequency work frequency of circuit in MHz
/// @return Length of pulse in circuit clocks
unsigned short too_long_pulse(unsigned short frequency);

/// @brief calculates length of pulse that is too short (<1us) to be processed by circuit
/// @param frequency work frequency of circuit in MHz
/// @return Length of pulse in circuit clocks
unsigned short too_short_pulse(unsigned short frequency);

#endif