#pragma once

///////////////////////////////////////////////////////////////
//@brief FlipFlop��
//@details input_j, input_kΪ���룬output_q, output_q_barΪ���, hold_j, hold_kΪ��ʱ���ֵ�����
///////////////////////////////////////////////////////////////

class FlipFlop
{
public:
	void j_connect_to(const bool* j);
	void k_connect_to(const bool* k);

	//@brief ���ݱ��ֵ��źţ��������
	void update();

	//@brief �������룬���±��ֵ��ź�
	void update_hold();

	bool* ref_q();
	bool* ref_q_bar();

	bool get_q();

private:
	const bool* input_j = nullptr;
	const bool* input_k = nullptr;

	bool hold_j = false;
	bool hold_k = false;

	bool output_q = false;
	bool output_q_bar = true;
};

