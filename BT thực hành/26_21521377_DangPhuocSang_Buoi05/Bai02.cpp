#include <bits/stdc++.h>
using namespace std;

typedef class NhanVien
{
    protected:
        int maSo;
        string hoTen;
        int luongCB;
        double luong;
    public:
        NhanVien()
        {
            maSo = luongCB = luong = 0;
            hoTen = "";
        }
        ~NhanVien(){}
        virtual void nhapNV();
        virtual void xuatNV();
        virtual void capnhatLuong(){}
        int getLuongCB();
        int getMa();
        void setLuongCB(int &x);
        double getLuong();
} NV;

void NV::nhapNV()
{
    cout << "Nhap ma so: ";
    cin >> maSo;
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin,hoTen);
}

void NV::xuatNV()
{
    cout << maSo << " " << hoTen << endl;
}

int NV::getLuongCB()
{
    return luongCB;
}

int NV::getMa()
{
    return maSo;
}

double NV::getLuong()
{
    return luong;
}

void NV::setLuongCB(int &x)
{
    luongCB = x;
}

typedef class LapTrinhVien: public NhanVien
{
    protected:
        int soGio;
    public:
        LapTrinhVien():NhanVien()
        {
            luongCB = 7500000;
            soGio = 0;
        }
        ~LapTrinhVien(){}
        void nhapNV();
        void xuatNV();
        void capnhatLuong();
} LTV;

void LTV::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so gio lam them: ";
    cin >> soGio;
}

void LTV::xuatNV()
{
    NV::xuatNV();
    cout << "So gio lam them: " << soGio << endl;
    cout << "Luong: " << luong << endl;
}

void LTV::capnhatLuong()
{
    luong = luongCB + soGio * 250000;
}

typedef class PhanTichVien: public NhanVien
{
    protected:
        int soGio, phuCap;
    public:
        PhanTichVien():NhanVien()
        {
            luongCB = 6500000;
            soGio = phuCap = 0;
        }
        ~PhanTichVien(){}
        void nhapNV();
        void xuatNV();
        void capnhatLuong();
} PTV;

void PTV::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so gio lam them: ";
    cin >> soGio;
    cout << "Nhap tien phu cap: ";
    cin >> phuCap;
}

void PTV::xuatNV()
{
    NV::xuatNV();
    cout << "So gio lam them: " << soGio << endl;
    cout << "So tien phu cap: " << phuCap << endl;
    cout << "Luong: " << luong << endl;
}

void PTV::capnhatLuong()
{
    luong = (luongCB + soGio * 250000) * 1.8;
}

typedef class NhanVienKiem: public NhanVien
{
    protected:
        int soLoi;
    public:
        NhanVienKiem():NhanVien()
        {
            luongCB = 5500000;
            soLoi = 0;
        }
        ~NhanVienKiem(){}
        void nhapNV();
        void xuatNV();
        void capnhatLuong();
} NVK;

void NVK::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so loi da phat hien: ";
    cin >> soLoi;
}

void NVK::xuatNV()
{
    NV::xuatNV();
    cout << "So loi da phat hien: " << soLoi << endl;
    cout << "Luong: " << luong << endl;
}

void NVK::capnhatLuong()
{
    luong = luongCB + soLoi * 85000;
}

