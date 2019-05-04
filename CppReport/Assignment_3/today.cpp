#include<iostream>
#include<string>

using namespace std;

class today {
public:
	explicit today()
	{
		print();
		print1();
	}
	explicit today(int month, int day)
		:month(month), day(day)
	{
		print();
		print1();
	}
	explicit today(int day)
		:day(day)
	{
		print();
		print1();
	}

private:
	int year = 2019;
	int month = 3;
	int day = 22;

public:
	void print()
	{
		cout << year << "³â " << month << "¿ù " << day << endl;
		
	}
	void print1()
	{
		cout << month << "¿ù " << day << endl;
		cout << "\n";
	}


};

int main()
{

	today a;
	today b(4, 20);
	today c(13);


	system("pause");
}