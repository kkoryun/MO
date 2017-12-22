#pragma once

#include <functional>
#include <math.h>

class Method
{
public:

    Method(double a, double b, std::function<double(double)> func,double eps = 0.01) 
    {
        m_counter = 0;
        m_eps = eps;
        m_a = a;
        m_b = b;
        m_func_r1 = func;
    }

    void setEps(double eps) 
    {
        m_eps = eps;
    }

    int getCount() const 
    {
        return m_counter;
    }

    std::pair<double, double> getInterval() const 
    {
        return std::pair<double, double>(m_a, m_b);
    }

    double getMin(std::function<double(double, double)> res_from_interv = 
        [](double a, double b) ->double {return (a + b) / 2.0; }) const
    {
        return m_func_r1(res_from_interv(m_a, m_b));
    }

    double getArgMin(std::function<double(double, double)> res_from_interv = 
        [](double a, double b) ->double {return (a + b) / 2.0; }) const
    {
        return res_from_interv(m_a, m_b);
    }

    virtual void compute() 
    {
        return;
    }
protected:
    int m_counter ;
    float m_a;
    float m_b;
    double m_eps;

    std::function<double(double)> m_func_r1;
};

