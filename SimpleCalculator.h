#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H
#include "BigInteger.h"

class SimpleCalculator {
public:
    static auto add(auto a, auto b) -> decltype(a+b) {return a+b;}

    static auto subtraction(auto a, auto b) -> decltype(a-b) {return a-b;}

    static auto multiple(auto a, auto b) -> decltype(a*b) {return a*b;}

    static auto division(auto a, auto b) -> decltype(a/b) {
        if(b == 0) {
            throw std::invalid_argument("Division by Zero");
        }
        return a/b;
    }

    static auto factorial(int n) -> int {
        if(n == 1) return 1;
        return n * factorial(n-1);
    }

    //newton-raphson theory
    static auto sqrt(auto a) {
        if(a < 0) {
            throw std::invalid_argument("Cannot calculate sqrt of a negative number");
        }

        double x = a / 2;
        double next_x;
        double epsilon = 1e-6;

        while(true) {
            next_x = (x + a / x) / 2;
            if(std::fabs(next_x - x) < epsilon){ break; }
            x = next_x;
        }

        return next_x;
    }

    //add function square(double, double)
    static auto square(auto a, auto b) -> decltype(a*b) {
        int n = 1;
        for(int i=0;i<b;i++) {
            n *= a;
        }
        return n;
    }
};

#endif //SIMPLECALCULATOR_H
