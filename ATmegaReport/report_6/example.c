define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>

void Timer_Init(){
   TCCR0 =( 1 << WGM00 ) | (1 << WGM01 ) | ( 1 <<COM01) | ( 4 << CS0); 
   //Fast PWM 모드 설정
   //5번 1번 => 비반전 비교 출력 모드 , CS0 에 4번 초기화
   TIMSK = (1 << OCIE0); 
}

int main(void)
{
   Timer_Init(); //Timer 초기화
   DDRB = 0xFF; //B를 출력 포트로 설정
   unsigned char Level[2] = {1,254};

   while(1){
       for(i=0;i<2;i++){
           OCR0 = Level[i]; //1과 254의 값 반복 입력
           _delay_ms(1000); //delay 1000ms
       }
   }
}