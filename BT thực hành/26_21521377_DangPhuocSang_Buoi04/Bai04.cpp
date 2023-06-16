#include <bits/stdc++.h>
using namespace std;

typedef class NhanVien
{
    private:
        int ma;
        string ten;
        int luong;
    public:
        NhanVien()
        {
            ma = 0;
            ten = "";
            luong = 0;
        }
        NhanVien(int m, string t)
        {
            ma = m;
            ten = t;
            luong = 0;
        }
        void nhapNV();
        void randomNV();
        void xuatNV();
        void xuatNVcoluong();
        void capnhatNV(NhanVien a[], int &n, int m);
        int getLuong();
        void setLuong(int x);
        int timNV(NhanVien a[], int n, int ma);
        int maxluong(NhanVien a[], int n);
        int minluong(NhanVien a[], int n);
} NV;

void NV::nhapNV()
{
    cout << "Nhap ma NV: ";
    cin >> ma;
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, ten);
}

void NV::randomNV()
{
    ma = 1000 + rand() % 10000;
    string first[5] = {"Nguyen","Tran","Le","Ly","Dang"};
    string middle[6] = {"Khanh","Phuoc","Kim","Gia","Huynh","Minh"};
    string name[5] = {"Sang","Vy","Ha","Giang","Thu"};
    int h = rand() % 5;
    int l = rand() % 6;
    int t = rand() % 5;
    ten = first[h] + " " + middle[l] + " " + name[t] + "\0";
}

void NV::xuatNV()
{
    cout << ma << "\t" << ten;
}

void NV::xuatNVcoluong()
{
    xuatNV();
    cout << "\t" << luong << endl;
}

int NV::timNV(NV a[], int n, int ma)
{
    for (int i = 0; i < n; i++)
        if (a[i].ma == ma)
            return i;
    return -1;
}

void NV::capnhatNV(NV a[], int &n, int ma)
{
    int index = timNV(a,n,ma);
    int luachon;
    cout << "Nhap 1 de thay doi ma so" << endl;
    cout << "Nhap 2 de thay doi ho ten" << endl;
    cout << "Nhap lua chon: ";
    cin >> luachon;
    switch(luachon)
    {
        case 1:
            cout << "Nhap ma so moi: ";
            cin >> a[index].ma;
            break;
        case 2:
            cout << "Nhap ho va ten moi: ";
            cin.ignore();
            getline(cin,a[index].ten);
            break;
        default:
            exit(1);
            break;
    }
}

int NV::getLuong()
{
    return luong;
}

void NV::setLuong(int x)
{
    luong = x;
}

int NV::maxluong(NV a[], int n)
{
    if (n == 0) return -1;
    int Max = a[0].luong;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].luong > Max)
        {
            Max = a[i].luong;
            index = i;
        }
    }
    return index;
}

int NV::minluong(NV a[], int n)
{
    if (n == 0) return -1;
    int Min = a[0].luong;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].luong < Min)
        {
            Min = a[i].luong;
            index = i;
        }
    }
    return index;
}

typedef class SanXuat: public NhanVien
{
    private:
        int soSP;
        int luongCB;
    public:
        SanXuat():NhanVien()
        {
            soSP = 0;
            luongCB = 5300000;
        }
        SanXuat(int m, string t, int sp):NhanVien(m,t)
        {
            soSP = sp;
            luongCB = 5300000;
        }
        void nhapSX();
        void randomSX();
        int getLuongCB();
        int getSoSP();
        void xuatSX();
        void capnhatluongSX();
        void xuatSXcoluong();
        void top10SX(SanXuat a[], int &n);
} SX;

void SX::nhapSX()
{
    NV::nhapNV();
    cout << "Nhap so san pham: ";
    cin >> soSP;
}

void SX::randomSX()
{
    NV::randomNV();
    soSP = rand() % 50;
}

void SX::xuatSX()
{
    NV::xuatNV();
    cout << "\t" << soSP << endl;
}

int SX::getLuongCB()
{
    return luongCB;
}

int SX::getSoSP()
{
    return soSP;
}

void SX::capnhatluongSX()
{
    NV::setLuong(getLuongCB() + getSoSP() * 170000);
}

void SX::xuatSXcoluong()
{
    xuatSX();
    cout << "Luong: " << NV::getLuong() << endl;
}

