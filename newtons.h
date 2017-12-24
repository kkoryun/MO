#pragma once

#include "method.h"

class Newtons : public Method
{
public:
	Newtons(double a, double b, std::function<double(double)> func, double eps, double delt, std::function<double(double)> func_d1, std::function<double(double)> func_d2,double x0 =0.0)
		: Method(a, b, func, delt,eps)
	{
		m_func_r1_d1 = func_d1;
		m_func_r1_d2 = func_d2;
		m_x0 = x0;
	}
	void compute() override 
	{
		double prev_x = m_x0;
		double cur_x;
		double f1 = m_func_r1_d1(m_x0);
		double f2 = m_func_r1_d2(m_x0);
		cur_x = m_x0 - f1 / f2;
		m_counter++;
		while (abs(cur_x- prev_x)>m_delt)
		{
			prev_x = cur_x;
			cur_x = prev_x - m_func_r1_d1(prev_x) / m_func_r1_d2(prev_x);
			m_counter++;
		}
		
	}

private:
	std::function<double(double)> m_func_r1_d1; // df/dx
	std::function<double(double)> m_func_r1_d2;// df/dx^2
	double m_x0;
};
