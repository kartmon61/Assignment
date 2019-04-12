#include "morse.h"

//������ �ʱ�ȭ
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

//���ڿ��� �𽺺�ȣ�� ��ȯ�ϴ� �Լ�
void Morse::text2Morse(string text, string& morse) {

	morse = "";
	//���ڿ��� ���ڸ� ���� �𽺺�ȣ�� ��ȯ�Ͽ� morse���ڿ��� �߰�
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

//�� ��ȣ�� ���ڿ��� ��ȯ�ϴ� �Լ�
bool Morse::morse2Text(string morse, string& text) {
	string morse1;
	text2Morse(text, morse1);
	//�Է��� ���ڿ��� ���� �𽺺�ȣ�� ���ڿ��� ���ٸ� true �� ��ȯ 
	if (morse1 == morse) return true;
	//�ƴ϶�� false �� ��ȯ
	else return false;
}
