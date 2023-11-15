// ParticipationLab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include "Rectangle.h"
#include "NegativeNumberException.h"

using namespace std;

int main()
{
    Rectangle<double> r1;
    Rectangle<int> r2;
    Rectangle<int> r3;

    try {
        r1.setLength(2.2);
        r1.setWidth(3.3);
    }
    catch (NegativeNumberException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << r1;

    try {
        r2.setLength(4);
        r2.setWidth(5);
    }
    catch (NegativeNumberException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << r2;

    
    try {
        r3.setLength(-5);
        r3.setWidth(-7);
    }
    catch (NegativeNumberException &e) {
        cout << "Exception: " << e.what() << endl;
    }

    //cout << r3;
}