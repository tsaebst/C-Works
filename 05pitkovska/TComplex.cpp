//written by Spitkovska
#include "TComplex.h"
#include "AComplex .h"
#include <cmath>


TComplex::TComplex(double r, double angle) :
    _ro(r), _phi(angle), _id(++_freeID)
{
#ifdef NDEBUG 
    cout << "Trigonom Number was created ->" << *this << ". Id: " << _id << endl;
#endif
}

TComplex::TComplex(const TComplex& t) :
    _ro(t.mod()), _phi(t.arg()), _id(++_freeID)
{
#ifdef NDEBUG 
    cout << "Trigonom Number was copied from ->" << *this << ". Id: " << _id << endl;
#endif
}

TComplex::TComplex(const AComplex& a) :
    _ro(a.mod()), _phi(a.arg()), _id(++_freeID)
{
#ifdef NDEBUG 
    cout << "Trigonom Number was created from alg form ->" << *this << ". Id: " << _id << endl;
#endif
}

TComplex::~TComplex()
{
#ifdef NDEBUG 
    cout << "Trigonom Number was deleted ->" << *this << ". Id: " << _id << endl;
#endif
}

TComplex& TComplex::operator= (const TComplex& t)
{
    if (this != &t)
    {
        _ro = t.mod();
        _phi = t.arg();
    }
    return *this;
}


const TComplex operator* (const TComplex& a, const TComplex& b)
{
    return TComplex(a.mod() * b.mod(), a.arg() + b.arg());
}

const TComplex operator/ (const TComplex& a, const TComplex& b)
{
    return TComplex(a.mod() / b.mod(), a.arg() - b.arg());
}

std::ostream& operator<<(std::ostream& os, const TComplex& a)
{
    os << a.mod() << "(cos(" << a.arg() << ")" << "+sin(" << a.arg() << ")i)";
    return os;
}