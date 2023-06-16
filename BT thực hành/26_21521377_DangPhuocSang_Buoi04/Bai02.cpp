//Them phong to, thu nho, kiem tra vi tri diem so voi duong tron
#include <bits/stdc++.h>
#define PI 3.14
using namespace std;

class Diem
{
    private:
        int hoanh, tung;
    public:
        Diem()
        {
            tung = hoanh = 0;
        }
        Diem(int h, int t)
        {
            hoanh = h;
            tung = t;
        }
        void nhapDiem();
        int layhoanh();
        int laytung();
        void sethoanh(int k);
        void settung(int k);
        void xuatDiem();
        double khoanhcach(Diem a);
};

void Diem::nhapDiem()
{
    cout << "Nhap lan luot hoanh do va tung do: ";
    cin >> hoanh >> tung;
}

void Diem::xuatDiem()
{
    cout << "(" << hoanh << " , " << tung << ")" << endl;
}

int Diem::layhoanh()
{
    return hoanh;
}

int Diem::laytung()
{
    return tung;
}

void Diem::sethoanh(int k)
{
    hoanh = k;
}

void Diem::settung(int k)
{
    tung = k;
}

double Diem::khoanhcach(Diem a)
{
    int h1 = hoanh;
    int t1 = tung;
    int h2 = a.layhoanh();
    int t2 = a.laytung();
    double kc = sqrt((h1-h2)*(h1-h2) + (t1-t2)*(t1-t2));
    return kc;
}

typedef class DuongTron: public Diem
{
    private:
        double r;
    public:
        DuongTron():Diem(0,0)
        {
            r = 0;
        }
        DuongTron(double bankinh, int h, int t):Diem(h,t)
        {
            r = bankinh;
        }
        void nhapDT();
        void xuatDT();
        Diem layTam();
        double chuviDT();
        double dientichDT();
        DuongTron phongtoDT(int n); //n la ty so phan tram
        DuongTron thunhoDT(int n);
        int kiemtraDT(DuongTron a);
        int kiemtravitriDiem(Diem a);
} DT;

void DT::nhapDT()
{
    cout << "Nhap toa do tam" << endl;
    Diem::nhapDiem();
    cout << "Nhap ban kinh: ";
    cin >> r;
}

void DT::xuatDT()
{
    cout << "Duong tron co tam ";
    Diem::xuatDiem();
    cout << "Ban kinh: " << r << endl;
}

Diem DT::layTam()
{
    Diem kq(layhoanh(),laytung());
    return kq;
}

double DT::chuviDT()
{
    return r*2*PI;
}

double DT::dientichDT()
{
    return r*r*PI;
}

DT DT::phongtoDT(int n)
{
    DT kq(r,layhoanh(),laytung());
    kq.r = r * ((n + 100) * 1.0 / 100);
    return kq;
}

DT DT::thunhoDT(int n)
{
    DT kq(r,layhoanh(),laytung());
    kq.r = r * ((100 - n) * 1.0 / 100);
    return kq;
}

int DT::kiemtraDT(DT a)
{
    double kc = khoanhcach(a.layTam());
    if (kc > this->r + a.r)
        return 0; //Phan biet
    else if (kc == this->r + a.r || kc == abs(this->r - a.r))
        return 1; //Tiep xuc
    else
        return 2; //Giao nhau
}

int DT::kiemtravitriDiem(Diem a)
{
    double kc = khoanhcach(a);
    if (kc > r)
        return -1; //Diem nam ngoai
    else if (kc == r)
        return 0; //Diem nam tren
    else
        return 1; //Diem nam trong
}

int main()
{
    DT a, b;
    double kq;
    Diem x;
    int n, k;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap duong tron" << endl;
        cout << "Lua chon 2: Xuat thong tin duong tron" << endl;
        cout << "Lua chon 3: Tinh chu vi" << endl;
        cout << "Lua chon 4: Tinh dien tich" << endl;
        cout << "Lua chon 5: Kiem tra moi quan he 2 DT" << endl;
        cout << "Lua chon 6: Phong to duong tron len n %" << endl;
        cout << "Lua chon 7: Thu nho duong tron xuong n %" << endl;
        cout << "Lua chon 8: Vi tri tuong doi giua Diem va DT" << endl;
        cout << "=========================" << endl;
        cin >> n;
        switch(n)
        {
            case 1:
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                break;
            case 2:
                cout << "Xuat thong tin duong tron" << endl;
                a.xuatDT();
                break;
            case 3:
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                kq = a.chuviDT();
                cout << "Chu vi: " << kq << endl;
                break;
            case 4:
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                kq = a.dientichDT();
                cout << "Dien tich: " << kq << endl;
                break;
            case 5:
                cout << "Kiem tra vi tri tuong doi giua 2 DT" << endl;
                cout << "Nhap duong tron a" << endl;
                a.nhapDT();
                cout << "Nhap duong tron b" << endl;
                b.nhapDT();
                k = a.kiemtraDT(b);
                if (k == 0)
                    cout << "Hai duong tron phan biet" << endl;
                else if (k == 1)
                    cout << "Hai duong tron tiep xuc nhau" << endl;
                else
                    cout << "Hai duong tron cat nhau tai 2 diem" << endl;
                break;
            case 6:
                cout << "Phong to duong tron" << endl;
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                cout << "Nhap ty le phan tram muon phong to them: ";
                cin >> k;
                a = a.phongtoDT(k);
                cout << "Duong tron da duoc phong to them " << k << "%" << endl;
                a.xuatDT();
                break;
            case 7:
                cout << "Thu nho duong tron" << endl;
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                cout << "Nhap ty le phan tram muon thu nho bot: ";
                cin >> k;
                a = a.thunhoDT(k);
                cout << "Duong tron da duoc thu nho lai " << k << "%" << endl;
                a.xuatDT();
                break;
            case 8:
                cout << "Kiem tra vi tri tuong doi giua Diem x va DT" << endl;
                cout << "Nhap duong tron" << endl;
                a.nhapDT();
                cout << "Nhap toa do diem x" << endl;
                x.nhapDiem();
                k = a.kiemtravitriDiem(x);
                if (k == -1)
                    cout << "Diem x nam ngoai duong tron" << endl;
                else if (k == 0)
                    cout << "Diem x nam tren duong tron" << endl;
                else
                    cout << "Diem x nam trong duong tron" << endl;
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(0);
        }
    }
    return 0;
}
