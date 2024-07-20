//written by Spitkovska
#pragma once
#include <iostream>
#include "AComplex .h" 

class AComplex;

class TComplex
{
private:
    double _ro;
    double _phi;
    static int _freeID;
    int _id;
public:
    TComplex(double ro = 0, double phi = 0);
    TComplex(const AComplex&);
    TComplex(const TComplex&);
    ~TComplex();
    // Присвоєння
    TComplex& operator=(const TComplex&);
    // Модифікатори 
    double& mod() { return _ro; };
    double& arg() { return _phi; };
    // Селектори 
    const double& mod() const { return _ro; };
    const double& arg() const { return _phi; };
    // Дійсна та уявна частини 
    double re() const { return _ro * cos(_phi); };
    double im() const { return _ro * sin(_phi); };

};
//Утиліти
const TComplex operator*(const TComplex&, const TComplex&);
const TComplex operator/(const TComplex&, const TComplex&);
//Введення
std::ostream& operator<<(std::ostream&, const TComplex&);
