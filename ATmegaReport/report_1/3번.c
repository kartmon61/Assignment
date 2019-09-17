#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    //포지션 1번 핀으로 초기화
    int position = 0x01;
    //방향 초기화
    int direction = 0;
    //포트 OUTPUT 설정
	DDRF = 0xFF;
    //포트 INPUT 설정
	DDRC = 0x00;
	
    while (1) 
    {
        //1번 스위치를 눌렀을때
	    if((PINC & 0x01)== 0x01){
            //position 핀 HIGH
            PORTF = position;
            while(1){
                //방향에 따라 케이스 나눈다.		
                if(position==0){
                    //0번 방향
                    case 0:
                        //8번핀에 도달했을 때
                        if(position == 0x80){
                            //방향 1로 바꿈
                            direction = 1;
                        }
                        //position 1씩 좌로 이동
                        else{
                            position = position << 1;
                        }
                        break;
                }
                //1번 방향
                else if(position==1){
                        //1번핀에 도달했을 때
                        if(position == 0x01){
                            //방향 0으로 바꿈
                            direction = 0;
                        }
                        else{
                            //position 1씩 우로 이동
                            position = position >> 1;
                        }
                        break;
                }
                //2번 스위치를 눌렀을 때 정지
                if((PINC & 0x02) == 0x02) break;
                //1초 딜레이
                _delay_ms(1000);	
            }
        }
    }
}
