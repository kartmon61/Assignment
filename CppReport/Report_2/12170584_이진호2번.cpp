#include<iostream>
#include<cstring>
#include<istream>

using namespace std;

int main()
{
	int i = 0;
	int cnt = 0;
	char a[10000];
	cout << "���ڿ� �Է�: ";
	cin.getline(a, 10000);

	char b;
	cout << "�˻��� ���� : ";
	cin >> b;

	while (a[i] != NULL)
	{
		if (a[i] == b)
		{
			cnt++;
		}

		i++;
	}

	cout << "���ڿ� ���� : " << cnt << endl;
	
	system("pause");
}