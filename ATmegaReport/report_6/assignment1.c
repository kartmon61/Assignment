/*
 * pwm.c
 *
 * Created: 2019-11-06 오전 11:07:12
 * Author : hp
 */ 

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

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

void USART_Receive_String(char *str)
{
   int i = 0;
   for(i = 0; str[i-1] != '\r' ;i++)
   {
      str[i] = USART_Receive();
   }
   str[i] = '\0';
}

void Timer_Init(){
   TCCR0 =( 1 << WGM00 ) | (1 << WGM01 ) | ( 1 <<COM01) | ( 4 << CS0); 
   //Fast PWM 모드 설정
   //5번 1번 => 비반전 비교 출력 모드 , CS0 에 4번 초기화
   TIMSK = (1 << OCIE0); 
}

int main(void)
{
   char str[3]; //문자열 저장
   int num[3]; //숫자 저장
   int result = 0; 
   int n = 1;
   USART_init(MYUBRR); //USART 초기화
   Timer_Init(); //Timer 초기화
   DDRB = 0xFF; //B를 출력 포트로 설정
   int i;
   
    while (1) 
    {
      result = 0; //result 입력값 초기화
      str[3] = NULL; //문자열 초기화
      n=1; //n값 초기화
      USART_Receive_String(str); //문자열 입력
      USART_Transmit_String(str); //USART에 문자열 출력
      int length = strlen(str); //문자열 길이 저장
      //숫자를 1의자리 수부터 문자열 길이 만큼 순서대로 저장
      for(i=0;i<length;i++){
         num[length-i-1] = str[i]-48; 
      }
      //1의 자리 수부터 역으로 가져와 result에 입력값 저장
      for(i=0;i<length;i++){
         result += n*num[i];
         n*=10;
      }
      _delay_ms(1000); //delay 1000ms
      OCR0 = result; //result의 값에 따른 모터 이동
    }
}
