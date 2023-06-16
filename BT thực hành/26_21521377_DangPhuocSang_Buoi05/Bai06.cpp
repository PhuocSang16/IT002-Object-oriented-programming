#include <bits/stdc++.h>
using namespace std;

class Day
{
    public:
        int day, month, year;
        bool checkDay()
        {
            int dayMax;
            if (day < 1 || day > 31 || month < 1 || month > 12) return false;
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                switch(month)
                {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        dayMax = 31;
                        break;
                    case 2:
                        dayMax = 29;
                        break;
                    default:
                        dayMax = 30;
                        break;
                }
            }
            else
            {
                switch(month)
                {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        dayMax = 31;
                        break;
                    case 2:
                        dayMax = 28;
                        break;
                    default:
                        dayMax = 30;
                        break;
                }
            }
            return (day <= dayMax);
        }
        void nhapDay();
        void randomDay();
        void xuatDay();
};

void Day::nhapDay()
{
    cout << "Nhap ngay thang nam: ";
    cin >> day >> month >> year;
    while (checkDay() == false)
    {
        cout << "Khong hop le, nhap lai: ";
        cin >> day >> month >> year;
    }
}

void Day::xuatDay()
{
    cout << day << "/" << month << "/" << year << endl;
}

void Day::randomDay()
{
    while (checkDay() == false)
    {
        day = rand() % 31 + 1;
        month = rand() % 12 + 1;
        year = rand() % 100 + 2000;
    }
}

typedef class NhanVien
{
    protected:
        int maNV;
        string hoTen;
        int luongCB;
        Day ngaySinh;
        int luong;
    public:
        NhanVien()
        {
            maNV = luong = luongCB = 0;
            hoTen = "";
        }
        int getLuongCB();
        virtual int getSoSP()
        {
            return 0;
        }
        int getLuong();
        int getMa();
        void setLuongCB(int x);
        virtual bool checkSX()
        {
            return false;
        }
        virtual bool checkVP()
        {
            return false;
        }
        virtual bool checkQL()
        {
            return false;
        }
        virtual void nhapNV();
        virtual void randomNV();
        virtual void xuatNV();
        virtual void updateLuong(){};
        virtual void xuatNVcoluong(){};
} NV;

int NV::getLuongCB()
{
    return luongCB;
}

int NV::getLuong()
{
    return luong;
}

int NV::getMa()
{
    return maNV;
}

void NV::setLuongCB(int x)
{
    luongCB = x;
}

void NV::nhapNV()
{
    cout << "Nhap ma so: ";
    cin >> maNV;
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin,hoTen);
    ngaySinh.nhapDay();
}

void NV::randomNV()
{
    maNV = 1000 + rand() % 10000;
    string first[5] = {"Nguyen","Tran","Le","Ly","Dang"};
    string middle[6] = {"Khanh","Phuoc","Kim","Gia","Huynh","Minh"};
    string name[5] = {"Sang","Vy","Ha","Giang","Thu"};
    int h = rand() % 5;
    int l = rand() % 6;
    int t = rand() % 5;
    hoTen = first[h] + " " + middle[l] + " " + name[t] + "\0";
    ngaySinh.randomDay();
}

void NV::xuatNV()
{
    cout << maNV << " " << hoTen << endl;
    ngaySinh.xuatDay();
}

typedef class SanXuat: public NhanVien
{
    protected:
        int soSP;
    public:
        SanXuat():NhanVien()
        {
            soSP = 0;
            luongCB = 5300000;
        }
        void nhapNV();
        void xuatNV();
        bool checkSX()
        {
            return true;
        }
        int getSoSP()
        {
            return soSP;
        }
        void randomNV();
        void updateLuong();
        void xuatNVcoluong();
} SX;

void SX::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so san pham: ";
    cin >> soSP;
}

void SX::randomNV()
{
    NV::randomNV();
    soSP = rand() % 50 + 1;
}

void SX::xuatNV()
{
    NV::xuatNV();
    cout << "So san pham: " << soSP << endl;
}

void SX::updateLuong()
{
    luong = luongCB + soSP * 175000;
}

void SX::xuatNVcoluong()
{
    SX::xuatNV();
    cout << "Luong: " << luong << endl;
}

typedef class VanPhong: public NhanVien
{
    protected:
        int soNgay, troCap;
    public:
        VanPhong():NhanVien()
        {
            soNgay = troCap = 0;
            luongCB = 4500000;
        }
        bool checkVP()
        {
            return true;
        }
        void nhapNV();
        void randomNV();
        void xuatNV();
        void xuatNVcoluong();
        void updateLuong();
} VP;

void VP::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgay;
    cout << "Nhap tien tro cap: ";
    cin >> troCap;
}

void VP::randomNV()
{
    NV::randomNV();
    soNgay = rand() % 31 + 1;
    troCap = (rand() % 5 + 1) * 1000000;
}

void VP::xuatNV()
{
    NV::xuatNV();
    cout << "So ngay lam viec: " << soNgay << endl;
    cout << "So tien tro cap: " << troCap << endl;
}

