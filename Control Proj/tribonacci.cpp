#include "functions.h"

//мною був обраний тип long long int, оскільки значення нашого ряду будуть виключно додатніми. розмір такого типу даних складає 64 байти. тобто максимальне число ~ 2^64-1
unsigned long long  int tribonacciRecurrent(int n)
{
	if ((n == 0) | (n == 1))
	{
		return 0;
	}
	else if ((n == 2) | (n == 3))
	{
		return 1;
	}
	long long int x1 = 0;
	long long int x2 = 1;
	long long int x3 = 1;
	long long int xk;
	for (int k = 4; k <= n; ++k)
	{

		xk = (x1 + x2 + x3);
		x1 = x2;
		x2 = x3;
		x3 = xk;

	}
	return xk;
}

unsigned long long  int tribonacciRecursive(int x, long long int x1 = 0, long long int x2 = 1,  long long int x3 = 1)
{
	if ((x == 1) || (x == 0))
	{
		return 0;
	}
	else if ((x == 2) | (x == 3))
	{
		return 1;
	}
	return(x-1, x2, x3, (x1+x2+x3));
}




