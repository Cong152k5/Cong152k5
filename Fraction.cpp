#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

Fraction::Fraction(int num = 0, int den = 1) {
    if (den == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        numerator = num;
        denominator = den;
        simplify();
    }
}

Fraction::Fraction(int random) {
    numerator = rand() % (random + 1);
    denominator = rand() % (random + 1);
    if (denominator == 0)
        denominator = 1;
    simplify();
}

void Fraction::simplify() {
    int gcd = findGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << '/' << frac.denominator;
    return os;
}
