#include "Dyhotomia_class.h"
#include "Newton_class.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Метод дихотомії:\n";
    Dyhotomia_class dyh;
    dyh.setVolumes(2, 4);
    dyh.setTolerance(1e-3);

    double root1;
    int steps1 = dyh.count(root1);

    cout << "Корінь: x = " << root1 << "\n";
    cout << "Ітерацій: " << steps1 << "\n";

    cout << "\nМетод Ньютона:\n";
    Newton_class newton;
    newton.setStart(5.0);
    newton.setTolerance(1e-9);

    double root2;
    int steps2 = newton.count(root2);

    cout << "Корінь: x = " << root2 << "\n";
    cout << "Ітерацій: " << steps2 << "\n";

    return 0;
}
