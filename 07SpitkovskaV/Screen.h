//written by Spitkovska
#pragma once

#include <ostream>
using namespace std;
class Screen

{
private:
	// Максимальна висота екрана
	static const int maxHeight;
	// Максимальна ширина екрана
	static const int maxWidth;
	// Наповнювач
	static const char _filler;
	// Фактична висота екрана
	int _height;
	// Фактична ширина екрана
	int _width;
	// Наповнення екрана
	char* _wContent;
	// Де міститься курсор
	mutable int _cursor;
	// Нереалізовані, а тому закриті копіювання: 
	// копіювання екранів не передбачено
	Screen(const Screen&);
	Screen& operator= (const Screen&);

public:
	// Конструктор: Екран буде заповнено рядком pc, якщо його задано, 
	// а ні – то наповнювачем _filler
	Screen(int, int, char* pc = 0);
	// Деструктор
	~Screen() { delete[] _wContent; }
	// Однойменні сталі та несталі методи 
	// Помістити курсор на початок екрана 
	const Screen& home() const { _cursor = 0; return *this; }
	Screen& home() { _cursor = 0; return *this; }
	// Перемістити курсор на один символ праворуч 
	const Screen& move() const;
	Screen& move();
	// Перемістити курсор на один символ ліворуч 
	const Screen& back() const;
	Screen& back();
	// Показати вміст екрана 
	const Screen& show() const;
	Screen& show();
	// Перенести курсор на задану позицію
	const Screen& move(int, int) const;
	Screen& move(int, int);
	// Очистити екран 
	Screen& clear();
	// Показати символ, перед яким міститься курсор 
	const Screen& showCurrent() const;
	// Селектор 
	char get() const;
	char get();
	// Модифікатор 
	Screen& set(char);
	const Screen& set(char) const;
};
//Указник на конст/неконст метод класу екран
typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();
// Виклкик констатної/неконстантої функції
void task(Screen&, int, NonConstAction);
void taskConst(const Screen&, int, ConstAction);
//Утиліта виводу
ostream& operator<<(ostream&, const Screen&);
