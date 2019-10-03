#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#define COMPARE_MATCH 1 //타이머 모드 설정

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned int msec, sec; //타이머 글로벌 변수


//Over flow
#ifdef OVER_FLOW

void Timer_Init(){
    TCCR0 = (4<<CS0);   //프리스케일러의 타이머 0에서 64로 설정
    TIMSK = (1<<T0IE0); //오버플로우 인터럽트 활성화
    TCNT0 = 6;  //포인트 카운터의 스타팅 포인터를 6으로 지정
}

//타이머 오버플로우의 인터럽트 
ISR(TIMER0_0VF_vect){  
    msec++;
    if(msec == 1000){
        msec = 0;
        sec++;
    }
    if(sec == 100){
        sec = 0;
    }
    TCNT0 = 6;  //TCNT0 초기화
}

//Compare Match
#elif COMPARE_MATCH

void Timer_Init(){
    TCCR0 = (4<<CS0);
    TIMSK = (1 << 0CIE0);
    0CR0 = 249;
}

//컴페어 매치의 인터럽트
ISR(TIMER0_COMP_vect){
    msec++;
    if(msec == 1000){
        msec = 0;
        sec++;
    }
    if(sec == 100){
        sec = 0;
    }
}

#endif





void USART_Init(unsigned int ubrr){
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = ( 1<< RXEN0) | (1<<TXEN0);
    UCSR0C = (3<<UCSZ0);
}

void USART_Transmit(char data){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

void USART_Transmit_String(char *str){
    while(*str != '\0'){
        USART_Transmit(*str++);
    }
}

int main(void){
    USART_Init(MYUBRR);
    Timer_Init();
    SREG = 0x80;    //전역 인터럽트 활성화

    while(1){
        USART_Transmit_String("Timer : ");
        USART_Transmit(sec/10 + 48);
        USART_Transmit(sec%10 + 48);
        USART_Transmit('\r');
        _delay_ms(300);
    }
}