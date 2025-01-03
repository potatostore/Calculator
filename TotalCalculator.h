#ifndef TOTALCALCULATOR_H
#define TOTALCALCULATOR_H
#include "TrigonometryCalculator.h"
#include "LogCalculator.h"
#include "ComplexCalculator.h"
#include "CalculusCalculator.h"
#include "SimpleCalculator.h"

class TotalCalculator{
public:
    static auto add(auto a, auto b) -> decltype(a+b) {
        return SimpleCalculator::add(a, b);
    }

    static auto subtraction(auto a, auto b) -> decltype(a-b) {
        return SimpleCalculator::subtraction(a, b);
    }

    static auto multiple(auto a, auto b) -> decltype(a*b) {
        return SimpleCalculator::multiple(a, b);
    }

    static auto division(auto a, auto b) -> decltype(a/b) {
        return SimpleCalculator::division(a, b);
    }

    static auto factorial(int n) -> int {
        return SimpleCalculator::factorial(n);
    }

    static auto sqrt(auto a) {
        return SimpleCalculator::sqrt(a);
    }

    //add function square(double, double)
    static auto square(auto a, auto b) -> decltype(a*b) {
        return SimpleCalculator::square(a, b);
    }

    static auto sin(double angle) -> double {
        return TrigonometryCalculator::sin(angle);
    };

    static auto cos(double angle) -> double {
        return TrigonometryCalculator::cos(angle);
    }

    static auto tan(double angle) -> double {
        return TrigonometryCalculator::tan(angle);
    }

    static auto arcsin(auto y) -> double {
        return TrigonometryCalculator::arcsin(y);
    }

    static auto arccos(auto y) -> double {
        return TrigonometryCalculator::arccos(y);
    }

    static auto arctan(auto y) -> double {
        return TrigonometryCalculator::arctan(y);
    }

    static auto ln(auto x) {
        return LogCalculator::ln(x);
    }

    static auto customLog(auto a, auto x) {
        return LogCalculator::customLog(a, x);
    }

    static auto normalLog(auto x) {
       return LogCalculator::normalLog(x);
    }

    static auto complexAdd(std::complex<double> a, std::complex<double> b) {
        return ComplexCalculator::complexAdd(a, b);
    }

    static auto complexSubstraction(std::complex<double> a, std::complex<double> b) {
        return ComplexCalculator::complexSubstraction(a, b);
    }

    static auto complexMultiple(std::complex<double> a, std::complex<double> b) {
        return ComplexCalculator::complexMultiple(a, b);
    }

    static auto complexDivision(std::complex<double> a, std::complex<double> b) {
        return ComplexCalculator::complexDivision(a, b);
    }

    static auto integral(auto a) {
        return CalculusCalculator::integral(a);
    }

    static auto derivate(auto a) {
        return CalculusCalculator::derivate(a);
    }

};
#endif //TOTALCALCULATOR_H
