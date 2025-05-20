#include "Newton_class.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

Newton_class::Newton_class() {}
Newton_class::~Newton_class() {}

void Newton_class::setStart(double start) {
    x0 = start;
}

void Newton_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

int Newton_class::count(double& x) {
    // Лямбда для функції
    auto fx = [](double x) {
        if (x <= 0) {
            cerr << "Помилка: x <= 0\n";
            return numeric_limits<double>::quiet_NaN();
        }
        return exp(x) + log(x) - 10 * x;
    };

    // Лямбда для похідної
    auto dfx = [](double x) {
        if (x <= 0) {
            cerr << "Помилка: x <= 0\n";
            return numeric_limits<double>::quiet_NaN();
        }
        return exp(x) + 1 / x - 10;
    };

    x = x0;
    int iter = 0;
    int maxIter = 100;

    while (iter < maxIter) {
        double dx = dfx(x);

        if (isnan(x) || isnan(fx(x)) || isnan(dx)) {
            cerr << "NaN в обчисленнях на ітерації " << iter << endl;
            return -1;
        }

        if (fabs(dx) < 1e-12) {
            cerr << "Похідна близька до нуля" << endl;
            return -1;
        }

        x = x - fx(x) / dx;
        ++iter;

        if (fabs(fx(x)) < eps) {
            return iter;
        }
    }

    cerr << "Перевищено максимальну кількість ітерацій" << endl;
    return maxIter;
}
