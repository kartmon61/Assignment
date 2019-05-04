#include<iostream>

using namespace std;

class bun {

public:
	explicit bun()
		:bunja(1), bunmo(3)
	{
		print();
	}
	explicit bun(int a)
		:bunja(a), bunmo(3)
	{
		print();
	}
	explicit bun(int a, int b)
		:bunja(a), bunmo(b)
	{
		print();
	}
private:
	int bunja;
	int bunmo;


public:
	void print()
	{
		cout << bunja << "/" << bunmo << endl;
	}

};

int main()
{
	bun a;
	bun b(2);
	bun c(4, 5);

	system("pause");
}