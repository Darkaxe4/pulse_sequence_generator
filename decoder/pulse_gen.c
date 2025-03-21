#include"pulse_gen.h"
#include<stdlib.h>


void update_pulse_generator(struct Pulse_generator* pulse_generator, unsigned int elapsed_time)
{
    if (pulse_generator->is_sequence_ended)
        return;
    pulse_generator->elapsed_time_ns += elapsed_time;
    if (!pulse_generator->state)
    {
        if (pulse_generator->elapsed_time_ns >= 500)
        {
            pulse_generator->state = 1;
            pulse_generator->elapsed_time_ns = 0;
        }
    }
    else if (pulse_generator->elapsed_time_ns >= pulse_generator->sequence[pulse_generator->sequence_index])
    {
        pulse_generator->state = 0;
        pulse_generator->elapsed_time_ns = 0;
        pulse_generator->sequence_index++;
        if (pulse_generator->sequence_index >= pulse_generator->sequence_size)
            pulse_generator->is_sequence_ended = 1;
    }
};