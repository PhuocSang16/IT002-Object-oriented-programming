#include <bits/stdc++.h>
using namespace std;

class Day
{
    public:
        int day, month, year;
        bool checkDay();
        void nhapDay();
        void xuatDay();
        bool operator == (Day a);
};

bool Day::operator == (Day a)
{
    return (this->day == a.day && this->month == a.month && this->year == a.year);
}

bool Day::checkDay()
{
    if (day > 31 || day < 1 || month > 12 || month < 1) return false;
    int maxDay;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                maxDay = 31;
                break;
            case 4: case 6: case 9: case 11:
                maxDay = 30;
                break;
            case 2:
                maxDay = 29;
                break;
            default:
                break;
        }
    }
    else
    {
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                maxDay = 31;
                break;
            case 4: case 6: case 9: case 11:
                maxDay = 30;
                break;
            case 2:
                maxDay = 28;
                break;
            default:
                break;
        }
    }
    return (day <= maxDay);
}

void Day::nhapDay()
{
    cout << "Nhap theo thu tu ngay thang nam: ";
    cin >> day >> month >> year;
    while (checkDay() == false)
    {
        cout << "Khong hop le, vui long nhap lai: ";
        cin >> day >> month >> year;
    }
}

void Day::xuatDay()
{
    cout << day << "/" << month << "/" << year << endl;
}

class Sach
{
    protected:
        int maSach;
        string tenSach;
        int giaTien;
    public:
        Sach()
        {
            maSach = giaTien = 0;
            tenSach = "";
        }
        ~Sach(){}
        int getMa();
        int getGT();
        virtual bool checkSGK()
        {
            return false;
        }
        virtual bool checkTT()
        {
            return false;
        }
        virtual bool checkTC()
        {
            return false;
        }
        void setGT(int gt);
        virtual void nhapSach();
        virtual void xuatSach();
        virtual string getMon(){};
        virtual string getTG(){}
        virtual Day getDay(){}
};

int Sach::getGT()
{
    return giaTien;
}

int Sach::getMa()
{
    return maSach;
}

void Sach::setGT(int gt)
{
    giaTien = gt;
}

void Sach::nhapSach()
{
    cout << "Nhap ma: ";
    cin >> maSach;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin,tenSach);
    cout << "Nhap gia tien: ";
    cin >> giaTien;
}

void Sach::xuatSach()
{
    cout << maSach << " " << tenSach << endl;
    cout << "Gia tien: " << giaTien << endl;
}

typedef class SachGiaoKhoa: public Sach
{
    protected:
        string monHoc;
    public:
        SachGiaoKhoa():Sach()
        {
            monHoc = "";
        }
        ~SachGiaoKhoa(){}
        string getMon();
        bool checkSGK()
        {
            return true;
        }
        void nhapSach();
        void xuatSach();
} SGK;

string SGK::getMon()
{
    return monHoc;
}

void SGK::nhapSach()
{
    cout << "Nhap mon hoc: ";
    cin.ignore();
    getline(cin, monHoc);
    Sach::nhapSach();
}

void SGK::xuatSach()
{
    cout << "Sach giao khoa mon " << monHoc << endl;
    Sach::xuatSach();
}

typedef class TieuThuyet: public Sach
{
    protected:
        string tacGia;
    public:
        TieuThuyet():Sach()
        {
            tacGia = "";
        }
        ~TieuThuyet(){}
        string getTG();
        bool checkTT()
        {
            return true;
        }
        void nhapSach();
        void xuatSach();
} TT;

string TT::getTG()
{
    return tacGia;
}

void TT::nhapSach()
{
    cout << "Nhap ten tac gia: ";
    cin.ignore();
    getline(cin, tacGia);
    Sach::nhapSach();
}

void TT::xuatSach()
{
    cout << "Tieu thuyet" << endl;
    cout << "Tac gia: " << tacGia << endl;
    Sach::xuatSach();
}

typedef class TapChi: public Sach
{
    protected:
        Day ngay;
    public:
        TapChi():Sach()
        {
            ngay.day = ngay.month = 1;
            ngay.year = 2000;
        }
        ~TapChi(){}
        bool checkTC()
        {
            return true;
        }
        void nhapSach();
        void xuatSach();
        Day getDay();
} TC;

Day TC::getDay()
{
    return ngay;
}

