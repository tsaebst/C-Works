//Written by Spitkovska
#pragma once

#include <iostream>
using namespace std;

// Простий масив елементів
template<size_t n, class ArrayElem>
class Array
{
private:
    size_t _size; // Розмір масиву
    ArrayElem* _array;// Вміст масиву

public:
    class BadArray;
    // Конструктор, закритий для конвертування типів 
    explicit Array() : _size(n)
    {
        _array = new ArrayElem[_size]();
    #ifdef NDEBUG
            cout << "Created " << _size << "-size array: " << *this << endl;
    #endif
    }

    // Деструктор 
    ~Array() { delete[] _array; }
    
    // Видати розмірність масиву (селектор) 
    size_t size() const { return _size; }

    // Селектор елемента масиву: операція сталого індексування 
    Array(const Array& arr) : _size(arr._size)
    {
        _array = new ArrayElem[_size]();
        for (size_t i = 0; i < _size; i++) {
            _array[i] = arr._array[i];
        }
    }
    // Селектор елемента масиву
    const ArrayElem& operator[](const size_t id) const 
    {
        if (id < _size)
        {
            return _array[id];
        }
        throw BadArray("Index out of range: ", id);
    }
    // Селектор-модифікатор елемента масиву: операція індексування 
    ArrayElem& operator[](const size_t id) 
    {
        if (id < _size)
        {
            return _array[id];
        }
        throw BadArray("Index is out of range: ", id);
    }


    //Присвоєння
    Array& operator=(const Array& ar) 
    {
        if (this != &ar) {
            delete[] _array;
            _size = ar._size;
            _array = new ArrayElem[_size]();
            for (size_t i = 0; i < _size; i++)
            {
                _array[i] = ar._array[i];
            }
        }
        return *this;
    }

    //Оператор додавання
    template<size_t n, class ArrayElem>
    Array<n, ArrayElem> operator+(const Array<n, ArrayElem>& arr1) const
    {
        Array<n, ArrayElem> result;
        for (size_t i = 0; i < n; ++i) 
        {
                result[i] = (*this)[i] + arr1[i]; 
        }
        return result;
    }

};


//Додамо вкладений клас обробки помилок при виході індексів за межі масиву
template<size_t n, class ArrayElem>
class Array<n, ArrayElem>::BadArray
{
private:
    size_t _index;
    string _error;
public:

    explicit BadArray(string error = "", const size_t id = 0) : _error(error), _index(id) {}

    void showError() const 
    {
        cout << "Error occured: " << _error << endl;
        cout << "Problematic id: " << _index << endl;
    }
};

//Темплейт утилиті виводу
template<size_t n, class ArrayElem>
ostream& operator<<(ostream& os, const Array<n, ArrayElem>& array)
{
    os << "[";
    int max = array.size();
    for (size_t i = 0; i < max; i++)
    {
        os << array[i];
        if (i < (max - 1))
        {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

