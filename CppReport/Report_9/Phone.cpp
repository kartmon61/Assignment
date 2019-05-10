//
// Created by 이진호 on 2019-05-10.
//
#include "Phone.h"

Phone::Phone(string number) {
    this->number=number;

}

void Phone::call() {
    cout << number <<"에서 전화를 겁니다." << endl;
}

void Phone::receive() {
    cout << number <<"에서 전화를 받습니다." << endl;
}





