#ifndef CIRCUIT__h
#define CIRCUIT__h

#include<stdbool.h>
#include<stdio.h>

struct Circuit{
    unsigned int* output_sequence;
    unsigned int current_pulse_index;
    unsigned int current_pulse_len;

    bool is_receiving_pulse;
};

/// @brief Updates the circuit state based on clock and pulse generator inputs
/// @param circuit Circuit to update
/// @param clock_state Current state of the clock signal (true/false)
/// @param pulse_gen_state Current state of the pulse generator (true/false)
void update_circuit(struct Circuit* circuit, bool clock_state, bool pulse_gen_state);

#endif 