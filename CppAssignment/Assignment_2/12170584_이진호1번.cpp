#include<iostream>
#include<string>

using namespace std;

int main()
{
	
		string id, pass;
		string fid, fpass;

		cout << "���̵� ��� : ";
		cin >> id;
		cout << "�н����� ��� : ";
		cin >> pass;

		while (1)
		{
			cout << "���̵� �Է� : ";
			cin >> fid;
			cout << "�н����� �Է� : ";
			cin >> fpass;

			if (fid == id && fpass == pass)
			{
				cout << "�α��� ����! " << endl; break;
			}
			else cout << "�α��� ����! " << endl;

		}
		

	
	system("pause");
}