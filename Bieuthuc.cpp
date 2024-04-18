#include"Bieuthuc.h"
#include<iostream>
using namespace std;

Bieuthuc::Bieuthuc(int level)
{
    srand(time(0));
    switch (level)
    {
    case 1:
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        pheptoan = '+';
        break;
    case 2:
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
        break;
    case 3:
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        pheptoan = (rand() % 3 == 0) ? '+' : ((rand() % 2 == 0) ? '-' : '*');
        break;
    case 4:
        a = rand() % 91 + 10; // 10 <= a,b <= 100
        b = rand() % 91 + 10;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
        break;
    default:
        a = rand() % 91 + 10; // 10 <= a,b <= 100
        b = rand() % 91 + 10;
        pheptoan = (rand() % 3 == 0) ? '+' : ((rand() % 2 == 0) ? '-' : '*');
        break;
    }
}

ostream& operator<<(ostream& out, Bieuthuc bt)
{
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

bool Bieuthuc::kiemtra(float traloi)
{
    float result = giatri();
    return result == traloi;
}

float Bieuthuc::giatri()
{
    switch (pheptoan)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        return 0;
    }
}