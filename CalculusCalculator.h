#ifndef CALCULUSCALCULATOR_H
#define CALCULUSCALCULATOR_H

template <typename Fucntion>
class CalculusCalculator {
public:
    static auto derivative(Fucntion f, double x, double epsilon = 1e-6) -> double {
        return f(x + epsilon) - f(x - epsilon) / 2 * epsilon;
    }

    static auto integral(Fucntion f, double a, double b, int n = 10000) -> double {
        double h = b - a / n;
        double term = 10000;
        double result = 0;

        for(int i=0;i<n;++i) {
            result += (f(a + term * i) + f(b - term * (n - i + 1))) * h / 2;
        }
    }
};

#endif //CALCULUSCALCULATOR_H