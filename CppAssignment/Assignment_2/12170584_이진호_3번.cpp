#include<iostream>
#include<cstring>
#include<istream>

using namespace std;

int main()
{
	string a = "yes";
	char b[100];
	cout << "�����ϰ� ������ yes�� �Է��ϼ��� : ";
	cin.getline(b, 100);

	while (a != b)
	{
		cout << "�����ϰ� ������ yes�� �Է��ϼ��� : ";
		cin.getline(b, 100);
	}
	
	cout << "�����մϴ�." << endl;


	system("pause");
}