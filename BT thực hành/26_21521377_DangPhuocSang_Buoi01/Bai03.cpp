#include <iostream>
using namespace std;

typedef struct PhanSo
{
    int tuSo, mauSo;
} PS;

void nhapPS(PS &a)
{
    cout << "Nhap tu so: ";
    cin >> a.tuSo;
    cout << "Nhap mau so: ";
    cin >> a.mauSo;
}

void xuatPS(PS a)
{
    if (a.mauSo == 1)
        cout << a.tuSo << endl;
    else
        cout << a.tuSo << "/" << a.mauSo << endl;
}

int UCLN(int x, int y)
{
    if (y == 0)
        return x;
    return UCLN(y, x % y);
}

int BCNN(int x, int y)
{
    return (x * y) / UCLN(x,y);
}

PS rutGon(PS a)
{
    int gcd = UCLN(a.tuSo, a.mauSo);
    a.tuSo /= gcd;
    a.mauSo /= gcd;
    if (a.mauSo < 0)
    {
        a = {-a.tuSo, -a.mauSo};
    }
    return a;
}

void quyDong(PS &a, PS &b)
{
    int k = BCNN(a.mauSo,b.mauSo);
    a.tuSo *= k/a.mauSo;
    a.mauSo = k;
    b.tuSo *= k/b.mauSo;
    b.mauSo = k;
}

PS Tong(PS a, PS b)
{
    quyDong(a,b);
    PS tong = {a.tuSo + b.tuSo, a.mauSo};
    rutGon(tong);
    return tong;
}

PS Hieu(PS a, PS b)
{
    quyDong(a,b);
    PS hieu = {a.tuSo - b.tuSo, a.mauSo};
    rutGon(hieu);
    return hieu;
}

PS Tich(PS a, PS b)
{
    PS tich = {a.tuSo * b.tuSo, a.mauSo * b.mauSo};
    rutGon(tich);
    return tich;
}

PS Thuong(PS a, PS b)
{
    PS thuong = {a.tuSo * b.mauSo, a.mauSo * b.tuSo};
    rutGon(thuong);
    return thuong;
}

int main()
{
    PS p1, p2;
    cout << "Nhap phan so thu nhat:" << endl;
    nhapPS(p1);
    while (p1.mauSo == 0)
    {
        cout << "Phan so khong hop le. Vui long nhap lai:" <<endl;
        nhapPS(p1);
    }
    cout << "Nhap phan so thu hai:" << endl;
    nhapPS(p2);
    while (p2.mauSo == 0)
    {
        cout << "Phan so khong hop le. Vui long nhap lai:" <<endl;
        nhapPS(p2);
    }
    PS tong = Tong(p1,p2);
    PS hieu = Hieu(p1,p2);
    PS tich = Tich(p1,p2);
    PS thuong = Thuong(p1,p2);
    cout << "Tong hai phan so:" << endl;
    xuatPS(tong);
    cout << "Hieu hai phan so:" << endl;
    xuatPS(hieu);
    cout << "Tich hai phan so:" << endl;
    xuatPS(tich);
    cout << "Thuong hai phan so:" << endl;
    xuatPS(thuong);
    return 0;
}
