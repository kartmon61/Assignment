#include<iostream>
#include<string>
#include<random>
#include<ctime>

using namespace std;

int main() {
	//���� �Լ� ����
	default_random_engine engine(static_cast<unsigned int>(time(0)));

	//���� ascii �ڵ� ��ȣ �����ϴ� randomInt ����
	uniform_int_distribution<unsigned int>
		randomInt(97, 122);

	//���� ����
	string a;
	int point;

	//while�� ��� �ݺ�
	while (1) {
		cout << "���ڿ��� �Է��ϼ���" << endl;
		getline(cin, a);

		//���� a�� exit�� �ԷµǸ� while���� ���
		if (a == "exit") break;

		//���� ���ڿ��� ��ġ�� �����ϴ� randomInt2 ����
		uniform_int_distribution<unsigned int>
			randomInt2(0,a.length());

		//���� ���ڿ� ��ġ 
		point = randomInt2(engine);

		//���� ���ڿ� ��ġ�� ���� ���ڿ� ����
		a[point] = (char)randomInt(engine);

		//��ȯ�� ���ڿ� ���
		cout <<"��ȯ�� ���ڿ�: "<< a << endl;
	}
	
	system("pause");

}