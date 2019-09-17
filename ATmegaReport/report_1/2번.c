#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRF = 0xFF; //PORTF를 OUTPUT으로 설정
    DDRC = 0x00; //PORTC를 INPUT으로 설정
     int flag = 0;  
    
    while (1) 
    {
          //1번 핀을 누를 경우, flag 가 0일때
        if(((PINC & 0x01) == 0x01) && flag == 0)
            PORTF = 0xFF; //PORTF의 모든 핀 HIGH로 전환
              flag = 1; //flag 1로 변경
         //1번 핀을 누를 경우, flag가 1일때
        else if(((PINC & 0x01) == 0x01) && flag == 1){
            PORTF = 0x00; //PORTF의 모든 핀 LOW로 전환
              flag = 0; //flag 0로 변경
        }
        _delay_ms(500); //delay 0.5초
    }
}
