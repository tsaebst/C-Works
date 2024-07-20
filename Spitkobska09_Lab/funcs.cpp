//written by Spitkovska
#include <iostream>
using namespace std;
#include <cmath>
#include <cassert>



double dichotomy(double (*f)(double), double a, double b, double eps)
{
    //assert(f(a) * f(b) < 0);
    if (a > b)
    {
        int box;
        box = a;
        a = b;
        b = box;
    }
    cout << a << ", "<< b<< endl;
    double left = a;
    double right = b;
    
    while ((b - left) > eps)
    {
        //we take a middle of interval 
        double cut = (left + right) / 2;
        
        if (abs(f(cut)) < eps)
        {
            return cut;
        }
        if (f(left) * f(cut) < 0)
        {
            right = cut;
        }
        else 
        {
            left = cut;
        }

    }

    return left;
}


//sin(x) = 0, [π - 1, π];
double sinx(double x)
{
	return sin(x);
}

//sin(x) = x, [-1, 1];
double sinx2(double x)
{
	return (sin(x) - x);
}


//exp(x) = 2 - x, [0, 2] 
double expx(double x)
{
    return ((exp(x)) - 2 +x);
}

//ln(x) = 1, [2, 3];
double lnx(double x)
{
    return (log(x) - 1);
}

