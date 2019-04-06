#include<iostream>
#include<string>

using namespace std;

class student {
public:
	explicit student()
		:depart("전자공학과"),name("홍길동"),num(12345)
	{
		print();
	}
	explicit student(string name,int num)
		:depart("전자공학과"), name(name), num(num)
	{
		print();
	}
	explicit student(string name)
		:depart("전자공학과"), name(name), num(12345)
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

		cout << "학과 : " << depart << endl;
		cout << "학생이름 : " << name << endl;
		cout << "학번 : " << num << endl;
		cout << "\n";
	}


};

int main()
{

	student a;
	student b("홍길순", 54353);
	student c("김길동");


	system("pause");
}