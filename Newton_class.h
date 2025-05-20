#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_H

#include <iostream>
#include <cmath>

class Newton_class {
private:
    double x0;
    double eps;

public:
    Newton_class();
    ~Newton_class();

    void setStart(double start);
    void setTolerance(double vol_eps);
    int count(double& x);
};

#endif
