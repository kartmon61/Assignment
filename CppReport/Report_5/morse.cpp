#include "morse.h"

//생성자 초기화
Morse::Morse() {
	string alphabet[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
	"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
	"..-","...-",".--","-..-","-.--","--.." };

	string digit[10] = { "-----",".----","..--","...--","....-",".....",
	"-....","--...","---..","----." };

	for (int i = 0; i < 26; i++) {
		this->alphabet[i] = alphabet[i];
	}

	for (int i = 0; i < 10; i++) {
		this->digit[i] = digit[i];
	}

	this->slash = "-..-.";
	this->question = "..-..";
	this->comma = "--..--";
	this->period = ".-.-.-";
	this->plus = ".-.-.";
	this->equal = "-...-";
}

//문자열을 모스부호로 변환하는 함수
void Morse::text2Morse(string text, string& morse) {

	morse = "";
	//문자열의 문자를 각각 모스부호로 변환하여 morse문자열에 추가
	for (unsigned int i = 0; i < text.length(); i++) {

		if (text[i] >= 97 && text[i] < 123) {
			morse += alphabet[text[i] - 97] + " ";
		}
		else if (text[i] >= 65 && text[i] < 91) {
			morse += alphabet[text[i] - 65] + " ";
		}
		else if (text[i] >= 48 && text[i] < 58) {
			morse += digit[text[i] - 48] + " ";
		} 
		else if (text[i] == '/') {
			morse += slash + " ";
		}
		else if (text[i] == '?') {
			morse += question + " ";
		}
		else if (text[i] == ',') {
			morse += comma + " ";
		}
		else if (text[i] == '.') {
			morse += period + " ";
		}
		else if (text[i] == '+') {
			morse += plus + " ";
		}
		else if (text[i] == '=') {
			morse += equal + " ";
		}
		else if (text[i] == ' ') {
			morse += "  ";
		}

	}

}

//모스 부호를 문자열로 반환하는 함수
bool Morse::morse2Text(string morse, string& text) {
	string morse1;
	text2Morse(text, morse1);
	//입력한 문자열의 값이 모스부호의 문자열과 같다면 true 값 반환 
	if (morse1 == morse) return true;
	//아니라면 false 값 반환
	else return false;
}
