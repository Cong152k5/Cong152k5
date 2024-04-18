#include <iostream>
#include <vector>
#include <ctime>
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include "Dethi.h"

using namespace std;

int main() {
    // Kh?i t?o ng?u nhiên
    srand(time(NULL));

    // ?i?m ban ??u
    int diem = 0;

    // Hi?n th? thông tin
    cout << "Chuong trinh do vui voi bieu thuc so hoc!" << endl;

    // Vòng l?p chính
    while (true) {
        // Hi?n th? ?i?m và c?p ??
        cout << "Diem hien tai: " << diem << endl;
        cout << "Cap do: ";
        int capdo = diem / 3 + 1;
        cout << capdo << endl;

        // T?o ?? thi v?i s? l??ng câu h?i t?ng d?n theo c?p ??
        Dethi deThi(capdo, capdo, capdo, capdo);

        // L?y danh sách câu h?i
        vector<Bieuthuc> dsCauHoi = deThi.danhsach();

        // L?p qua t?ng câu h?i
        for (int i = 0; i < dsCauHoi.size(); ++i) {
            // Hi?n th? câu h?i
            cout << "Cau hoi " << i + 1 << ": " << dsCauHoi[i] << endl;

            // Nh?p câu tr? l?i
            cout << "Nhap cau tra loi: ";
            float cauTraLoi;
            cin >> cauTraLoi;

            // Ki?m tra câu tr? l?i
            if (dsCauHoi[i].kiemtra(cauTraLoi)) {
                cout << "Dap an dung!" << endl;
                // T?ng ?i?m
                diem++;
            }
            else {
                cout << "Dap an sai!" << endl;
                // Gi?m ?i?m
                diem = max(0, diem - 1);
            }
        }

        // Ki?m tra xem ng??i ch?i mu?n ti?p t?c không
        cout << "Ban co muon choi tiep khong? (Y/N): ";
        char tieptuc;
        cin >> tieptuc;
        if (tieptuc != 'Y' && tieptuc != 'y') {
            break;
        }
    }

    cout << "Diem cuoi cung cua ban la: " << diem << endl;

    return 0;
}
