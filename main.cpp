#include <iostream>

#include "dichotomy.h"
#include "passive.h"
#include "fibonacci.h"
#include "golden_ratio.h"
#include "newtons.h"

int main() {

    float a = -2;
    float b = 6;
    float eps = 0.000001f;
    float delt = 0.02f;
    auto lambda = [](double x) -> double 
	{
        double res = x * exp(-2 * x);
        return res; 
	};
	auto dif1 = [](double x) -> double
	{
		double res = (1 - 2 * x) * exp(-2 * x);
		return res; 
	};
	auto dif2 = [](double x) -> double 
	{
		double res = 4 * (x - 1) * exp(-2 * x);
		return res; 
	};

	for (size_t i = 1; i < 1; i++)
	{
		double tt = 1.0 / powf(2, i);
		Passive passive(a, b, lambda, delt);
		passive.compute();
		float passive_argMin = passive.getArgMin();
		auto passive_interval = passive.getInterval();
		int passive_step_number = passive.getCount();
		std::cout << "passive_argMin = " << passive_argMin << " passive_interval =["
			<< passive_interval.first << "," << passive_interval.second << "] " << " passive_step_number = " << passive_step_number<<std::endl;
	}
	
	std::cout << "###" << std::endl;
	for (int i = 0;i < 5;i++) 
	{
		double tt = 1.0 / powf(2, i);
		Dichotomy dichotomy(a, b, lambda, eps, delt * tt);
		dichotomy.compute();
		float dichotomy_argMin = dichotomy.getArgMin();
		auto dichotomy_interval = dichotomy.getInterval();
		int dichotomy_step_number = dichotomy.getCount();
		std::cout << " dichotomy_step_number = " << dichotomy_step_number << " delta ="<< (delt * tt) << std::endl;
	}
	std::cout << "###" << std::endl;
	for (int i = 0;i < 5;i++)
	{
		double tt = 1.0/powf(2, i);
		Fibonacci fibonacci(a, b, lambda, eps, delt*tt);
		fibonacci.compute();
		float fibonacci_argMin = fibonacci.getArgMin();
		auto fibonacci_interval = fibonacci.getInterval();
		int fibonacci_step_number = fibonacci.getCount();
		std::cout << " dichotomy_step_number = " << fibonacci_step_number << " delta =" << (delt * tt) << std::endl;
	}
	std::cout << "###" << std::endl;
	for (int i = 0;i < 5;i++)
	{
		double tt = 1.0 / powf(2, i);
		GoldenRatio goldenRatiom(a, b, lambda, eps, delt*tt);
		goldenRatiom.compute();
		float goldenRatiom_argMin = goldenRatiom.getArgMin();
		auto goldenRatiom_interval = goldenRatiom.getInterval();
		int goldenRatiom_step_number = goldenRatiom.getCount();
		std::cout << " dichotomy_step_number = " << goldenRatiom_step_number << " delta =" << (delt * tt) << std::endl;
	}

	Newtons newtons(a,b,lambda,eps,delt,dif1,dif2,-1.9);
	newtons.compute();
	/*for (int i = 0;i < 5;i++)
	{
		double tt = 1.0 / powf(2, i);
		Newtons newtons(a, b, lambda, eps, delt*tt,);
		newtons.compute();
		float newtons_argMin = newtons.getArgMin();
		auto newtons_interval = newtons.getInterval();
		int newtons_step_number = newtons.getCount();
		std::cout << " dichotomy_step_number = " << newtons_step_number << " delta =" << (delt * tt) << std::endl;
	}*/
    return 0;
}