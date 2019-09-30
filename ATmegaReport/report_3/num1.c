void USART_clear(){
	USART_Transmit("$C"); //lcd의 화면을 클리어
	USART_Transmit_String("$G,1,1\r");	//lcd의 커서를 1,1로 지정
	USART_Transmit_String("$T,");	//문자열 출력
}