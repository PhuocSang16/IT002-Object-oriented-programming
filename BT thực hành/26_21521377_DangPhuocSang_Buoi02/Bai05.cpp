#include <bits/stdc++.h>
#define PI 3.14
using namespace std;

class ToaDo
{
    private:
        int tungDo, hoanhDo;
    public:
        void nhapTD();
        int layhoanhTD();
        int laytungTD();
        void xuatTD();
};

void ToaDo::nhapTD()
{
    cout << "Nhap lan luot hoanh do va tung do: ";
    cin >> hoanhDo >> tungDo;
}

void ToaDo::xuatTD()
{
    cout << "(" << hoanhDo << " , " << tungDo << ")" << endl;
}

int ToaDo::layhoanhTD()
{
    return hoanhDo;
}

int ToaDo::laytungTD()
{
    return tungDo;
}

class DuongTron
{
    private:
        ToaDo tam;
        float R;
    public:
        void nhapDT();
        void xuatDT();
        float chuviDT();
        float dientichDT();
        DuongTron phongtoDT(int n);
        DuongTron thunhoDT(int n);
        void kiemtra2DT(DuongTron a);
};

void DuongTron::nhapDT()
{
    cout << "Nhap toa do tam duong tron:" << endl;
    tam.nhapTD();
    cout << "Nhap ban kinh: ";
    cin >> R;
}

void DuongTron::xuatDT()
{
    cout << "Toa do tam:" << endl;
    tam.xuatTD();
    cout << "Ban kinh R = " << R << endl;
}

float DuongTron::chuviDT()
{
    return 2*R*PI;
}

float DuongTron::dientichDT()
{
    return R*R*PI;
}

DuongTron DuongTron::phongtoDT(int n)
{
    DuongTron kq;
    kq.tam = this->tam;
    kq.R = this->R * ((n+100)*1.0/100);
    return kq;
}

DuongTron DuongTron::thunhoDT(int n)
{
    DuongTron kq;
    kq.tam = this->tam;
    kq.R = this->R * ((100-n)*1.0/100);
    return kq;
}

void DuongTron::kiemtra2DT(DuongTron a)
{
    int h1 = a.tam.layhoanhTD();
    int t1 = a.tam.laytungTD();
    int h2 = this->tam.layhoanhTD();
    int t2 = this->tam.laytungTD();
    float khoangcach = sqrt((h1-h2)*(h1-h2) + (t1-t2)*(t1-t2));
    if (khoangcach > R + a.R)
        cout << "Khong giao nhau" << endl;
    else if (khoangcach == R + a.R)
        cout << "Tiep xuc nhau" << endl;
    else
        cout << "Cat nhau tai hai diem" << endl;
}

int main()
{
    DuongTron a,b;
    int k;
    int n;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap duong tron" << endl;
        cout << "Lua chon 2: Xuat thong tin duong tron" << endl;
        cout << "Lua chon 3: Tinh chu vi" << endl;
        cout << "Lua chon 4: Tinh dien tich" << endl;
        cout << "Lua chon 5: Phong to duong tron theo phan tram" << endl;
        cout << "Lua chon 6: Thu nho duong tron theo phan tram" << endl;
        cout << "Lua chon 7: Kiem tra 2 duong tron co giao nhau khong?" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                a.nhapDT();
                break;
            case 2:
                a.xuatDT();
                break;
            case 3:
                a.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                a.xuatDT();
                cout << "Chu vi duong tron la:" << a.chuviDT() << endl;
                break;
            case 4:
                a.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                a.xuatDT();
                cout << "Dien tich duong tron la:" << a.dientichDT() << endl;
                break;
            case 5:
                a.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                a.xuatDT();
                cout << "Nhap % muon phong to: ";
                cin >> k;
                cout << "Thong tin hinh trong da phong to them " << k << "% la:" << endl;
                a.phongtoDT(k).xuatDT();
                break;
            case 6:
                a.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                a.xuatDT();
                cout << "Nhap % muon thu nho: ";
                cin >> k;
                cout << "Thong tin hinh trong da thu nho lai " << k << "% la:" << endl;
                a.thunhoDT(k).xuatDT();
                break;
            case 7:
                cout << "Nhap duong tron thu 1:" << endl;
                a.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                a.xuatDT();
                cout << "Nhap duong tron thu 2:" << endl;
                b.nhapDT();
                cout << "Thong tin duong tron vua nhap la:" << endl;
                b.xuatDT();
                a.kiemtra2DT(b);
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
