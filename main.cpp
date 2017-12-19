#include <math.h>
#include "dichotomy.h"
int main() {
    float a = -2;
    float b = 6;
    float eps = 0.001f;
    float delt = 0.1f;
    auto lambda = [](float x) -> float {
        float res = x * exp(-2 * x);
        return res; };

    Dichotomy d(a,b,lambda);
    d.compute();
    float dich = d.getArgMin();
    auto inter = d.getInterval();
    auto step = d.getCount();



    return 0;
}