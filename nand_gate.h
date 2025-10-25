#pragma once

#include <vector>

///////////////////////////////////
// @brief NAND gate
///////////////////////////////////

class NandGate
{
public:
	NandGate(std::vector<bool*> inputs);

	void update();
	void show();

private:
	std::vector<bool*> inputs;
	bool output = true;
};

