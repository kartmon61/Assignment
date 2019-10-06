/*
 * Lab5.c
 *
 * Created: 2017-07-24 오전 11:20:59
 * Author : hp
 */

#define F_CPU 16000000UL //16MHz 설정
#define BAUD 9600 //9600bfs 설정
#define MYUBRR F_CPU/16/BAUD-1 //UBRR 계산

#define COMPARE_MATCH 1 //타이머 모드 설정 (Overflow, CompareMatch)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int msec, sec; //타이머 글로벌 변수


//Over flow
#ifdef OVER_FLOW

void Timer_Init(){
	TCCR0 = (4<<CS0);   //프리스케일러의 타이머 0에서 64로 설정
	TIMSK = (1<<TOIE0); //오버플로우 인터럽트 활성화
	TCNT0 = 6;  //포인트 카운터의 스타팅 포인터를 6으로 지정
}

//타이머 오버플로우의 인터럽트
ISR(TIMER0_OVF_vect){
	msec++;	//ms 증가
	//ms가 1000이 될때
	if(msec == 1000){	
		msec = 0; //msec를 0으로 초기화
		sec++; //sec 증가
	}
	//sec가 100이 될때
	if(sec == 100){
		sec = 0; //sec 0으로 초기화
	}
	TCNT0 = 6;  //TCNT0 초기화
}

//Compare Match
#elif COMPARE_MATCH

void Timer_Init(){
	TCCR0 = (4<<CS0);
	TIMSK = (1 << OCIE0);
	OCR0 = 249;	//컴페어 매치를 250으로 만들때 카운트 증가시킨다.
}

//컴페어 매치의 인터럽트
ISR(TIMER0_COMP_vect){
	msec++;	//ms 증가
	//ms가 1000이 될때
	if(msec == 1000){	
		msec = 0; //msec를 0으로 초기화
		sec++; //sec 증가
	}
	//sec가 100이 될때
	if(sec == 100){
		sec = 0; //sec 0으로 초기화
	}
}

#endif


// USART 초기화 함수
void USART_Init(unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr >> 8); //0으로 초기화
	UBRR0L = (unsigned char)ubrr; //그대로 출력
	UCSR0B =(1<<RXEN0) | (1<<TXEN0); //송수신 가능
    //0000 0000 0000 0011 -> 0000 0000 0000 1100 char size 12로 설정
	UCSR0C = (3<< UCSZ0); 
	
}


// USART 데이터 전송 함수
void USART_Transmit(char data){
	while(!((UCSR0A)&(1<<UDRE0))); //입력이 안들어오면 반복
	UDR0 = data; //UDR0에 데이터 저장
}

// USART 문자열 전송 함수
void USART_Transmit_String(char *str){
	//문자열이 null이 될때 까지
	while(*str != '\0'){
		USART_Transmit(*str++); // 문자 출력
	}
}

int main(void)
{
    USART_Init(MYUBRR); //USART 초기화
	Timer_Init(); //타이머 활성화

    int save_sec = 0; 
    int flag1 = 0;  //버튼 1 flag 변수
    int flag2 = 0; //버튼 2 flag 변수
    DDRC = 0x00;   //입력 포트 C로 설정
    SREG = 0x80; //전역 인터럽트 활성화

    while (1)
    {
        //버튼 1을 누를때
        if ((PINC & 0x01) == 0x01)
        {   
            //flag1의 상태가 0일때
            if (flag1 == 0)
            {   
                flag1 = 1; //flag1을 1로 전환
            }
            //flag1의 상태가 1일때
            else if (flag1 == 1)
            {
                flag1 = 2;  //flag1을 2로 전환
            }
            //flag1dml 상태가 2일때
            else
            {
                flag1 = 1; //flag1을 1로 전환
            }
            _delay_ms(500); //500ms 딜레이
        }

        //버튼 2를 누르면 초기화
        else if ((PINC & 0x02) == 0x02)
        {
            sec = 0; //시간 초기화
			
        }

        //버튼 3
        else if ((PINC & 0X04) == 0X04)
        {
            //flag2의 상태가 0일때
            if (flag2 == 0)
            {
                flag2 = 1; //flag2를 1로 전환
            }
            //flag2의 상태가 1일때
            else
            {
                flag2 = 0; //flag2를 0으로 전환
            }
			_delay_ms(500); //500ms 딜레이
        }

        //스위치1 첫번째 상태
        //타이머 초기화
        if (flag1 == 0)
        {
            sec = 0;
        }
        //스위치1 두번째 상태
        //타이머 시작
        else if (flag1 == 1)
        {
            //스위치3 첫번째 상태
            if (flag2 == 0)
            {
                USART_Transmit_String("Timer : ");	
		        USART_Transmit(sec/10 + 48);	//10의 자리수 아스키코드로 변환해서 USART 출력
		        USART_Transmit(sec%10 + 48);	//1의 자리수 아스키코드로 변환해서 USART 출력
		        USART_Transmit('\r');	//명령어 종료
                save_sec = sec; //save_sec의 현재 시간 저장
            }
            //스위치3 두번째 상태 (첫번째 상태 출력 유지)
            else if (flag2 == 1)
            {
            }
        }
        //스위치1 세번째 상태
        //타이머 정지
        else if (flag1 == 2)
        {

            sec = save_sec; //save_sec에 저장되어있던 시간을 sec에 저장
        }
        _delay_ms(300); //300ms 딜레이
    }
}
