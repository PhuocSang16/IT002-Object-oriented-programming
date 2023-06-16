#include <bits/stdc++.h>
using namespace std;

typedef class SinhVien
{
    private:
        int maSo;
        string hoTen;
        string diaChi;
        int soTinChi;
        double TB;
    public:
        SinhVien()
        {
            maSo = soTinChi = 0;
            hoTen = diaChi = "";
            TB = 0;
        }
        SinhVien(int ma, string ten, string dc, int tc, double tb)
        {
            maSo = ma;
            hoTen = ten;
            diaChi = dc;
            soTinChi = tc;
            TB = tb;
        }
        int getTinChi();
        double getTB();
        void nhapSV();
        void xuatSV();
        bool totNghiep();
} SV;

int SV::getTinChi()
{
    return soTinChi;
}

double SV::getTB()
{
    return TB;
}

void SV::nhapSV()
{
    cout << "Nhap ma so SV: ";
    cin >> maSo;
    cout << "Nhap ho va ten SV: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap dia chi SV: ";
    cin.ignore();
    getline(cin, diaChi);
    cout << "Nhap so tin chi cua SV: ";
    cin >> soTinChi;
    cout << "Nhap diem TB: ";
    cin >> TB;
}

void SV::xuatSV()
{
    cout << maSo << "\t" << hoTen << "\t" << diaChi << "\t" << soTinChi << "\t" << TB << endl;
}

bool SV::totNghiep()
{
    return (TB >= 5);
}

typedef class DaiHoc: public SinhVien
{
    private:
        string tenLV;
        double diemLV;
    public:
        DaiHoc():SinhVien()
        {
            tenLV = "";
            diemLV = 0;
        }
        DaiHoc(int ma, string ten, string dc, int tc, double tb, string tlv, double lv):SinhVien(ma,ten,dc,tc,tb)
        {
            tenLV = tlv;
            diemLV = lv;
        }
        void nhapDH();
        void xuatDH();
        bool totNghiep();
        DaiHoc MaxTB(DaiHoc a[], int n);

} DH;

void DH::nhapDH()
{
    SV::nhapSV();
    cout << "Nhap ten luan van: ";
    cin.ignore();
    getline(cin, tenLV);
    cout << "Nhap diem luan van: ";
    cin >> diemLV;
}

void DH::xuatDH()
{
    SV::xuatSV();
    cout << "Ten luan van: " << tenLV << endl;
    cout << "Diem luan van: " << diemLV << endl;
}

bool DH::totNghiep()
{
    if (SV::totNghiep() == true)
    {
        return (SV::getTinChi() >= 120 && diemLV >= 5);
    }
    else
        return false;
}

DH DH::MaxTB(DH a[], int n)
{
    DH kq = a[0];
    for (int i = 1; i < n; i++)
        if (a[i].SV::getTB() > kq.SV::getTB()) kq = a[i];
    return kq;
}

class VB2: public SinhVien
{
    private:
        double diemTN;
    public:
        VB2():SinhVien()
        {
            diemTN = 0;
        }
        VB2(int ma, string ten, string dc, int tc, double tb, double dtn):SinhVien(ma,ten,dc,tc,tb)
        {
            diemTN = dtn;
        }
        void nhapVB2();
        void xuatVB2();
        bool totNghiep();
        VB2 MaxTB(VB2 a[], int n);
};

void VB2::nhapVB2()
{
    SinhVien::nhapSV();
    cout << "Nhap diem tot nghiep: ";
    cin >> diemTN;
}

void VB2::xuatVB2()
{
    SinhVien::xuatSV();
    cout << "Diem tot nghiep cua sinh vien: " << diemTN << endl;
}

bool VB2::totNghiep()
{
    if (SV::totNghiep() == true)
    {
        return (SV::getTinChi() >= 84 && diemTN >= 5);
    }
    return false;
}

