#include "morse.h"


int main() {

	string text;
	string morse;

	cout << "�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� ��ȯ�˴ϴ�."<< endl;
	getline(cin, text);

	//��ü ����
	Morse m;
	//���ڿ��� �� ��ȣ�� ���
	m.text2Morse(text, morse);
	cout << morse << endl;
	cout << "�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� ��ȯ�մϴ�." << endl;
	
	//�� ��ȣ�� ���ڿ��� ���
	if (m.morse2Text(morse, text)) cout << text << endl;
	else cout << "�� ��ȣ�� ���߿� ���� �Ǿ����ϴ�." << endl;

	system("pause");

}