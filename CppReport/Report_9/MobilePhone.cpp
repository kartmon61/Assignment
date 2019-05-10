//
// Created by 이진호 on 2019-05-10.
//
#include "MobilePhone.h"

MobilePhone::MobilePhone(string number, string ip, int charge)
        :Phone(number) {
    this->ip=ip;
    this->charge=charge;
}

void MobilePhone::connectWireless() {
    cout << ip <<" wireless에 연결합니다."<< endl;
}

void MobilePhone::recharge() {
    cout << "현재상태: " << charge <<"% recharge 합니다"<< endl;
}