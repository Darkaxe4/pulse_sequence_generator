#include "circuit.h"

void update_circuit(struct Circuit *circuit, bool clock_state, bool pulse_gen_state)
{
    if (circuit->is_receiving_pulse)
    {
        if (clock_state)
        {
            if (pulse_gen_state)
            {
                circuit->output_sequence[circuit->current_pulse_index] = ++circuit->current_pulse_len;
            }
            else 
            {
                circuit->is_receiving_pulse = 0;
                circuit->output_sequence[circuit->current_pulse_index] = circuit->current_pulse_len;
                circuit->current_pulse_len = 0;
                circuit->current_pulse_index++;
            }
        }
    }
    else if (clock_state)
    {
        if (pulse_gen_state)
        {
            circuit->is_receiving_pulse = 1;
        }
    }
}