void SX::top10SX(SX a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].getLuong() < a[j].getLuong()) swap(a[i],a[j]);
        }
    }
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].xuatSXcoluong();
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            a[i].xuatSXcoluong();
        }
    }
}

typedef class VanPhong: public NhanVien
{
    private:
        int soNgay;
        int luongCB;
    public:
        VanPhong():NhanVien()
        {
            soNgay = 0;
            luongCB = 4500000;
        }
        VanPhong(int m, string t, int sn):NhanVien(m,t)
        {
            soNgay = sn;
            luongCB = 4500000;
        }
        void nhapVP();
        void randomVP();
        int getLuongCB();
        int getSoNgay();
        void xuatVP();
        void capnhatluongVP();
        void xuatVPcoluong();
        void top10VP(VanPhong a[], int &n);
} VP;

void VP::nhapVP()
{
    NV::nhapNV();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgay;
}

void VP::randomVP()
{
    NV::randomNV();
    soNgay = rand() % 30;
}

void VP::xuatVP()
{
    NV::xuatNV();
    cout << "\t" << soNgay << " ngay" << endl;
}

int VP::getLuongCB()
{
    return luongCB;
}

int VP::getSoNgay()
{
    return soNgay;
}

void VP::capnhatluongVP()
{
    NV::setLuong(getLuongCB() + getSoNgay() * 220000);
}

void VP::xuatVPcoluong()
{
    xuatVP();
    cout << "Luong: " << NV::getLuong() << endl;
}

void VP::top10VP(VP a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].getLuong() < a[j].getLuong()) swap(a[i],a[j]);
        }
    }
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].xuatVPcoluong();
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            a[i].xuatVPcoluong();
        }
    }
}

