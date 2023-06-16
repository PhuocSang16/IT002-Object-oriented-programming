#include <bits/stdc++.h>
using namespace std;

typedef class SoPhuc
{
    private:
        float thuc, ao;
    public:
        void nhapSP();
        void xuatSP();
        SoPhuc tongSP(SoPhuc a);
        SoPhuc hieuSP(SoPhuc a);
        SoPhuc tichSP(SoPhuc a);
        SoPhuc thuongSP(SoPhuc a);
} SP;

void SP::nhapSP()
{
    cout << "Nhap lan luot phan thuc va phan ao: ";
    cin >> this->thuc >> this->ao;
}

void SP::xuatSP()
{
    if (ao == 0)
        cout << thuc << endl;
    else if (thuc == 0)
        cout << ao << "i" << endl;
    else
    {
        if (ao < 0)
            cout << thuc << ao << "i" << endl;
        else
            cout << thuc << "+" << ao << "i" << endl;
    }
}

SP SP::tongSP(SP a)
{
    SP kq;
    kq.ao = a.ao + this->ao;
    kq.thuc = a.thuc + this->thuc;
    return kq;
}

SP SP::hieuSP(SP a)
{
    SP kq;
    kq.ao = this->ao - a.ao;
    kq.thuc = this->thuc - a.thuc;
    return kq;
}

SP SP::tichSP(SP a)
{
    SP kq;
    kq.thuc = (a.thuc * this->thuc - a.ao * this->ao);
    kq.ao = (a.thuc * this->ao + a.ao * this->thuc);
    return kq;
}

SP SP::thuongSP(SP a)
{
    SP kq;
    kq.thuc = ((a.thuc * this->thuc + a.ao * this->ao) / (a.ao * a.ao + a.thuc * a.thuc));
    kq.ao = ((a.thuc * this->ao + a.ao * this->thuc) / (a.ao * a.ao + a.thuc * a.thuc));
    return kq;
}

int main()
{
    SP a,b;
    int n;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap so phuc" << endl;
        cout << "Lua chon 2: Xuat so phuc" << endl;
        cout << "Lua chon 3: Tong 2 so phuc" << endl;
        cout << "Lua chon 4: Hieu 2 so phuc" << endl;
        cout << "Lua chon 5: Tich 2 so phuc" << endl;
        cout << "Lua chon 6: Thuong 2 so phuc" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                a.nhapSP();
                break;
            case 2:
                a.xuatSP();
                break;
            case 3:
                cout << "Nhap so phuc thu 1:" << endl;
                a.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                a.xuatSP();
                cout << "Nhap so phuc thu 2:" << endl;
                b.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                b.xuatSP();
                cout << "Tong 2 so phuc la:" << endl;
                a.tongSP(b).xuatSP();
                break;
            case 4:
                cout << "Nhap so phuc thu 1:" << endl;
                a.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                a.xuatSP();
                cout << "Nhap so phuc thu 2:" << endl;
                b.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                b.xuatSP();
                cout << "Hieu 2 so phuc la:" << endl;
                a.hieuSP(b).xuatSP();
                break;
            case 5:
                cout << "Nhap so phuc thu 1:" << endl;
                a.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                a.xuatSP();
                cout << "Nhap so phuc thu 2:" << endl;
                b.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                b.xuatSP();
                cout << "Tich 2 so phuc la:" << endl;
                a.tichSP(b).xuatSP();
                break;
            case 6:
                cout << "Nhap so phuc thu 1:" << endl;
                a.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                a.xuatSP();
                cout << "Nhap so phuc thu 2:" << endl;
                b.nhapSP();
                cout << "So phuc vua nhap:" << endl;
                b.xuatSP();
                cout << "Thuong 2 so phuc la:" << endl;
                a.thuongSP(b).xuatSP();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
