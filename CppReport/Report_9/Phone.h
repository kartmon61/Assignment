//
// Created by 이진호 on 2019-05-10.
//

#ifndef ASSIGNMENT_PHONE_H
#define ASSIGNMENT_PHONE_H

#include <iostream>
#include <string>

using namespace std;

class Phone{
private:
    string number;

public:
    Phone(string number);
    void call();
    void receive();
};





#endif //ASSIGNMENT_PHONE_H
