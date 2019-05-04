#include<iostream>
#include<cstring>
#include<istream>

using namespace std;

int main()
{
	string a = "yes";
	char b[100];
	cout << "종료하고 싶으면 yes를 입력하세요 : ";
	cin.getline(b, 100);

	while (a != b)
	{
		cout << "종료하고 싶으면 yes를 입력하세요 : ";
		cin.getline(b, 100);
	}
	
	cout << "종료합니다." << endl;


	system("pause");
}