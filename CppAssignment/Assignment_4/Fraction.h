#include<iostream>

using namespace std;

class Fraction {
public:
	Fraction();
	Fraction(int d);
	Fraction(int n, int d);
private:
	int numerator;
	int denominator;
public:
	void addFraction(Fraction,Fraction);
	void subFraction(Fraction, Fraction);
	void mulFraction(Fraction, Fraction);
	void divFraction(Fraction, Fraction);
	void printFraction(int,int);
}; 

