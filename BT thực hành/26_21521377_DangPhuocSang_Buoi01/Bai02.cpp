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

bool kiemTra(PS a)
{
    if (a.mauSo == 0)
        return false;
    return true;
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

void xuatPS(PS a)
{
    if (a.mauSo == 1)
        cout << a.tuSo << endl;
    else
        cout << a.tuSo << "/" << a.mauSo << endl;
}

int main()
{
    PS p;
    nhapPS(p);
    while (kiemTra(p) == false)
    {
        cout << "Phan so khong hop le, vui long nhap lai" << endl;
        nhapPS(p);
    }
    cout<< "Phan so vua nhap la:" <<endl;
    xuatPS(p);
    p = rutGon(p);
    cout << "Phan so da rut gon la:" << endl;
    xuatPS(p);
    return 0;
}
