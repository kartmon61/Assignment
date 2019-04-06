#include<iostream>
#include<string>

using namespace std;

int main()
{
	
		string id, pass;
		string fid, fpass;

		cout << "아이디 등록 : ";
		cin >> id;
		cout << "패스워드 등록 : ";
		cin >> pass;

		while (1)
		{
			cout << "아이디 입력 : ";
			cin >> fid;
			cout << "패스워드 입력 : ";
			cin >> fpass;

			if (fid == id && fpass == pass)
			{
				cout << "로그인 성공! " << endl; break;
			}
			else cout << "로그인 실패! " << endl;

		}
		

	
	system("pause");
}