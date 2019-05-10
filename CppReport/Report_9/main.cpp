
#include "MusicPhone.h"


int main(){
    MusicPhone a("010-1234-5678","1234",10,"썸");
    MusicPhone b("010-1234-1234","4321",15,"나만바라봐");
    MusicPhone c("010-5678-5678","5678",30,"썸탈꺼야");

    a.call();
    a.receive();
    b.connectWireless();
    b.recharge();
    c.downloadMusic();
    c.play();
}