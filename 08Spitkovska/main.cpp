//Written by Spitkovska
#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    //INT Arr
    cout << "Testing array with int values" << endl;
    Array<7, int> Arr7Int = Array<7, int>();
    for (int i = 0; i < Arr7Int.size(); i++)
    {
        Arr7Int[i] = i;
    }
    cout << Arr7Int << endl;
    //CHAR Arr
    cout << "Testing array with char values" << endl;
    Array<5, char> Arr5Char = Array<5, char>();
    for (int i = 0; i < Arr5Char.size(); i++)
    {
        Arr5Char[i] = 'a' + i;
    }
    cout << Arr5Char << endl;


    //Double Arr
    cout << "Testing array with double values" << endl;
    Array<3, double> Arr3Double = Array<3, double>();
    for (int i = 0; i < Arr3Double.size(); i++)
    {
        Arr3Double[i] = 0.5 * i;
    }
    cout << Arr3Double << endl;

    cout << "Bad index work demonstration: " << endl;
    try {
        cout << Arr7Int[7];
    }
    catch (Array<7, int>::BadArray& error)
    {
        error.showError();
    }


    Array<7, int> Arr7IntCopy;
    Arr7IntCopy = Arr7Int;

    cout << "Double to int convertation:" << endl;
    Arr7Int[0] = 8.5;
    Arr7Int[6] = 15.2;
    cout << Arr7Int << endl;
    Arr7Int = Arr7IntCopy;
    cout << "After redefining: " << Arr7Int << endl;

    cout << "Double to char" << endl;
    Arr5Char[0] = 12.5;
    cout << Arr5Char << endl;


    Array<5, double> Arr5Double = Array<5, double>();
    for (int i = 0; i < Arr5Double.size(); i++)
    {
        Arr5Double[i] = i * 1;
    }

    Array<5, double> Arr5DoubleAdd = Array<5, double>();
    for (int i = 0; i < Arr5DoubleAdd.size(); i++)
    {
        Arr5DoubleAdd[i] = i * 2;
    }

    cout << "Arr5Double: " << Arr5Double << endl;
    cout << "Arr5DoubleAdd: " << Arr5DoubleAdd << endl;
    Arr5Double = Arr5Double + Arr5DoubleAdd;
    cout << "Arr5Double after + Arr5DoubleAdd: " << Arr5Double << endl;
    return 0;
}
