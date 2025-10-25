#pragma once

#include <vector>

class FlipFlop;

/////////////////////////////////////////////////////////
//@brief ʱ���࣬���������ӵ����д�����ָ��
//@param flip_flops ������ָ������
/////////////////////////////////////////////////////////

class Clock
{
public:
	Clock(std::vector<FlipFlop*> flip_flops);

	// @brief �������д�����
	// @note ��˳����´�������ȷ��������֮���ʱ���ϵ���ȸ��´�������������ٸ��´�����������
	void update();

private:
	std::vector<FlipFlop*> flip_flops;
};

