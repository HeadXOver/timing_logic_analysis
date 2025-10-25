#include "clock.h"

#include "flip_flop.h"

Clock::Clock(std::vector<FlipFlop*> flip_flops): flip_flops(flip_flops)
{
}

void Clock::update()
{
	for (auto flip_flop : flip_flops) {
		flip_flop->update();
	}

	for (auto flip_flop : flip_flops) {
		flip_flop->update_hold();
	}
}