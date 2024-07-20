//written by Spitkovska
#include "Screen.h"
#include <iostream>
#pragma warning(disable : 4018)

using namespace std;

const int Screen::maxHeight = 24;
const int Screen::maxWidth = 80; 
const char Screen::_filler = '.';

// Конструктор: Екран буде заповнено рядком pc, Лістинг 5.31
// якщо його задано, а ні – то наповнювачем _filler 
Screen::Screen(const int m, const int n, char* s) :
	// Ініціалізація довжини та ширини екрана з одночасною перевіркою 
	// виходу за його максимальні межі – у такому разі буде взято їх 
	_width(m > maxWidth ? maxWidth : m), _height(n > maxHeight ? maxHeight : n),
	_wContent(new char[_height * _width + 1]), // Образ екрана в пам’яті 
	_cursor(0) { // Курсор установлюється перед першим символом
	// Указник може бути невизначеним, тоді вважаємо рядок порожнім, а ні – 
	// то беремо його довжину: if (s==0) lens=0; else lens = strlen(s); 
	size_t lens = s == 0 ? 0 : strlen(s);
	// Якщо довжина рядка наповнення надто велика, урізаємо його 
	size_t len = lens > _height * _width ? _height * _width : lens;
	// Його заповнення починаємо з кінця символом закінчення рядка 
	_wContent[_height * _width] = '\0'; size_t k = 0;
	if (s != 0)
		// Записуємо на початку екрана рядок, переданий як параметр 
		for (; k < len; k++)
			*(_wContent + k) = *s++;
	// Заповнюємо екран до кінця наповнювачем 
	for (; k < _height * _width; k++)
		*(_wContent + k) = _filler;
}


// Переміщення курсору на один символ праворуч 
const Screen& Screen::move() const 
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
}

Screen& Screen::move()
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
}

// Переміщення курсору на один символ ліворуч 
const Screen& Screen::back() const 
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
}

Screen& Screen::back()
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
}

// Відображення вмісту екрана 
const Screen& Screen::show() const 
{
	int cursor = _cursor; // Збереження значення курсору
	cout << "cursor=" << _cursor << endl; 
	home();
	// Цикл за рядками екрана 
	for (int i = 0; i < _height; i++) {
		// Формування одного рядка 
		for (int j = 0; j < _width; j++) 
		{
			cout << get(); move();
		}
		cout << endl;
	}
	_cursor = _cursor; // Відновлення значення курсору
	return *this;
}

Screen& Screen::show()
{
	int cursor = _cursor; 
	cout << "cursor=" << _cursor << endl; 
	home();
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) 
		{
			cout << get(); move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
}

const Screen& Screen::move(const int i, const int j) const 
{
	// Якщо позиція некоректна, переносимо курсор у початок екрана 
	if ((i >= _height) || (j >= _width)) _cursor = 0;
	else _cursor = _width * i + j;
	return *this;
}
Screen& Screen::move(const int i, const int j)
{
	if ((i < 0) || (j < 0) || (i >= _width) || (j >= _height)) _cursor = 0;
	else _cursor = _width * j + i;
	return *this;
}

// Очищення екрана
Screen& Screen::clear() 
{ 
	for (int i = 0; i < _height * _width; i++)
	{
		*(_wContent + i) = _filler;
	}
	 _cursor=0; 
	 return *this; 
}


const Screen& Screen::showCurrent() const
{
	cout << get() << endl;
	return *this;
}

char Screen::get() const 
{
	return *(_wContent + _cursor);
}

char Screen::get()
{
	return *(_wContent + _cursor);
}


//Модифікатор теж розрахований на транзитивне застосування
Screen& Screen::set(char a) 
{
	* (_wContent + _cursor) = a;
	return *this;
}

const Screen& Screen::set(char a) const
{
	*(_wContent + _cursor) = a;
	return *this;
}

// Оператор =
Screen& Screen::operator= (const Screen& screen)
{
	if (this != &screen)
	{
		_width = screen._width;
		_height = screen._height;
		_cursor = screen._cursor;

		delete[] _wContent;
		_wContent = new char[_width * _height];
		std::copy(screen._wContent, screen._wContent + _width * _height, _wContent);
	}
	return *this;
}
 

ostream& operator<<(ostream& os, const Screen& screen)
{
	screen.show();
	return os;
}

void taskConst(const Screen& screen, int iterr, ConstAction task)
{
	for (int i = 0; i < iterr; i++)
	{
		(screen.*task)();
	}
}

void task(Screen& screen, int iterr, NonConstAction task)
{
	for (int i = 0; i < iterr; i++)
	{
		(screen.*task)();
	}
}