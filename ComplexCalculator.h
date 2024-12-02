#ifndef COMPLEXCALCULATOR_H
#define COMPLEXCALCULATOR_H
#include "SimpleCalculator.h"

class ComplexCalculator{
public:
    static auto complexAdd(std::complex <auto> a, std::complex <auto> b) {
        return a+b;
    }

    static auto complexSubstraction(std::complex <auto> a, std::complex <auto> b) {
        return a-b;
    }

    static auto complexMultiple(std::complex <auto> a, std::complex <auto> b) {
        return a*b;
    }

    static auto complexDivision(std::complex <auto> a, std::complex <auto> b) {
        if(b.real() == 0 && b.imag() == 0) {
            throw std::invalid_argument("Complex Cannot Divise by Zero.");
        }
        return a/b;
    }
};

#endif //COMPLEXCALCULATOR_H
