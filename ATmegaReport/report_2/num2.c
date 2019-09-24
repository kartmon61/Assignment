과제 2번

#define F_CPU 16000000UL //16MHz 설정
#define BAUD 9600 //9600bfs 설정
#define MYUBRR F_CPU/16/BAUD-1 //UBRR 계산

#include <util/delay.h>
#include <avr/io.h>


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

// USART 데이터 수신 함수
char USART_Receive(){
	while(!(UCSR0A &(1<<RXC0))); //입력이 안들어오면 반복
	return UDR0; //UDR0 반환 
}

//메인 함수
int main(void)
{
	DDRF=0x00; //PORTF를 INPUT으로 설정
	DDRA=0xFF; //PORTA를 OUTPUT으로 설정
	USART_Init(MYUBRR); //UBRR 초기화
	char showPIN; 
	
	while (1)
	{
        //PINA에 입력이 들어왔을 때
		if(PINA){ 
			PORTF=PINA; //PINA의 입력 값을 포트F의 핀에 출력

            //PINA의 입력 값에 맞는 값을 showPIN에 저장
			switch(PINA){
				case 0x01:
					showPIN='1'; break;
				case 0x02:
					showPIN='2'; break;	
				case 0x04:
					showPIN='3'; break;
				case 0x08:
					showPIN='4'; break;
				case 0x10:
					showPIN='5'; break;
				case 0x20:
					showPIN='6'; break;
				case 0x40:
					showPIN='7'; break;
				case 0x80:
					showPIN='8'; break;
			}

			USART_Transmit(showPIN); //showPIN의 값을 시리얼 모니터에 출력
		}
		_delay_ms(100); //0.1초 딜레이
	}
}
