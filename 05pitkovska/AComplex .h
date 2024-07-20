//written by Spitkovska
#pragma once
#include <iostream>
#include <cmath> 

class TComplex;
class AComplex
{
private:
    double _re;
    double _im;
    int _id;
    static int _freeID;

public:
    AComplex(double re = 0, double im = 0);
    AComplex(const TComplex&);
    AComplex(const AComplex&);
    ~AComplex();
    // Присвоєння
    AComplex& operator= (const AComplex&);
    // Модифікатори 
    double& re() { return _re; };
    double& im() { return _im; };
    // Селектори 
    const double& re() const { return _re; };
    const double& im() const { return _im; };
    // Модуль і аргумент 
    double mod() const { return (sqrt(_re * _re + _im * _im)); };
    double arg() const { return (atan(_im / _re)); };
    //Спряжене
    const AComplex conj() const { return AComplex(_re, -_im); };

};
// Операції-утиліти 
AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator-=(AComplex&, const AComplex&);
const AComplex operator+ (const AComplex&, const AComplex&);
const AComplex operator- (const AComplex&, const AComplex&);
bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);
//Введеня
std::ostream& operator<<(std::ostream&, const AComplex&);
