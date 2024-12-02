#ifndef LOGCALCULATOR_H
#define LOGCALCULATOR_H
#include "SimpleCalculator.h"

class LogCalculator {
public:
    //taylor expansion
    static auto ln(auto x) {
        if(x <= 0) {
            throw std::invalid_argument("Cannot calculate Negative number in log function.");
        }
        double result = 0;
        double epsilon = 1e-6;

        for(int n=1;;n+=2) {
            double power = (1.0 / n) * square((x-1) / (x+1) , n);
            if(std::fabs(power) < epsilon) {
                break;
            }
            result += power;
        }

        return result * 2;
    }

    static auto customLog(auto a, auto x) {
        if(x <= 0 || a <= 0 || a == 1) {
            throw std::invalid_argument("Cannot calculate Negative number in log function");
        }

        return ln(x) / ln(a);
    }

    static auto normalLog(auto x) {
        if(x <= 0) {
            throw std::invalid_argument("Cannot calculate Negative number in log function");
        }

        return ln(x) / ln(10);
    }
};

#endif //LOGCALCULATOR_H
