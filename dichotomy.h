#pragma once

#include <functional>

#include "method.h"

class Dichotomy:public Method
{
public:
    Dichotomy(double a, double b, std::function<double(double)> func, double delt = 0.1, double eps = 0.01):Method(a,b,func)
    {
        m_delt = delt;
    }

     void compute() override
    {
        while (m_b - m_a > m_delt)
        {
            m_counter++;
            float x1 = (m_b + m_a) / 2 - m_eps;
            float x2 = (m_b + m_a) / 2 + m_eps;
            if (m_func_r1(x1) < m_func_r1(x2))
            {
                m_b = x2;
            }
            else {
                m_a = x1;
            }
        }
    }
    
   
private:
    double m_delt;

};
