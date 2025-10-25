////////////////////////////////////////////////////////////
//  ʱ���߼�������������ģ��
//  ������ͼ�������Ƽ�����
////////////////////////////////////////////////////////////

#include <iostream>

#include "flip_flop.h"
#include "clock.h"
#include "nand_gate.h"

int main() 
{
	// ����������
	FlipFlop ff0;
	FlipFlop ff1;
	FlipFlop ff2;


	// ͬһ��ʱ���źţ���������������
	Clock cp({ &ff0 , &ff1 , &ff2 });

    // �������������ӵ�ͬһ�������
    // !Y = !q0 && !q1 && q2
	NandGate output({ff0.ref_q_bar(), ff1.ref_q_bar(), ff2.ref_q()});

	// ������������
	ff0.j_connect_to(ff2.ref_q_bar());
	ff0.k_connect_to(ff2.ref_q());

	ff1.j_connect_to(ff0.ref_q());
	ff1.k_connect_to(ff0.ref_q_bar());

	ff2.j_connect_to(ff1.ref_q());
	ff2.k_connect_to(ff1.ref_q_bar());


	// ���10������
	for (int i = 0; i < 10; i++) {
		cp.update();
		output.update();

		std::cout << i << ": ��������: ";
		output.show();

		std::cout << "ff0���: " << ff0.get_q() << std::endl;
		std::cout << "ff1���: " << ff1.get_q() << std::endl;
		std::cout << "ff2���: " << ff2.get_q() << std::endl;
	}
}