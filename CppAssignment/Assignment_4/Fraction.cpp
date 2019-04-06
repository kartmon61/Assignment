#include "Fraction.h"

Fraction::Fraction()
	:numerator(1),denominator(1)
{

}

Fraction::Fraction(int d)
	: numerator(1), denominator(d)
{

}

Fraction::Fraction(int n, int d)
	: numerator(n), denominator(d)
{

}

void Fraction::addFraction(Fraction a,Fraction b)
{
	int bunja = ((a.numerator*b.denominator) + (b.numerator*a.denominator));
	int bunmo = (a.denominator*b.denominator);

	printFraction(a.numerator, a.denominator);
	cout << "+";
	printFraction(b.numerator, b.denominator);
	cout << "=";
	printFraction(bunja, bunmo);
	cout << endl;
}

void Fraction::subFraction(Fraction a, Fraction b)
{
	int bunja = ((a.numerator*b.denominator) - (b.numerator*a.denominator));
	int bunmo = (a.denominator*b.denominator);

	printFraction(a.numerator, a.denominator);
	cout << "-";
	printFraction(b.numerator, b.denominator);
	cout << "=";
	printFraction(bunja, bunmo);
	cout << endl;
}

void Fraction::mulFraction(Fraction a, Fraction b)
{
	int bunja = (a.numerator*b.numerator) ;
	int bunmo = (a.denominator*b.denominator);

	printFraction(a.numerator, a.denominator);
	cout << "*";
	printFraction(b.numerator,b.denominator);
	cout << "=";
	printFraction(bunja, bunmo);
	cout << endl;
	

}

void Fraction::divFraction(Fraction a, Fraction b)
{
	int bunja = (a.numerator*b.denominator);
	int bunmo = (a.denominator*b.numerator);

	printFraction(a.numerator, a.denominator);
	cout << "/";
	printFraction(b.numerator, b.denominator);
	cout << "=";
	printFraction(bunja, bunmo);
	cout << endl;
}

void Fraction::printFraction(int a,int n)
{
	cout << a << "/" << n;
}