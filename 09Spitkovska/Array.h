#pragma once
#include <iostream>
//
////Written by Spitkovska
//#pragma once
//
//#include <iostream>
//using namespace std;
//
//// Простий масив елементів
//template<size_t n, class ArrayElem>
//class Array
//{
//private:
//    size_t _size; // Розмір масиву
//    ArrayElem* _array;// Вміст масиву
//
//public:
//    class BadArray;
//    // Конструктор, закритий для конвертування типів 
//    explicit Array() : _size(n)
//    {
//        _array = new ArrayElem[_size]();
//#ifdef NDEBUG
//        cout << "Created " << _size << "-size array: " << *this << endl;
//#endif
//    }
//
//    // Деструктор 
//    ~Array() { delete[] _array; }
//
//    // Видати розмірність масиву (селектор) 
//    size_t size() const { return _size; }
//
//    // Селектор елемента масиву: операція сталого індексування 
//    Array(const Array& arr) : _size(arr._size)
//    {
//        _array = new ArrayElem[_size]();
//        for (size_t i = 0; i < _size; i++) {
//            _array[i] = arr._array[i];
//        }
//    }
//    // Селектор елемента масиву
//    const ArrayElem& operator[](const size_t id) const
//    {
//        if (id < _size)
//        {
//            return _array[id];
//        }
//        throw BadArray("Index out of range: ", id);
//    }
//    // Селектор-модифікатор елемента масиву: операція індексування 
//    ArrayElem& operator[](const size_t id)
//    {
//        if (id < _size)
//        {
//            return _array[id];
//        }
//        throw BadArray("Index is out of range: ", id);
//    }
//
//
//    //Присвоєння
//    Array& operator=(const Array& ar)
//    {
//        if (this != &ar) {
//            delete[] _array;
//            _size = ar._size;
//            _array = new ArrayElem[_size]();
//            for (size_t i = 0; i < _size; i++)
//            {
//                _array[i] = ar._array[i];
//            }
//        }
//        return *this;
//    }
//
//    //Оператор додавання
//    template<size_t n, class ArrayElem>
//    Array<n, ArrayElem> operator+(const Array<n, ArrayElem>& arr1) const
//    {
//        Array<n, ArrayElem> result;
//        for (size_t i = 0; i < n; ++i)
//        {
//            result[i] = (*this)[i] + arr1[i];
//        }
//        return result;
//    }
//
//};
//
//
////Додамо вкладений клас обробки помилок при виході індексів за межі масиву
//template<size_t n, class ArrayElem>
//class Array<n, ArrayElem>::BadArray
//{
//private:
//    size_t _index;
//    string _error;
//public:
//
//    explicit BadArray(string error = "", const size_t id = 0) : _error(error), _index(id) {}
//
//    void showError() const
//    {
//        cout << "Error occured: " << _error << endl;
//        cout << "Problematic id: " << _index << endl;
//    }
//};
//
////Темплейт утилиті виводу
//template<size_t n, class ArrayElem>
//ostream& operator<<(ostream& os, const Array<n, ArrayElem>& array)
//{
//    os << "[";
//    int max = array.size();
//    for (size_t i = 0; i < max; i++)
//    {
//        os << array[i];
//        if (i < (max - 1))
//        {
//            os << ", ";
//        }
//    }
//    os << "]";
//    return os;
//}
#include <vector>

template<class ArrayElem>
class Array {
public:
    class BadArray;

    explicit Array(size_t size) : _size(size), _array(size) {}

    ~Array() = default;

    size_t size() const { return _size; }

    const ArrayElem& operator[](size_t index) const {
        if (index >= _size)
            throw BadArray("Index out of range: ", index);
        return _array[index];
    }

    ArrayElem& operator[](size_t index) {
        if (index >= _size)
            throw BadArray("Index out of range: ", index);
        return _array[index];
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            _size = other._size;
            _array = other._array;
        }
        return *this;
    }

    Array operator+(const Array& other) const {
        Array result(_size);
        for (size_t i = 0; i < _size; ++i)
            result[i] = (*this)[i] + other[i];
        return result;
    }

private:
    size_t _size;
    std::vector<ArrayElem> _array;
};

template<class ArrayElem>
class Array<ArrayElem>::BadArray {
private:
    size_t _index;
    std::string _error;

public:
    explicit BadArray(std::string error = "", size_t index = 0) : _error(error), _index(index) {}

    void showError() const {
        std::cerr << "Error occurred: " << _error << std::endl;
        std::cerr << "Problematic index: " << _index << std::endl;
    }
};

template<class ArrayElem>
std::ostream& operator<<(std::ostream& os, const Array<ArrayElem>& array) {
    os << "[";
    for (size_t i = 0; i < array.size(); ++i) {
        os << array[i];
        if (i < array.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
