#include <bits/stdc++.h>
using namespace std;

typedef class ThoiGian
{
    private:
        int gio, phut, giay;
    public:
        friend istream& operator >> (istream &is, ThoiGian &a);
        friend ostream& operator << (ostream &os, ThoiGian a);
        int layGio();
        int layPhut();
        int layGiay();
        ThoiGian operator + (int b);
        ThoiGian operator - (int b);
        ThoiGian operator + (ThoiGian a);
        ThoiGian operator - (ThoiGian a);
        ThoiGian operator ++ ();
        ThoiGian operator -- ();
        void changeTG();
} TG;

istream& operator >> (istream &is, ThoiGian &a)
{
    cout << "Nhap thong tin thoi gian" << endl;
    cout << "Nhap gio, phut, giay: ";
    is >> a.gio >> a.phut >> a.giay;
    return is;
}

int TG::layGio()
{
    return gio;
}

int TG::layPhut()
{
    return phut;
}

int TG::layGiay()
{
    return giay;
}

ostream& operator << (ostream &os, ThoiGian a)
{
    int h = a.layGio();
    int m = a.layPhut();
    int s = a.layGiay();
    while (s >= 60)
    {
        s -= 60;
        m++;
    }
    while (m >= 60)
    {
        m -= 60;
        h++;
    }
    os << h << "h " << m << "m " << s << "s" << endl;
    return os;
}

TG TG::operator + (int b)
{
    TG kq;
    kq.gio = gio;
    kq.phut = phut;
    kq.giay = giay + b;
    return kq;
}

TG TG::operator - (int b)
{
    TG kq;
    kq.gio = gio;
    kq.phut = phut;
    kq.giay = giay - b;
    return kq;
}

TG TG::operator + (TG a)
{
    TG kq;
    kq.gio = gio + a.gio;
    kq.phut = phut + a.phut;
    kq.giay = giay + a.giay;
    return kq;
}

TG TG::operator - (TG a)
{
    TG kq;
    kq.gio = gio - a.gio;
    kq.phut = phut - a.phut;
    kq.giay = giay - a.giay;
    return kq;
}

TG TG::operator ++ ()
{
    TG kq;
    kq.gio = gio;
    kq.phut = phut;
    kq.giay = giay + 1; //Dung ++giay hoac --giay se lam thay doi du lieu
    return kq;
}

TG TG::operator -- ()
{
    TG kq;
    kq.gio = gio;
    kq.phut = phut;
    kq.giay = giay - 1;
    return kq;
}

void TG::changeTG()
{
    int day = 0;
    while (giay >= 60)
    {
        giay -= 60;
        phut++;
    }
    while (phut >= 60)
    {
        phut -= 60;
        gio++;
    }
    while (gio >= 24)
    {
        gio -= 24;
        day++;
    }
    cout << day << "d " << gio << "h " << phut << "m " << giay << "s" << endl;
}

int main()
{
    TG a, b;
    int n, x;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap thoi gian" << endl;
        cout << "Lua chon 2: Xuat thoi gian" << endl;
        cout << "Lua chon 3: Cong/Tru mot so nguyen giay vao thoi gian" << endl;
        cout << "Lua chon 4: Cong/Tru 2 thoi gian" << endl;
        cout << "Lua chon 5: ++/--Thoi gian" << endl;
        cout << "Lua chon 6: Chuyen thoi gian ve ngay gio phut giay" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                cin >> a;
                break;
            case 2:
                cout << a;
                break;
            case 3:
                cin >> a;
                cout << "Nhap so nguyen x: ";
                cin >> x;
                cout << "Tong = " << a + x << endl;
                cout << "Hieu = " << a - x << endl;
                break;
            case 4:
                cin >> a;
                cin >> b;
                cout << "Tong 2 thoi gian: " << a + b << endl;
                cout << "Hieu 2 thoi gian: " << a - b << endl;
                break;
            case 5:
                cin >> a;
                cout << "++Thoi gian: " << ++a << endl;
                cout << "--Thoi gian: " << --a << endl;
                break;
            case 6:
                cin >> a;
                a.changeTG();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
