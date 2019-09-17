#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRF = 0xFF; //PORTF를 OUTPUT으로 설정
    DDRC = 0x00; //PORTC를 INPUT으로 설정
    
    while (1) 
    {
            if((PINC & 0x01) == 0x01) //1번 PIN을 누를 경우
                PORTF = 0xFF; //PORTF의 모든 핀 HIGH로 전환
            else 
                PORTF = 0x00; //PORTF의 모든 핀 LOW로 전환
            _delay_ms(500); //0.5초 딜레이
    }
}
