#include<iostream>
#include<string>

using namespace std;

class student {
public:
	explicit student()
		:depart("���ڰ��а�"),name("ȫ�浿"),num(12345)
	{
		print();
	}
	explicit student(string name,int num)
		:depart("���ڰ��а�"), name(name), num(num)
	{
		print();
	}
	explicit student(string name)
		:depart("���ڰ��а�"), name(name), num(12345)
	{
		print();
	}

private:
	string depart;
	string name;
	int num;

public:
	void print()
	{

		cout << "�а� : " << depart << endl;
		cout << "�л��̸� : " << name << endl;
		cout << "�й� : " << num << endl;
		cout << "\n";
	}


};

int main()
{

	student a;
	student b("ȫ���", 54353);
	student c("��浿");


	system("pause");
}