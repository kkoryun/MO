#pragma once

#include "method.h"

class Dichotomy:public Method
{
public:
    Dichotomy(double a, double b, std::function<double(double)> func,
		double eps = 0.01, double delt = 0.1) : Method(a, b, func,delt ,eps)
    {

    }

     void compute() override
    {
        while ((m_b - m_a) > m_delt)
        {
            m_counter++;
            double x1 = (m_b + m_a) / 2.0 - m_eps;
            double x2 = (m_b + m_a) / 2.0 + m_eps;
            if (m_func_r1(x1) < m_func_r1(x2))
            {
                m_b = x2;
            }
			else
			{
				m_a = x1;
			}
			std::cout.precision(std::numeric_limits<double>::digits10 + 1);
			//std::cout << "interval =[" << m_a << "," << m_b << "] " << "interval length = "<<(m_b-m_a)<<std::endl;
			
        }
    }
    
   
private:


};