int main()
{
    NV h;
    SX a1; VP b1;
    SX a[200];
    VP b[200];
    int n, k, x, y, index;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap danh sach nhan vien SX" << endl;
        cout << "Lua chon 2: Nhap danh sach nhan vien VP" << endl;
        cout << "Lua chon 3: Random ngau nhien ca 2 loai nhan vien" << endl;
        cout << "Lua chon 4: Xuat danh sach ca 2 loai nhan vien" << endl;
        cout << "Lua chon 5: Tinh va cap nhat luong cho tat ca nhan vien" << endl;
        cout << "Lua chon 6: Tim nhan vien theo ma" << endl;
        cout << "Lua chon 7: Cap nhat thong tin bat ky theo ma" << endl;
        cout << "Lua chon 8: Tim nhan vien co luong thap nhat o 2 danh sach" << endl;
        cout << "Lua chon 9: Tim nhan vien co luong cao nhat o 2 danh sach" << endl;
        cout << "Lua chon 10: Tim top 10 nhan vien co luong cao nhat o ca 2 danh sach" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                cout << "Nhap so luong nhan vien: ";
                cin >> x;
                for (int i = 0; i < x; i++)
                    a[i].nhapSX();
                break;
            case 2:
                cout << "Nhap so luong nhan vien: ";
                cin >> y;
                for (int i = 0; i < y; i++)
                    b[i].nhapVP();
                break;
            case 3:
                cout << "Nhap so luong nhan vien SX: ";
                cin >> x;
                srand((int)time(0));
                for (int i = 0; i < x; i++)
                    a[i].randomSX();
                cout << "Nhap so luong nhan vien VP: ";
                cin >> y;
                srand((int)time(0));
                for (int i = 0; i < y; i++)
                    b[i].randomVP();
                break;
            case 4:
                if (x != 0)
                {
                    cout << "Danh sach nhan vien SX:" << endl;
                    for (int i = 0; i < x; i++)
                        a[i].xuatSX();
                }
                else
                    cout << "Danh sach nhan vien SX rong" << endl;
                if (y != 0)
                {
                    cout << "Danh sach nhan vien VP:" << endl;
                    for (int i = 0; i < y; i++)
                        b[i].xuatVP();
                }
                else
                    cout << "Danh sach nhan vien VP rong" << endl;
                break;
            case 5:
                if (x != 0)
                {
                    cout << "Cap nhat luong cho nhan vien SX" << endl;
                    cout << endl;
                    for (int i = 0; i < x; i++)
                    {
                        a[i].capnhatluongSX();
                        a[i].xuatSXcoluong();
                    }
                }
                else
                    cout << "Danh sach SX rong" << endl;
                if (y != 0)
                {
                    cout << "Cap nhat luong cho nhan vien VP" << endl;
                    cout << endl;
                    for (int i = 0; i < y; i++)
                    {
                        b[i].capnhatluongVP();
                        b[i].xuatVPcoluong();
                    }
                }
                else
                    cout << "Danh sach VP rong" << endl;
                break;
            case 6:
                cout << "Nhap ma nhan vien can tim: ";
                cin >> k;
                if (h.timNV(a,x,k) != -1)
                {
                    index = h.timNV(a,x,k);
                    cout << "Da tim thay" << endl;
                    cout << endl;
                    a[index].xuatSX();
                }
                else if (h.timNV(b,y,k) != -1)
                {
                    index = h.timNV(b,y,k);
                    cout << "Da tim thay" << endl;
                    cout << endl;
                    b[index].xuatVP();
                }
                else
                    cout << "Khong tim thay" << endl;
                break;
            case 7:
                cout << "Nhap ma nhan vien can tim de cap nhat: ";
                cin >> k;
                if (h.timNV(a,x,k) != -1)
                    h.capnhatNV(a,x,k);
                else if (h.timNV(b,y,k) != -1)
                    h.capnhatNV(b,y,k);
                else
                    cout << "Khong tim thay" << endl;
                break;
            case 8:
                if (x != 0)
                {
                    cout << "Cap nhat luong cho nhan vien SX" << endl;
                    cout << endl;
                    for (int i = 0; i < x; i++)
                    {
                        a[i].capnhatluongSX();
                    }
                }
                else
                    cout << "Danh sach SX rong" << endl;
                if (y != 0)
                {
                    cout << "Cap nhat luong cho nhan vien VP" << endl;
                    cout << endl;
                    for (int i = 0; i < y; i++)
                    {
                        b[i].capnhatluongVP();
                    }
                }
                else
                    cout << "Danh sach VP rong" << endl;
                if (x != 0)
                {
                    cout << "Nhan vien SX co luong thap nhat la:" << endl;
                    index = h.minluong(a,x);
                    a[index].xuatSXcoluong();
                }
                if (y != 0)
                {
                    cout << "Nhan vien VP co luong thap nhat la:" << endl;
                    index = h.minluong(b,y);
                    b[index].xuatVPcoluong();
                }
                break;
            case 9:
                if (x != 0)
                {
                    cout << "Cap nhat luong cho nhan vien SX" << endl;
                    cout << endl;
                    for (int i = 0; i < x; i++)
                    {
                        a[i].capnhatluongSX();
                    }
                }
                else
                    cout << "Danh sach SX rong" << endl;
                if (y != 0)
                {
                    cout << "Cap nhat luong cho nhan vien VP" << endl;
                    cout << endl;
                    for (int i = 0; i < y; i++)
                    {
                        b[i].capnhatluongVP();
                    }
                }
                else
                    cout << "Danh sach VP rong" << endl;
                if (x != 0)
                {
                    cout << "Nhan vien SX co luong cao nhat la:" << endl;
                    index = h.maxluong(a,x);
                    a[index].xuatSXcoluong();
                }
                if (y != 0)
                {
                    cout << "Nhan vien VP co luong cao nhat la:" << endl;
                    index = h.maxluong(b,y);
                    b[index].xuatVPcoluong();
                }
                break;
            case 10:
                if (x != 0)
                {
                    cout << "Cap nhat luong cho nhan vien SX" << endl;
                    cout << endl;
                    for (int i = 0; i < x; i++)
                    {
                        a[i].capnhatluongSX();
                    }
                    cout << "Top 10 NV:" << endl;
                    a1.top10SX(a,x);
                }
                else
                    cout << "Danh sach SX rong" << endl;
                if (y != 0)
                {
                    cout << "Cap nhat luong cho nhan vien VP" << endl;
                    cout << endl;
                    for (int i = 0; i < y; i++)
                    {
                        b[i].capnhatluongVP();
                    }
                    cout << "Top 10 NV:" << endl;
                    b1.top10VP(b,y);
                }
                else
                    cout << "Danh sach VP rong" << endl;
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(0);
        }
    }
    return 0;
}
