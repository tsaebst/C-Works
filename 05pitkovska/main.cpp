//written by Spitkovska
#include <iostream>
#include "AComplex .h"
#include "TComplex.h"

int AComplex::_freeID = 0;
int TComplex::_freeID = 0;

using namespace std;

int main() {
	// Визначення чисел в алгебричному вигляді 
	AComplex z1(1, 1), z2(0, 1);
	cout << "Conversion operator" << endl;
	cout << "Utilities as operation" << endl;
	cout << "Complex==========" << endl;
	// Операції над аргументами різних типів із застосуванням перетворень 
	cout << z1 + z2 << endl;
	cout << z1 << endl;
	cout << "Conj: " << z1.conj() << endl;
	cout << (z1 = z2 = 1) << endl;
	cout << (z2 = z1 += 1) << endl; cout << ((z1 += z2) = 1) << endl;
	z1 -= z2;
	cout << z1 << endl;
	z2 += (2 * z2 - z1);
	cout << z2 << endl;
	// Визначення чисел у тригонометричному вигляді 
	TComplex t1(1, 2), t2(2, 3);
	cout << "TComplex==========" << endl;
	cout << t1 << endl; cout << t2 << endl;
	// Операції над аргументами різних типів із застосуванням перетворень 
	AComplex z3(3, 3);
	cout << "Mixed==========" << endl;
	cout << z1 + t1 << endl;
	cout << t1 + z1 << endl;
	cout << z1 * t1 << endl;
	cout << t1 * z1 << endl;
	cout << (t1 == t1) << endl;
	cout << (AComplex(t1) == t1) << endl;
	cout << (TComplex(z3) == z3) << endl;

	return 0;
}