#pragma once

#include "method.h"

#define INV_GOLDEN_RATION 0.6180339887498949;

class GoldenRatio : public Method
{
public:
	GoldenRatio(double a, double b, std::function<double(double)> func,
		double eps = 0.01, double delt = 0.1) : Method(a, b, func, delt, eps)
	{
	
	}

	void compute() override 
	{
		double coef = (m_b - m_a) * INV_GOLDEN_RATION;
		double x = m_b - coef;
		double y = m_a + coef;
		double Qx = m_func_r1(x);
		double Qy = m_func_r1(y);
		m_counter++;
		while ((m_b - m_a) > m_delt)
		{
			m_counter++;
			if (Qx <= Qy) 
			{
				m_b = y;
				y = x;
				Qy = Qx;
				x = m_b - (m_b - m_a)*INV_GOLDEN_RATION;
				Qx = m_func_r1(x);
			}
			else 
			{
				m_a = x;
				x = y;
				Qx = Qy;
				y = m_a + (m_b - m_a)*INV_GOLDEN_RATION;
				Qy = m_func_r1(y);
			}
			//std::cout << "interval =[" << m_a << "," << m_b << "] " << "interval length = " << (m_b - m_a) << std::endl;
		}
	}

};
