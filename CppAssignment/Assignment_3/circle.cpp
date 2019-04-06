#include<iostream>
#include<string>

#define PI  3.14
using namespace std;

class circle {

private:
	int radius = 3;
	string color = "초록색";

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
		cout <<"원의 색상은 "<< color <<"입니다." << endl;
	}


};



int main()

{
	circle a;
	cout << "원의 넓이는 " << a.result1() << "입니다."<<endl;
	cout << "원의 지름은 " << a.result2() << "입니다." << endl;
	a.print();

	system("pause");

}