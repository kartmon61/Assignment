//
// Created by 이진호 on 2019-05-03.

#include "Complex.h"


int main(){

    Complex a(1,-2);
    Complex b(1,-3);
    Complex c;
    //덧셈
    c=a+b;
    a.printComplex();
    cout << "+";
    b.printComplex();
    cout << "=";
    c.printComplex();
    cout << endl;
    //뺄셈
    c=a-b;
    a.printComplex();
    cout << "-";
    b.printComplex();
    cout << "=";
    c.printComplex();
    cout << endl;
    //곱셈
    c=a*b;
    a.printComplex();
    cout << "*";
    b.printComplex();
    cout << "=";
    c.printComplex();
    cout << endl;
    //나눗셈
    c=a/b;
    a.printComplex();
    cout << "/";
    b.printComplex();
    cout << "=";
    c.printComplex();
    cout << endl;
}