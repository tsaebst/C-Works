//written by Spitkovska

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
using namespace std;
#include "funcs.h"

//sin(x) = x, [-1, 1];
//sin(x) = 0, [π - 1, π];
//ln(x) = 1, [2, 3];
//exp(x) = 2 - x, [0, 2] 
int main()
{
	const double pi = M_PI;
	const double eps = 1.0e-15;

	double a;
	double b;

	a = -1;
	b = 1;

	cout << "sin(x) = x, for [-1, 1]. x = " << dichotomy(sinx2, a, b, eps) << endl;

	a = pi - 1;
    b = pi;

	cout <<"sin(x) = 0, for [pi-1, pi]. x = " << dichotomy(sinx, a, b, eps)<<endl;

	a = 0;
	b = 2;

	cout << "exp(x) = 2-x, for [0, 2]. x = " << dichotomy(expx, a, b, eps) << endl;

	a = 2;
	b = 3;

	cout << "ln(x) = 1, for [2, 3]. x = " << dichotomy(lnx, a, b, eps) << endl;


	return 0;
}

