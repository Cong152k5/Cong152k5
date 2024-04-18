#include "BieuthucPT.h"
#include <cstdlib>
#include <ctime>

BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
    srand(time(NULL));

    // Sinh ngẫu nhiên dữ liệu cho toán hạng thứ hai và phép toán thứ hai
    switch (level) {
    case 1:
    case 2:
    case 3:
        c = rand() % 10 + 1;
        d = rand() % 10 + 1;
        pheptoan2 = rand() % 3 == 0 ? '+' : (rand() % 2 == 0 ? '-' : '*');
        break;
    case 4:
    case 5:
        c = rand() % 91 + 10;
        d = rand() % 91 + 10;
        pheptoan2 = rand() % 3 == 0 ? '+' : (rand() % 2 == 0 ? '-' : '*');
        break;
    default:
        break;
    }
}

ostream& operator<<(ostream& out, BieuthucPT bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b << " " << bt.pheptoan2 << " " << bt.c << " " << bt.d << " = ?";
    return out;
}

bool BieuthucPT::kiemtra(float traloi) {
    float result;
    switch (pheptoan2) {
    case '+':
        result = giatri() + (c + d);
        break;
    case '-':
        result = giatri() - (c + d);
        break;
    case '*':
        result = giatri() * (c * d);
        break;
    default:
        result = 0;
        break;
    }
    return result == traloi;
}

float BieuthucPT::giatri() {
    float result;
    switch (pheptoan) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}
