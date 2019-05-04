//
// Created by 이진호 on 2019-05-03.
//

#ifndef ASSIGNMENT_8_COMPLEX_H
#define ASSIGNMENT_8_COMPLEX_H
#include<iostream>
using namespace std;

class Complex{
private:
    double real;
    double image;

public:
    Complex();
    Complex(double i);
    Complex(double r,double i);
    Complex operator+(Complex op2);
    Complex operator-(Complex op2);
    Complex operator*(Complex op2);
    Complex operator/(Complex op2);
    void printComplex();
};


#endif //ASSIGNMENT_8_COMPLEX_H
