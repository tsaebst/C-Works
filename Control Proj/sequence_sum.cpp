#include <iostream>
#include <cmath>
#include "functions.h"

double powerCheck(double x, double eps)
{
	double s = 1;
	int n = 1;
	while (abs(pow(-1, n) * (1 / pow(x, n * n))) > eps)
	{
		s += pow(-1, n) * (1 / pow(x, n * n));
		++n;
	}

	return s;
}