void TC::nhapSach()
{
    cout << "Nhap thoi gian xuat ban: ";
    ngay.nhapDay();
    Sach::nhapSach();
}

void TC::xuatSach()
{
    cout << "Tap chi" << endl;
    ngay.xuatDay();
    Sach::xuatSach();
}

int main()
{
    Sach *a[200];
    int n, k, ma, tien, lc, x;
    string s;
    Day nxb;
    while(1)
    {
        cout << "==========Quan ly sach==========" << endl;
        cout << "Lua chon 1: Nhap sach" << endl;
        cout << "Lua chon 2: Xuat sach" << endl;
        cout << "Lua chon 3: Tim sach theo ma sach" << endl;
        cout << "Lua chon 4: Tim tieu thuyet theo ten TG" << endl;
        cout << "Lua chon 5: Tim sach giao khoa theo mon hoc" << endl;
        cout << "Lua chon 6: Tim tap chi theo ngay ra xuat ban" << endl;
        cout << "Lua chon 7: In top 10 sach co gia tien cao nhat" << endl;
        cout << "Lua chon 8: Thay doi gia tien 1 cuon sach theo ma sach" << endl;
        cout << "Lua chon 9: Dem so luong sach giao khoa hien tai" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> lc;
        switch (lc)
        {
            case 1:
                cout << "Nhap so luong sach: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Loai 1: Sach giao khoa" << endl;
                    cout << "Loai 2: Tieu thuyet" << endl;
                    cout << "Loai 3: Tap chi" << endl;
                    cout << "Nhap loai sach: ";
                    cin >> k;
                    switch (k)
                    {
                        case 1:
                            a[i] = new SGK;
                            a[i]->nhapSach();
                            break;
                        case 2:
                            a[i] = new TT;
                            a[i]->nhapSach();
                            break;
                        case 3:
                            a[i] = new TC;
                            a[i]->nhapSach();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; i++)
                    a[i]->xuatSach();
                break;
            case 3:
                cout << "Nhap ma sach can tim: ";
                cin >> ma;
                x = 0;
                for (int i = 0; i < n; i++)
                    if (a[i]->getMa() == ma)
                    {
                        x++;
                        a[i]->xuatSach();
                    }
                if (x == 0) cout << "Khong tim thay" << endl;
                break;
            case 4:
                cout << "Nhap ten tac gia: ";
                cin.ignore();
                getline(cin, s);
                x = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->checkTT() == true && a[i]->getTG() == s)
                    {
                        a[i]->xuatSach();
                        x++;
                    }
                }
                if (x == 0) cout << "Khong tim thay tac gia, hoac khong co tieu thuyet trong danh sach" << endl;
                break;
            case 5:
                cout << "Nhap mon hoc: ";
                cin.ignore();
                getline(cin, s);
                x = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->checkSGK() == true && a[i]->getMon() == s)
                    {
                        a[i]->xuatSach();
                        x++;
                    }
                }
                if (x == 0) cout << "Khong tim thay mon hoc, hoac khong co sach giao khoa trong danh sach" << endl;
                break;
            case 6:
                cout << "Nhap thoi gian xuat ban" << endl;
                nxb.nhapDay();
                x = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->checkTT() == true && a[i]->getDay() == nxb)
                    {
                        a[i]->xuatSach();
                        x++;
                    }
                }
                if (x == 0) cout << "Khong tim thay ngay xuat ban, hoac khong co tap chi trong danh sach" << endl;
                break;
            case 7:
                for (int i = 0; i < n -1; i++)
                    for (int j = i + 1; j < n; j++)
                        if (a[i]->getGT() < a[i]->getGT()) swap(a[i],a[j]);
                if (n <= 10)
                {
                    for (int i = 0; i < n; i++)
                        a[i]->xuatSach();
                }
                else
                {
                    for (int i = 0; i < 10; i++)
                        a[i]->xuatSach();
                }
                break;
            case 8:
                cout << "Nhap ma sach: ";
                cin >> ma;
                x = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->getMa() == ma)
                    {
                        cout << "Nhap lai gia tien: ";
                        cin >> tien;
                        a[i]->setGT(tien);
                        x++;
                    }
                }
                if (x == 0) cout << "Khong tim thay sach" << endl;
                break;
            case 9:
                x = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->checkSGK() == true) x++;
                }
                cout << "So sach giao khoa: " << x << endl;
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}
