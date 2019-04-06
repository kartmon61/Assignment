#include<iostream>
#include<cstring>
#include<istream>

using namespace std;

int main()
{
	int i = 0;
	int cnt = 0;
	char a[10000];
	cout << "문자열 입력: ";
	cin.getline(a, 10000);

	char b;
	cout << "검색할 문자 : ";
	cin >> b;

	while (a[i] != NULL)
	{
		if (a[i] == b)
		{
			cnt++;
		}

		i++;
	}

	cout << "문자열 갯수 : " << cnt << endl;
	
	system("pause");
}