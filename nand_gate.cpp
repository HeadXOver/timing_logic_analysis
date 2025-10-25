#include "nand_gate.h"

#include <iostream>

NandGate::NandGate(std::vector<bool*> inputs) : inputs(inputs)
{
}

void NandGate::update()
{
    for (int i = 0; i < inputs.size(); i++) {
        if (!*inputs[i]) {
            output = true;
            return;
        }
    }
    output = false;
}

void NandGate::show()
{
    std::cout << "NandGate: " << output << std::endl;
}
