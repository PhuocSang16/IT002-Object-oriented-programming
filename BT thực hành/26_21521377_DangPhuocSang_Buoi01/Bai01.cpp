#include <iostream>
using namespace std;
typedef struct PhanSo
{
    int tuSo, mauSo;
} PS;

bool kiemTra(PS a)
{
    if (a.mauSo == 0)
        return false;
    return true;
}

void nhapPS(PS &a)
{
    cout << "Nhap tu so: ";
    cin >> a.tuSo;
    cout << "Nhap mau so: ";
    cin >> a.mauSo;
    while (kiemTra(a) == false)
    {
        cout << "Phan so khong hop le, vui long nhap lai" << endl;
        nhapPS(a);
    }
}

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
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

int soSanh(PS a, PS b)
{
    float k1 = (a.tuSo * 1.0 / a.mauSo);
    float k2 = (b.tuSo * 1.0 / b.mauSo);
    if (k1 < k2)
        return 2;
    else if (k1 > k2)
        return 1;
    else
        return 0;
}

void xuatPS(PS a)
{
    if (a.mauSo == 1)
        cout << a.tuSo << endl;
    else
        cout << a.tuSo << "/" << a.mauSo << endl;
}

int main()
{
    PS p1, p2;
    nhapPS(p1);
    rutGon(p1);
    nhapPS(p2);
    rutGon(p2);
    int ss = soSanh(p1,p2);
    cout << "Phan so lon hon la:" << endl;
    if (ss == 1)
        xuatPS(p1);
    else if (ss == 2)
        xuatPS(p2);
    else
        cout << "Hai phan so bang nhau" << endl;
    return 0;
}
