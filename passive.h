#pragma once

#include <vector>

#include "method.h"

class Passive: public Method
{
public:
    Passive(double a, double b, std::function<double(double)> func, double eps = 0.01):Method(a,b,func,eps)
    {

    }
    
    void compute() override 
    {
        std::vector<double> points;
        points.reserve(static_cast<unsigned>((m_b-m_a)/m_eps));
        double s = m_a;
        while (s <= m_b)
        {
            points.push_back(s);
            s += m_eps;
        }
        double min = m_func_r1(m_a);
        size_t min_index =0;
        for (size_t i = 0;i<points.size();i++)
        {
			if(m_func_r1(points[i]) < min)
			{
				min = m_func_r1(points[i]);
				min_index = i;
			}
			m_counter++;
        }
		if (min_index != 0)
			m_a = points[min_index - 1];
		if (min_index != points.size())
			m_b = points[min_index + 1];
    }


};

