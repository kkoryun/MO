#pragma once

#include <functional>
#include <math.h>

class Method
{
public:

    Method(double a, double b, std::function<double(double)> func,double delt = 0.5 ,double eps = 0.001) 
    {
        m_counter = 0;
        m_eps = eps;
		m_delt = delt;
        m_a = a;
        m_b = b;
        m_func_r1 = func;
		originInterval = std::pair<double, double>(a, b);
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

	void reset()
	{
		m_a = originInterval.first;
		m_b = originInterval.second;
		m_counter = 0;
	}
protected:
    int m_counter ;
    double m_a;
    double m_b;
    double m_eps;
	double m_delt;
	std::pair<double, double> originInterval;
    std::function<double(double)> m_func_r1;
};

