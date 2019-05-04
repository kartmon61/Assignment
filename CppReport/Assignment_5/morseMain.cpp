#include "morse.h"


int main() {

	string text;
	string morse;

	cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 변환됩니다."<< endl;
	getline(cin, text);

	//객체 생성
	Morse m;
	//문자열을 모스 부호로 출력
	m.text2Morse(text, morse);
	cout << morse << endl;
	cout << "모스 부호를 다시 영문 텍스트로 변환합니다." << endl;
	
	//모스 부호를 문자열로 출력
	if (m.morse2Text(morse, text)) cout << text << endl;
	else cout << "모스 부호가 도중에 변경 되었습니다." << endl;

	system("pause");

}