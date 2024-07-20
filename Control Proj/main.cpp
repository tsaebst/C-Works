#include <iostream>
using namespace std;
#include <cmath>
#include "functions.h"

//double task2(double eps, double x, double result=1)
//{
//	int n = 0;
//	double xn = (x - ) + x;
//	double an = pow(-1, n) * (1 / xn);
//	if (an == 0)
//	{
//		return result;
//	}
//	cout << an << endl;
//	result += an;
//	cout << result << endl;
//	return task2(n-1, x);
//
//}

double power(double x, int n) {
	double y = x;
	double a = y;
	double s = a;
	for (int k = 2; k <= n; k++) {
		y *= x * x;
		a *= y;
		s += a;
	}
	return s;
}





int main()
{
	// TASK 1
	unsigned int x = 3;
	int task1 = ~((x << 32)); //враховуючи кількість пам'яті, яку займає тип unsigned int(32 bites, to be correct) 
	//побітовий зсув вливо і вправо буде давати початкове значення х. відповідно і однакову інверсію.
	//cout << task1<<endl;
	//ми також можемо представити result так:
	task1 = ~(x);
	//cout << result<<endl;
	//TASK 2
	//cout << powerCheck(2, 0.001); DONE 
	// TASK 3
	//cout << tribonacciRecurrent(10) << endl; DONE
	//TASK 4
	cout << tribonacciRecursive(10) << endl; 
	//TASK 5
	//Fraction fraction = { 4, 6 };
	//Fraction res = FractionInvariation(fraction);
	//std::cout << res << std::endl;
	//doOper(z1, z2, operator+)
	//Fraction inv = doOper(task5.m,task5.n, FractionInvariation);
	//cout << doOper(task5, FractionInvariation) << endl;

	return 0;
}