int main()
{
    NV *a[200];
    int n, ma, lc, loai, index;
    int x;
    double tb = 0;
    while (1)
    {
        cout << "==========MENU=========" << endl;
        cout << "Lua chon 1: Nhap danh sach nhan vien" << endl;
        cout << "Lua chon 2: Xuat danh sach nhan vien" << endl;
        cout << "Lua chon 3: Xuat danh sach nhan vien co muc luong thap hon muc trung binh" << endl;
        cout << "Lua chon 4: Xuat nhan vien co luong cao nhat" << endl;
        cout << "Lua chon 5: Xuat nhan vien co luong thap nhat" << endl;
        cout << "Lua chon 6: Xuat thong tin lap trinh vien co luong cao nhat" << endl;
        cout << "Lua chon 7: Xuat thong tin nhan vien kiem thu co luong thap nhat" << endl;
        cout << "Lua chon 8: Cap nhat luong co ban theo ma nhan vien" << endl;
        cout << "=======================" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        switch (lc)
        {
            case 1:
                cout << "Nhap so nhan vien: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Nhap 1, 2, 3 de chon LTV, PTV, NVK: ";
                    cin >> loai;
                    switch (loai)
                    {
                        case 1:
                            a[i] = new LTV;
                            a[i]->nhapNV();
                            a[i]->capnhatLuong();
                            break;
                        case 2:
                            a[i] = new PTV;
                            a[i]->nhapNV();
                            a[i]->capnhatLuong();
                            break;
                        case 3:
                            a[i] = new NVK;
                            a[i]->nhapNV();
                            a[i]->capnhatLuong();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                cout << "Xuat danh sach:" << endl;
                for (int i = 0; i < n; i++)
                {
                    a[i]->xuatNV();
                }
                break;
            case 3:
                for (int i = 0; i < n; i++)
                {
                    tb += a[i]->getLuong();
                }
                tb /= n;
                cout << "Luong trung binh: " << tb << endl;
                cout << "Cac nhan vien co luong < luong trung tinh:" << endl;
                for (int i = 0; i < n; i++)
                {
                    if (a[i]->getLuong() < tb) a[i]->xuatNV();
                }
                break;
            case 4:
                index = 0;
                if (n == 0) cout << "Khong co nhan vien" << endl;
                else
                {
                    for (int i = 1; i < n; i++)
                    {
                        if (a[i]->getLuong() > a[index]->getLuong()) index = i;
                    }
                    cout << "Nhan vien co luong cao nhat:" << endl;
                    a[index]->xuatNV();
                }
                break;
            case 5:
                index = 0;
                if (n == 0) cout << "Khong co nhan vien" << endl;
                else
                {
                    for (int i = 1; i < n; i++)
                    {
                        if (a[i]->getLuong() < a[index]->getLuong())
                            index = i;
                    }
                    cout << "Nhan vien co luong thap nhat:" << endl;
                    a[index]->xuatNV();
                }
                break;
            case 6:
                if (n == 0) cout << "Khong co nhan vien" << endl;
                else
                {
                    index = 0;
                    while (a[index]->getLuongCB() != 7500000 && index < n) index++;
                    if (index < n)
                    {
                        for (int i = index + 1; i < n; i++)
                        {
                            if (a[i]->getLuongCB() == 7500000 && a[i]->getLuong() > a[index]->getLuong())
                                index = i;
                        }
                        cout << "Lap trinh vien co luong cao nhat:" << endl;
                        a[index]->xuatNV();
                    }
                    else cout << "Khong co lap trinh vien" << endl;
                }
                break;
            case 7:
                if (n == 0) cout << "Khong co nhan vien" << endl;
                else
                {
                    index = 0;
                    while (a[index]->getLuongCB() != 5500000 && index < n) index++;
                    if (index < n)
                    {
                        for (int i = index + 1; i < n; i++)
                        {
                            if (a[i]->getLuongCB() == 5500000 && a[i]->getLuong() < a[index]->getLuong())
                                index = i;
                        }
                        cout << "Nhan vien kiem co luong thap nhat:" << endl;
                        a[index]->xuatNV();
                    }
                    else cout << "Khong co nhan vien kiem" << endl;
                }
                break;
            case 8:
                cout << "Nhap ma nhan vien: ";
                cin >> ma;
                index = -1;
                for (int i = 0; i < n; i++)
                    if (a[i]->getMa() == ma) index = i;
                if (index != -1)
                {
                    cout << "Nhap lai luong co ban: ";
                    cin >> x;
                    a[index]->setLuongCB(x);
                    a[index]->capnhatLuong();
                    cout << "Da cap nhat" << endl;
                    a[index]->xuatNV();
                }
                else cout << "Khong tin thay nhan vien" << endl;
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}

