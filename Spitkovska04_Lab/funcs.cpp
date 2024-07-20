#include <math.h>

double agMean(double x, double y) {
    double xPrev = x;
    double yPrev = y;

    double xn = sqrt(x * y);
    double yn = (x + y) / 2;

    while (xn < xPrev && yn < yPrev && xn > yn) {
        xPrev = xn;
        yPrev = yn;

        xn = sqrt(xPrev * yPrev);
        yn = (xPrev + yPrev) / 2;
    }
    return xn;
}

