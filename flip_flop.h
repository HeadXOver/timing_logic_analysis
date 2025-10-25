#pragma once

///////////////////////////////////////////////////////////////
//@brief FlipFlop类
//@details input_j, input_k为输入，output_q, output_q_bar为输出, hold_j, hold_k为暂时保持的输入
///////////////////////////////////////////////////////////////

class FlipFlop
{
public:
	void j_connect_to(const bool* j);
	void k_connect_to(const bool* k);

	//@brief 根据保持的信号，更新输出
	void update();

	//@brief 根据输入，更新保持的信号
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

