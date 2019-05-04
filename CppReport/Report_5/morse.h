
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
	//������ �ʱ�ȭ
	Morse();
	//���ڿ��� �𽺺�ȣ�� ��ȯ�ϴ� �Լ�
	void text2Morse(string text, string& morse);
	//�𽺺�ȣ�� ���ڿ��� ��ȯ�ϴ� �Լ�
	bool morse2Text(string morse, string& text);
};