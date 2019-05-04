#include "Fraction.h"

int main()
{
	
	Fraction a(1, 2);
	Fraction b(1, 3);

	a.addFraction(a, b);
	a.subFraction(a, b);
	a.mulFraction(a, b);
	a.divFraction(a, b);

	
	system("pause");

}