#include <iostream>
using namespace std;
typedef struct PhanSo
{
    int tuSo, mauSo;
} PS;

int UCLN(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN(b, a % b);
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

void Nhap(PS a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i+1 << endl;
        cout << "Nhap tu so: ";
        cin >> a[i].tuSo;
        cout << "Nhap mau so: ";
        cin >> a[i].mauSo;
        while (a[i].mauSo == 0)
        {
            cout << "Phan so khong hop le. Vui long nhap lai" << endl;
            cout << "Nhap tu so: ";
            cin >> a[i].tuSo;
            cout << "Nhap mau so: ";
            cin >> a[i].mauSo;
        }
        a[i] = rutGon(a[i]);
    }
}

void xuatPS(PS x)
{
    rutGon(x);
    if (x.mauSo == 1)
        cout << x.tuSo << endl;
    else
        cout << x.tuSo << "/" << x.mauSo << endl;
}

void Xuat(PS a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        rutGon(a[i]);
        if (a[i].mauSo == 1) cout << a[i].tuSo << " ";
        else cout << a[i].tuSo << "/" << a[i].mauSo << " ";
    }
    cout << endl;
}

void quyDong(PS a[], int &n)
{
    int lcm = BCNN(a[0].mauSo, a[1].mauSo);
    for (int i = 2;i < n; i++)
    {
        lcm = BCNN(lcm, a[i].mauSo);
    }
    for (int i = 0; i < n; i++)
    {
        a[i].tuSo *= lcm/a[i].mauSo;
        a[i].mauSo = lcm;
    }
}

void sapxepTang(PS a[], int &n)
{
    quyDong(a,n);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].tuSo > a[j].tuSo) swap(a[i],a[j]);
}

void sapxepGiam(PS a[], int &n)
{
    quyDong(a,n);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i].tuSo < a[j].tuSo) swap(a[i],a[j]);
}

int main()
{
    int n;
    cout << "Nhap so phan so: ";
    cin >> n;
    PS a[n];
    Nhap(a,n);
    cout << "Day phan so vua nhap la:" << endl;
    Xuat(a,n);
    sapxepGiam(a,n);
    cout << "Phan so lon nhat trong day la:" << endl;
    xuatPS(a[0]);
    cout << "Day phan so sap xep giam dan:" << endl;
    Xuat(a,n);
    cout << "Day phan so sap xep tang dan:" << endl;
    sapxepTang(a,n);
    Xuat(a,n);
    return 0;
}
