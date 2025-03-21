
#ifndef PULSE_GEN__h
#define PULSE_GEN__h

#include <stdbool.h>


struct Pulse_generator{
    int* sequence;
    unsigned int sequence_size;
    unsigned int sequence_index;

    unsigned int elapsed_time_ns;

    bool state;
    bool is_sequence_ended;
};

/// @brief Updates the pulse generator state based on elapsed time
/// @param pulse_generator Pulse generator to update
/// @param elapsed_time Time elapsed since last update in nanoseconds 
void update_pulse_generator(struct Pulse_generator* pulse_generator, unsigned int elapsed_time);

#endif