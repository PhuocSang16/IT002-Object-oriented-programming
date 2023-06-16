#include <bits/stdc++.h>
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
    while (a.mauSo == 0)
    {
        cout << "Phan so vua nhap khong hop le, vui long nhap lai:" << endl;
        nhapPS(a);
    }
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

PS rutGon(PS &a)
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

void soSanh (PS a, PS b)
{
    quyDong(a,b);
    if (a.tuSo > b.tuSo)
        cout << "Phan so 1 > Phan so 2" << endl;
    else if (a.tuSo < a.mauSo)
        cout << "Phan so 1 < Phan so 2" << endl;
    else
        cout << "Hai phan so bang nhau" << endl;
}

int main()
{
    cout << "==========MENU==========" << endl;
    cout << "Lua chon 1: Nhap phan so" << endl;
    cout << "Lua chon 2: Xuat phan so" << endl;
    cout << "Lua chon 3: Rut gon phan so" << endl;
    cout << "Lua chon 4: So sanh 2 phan so" << endl;
    cout << "Lua chon 5: Cong 2 phan so" << endl;
    cout << "Lua chon 6: Tru 2 phan so" << endl;
    cout << "Lua chon 7: Nhan 2 phan so" << endl;
    cout << "Lua chon 8: Chia 2 phan so" << endl;
    int n;
    PS a, b, tong, hieu1, hieu2, tich, thuong1, thuong2;
    while (1)
    {
        cout << "Nhap lua chon cua ban: ";
        cin >> n;
        switch (n)
        {
            case 1:
                nhapPS(a);
                break;
            case 2:
                nhapPS(a);
                cout << "Phan so vua nhap la: ";
                xuatPS(a);
                break;
            case 3:
                nhapPS(a);
                a = rutGon(a);
                cout << "Phan so vua nhap da duoc rut gon la: ";
                xuatPS(a);
                break;
            case 4:
                nhapPS(a);
                a = rutGon(a);
                nhapPS(b);
                b = rutGon(b);
                cout << "Phan so thu nhat la: ";
                xuatPS(a);
                cout << "Phan so thu hai la: ";
                xuatPS(b);
                soSanh(a,b);
                break;
            case 5:
                nhapPS(a);
                a = rutGon(a);
                nhapPS(b);
                b = rutGon(b);
                cout << "Phan so thu nhat la: ";
                xuatPS(a);
                cout << "Phan so thu hai la: ";
                xuatPS(b);
                tong = Tong(a,b);
                cout << "Tong 2 phan so: ";
                xuatPS(tong);
                break;
            case 6:
                nhapPS(a);
                a = rutGon(a);
                nhapPS(b);
                b = rutGon(b);
                cout << "Phan so thu nhat la: ";
                xuatPS(a);
                cout << "Phan so thu hai la: ";
                xuatPS(b);
                hieu1 = Hieu(a,b);
                hieu2 = Hieu(b,a);
                cout << "Hieu 2 phan so (ps1 - ps2): ";
                xuatPS(hieu1);
                cout << "Hieu 2 phan so (ps2 - ps1): ";
                xuatPS(hieu2);
                break;
            case 7:
                nhapPS(a);
                a = rutGon(a);
                nhapPS(b);
                b = rutGon(b);
                cout << "Phan so thu nhat la: ";
                xuatPS(a);
                cout << "Phan so thu hai la: ";
                xuatPS(b);
                tich = Tich(a,b);
                cout << "Tich 2 phan so: ";
                xuatPS(tich);
                break;
            case 8:
                nhapPS(a);
                a = rutGon(a);
                nhapPS(b);
                b = rutGon(b);
                cout << "Phan so thu nhat la: ";
                xuatPS(a);
                cout << "Phan so thu hai la: ";
                xuatPS(b);
                thuong1 = Thuong(a,b);
                thuong2 = Thuong(b,a);
                cout << "Thuong 2 phan so (ps1 / ps2): ";
                xuatPS(thuong1);
                cout << "Thuong 2 phan so (ps2 / ps1): ";
                xuatPS(thuong2);
                break;
            default:
                cout << "Khong co lua chon nay." << endl;
        }
    }
    return 0;
}
