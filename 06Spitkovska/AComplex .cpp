//written by Spitkovska
#include "AComplex .h"
#include "TComplex.h"
#include <iostream>


using namespace std;


AComplex::AComplex(double re, double im) :
	_re(re), _im(im), _id(++_freeID) 
{
#ifdef NDEBUG 
	cout << "Alg Number was created ->" << *this << ". Id: " << _id << endl;
#endif
	return;
}

AComplex::AComplex(const AComplex& a) :
	_re(a.re()), _im(a.im()), _id(++_freeID)
{
#ifdef NDEBUG 
	cout << "Alg Number was copied ->" << *this << ". Id: " << _id << endl;
#endif
	return;
}

AComplex::AComplex(const TComplex& t) :
	_re(t.re()), _im(t.im()), _id(++_freeID)
{
#ifdef NDEBUG 
	cout << "Alg Number was created from trigonom form->" << *this << ". Id: " << _id << endl;
#endif
	return;
}
AComplex::~AComplex() 
{
#ifdef NDEBUG 
	cout << "Alg Number was deleted ->" << *this << ". Id: " << _id << endl;
#endif
	return;
}

AComplex& AComplex::operator=(const AComplex& a) 
{
	_re = a.re();
	_im = a.im();
	return *this;
}


AComplex& operator+=(AComplex& a, const AComplex& b)
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}

AComplex& operator-=(AComplex& a, const AComplex& b)
{
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}
const AComplex operator+(const AComplex& a, const AComplex& b)
{
	AComplex c(a);
	c += b;
	return c;
}

const AComplex  operator- (const AComplex& a, const AComplex& b) 
{
	AComplex c(a);
	c -= b;
	return c;
}

bool operator== (const AComplex& a, const AComplex& b)
{
	return a.re() == b.re() && a.im() == b.im();
}


bool operator!=(const AComplex& a, const AComplex& b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, const AComplex& a)
{
	return os << a.re() << "+" << a.im() << "i";
}