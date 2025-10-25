#include "flip_flop.h"

void FlipFlop::j_connect_to(const bool* j)
{
    input_j = j;
}

void FlipFlop::k_connect_to(const bool* k)
{
    input_k = k;
}

void FlipFlop::update() 
{
    output_q = (hold_j && output_q_bar) || (!hold_k && output_q);
    output_q_bar = !output_q;
}

void FlipFlop::update_hold()
{
    hold_j = *input_j;
    hold_k = *input_k;
}

bool* FlipFlop::ref_q()
{
    return &output_q;
}

bool* FlipFlop::ref_q_bar()
{
    return &output_q_bar;
}

bool FlipFlop::get_q()
{
    return output_q;
}
