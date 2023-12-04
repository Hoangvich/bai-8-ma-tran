#include <iostream>
#include <vector>

using namespace std;

// Nhập ma trận có kích thước n * m
void nhapMaTran(vector<vector<int>>& matran, int n, int m) {
    cout << "Nhap ma tran " << n << "x" << m << ":\n";
    for (int i = 0; i < n; ++i) {
        vector<int> hang_ngang;
        for (int j = 0; j < m; ++j) {
            int giaTri;
            cout << "Nhap phan tu tai vi tri [" << i << "][" << j << "]: ";
            cin >> giaTri;
            hang_ngang.push_back(giaTri);
        }
        matran.push_back(hang_ngang);
    }
}

// Hiển thị ma trận
void hienThiMaTran(const vector<vector<int>>& matran) {
    cout << "Ma tran da nhap:\n";
    for (const auto& hang_ngang : matran) {
        for (int gia_tri : hang_ngang) {
            cout << gia_tri << "\t";
        }
        cout << endl;
    }
}

// Tìm phần tử có giá trị nhỏ nhất trong ma trận
int timPhanTuNhoNhat(const vector<vector<int>>& matran) {
    int gia_tri_nho_nhat = matran[0][0];
    for (const auto& hang_ngang : matran) {
        for (int gia_tri : hang_ngang) {
            if (gia_tri < gia_tri_nho_nhat) {
                gia_tri_nho_nhat = gia_tri;
            }
        }
    }
    return gia_tri_nho_nhat;
}

// Tính tổng các phần tử trên 1 cột của ma trận
int tinhTongCot(const vector<vector<int>>& matran, int cot) {
    int tong = 0;
    for (const auto& hang_ngang : matran) {
        tong += hang_ngang[cot];
    }
    return tong;
}

// Liệt kê các phần tử dương có trong ma trận
void lietKePhanTuDuong(const vector<vector<int>>& matran) {
    cout << "Cac phan tu duong trong ma tran:\n";
    for (const auto& hang_ngang : matran) {
        for (int gia_tri : hang_ngang) {
            if (gia_tri > 0) {
                cout << gia_tri << "\t";
            }
        }
    }
    cout << endl;
}

// Đếm số phần tử âm trong ma trận
int demSoPhanTuAm(const vector<vector<int>>& matran) {
    int dem_phan_tu_am = 0;
    for (const auto& hang_ngang : matran) {
        for (int gia_tri : hang_ngang) {
            if (gia_tri < 0) {
                dem_phan_tu_am++;
            }
        }
    }
    return dem_phan_tu_am;
}

int main() {
    int n, m;
    cout << "Nhap so hang: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;

    vector<vector<int>> matran;
    nhapMaTran(matran, n, m);
    hienThiMaTran(matran);

    int gia_tri_nho_nhat = timPhanTuNhoNhat(matran);
    cout << "Phan tu nho nhat trong ma tran la: " << gia_tri_nho_nhat << endl;

    int cotCanTinh;
    cout << "Nhap cot can tinh tong: ";
    cin >> cotCanTinh;
    int tongCot = tinhTongCot(matran, cotCanTinh);
    cout << "Tong cac phan tu tren cot " << cotCanTinh << " la: " << tongCot << endl;

    lietKePhanTuDuong(matran);

    int soPhanTuAm = demSoPhanTuAm(matran);
    cout << "So phan tu am trong ma tran la: " << soPhanTuAm << endl;

    return 0;
}
