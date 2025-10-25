////////////////////////////////////////////////////////////
//  时序逻辑分析经典例题模拟
//  附例题图，六进制计数器
////////////////////////////////////////////////////////////

#include <iostream>

#include "flip_flop.h"
#include "clock.h"
#include "nand_gate.h"

int main() 
{
	// 三个触发器
	FlipFlop ff0;
	FlipFlop ff1;
	FlipFlop ff2;


	// 同一个时钟信号，连接三个触发器
	Clock cp({ &ff0 , &ff1 , &ff2 });

    // 三个触发器连接到同一个与非门
    // !Y = !q0 && !q1 && q2
	NandGate output({ff0.ref_q_bar(), ff1.ref_q_bar(), ff2.ref_q()});

	// 触发器的连接
	ff0.j_connect_to(ff2.ref_q_bar());
	ff0.k_connect_to(ff2.ref_q());

	ff1.j_connect_to(ff0.ref_q());
	ff1.k_connect_to(ff0.ref_q_bar());

	ff2.j_connect_to(ff1.ref_q());
	ff2.k_connect_to(ff1.ref_q_bar());


	// 输出10个周期
	for (int i = 0; i < 10; i++) {
		cp.update();
		output.update();

		std::cout << i << ": 与非门输出: ";
		output.show();

		std::cout << "ff0输出: " << ff0.get_q() << std::endl;
		std::cout << "ff1输出: " << ff1.get_q() << std::endl;
		std::cout << "ff2输出: " << ff2.get_q() << std::endl;
	}
}