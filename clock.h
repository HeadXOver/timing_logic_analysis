#pragma once

#include <vector>

class FlipFlop;

/////////////////////////////////////////////////////////
//@brief 时钟类，包含所连接的所有触发器指针
//@param flip_flops 触发器指针数组
/////////////////////////////////////////////////////////

class Clock
{
public:
	Clock(std::vector<FlipFlop*> flip_flops);

	// @brief 更新所有触发器
	// @note 按顺序更新触发器，确保触发器之间的时序关系，先更新触发器的输出，再更新触发器的输入
	void update();

private:
	std::vector<FlipFlop*> flip_flops;
};

