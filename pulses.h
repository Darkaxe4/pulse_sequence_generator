#ifndef PULSES__h
#define PULSES__h

/// @brief calculates length of pulse that encodes binary zero value (~1us)
/// @param frequency work frequency of circuit in Hz
/// @return Length of pulse in circuit clocks
unsigned long zero_pulse(unsigned long frequency);

/// @brief calculates length of pulse that encodes binary one value (~2us)
/// @param frequency work frequency of circuit in Hz
/// @return Length of pulse in circuit clocks
unsigned long one_pulse(unsigned long frequency);

/// @brief calculates length of pulse that is too long (>3us) to be processed by circuit
/// @param frequency work frequency of circuit in Hz
/// @return Length of pulse in circuit clocks
unsigned long too_long_pulse(unsigned long frequency);

/// @brief calculates length of pulse that is too short (<1us) to be processed by circuit
/// @param frequency work frequency of circuit in Hz
/// @return Length of pulse in circuit clocks
unsigned long too_short_pulse(unsigned long frequency);

#endif