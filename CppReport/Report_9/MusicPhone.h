//
// Created by 이진호 on 2019-05-10.
//

#ifndef ASSIGNMENT_MUSICPHONE_H
#define ASSIGNMENT_MUSICPHONE_H

#include "MobilePhone.h"

class MusicPhone: public MobilePhone{
private:
    string music;

public:
    MusicPhone(string number,string ip,int charge,string music);
    void downloadMusic();
    void play();
};

#endif //ASSIGNMENT_MUSICPHONE_H
