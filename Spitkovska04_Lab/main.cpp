
#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
    double x = 13;
    double y = 13;

    cout << "M(" << x << ", " << y << ") = " << agMean(x, y) << endl;

    x = 9;
    y = 11;
    cout << "M(" << x << ", " << y << ") = " << agMean(x, y) << endl;

    x = 0.01;
    y = 120;
    cout << "M(" << x << ", " << y << ") = " << agMean(x, y) << endl;

    return 0;
}