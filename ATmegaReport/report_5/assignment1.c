//USART Interrupt를 이용하여 LED On/Off

#define F_CPU 16000000UL    //16MHz 설정
#define BAUD 9600   //9600bfs 설정
#define MYUBRR F_CPU/16/BAUD-1  //UBRR 계산

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int msec=0, sec=0;  //타이머 글로벌 변수

//USART 초기화 함수
void USART_init(unsigned int ubrr) 		
{
	UBRR0H = (unsigned char)(ubrr >> 8); //0으로 초기화
	UBRR0L = (unsigned char) ubrr; //그대로 출력
	UCSR0B = (1 << RXEN0) | (1 << TXEN0); //송수신 가능
    //0000 0000 0000 0011 -> 0000 0000 0000 1100 char size 12로 설정
	UCSR0C = (3 << UCSZ0); 
}

//USART 데이터 전송 함수
void USART_Transmit(char data)			
{
	while (!(UCSR0A & (1 << UDRE0))); //입력이 안들어오면 반복
	UDR0 = data; //UDR0에 데이터 저장
}

//USART 문자열 전송 함수
void USART_Transmit_String(char *str)		
{   
    //문자열이 NULL이 될때 까지
	while( *str !='\0')
	{
		USART_Transmit(*str++); //문자 출력
	}
}

//USART 데이터 수신 함수
char USART_Receive()				
{
	while (!(UCSR0A & (1 << RXC0))); //입력이 안들어오면 반복
	return UDR0; //UDR0 반환
}

//타이머 초기화 함수
void timer_init(){				
	TCCR0=(4<<CS0); //프리스케일러의 타이머 0에서 64로 설정
	TIMSK=(1<<OCIE0); //컴페어매치 인터럽트 활성화
	OCR0=249; //컴페어 매치를 250으로 만들때 카운터를 증가시킨다.
}

//인터럽트 초기화 함수
void Interrupt_Init()			
{
	EIMSK = (1 << INT0) | (1 << INT1);    	//외부 인터럽트 0 과 1을 허용
	EICRA = (1 << ISC01) | (1 << ISC11);	//INT0 또는 1 핀 입력의 하강 상승 에지에서 인터럽트 발생
}

//ISR 컴페어 매치의 인터럽트
ISR(TIMER0_COMP_vect){			
	msec++; //ms 증가
    //msec가 1000이 될때
	if(msec == 1000){
		msec=0; //msec를 0으로 초기화
		sec++; //sec 1 증가
	}
    //sec가 100이 될때
	if(sec == 100){
		sec=0; //sec 0으로 초기화
	}
}

//인터럽트 INT0 발생 할때
ISR(INT0_vect)			
{
	TIMSK = 0;	//입력값 0이 들어왔을때 동작
	PORTA = 0Xff; //PORT A의 모든 핀 HIGH로 전환
}

//인터럽트 INT1 발생 할때
ISR(INT1_vect)			
{
	TIMSK = (1<<OCIE0); //컴페어 매치 인터럽트 활성화
	PORTA = 0x00; //PORT A의 모든 핀 LOW로 전환
}

int main(void)
{
	int a, b;
	
	DDRA = 0xFF; //PORTA 를 출력으로 설정
	DDRD = 0x00; //PORTD 를 입력으로 설정
	
	USART_init(MYUBRR); //USART 초기화
	timer_init(); //타이머 초기화
	Interrupt_Init(); //인터럽트 실행
	
	USART_Transmit_String("Timer: "); //USART에 "Timer: "출력
	_delay_ms(10); //딜레이 10ms
	SREG = 0x80; //전역 인터럽트 활성화
	
    while (1) 
    {
		a = sec/10 + 48; //10의 자리 값 저장
		b = sec%10 + 48; //1의 자리 값 저장
		USART_Transmit_String("Timer : ");
		USART_Transmit(a); //a 출력
		USART_Transmit(b); //b 출력
		USART_Transmit('\r'); //명령 종료
		_delay_ms(100);	//딜레이 100ms	
    }
}