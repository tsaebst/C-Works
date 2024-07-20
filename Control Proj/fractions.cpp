//#include <iostream>
//#include <cmath>
//#include <cassert>
//#include "functions.h"
//
//
//
//
//template <typename T>
//T FractionInvariation(const T& mn)
//{
//    int m = mn.m;
//    int n = mn.n;
//    if (m == 0)
//    {
//        n = m = 0;
//        return { m, n };
//    }
//    int divid = euclidusAlg(m, n);
//    m = std::abs(m / divid);
//    n = std::abs(n / divid);
//    return { m, n };
//}
//
//int euclidusAlg(int a, int b)
//{
//    if (a == 0)
//    {
//        return b;
//    }
//    else if (a < b)
//    {
//        return euclidusAlg(b, a);
//    }
//    else
//    {
//        if ((a - b) < 0)
//        {
//            return 1;
//        }
//        return euclidusAlg(a - b, b);
//    }
//}
//
//std::ostream& operator<<(std::ostream& os, const Fraction& f)
//{
//    return os << f.m << '/' << f.n;
//}