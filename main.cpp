#include <math.h>

#include "dichotomy.h"
#include "passive.h"
#include "fibonacci.h"

int main() {
    float a = -2;
    float b = 6;
    float eps = 0.01f;
    float delt = 0.5f;
    auto lambda = [](float x) -> float {
        //float res = x * exp(-2 * x);
		float res = x * x;
        return res; };


	Passive passive(a, b, lambda);
	passive.compute();
	float passive_argMin = passive.getArgMin();
	auto passive_interval = passive.getInterval();
	int passive_step_number = passive.getCount();

    Dichotomy dichotomy(a,b,lambda);
	dichotomy.compute();
    float dichotomy_argMin = dichotomy.getArgMin();
    auto dichotomy_interval = dichotomy.getInterval();
    int dichotomy_step_number = dichotomy.getCount();

	Fibonacci fibonacci(a,b,lambda);
	fibonacci.compute();
	float fibonacci_argMin = fibonacci.getArgMin();
	auto fibonacci_interval = fibonacci.getInterval();
	int fibonacci_step_number = fibonacci.getCount();




    return 0;
}