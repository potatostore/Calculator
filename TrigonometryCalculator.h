#ifndef TRIGONOMETRYCALCULATOR_H
#define TRIGONOMETRYCALCULATOR_H
#include "SimpleCalculator.h"
#define decimalPointPlace 6

class TrigonometryCalculator{
private:
    //convert angle into n * M_PI
    static double normalizingAngle(double angle) {
        return std::fmod(angle, 2 * M_PI);
    }

    //determine taylor expansion terms for triangle method
    static int determineTerms(double angle) {
        double absAngle = std::fabs(angle);
        if(absAngle < M_PI/4) return 10;
        else if(absAngle < M_PI) return 20;
        return 30;
    }

    static auto roundDecimal(auto input) {
        double roundValue = square(input, decimalPointPlace);
        return std::round(roundValue * input) / roundValue;
    }

public:
    //newton-raphson theory
    static auto sin(double angle) -> double {
        angle = normalizingAngle(angle);
        int terms = determineTerms(angle);
        int sign = 1;
        double x = angle * angle;
        double result = 0.0;

        for(int i=1;i<=terms;i+=2) {
            result += sign * x / SimpleCalculator::factorial(i);
            sign *= -1;
            x *= angle * angle;
        }

        return result;
    };

    static auto cos(double angle) -> double {
        angle = normalizingAngle(angle);
        int terms = determineTerms(angle);
        int sign = 1;
        double x = angle;
        double result = 0.0;

        for(int i=0;i<=terms;i+=2) {
            result += sign * x / SimpleCalculator::factorial(i);
            sign *= -1;
            x *= angle * angle;
        }

        return result;
    }

    static auto tan(double angle) -> double {
        angle = normalizingAngle(angle);
        double cosValue = cos(angle);

        if(std::abs(cosValue) < 1e-9) {
            throw std::runtime_error("cos(x) value is too small!");
        }
        return sin(angle) / cosValue;
    }

    //newton-raphson theory
    static auto arcsin(auto y) -> double {
        if(y > 1 || y < -1) {
            throw std::invalid_argument("Out of Range in arcsin(x), -1 <= x <= 1");
        }

        double x = y;
        double next_x;
        double epsilon = 1e-6;

        while(true) {
            next_x = x - (sin(x) - y) / cos(x);
            if(std::fabs(next_x - x) < epsilon) {
                break;
            }
            x = next_x;
        }

        return next_x;
    }

    static auto arccos(auto y) -> double {
        if(y > 1 || y < -1) {
            throw std::invalid_argument("Out of Range in arcsin(x), -1 <= x <= 1");
        }

        double x = y;
        double next_x;
        double epsilon = 1e-6;

        while(true) {
            next_x = x + (cos(x) - y) / sin(x);
            if(std::fabs(next_x - x) < epsilon) {
                break;
            }
            x = next_x;
        }

        return next_x;
    }

    static auto arctan(auto y) -> double {
        double epsilon = 1e-6;
        double result = 0;

        for(int n=0;;n+=2) {
            int sign = -1;
            double power = (sign * square(y, n+1)) / n+1;

            if(std::fabs(power) < epsilon) {
                break;
            }

            sign *= -1;
            result += power;
        }
        return result;
    }
};

#endif //TRIGONOMETRYCALCULATOR_H
