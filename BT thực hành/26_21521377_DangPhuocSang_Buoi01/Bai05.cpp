#include <iostream>
using namespace std;

typedef struct HocSinh
{
    string Hoten;
    double toan, van, TB;
} HS;

void Nhap(HS &a)
{
    cout << "Nhap thong tin hoc sinh:" << endl;
    cout << "Nhap ho va ten: ";
    getline(cin,a.Hoten);
    cout << "Nhap diem toan: ";
    cin >> a.toan;
    cout << "Nhap diem van: ";
    cin >> a.van;
    a.TB = (a.toan + a.van) / 2;
}

void Xuat(HS a)
{
    cout << "Thong tin hoc sinh:" << endl;
    cout << "Ho va ten: " << a.Hoten << endl;
    cout << "Diem toan: " << a.toan << endl;
    cout << "Diem van: " << a.van << endl;
    cout << "Diem trung binh: " << a.TB << endl;
}

int main()
{
    HS a;
    Nhap(a);
    Xuat(a);
    return 0;
}