VB2 VB2::MaxTB(VB2 a[], int n)
{
    VB2 kq = a[0];
    for (int i = 1; i < n; i++)
        if (a[i].SV::getTB() > kq.SV::getTB()) kq = a[i];
    return kq;
}

int main()
{
    DH a[200]; VB2 b[200];
    DH p; VB2 q;
    int n, x, y;
    double h;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap danh sach cac sinh vien dai hoc" << endl;
        cout << "Lua chon 2: Nhap danh sach cac sinh vien VB2" << endl;
        cout << "Lua chon 3: Xuat danh sach cac sinh vien dai hoc" << endl;
        cout << "Lua chon 4: Xuat danh sach cac sinh vien VB2" << endl;
        cout << "Lua chon 5: Tim sinh vien he DH co diem TB cao nhat" << endl;
        cout << "Lua chon 6: Tim sinh vien he VB2 co diem TB cao nhat" << endl;
        cout << "Lua chon 7: Xuat danh sach cac sinh vien he DH du dieu kien tot nghiep" << endl;
        cout << "Lua chon 8: Xuat danh sach cac sinh vien he VB2 du dieu kien tot nghiep" << endl;
        cout << "Lua chon 9: Xuat danh sach sinh vien chua du dieu kien tot nghiep he DH" << endl;
        cout << "Lua chon 10: Xuat danh sach sinh vien chua du dieu kien tot nghiep he VB2" << endl;
        cout << "============================" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> n;
        switch(n)
        {
            case 1:
                cout << "Nhap so luong sinh vien: ";
                cin >> x;
                for (int i = 0; i < x; i++)
                {
                    cout << "Nhap thong tin sinh vien thu: " << i+1 << endl;
                    a[i].nhapDH();
                }
                break;
            case 2:
                cout << "Nhap so luong sinh vien: ";
                cin >> y;
                for (int i = 0; i < y; i++)
                {
                    cout << "Nhap thong tin sinh vien thu: " << i+1 << endl;
                    b[i].nhapVB2();
                }
                break;
            case 3:
                if (x == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien he DH" << endl;
                    for (int i = 0; i < x; i++)
                        a[i].xuatDH();
                }
                break;
            case 4:
                if (y == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien he VB2" << endl;
                    for (int i = 0; i < y; i++)
                        b[i].xuatVB2();
                }
                break;
            case 5:
                if (!x)
                {
                    cout << "Sinh vien DH co diem TB cao nhat:" << endl;
                    p.MaxTB(a,x).xuatDH();
                }
                else
                    cout << "Danh sach khong co sinh vien hoac khong tim thay" << endl;
                break;
            case 6:
                if (!y)
                {
                    cout << "Sinh vien VB2 co diem TB cao nhat:" << endl;
                    q.MaxTB(b,y).xuatVB2();
                }
                else
                    cout << "Danh sach khong co sinh vien hoac khong tim thay" << endl;
                break;
            case 7:
                if (x == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien DH du dieu kien tot nghiep" << endl;
                    for (int i = 0; i < x; i++)
                        if (a[i].totNghiep() == true)
                            a[i].xuatDH();
                }
                break;
            case 8:
                if (y == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien VB2 du dieu kien tot nghiep" << endl;
                    for (int i = 0; i < y; i++)
                        if (b[i].totNghiep() == true)
                            b[i].xuatVB2();
                }
                break;
            case 9:
                if (x == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien DH chua du dieu kien tot nghiep" << endl;
                    for (int i = 0; i < x; i++)
                        if (a[i].totNghiep() == false)
                            a[i].xuatDH();
                }
                break;
            case 10:
                if (y == 0)
                    cout << "Danh sach rong" << endl;
                else
                {
                    cout << "Danh sach sinh vien VB2 chua du dieu kien tot nghiep" << endl;
                    for (int i = 0; i < y; i++)
                        if (b[i].totNghiep() == false)
                            b[i].xuatVB2();
                }
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}

