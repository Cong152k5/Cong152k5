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
    // Kh?i t?o ng?u nhi�n
    srand(time(NULL));

    // ?i?m ban ??u
    int diem = 0;

    // Hi?n th? th�ng tin
    cout << "Chuong trinh do vui voi bieu thuc so hoc!" << endl;

    // V�ng l?p ch�nh
    while (true) {
        // Hi?n th? ?i?m v� c?p ??
        cout << "Diem hien tai: " << diem << endl;
        cout << "Cap do: ";
        int capdo = diem / 3 + 1;
        cout << capdo << endl;

        // T?o ?? thi v?i s? l??ng c�u h?i t?ng d?n theo c?p ??
        Dethi deThi(capdo, capdo, capdo, capdo);

        // L?y danh s�ch c�u h?i
        vector<Bieuthuc> dsCauHoi = deThi.danhsach();

        // L?p qua t?ng c�u h?i
        for (int i = 0; i < dsCauHoi.size(); ++i) {
            // Hi?n th? c�u h?i
            cout << "Cau hoi " << i + 1 << ": " << dsCauHoi[i] << endl;

            // Nh?p c�u tr? l?i
            cout << "Nhap cau tra loi: ";
            float cauTraLoi;
            cin >> cauTraLoi;

            // Ki?m tra c�u tr? l?i
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

        // Ki?m tra xem ng??i ch?i mu?n ti?p t?c kh�ng
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
