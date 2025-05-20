#include "Dyhotomia_class.h"
#include <cmath>
#include <functional>

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

int Dyhotomia_class::count(double& x) {
    auto f = [](double x) {
        return exp(x) + log(x) - 10 * x;
    };

    int iter = 0;
    double a_local = a;
    double b_local = b;

    while (fabs(b_local - a_local) > eps) {
        double c = (a_local + b_local) / 2.0;
        if (f(a_local) * f(c) < 0)
            b_local = c;
        else
            a_local = c;

        ++iter;
        x = (a_local + b_local) / 2.0;
    }

    return iter;
}
