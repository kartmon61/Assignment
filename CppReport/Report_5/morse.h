
#include<iostream>
#include<string>

using namespace std;

class Morse {
private:
	string alphabet[26];

	string digit[10];

	string
		slash, question, comma, period, plus, equal;

public:
	//생성자 초기화
	Morse();
	//문자열을 모스부호로 변환하는 함수
	void text2Morse(string text, string& morse);
	//모스부호를 문자열로 반환하는 함수
	bool morse2Text(string morse, string& text);
};