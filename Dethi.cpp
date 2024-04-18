#include "Dethi.h"
using namespace std;
Dethi::Dethi(int n1, int n2, int n3, int level) {
    for (int i = 0; i < n1; ++i) ds.push_back(Bieuthuc(level));
    for (int i = 0; i < n2; ++i) ds.push_back(Bieuthuc(level + 1));
    for (int i = 0; i < n3; ++i) ds.push_back(Bieuthuc(level + 2));
}

void Dethi::xuat(ostream& output) {
    for (auto& bt : ds) {
        output << bt << " = ?" << std::endl;
    }
}

int Dethi::danhgia(istream& input) {
    int diem = 0;
    int traloi;
    for (auto& bt : ds) {
        cout << bt << " = ";
        input >> traloi;
        if (bt.kiemtra(traloi)) diem++;
    }
    return diem;
}
