//
// Created by 이진호 on 2019-05-03.
//
#include "Complex.h"

Complex::Complex()
    :real(1),image(1){

}

Complex::Complex(double i)
    :real(1),image(i){

}

Complex::Complex(double r, double i)
    :real(r),image(i){

}

Complex Complex::operator+(Complex op2){
    Complex temp;
    temp.image=this->image+op2.image;
    temp.real=this->real+op2.real;

    return temp;
}

Complex Complex::operator-(Complex op2) {
    Complex temp;
    temp.image=this->image-op2.image;
    temp.real=this->real-op2.real;

    return temp;

}

Complex Complex::operator*(Complex op2) {
    Complex temp;
    temp.image=this->real*op2.image+this->image*op2.real;
    temp.real=this->real*op2.real-this->image*op2.image;

    return temp;
}

Complex Complex::operator/(Complex op2) {
    Complex temp;
    double a=this->real;
    double b=this->image;
    double c=op2.real;
    double d=op2.image;


    temp.real= (a*c+b*d)/(c*c+d*d);
    temp.image= (b*c-a*d)/(c*c+d*d);

    return temp;
}

void Complex::printComplex(){
    if(image>0) printf("(%.2f+%.2fi)",real,image);
    else printf("(%.2f%.2fi)",real,image);
}