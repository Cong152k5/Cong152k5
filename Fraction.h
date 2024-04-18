#pragma once
#include <iostream>

using namespace std;
class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:
	Fraction(int, int);
	Fraction(int);
	void simplify();
	int findGCD(int a, int b);
	friend ostream& operator<<(ostream& os, const Fraction& frac);
};

