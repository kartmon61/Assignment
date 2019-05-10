//
// Created by 이진호 on 2019-05-10.
//

#include "MusicPhone.h"

MusicPhone::MusicPhone(string number, string ip, int charge, string music)
        :MobilePhone(number,ip,charge)
{
    this->music=music;
}


void MusicPhone::downloadMusic() {
    cout << music <<"을 다운로드 합니다." << endl;
}

void MusicPhone::play() {
    cout << music <<"을 재생합니다." << endl;
}