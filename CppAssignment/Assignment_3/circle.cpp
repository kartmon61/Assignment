#include<iostream>
#include<string>

#define PI  3.14
using namespace std;

class circle {

private:
	int radius = 3;
	string color = "�ʷϻ�";

public:
	int result1()
	{
		return radius * radius;
	}
	double result2()
	{
		return 2 * PI*radius;
	}
	void print()
	{
		cout <<"���� ������ "<< color <<"�Դϴ�." << endl;
	}


};



int main()

{
	circle a;
	cout << "���� ���̴� " << a.result1() << "�Դϴ�."<<endl;
	cout << "���� ������ " << a.result2() << "�Դϴ�." << endl;
	a.print();

	system("pause");

}