void VP::updateLuong()
{
    luong = luongCB + soNgay * 220000 + troCap;
}

void VP::xuatNVcoluong()
{
    VP::xuatNV();
    cout << "Luong: " << luong << endl;
}

typedef class QuanLy: public NhanVien
{
    protected:
        float heSo;
        int thuong;
    public:
        QuanLy():NhanVien()
        {
            heSo = 0.0;
            thuong = 0;
            luongCB = 5000000;
        }
        bool checkQL()
        {
            return true;
        }
        void nhapNV();
        void xuatNV();
        void randomNV();
        void updateLuong();
        void xuatNVcoluong();
} QL;

void QL::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap he so chuc vu: ";
    cin >> heSo;
    cout << "Nhap tien thuong: ";
    cin >> thuong;
}

void QL::xuatNV()
{
    NV::xuatNV();
    cout << "He so chuc vu: " << heSo << endl;
    cout << "Tien thuong: " << thuong << endl;
}

void QL::randomNV()
{
    NV::randomNV();
    heSo = (rand() % 100) / 10.0;
    thuong = (rand() % 10 + 1) * 1000000;
}

void QL::updateLuong()
{
    luong = luongCB * heSo + thuong;
}

void QL::xuatNVcoluong()
{
    QL::xuatNV();
    cout << "Luong: " << luong << endl;
}

int main()
{
    NV *a[500];
    int n, k, index, ma, x;
    float tong, tb;

    //Cau 1
    cout << "Nhap thu cong" << endl;
    cout << "Nhap so nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap 1 de nhap SX" << endl;
        cout << "Nhap 2 de nhap VP" << endl;
        cout << "Nhap 3 de nhap QL" << endl;
        cout << "Nhap: ";
        cin >> k;
        switch (k)
        {
            case 1:
                a[i] = new SX;
                a[i]->nhapNV();
                break;
            case 2:
                a[i] = new VP;
                a[i]->nhapNV();
                break;
            case 3:
                a[i] = new SX;
                a[i]->nhapNV();
                break;
            default:
                break;
        }
    }

    //Cau 2
    n = 20;
    cout << "Khoi tao ngau nhien 20 nhan vien" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap 1 de khoi tao SX" << endl;
        cout << "Nhap 2 de khoi tao VP" << endl;
        cout << "Nhap 3 de khoi tao QL" << endl;
        cout << "Nhap: ";
        cin >> k;
        switch (k)
        {
            case 1:
                a[i] = new SX;
                a[i]->randomNV();
                break;
            case 2:
                a[i] = new VP;
                a[i]->randomNV();
                break;
            case 3:
                a[i] = new SX;
                a[i]->randomNV();
                break;
            default:
                break;
        }
    }

    //Cau 3
    for (int i = 0; i < n; i++)
    {
        a[i]->updateLuong();
        a[i]->xuatNVcoluong();
    }

    //Cau 4
    for (int i = 0; i < n; i++)
        a[i]->xuatNV();

    //Cau 5
    tong = 0;
    for (int i = 0; i < n; i++)
        tong += a[i]->getLuong();
    tb = (float)tong / n;
    cout << "Tong luong: " << tong << endl;
    cout << "Trung binh luong: " << tb << endl;

    //Cau 6
    index = -1;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->getMa() == ma)
        {
            index = i;
            break;
        }
    }
    if (index == -1) cout << "Khong tim thay" << endl;
    else
    {
        cout << "Da tim thay" << endl;
        a[index]->xuatNVcoluong();
    }

    //Cau 7
    NV *ans = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i]->getLuong() > ans->getLuong()) ans = a[i];
    }
    cout << "Nhan vien co luong cao nhat la:" << endl;
    ans->xuatNVcoluong();

    //Cau 8
    cout << "Nhap 1, 2, 3 tuong ung voi SX, VP, QL: ";
    cin >> k;
    switch (k)
    {
        case 1:
            for (int i = 0; i < n; i++)
            {
                if (a[i]->checkSX() == true)
                {
                    cout << "Cap nhat lai luongCB: ";
                    cin >> x;
                    a[i]->setLuongCB(x);
                }
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                if (a[i]->checkVP() == true)
                {
                    cout << "Cap nhat lai luongCB: ";
                    cin >> x;
                    a[i]->setLuongCB(x);
                }
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                if (a[i]->checkQL() == true)
                {
                    cout << "Cap nhat lai luongCB: ";
                    cin >> x;
                    a[i]->setLuongCB(x);
                }
            }
            break;
        default:
            break;
    }

    //Cau 9
    index = -1;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;
    for (int i = 0; i < n; i++)
    {
        if (a[i]->getMa() == ma)
        {
            index = i;
            break;
        }
    }
    if (index == -1) cout << "Khong tim thay" << endl;
    else
    {
        cout << "Da tim thay" << endl;
        delete a[index];
    }

    //Cau 10
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i]->getLuong() > a[j]->getLuong()) swap(a[i],a[j]);
    for (int i = 0; i < n; i++)
        a[i]->xuatNVcoluong();

    return 0;
}
