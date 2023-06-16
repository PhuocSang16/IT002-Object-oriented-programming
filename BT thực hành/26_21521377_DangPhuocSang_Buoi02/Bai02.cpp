#include <bits/stdc++.h>
using namespace std;

class ToaDo
{
    private:
        float hoanh, tung;
    public:
        void nhapTD();
        void xuatTD();
        float layTDhoanh();
        float layTDtung();
        void thaydoiTD();
        ToaDo dichuyenTD();
        float laykcTD(ToaDo a);
        ToaDo timTDtrungdiem(ToaDo a);
        ToaDo();
        ToaDo(float h, float t)
        {
            hoanh = h;
            tung = t;
        }
        ~ToaDo()
        {
            cout << "Da xoa du lieu" << endl;
        }
        ToaDo saochepTD();
};

ToaDo::ToaDo()
{
    hoanh = 0;
    tung = 0;
}

void ToaDo::nhapTD()
{
    cout << "Nhap lan luot hoanh do va tung do: ";
    cin >> this->hoanh >> this->tung;
}

void ToaDo::xuatTD()
{
    cout << "(" << this->hoanh << "," << this->tung << ")" << endl;
}

float ToaDo::layTDhoanh()
{
    return this->hoanh;
}

float ToaDo::layTDtung()
{
    return this->tung;
}

void ToaDo::thaydoiTD()
{
    cout << "Nhap toa do moi" << endl;
    nhapTD();
}

ToaDo ToaDo::dichuyenTD()
{
    ToaDo target;
    cout << "Di chuyen den toa do:" << endl;
    target.nhapTD();
    return target;
}

float ToaDo::laykcTD(ToaDo a)
{
    return sqrt((hoanh - a.hoanh) * (hoanh - a.hoanh) + (tung - a.tung) * (tung - a.tung));
}

ToaDo ToaDo::timTDtrungdiem(ToaDo a)
{
    ToaDo kq;
    kq.hoanh = (a.hoanh + hoanh) / 2;
    kq.tung = (a.tung + tung) / 2;
    return kq;
}

ToaDo ToaDo::saochepTD()
{
    ToaDo kq;
    kq.hoanh = hoanh;
    kq.tung = tung;
    return kq;
}

int main()
{
    ToaDo a,b;
    ToaDo c(5,2);
    int n;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap toa do 1 diem" << endl;
        cout << "Lua chon 2: Xuat toa do 1 diem" << endl;
        cout << "Lua chon 3: Lay toa do 1 diem" << endl;
        cout << "Lua chon 4: Thay doi toa do diem" << endl;
        cout << "Lua chon 5: Di chuyen den toa do" << endl;
        cout << "Lua chon 6: Khoanh cach 2 diem" << endl;
        cout << "Lua chon 7: Tim toa do trung diem" << endl;
        cout << "Lua chon 8: Xoa toa do diem" << endl;
        cout << "Lua chon 9: Sao chep diem toa do" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                a.nhapTD();
                break;
            case 2:
                a.xuatTD();
                break;
            case 3:
                a.nhapTD();
                cout << "Hoanh do: " << a.layTDhoanh() << endl;
                cout << "Tung do: " << a.layTDtung() << endl;
                break;
            case 4:
                a.nhapTD();
                a.thaydoiTD();
                cout << "Toa do moi:" << endl;
                a.xuatTD();
                break;
            case 5:
                a.nhapTD();
                a = a.dichuyenTD();
                cout << "Toa do can den:" << endl;
                a.xuatTD();
                break;
            case 6:
                cout << "Nhap toa do diem thu 1" << endl;
                a.nhapTD();
                cout << "Nhap toa do diem thu 2" << endl;
                b.nhapTD();
                cout << "Khoang cach 2 diem vua nhap: " << a.laykcTD(b) << endl;
                break;
            case 7:
                cout << "Nhap toa do diem thu 1" << endl;
                a.nhapTD();
                cout << "Nhap toa do diem thu 2" << endl;
                b.nhapTD();
                cout << "Toa do trung diem la:" << endl;
                a.timTDtrungdiem(b).xuatTD();
                break;
            case 8:
                c.~ToaDo();
                break;
            case 9:
                a.nhapTD();
                b = a.saochepTD();
                cout << "Toa do da sao chep" << endl;
                b.xuatTD();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
