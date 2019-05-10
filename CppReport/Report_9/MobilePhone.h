//
// Created by 이진호 on 2019-05-10.
//

#ifndef ASSIGNMENT_MOBILEPHONE_H
#define ASSIGNMENT_MOBILEPHONE_H

#include "Phone.h"

class MobilePhone : public Phone{
private:
    string ip;
    int charge;

public:
    MobilePhone(string number,string ip, int charge);
    void connectWireless();
    void recharge();

};
#endif //ASSIGNMENT_MOBILEPHONE_H
