#include <bits/stdc++.h>
using namespace std;

typedef struct HocSinh
{
    string Hoten;
    double toan, van;
    double TB;
} HS;

void Nhap(HS a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin hoc sinh thu " << i+1 << endl;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin,a[i].Hoten);
        cout << "Nhap diem toan: ";
        cin >> a[i].toan;
        cout << "Nhap diem van: ";
        cin >> a[i].van;

        a[i].TB = (a[i].toan + a[i].van) / 2;
    }
}

HS maxTB(HS a[], int n)
{
    double k = a[0].TB;
    int x = 0;
    for (int i = 1; i < n; i++)
    {
        k = max(k,a[i].TB);
        if (k == a[i].TB)
            x = i;
    }
    return a[x];
}

HS minTB(HS a[], int n)
{
    double k = a[0].TB;
    int x = 0;
    for (int i = 1; i < n; i++)
    {
        k = min(k,a[i].TB);
        if (k == a[i].TB)
            x = i;
    }
    return a[x];
}

void xuatHS(HS a)
{
    cout << a.Hoten << "\t" << a.toan << "\t" << a.van << "\t" << a.TB << endl;
}

int main()
{
    int n;
    cout << "Nhap so hoc sinh: ";
    cin >> n;
    HS a[n];
    Nhap(a,n);
    HS x1 = maxTB(a,n);
    HS x2 = minTB(a,n);
    cout << "Hoc sinh co diem trung binh cao nhat la:" << endl;
    xuatHS(x1);
    cout << "Hoc sinh co diem trung binh thap nhat la:" << endl;
    xuatHS(x2);
    return 0;
}
