#include <bits/stdc++.h>
using namespace std;

typedef class NhanVien
{
    protected:
        int maNV;
        string hoTen;
        int luongCB;
        int luong;
    public:
        NhanVien()
        {
            maNV = luong = luongCB = 0;
            hoTen = "";
        }
        int getLuongCB();
        void setMa(const int &ma);
        void setTen(string &ten);
        virtual int getSoSP()
        {
            return 0;
        }
        int getLuong();
        int getMa();
        virtual void nhapNV();
        virtual void randomNV();
        virtual void xuatNV();
        virtual void updateLuong(){};
        virtual void xuatNVcoluong(){};
} NV;

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
        int getSoSP()
        {
            return soSP;
        }
        void xuatNV();
        void xuatNVcoluong();
        void randomNV();
        void updateLuong();
} SX;

typedef class VanPhong: public NhanVien
{
    protected:
        int soNgay;
    public:
        VanPhong():NhanVien()
        {
            soNgay = 0;
            luongCB = 4500000;
        }
        void nhapNV();
        void xuatNV();
        void xuatNVcoluong();
        void randomNV();
        void updateLuong();
} VP;

int NV::getLuong()
{
    return luong;
}

int NV::getLuongCB()
{
    return luongCB;
}

int NV::getMa()
{
    return maNV;
}

void NV::setMa(const int &ma)
{
    maNV = ma;
}

void NV::setTen(string &ten)
{
    hoTen = ten;
}

void NV::nhapNV()
{
    cout << "Nhap ma so: ";
    cin >> maNV;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
}

void SX::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so san pham: ";
    cin >> soSP;
}

void VP::nhapNV()
{
    NV::nhapNV();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgay;
}

void NV::xuatNV()
{
    cout << maNV << " " << hoTen << endl;
}

void SX::xuatNV()
{
    NV::xuatNV();
    cout << "So san pham: " << soSP << endl;
}

void VP::xuatNV()
{
    NV::xuatNV();
    cout << "So ngay lam viec: " << soNgay << endl;
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
}

void SX::randomNV()
{
    NV::randomNV();
    int x = rand() % 50;
    soSP = 1 + x;
}

void VP::randomNV()
{
    NhanVien::randomNV();
    int x = rand() % 30;
    soNgay = 1 + x;
}

void SX::updateLuong()
{
    luong = luongCB + soSP * 170000;
}

void VP::updateLuong()
{
    luong = luongCB + soNgay * 220000;
}

void SX::xuatNVcoluong()
{
    SX::xuatNV();
    cout << "Luong: " << luong << endl;
}

void VP::xuatNVcoluong()
{
    VP::xuatNV();
    cout << "Luong: " << luong << endl;
}


int main()
{
    NV *a[200];
    int ma, n, k, lc, loai, index, x, dem;
    string s;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap nhan vien thu cong" << endl;
        cout << "Lua chon 2: Nhap nhan vien tu dong" << endl;
        cout << "Lua chon 3: Xuat nhan vien" << endl;
        cout << "Lua chon 4: Tinh va cap nhat luong" << endl;
        cout << "Lua chon 5: Tim nhan vien theo ma nhan vien" << endl;
        cout << "Lua chon 6: Cap nhat nhan vien theo ma nhan vien" << endl;
        cout << "Lua chon 7: Tim nhan vien co luong cao nhat" << endl;
        cout << "Lua chon 8: Tim nhan vien co so san pham thap nhat" << endl;
        cout << "Lua chon 9: Tim top 10 nhan vien co nhieu san pham nhat" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        switch(lc)
        {
            case 1:
                cout << "Nhap so luong nhan vien: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Nhap 0 de nhap nhan vien San Xuat" << endl;
                    cout << "Nhap 1 de nhap nhan vien Van Phong" << endl;
                    cout << "Nhap loai: ";
                    cin >> loai;
                    if (loai == 0)
                    {
                        a[i] = new SX;
                    }
                    else
                    {
                        a[i] = new VP;
                    }
                    a[i]->nhapNV();
                }
                break;
            case 2:
                cout << "Nhap so luong nhan vien: ";
                cin >> n;
                srand((int)time(0));
                for (int i = 0; i < n; i++)
                {
                    loai = rand() % 2;
                    if (loai == 0)
                    {
                        a[i] = new SX;
                        a[i]->randomNV();
                    }
                    if (loai == 1)
                    {
                        a[i] = new VP;
                        a[i]->randomNV();
                    }
                }
                break;
            case 3:
                cout << "Xuat nhan vien" << endl;
                for (int i = 0; i < n; i++)
                {
                    a[i]->xuatNV();
                }
                break;
            case 4:
                cout << "Cap nhat luong" << endl;
                for (int i = 0; i < n; i++)
                {
                    a[i]->updateLuong();
                    a[i]->xuatNVcoluong();
                }
                break;
            case 5:
                cout << "Nhap ma nhan vien can tim: ";
                cin >> ma;
                index = -1;
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
                    a[index]->xuatNV();
                }
                break;
            case 6:
                cout << "Nhap ma nhan vien can tim: ";
                cin >> ma;
                index = -1;
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
                    cout << "Nhap 1 de thay doi ma nhan vien" << endl;
                    cout << "Nhap 2 de thay doi ten nhan vien" << endl;
                    cout << "Nhap 3 de thay doi loai nhan vien" << endl;
                    cout << "Nhap: ";
                    cin >> k;
                    switch(k)
                    {
                        case 1:
                            cout << "Nhap ma so moi: ";
                            cin >> ma;
                            a[index]->setMa(ma);
                            break;
                        case 2:
                            cout << "Nhap ten moi: ";
                            cin.ignore();
                            getline(cin, s);
                            a[index]->setTen(s);
                            break;
                        case 3:
                            cout << "Nhap 1 de doi thanh nhan vien SX, 2 de doi thanh nhan vien VP: ";
                            cout << x;
                            if (x == 1)
                            {
                                a[index] = new SX;
                                a[index]->nhapNV();
                            }
                            if (x == 2)
                            {
                                a[index] = new VP;
                                a[index]->nhapNV();
                            }
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 7:
                index = 0;
                a[0]->updateLuong();
                for (int i = 1; i < n && a[i]->getLuongCB() == 5300000; i++)
                {
                    a[i]->updateLuong();
                    if (a[i]->getLuong() > a[index]->getLuong()) index = i;
                }
                cout << "Nhan vien co luong cao nhat la:" << endl;
                a[index]->xuatNVcoluong();
                break;
            case 8:
                index = 0;
                while (a[index]->getLuongCB() != 5300000) index++;
                for (int i = index + 1; i < n; i++)
                {
                    if (a[i]->getLuongCB() != 5300000) continue;
                    else if (a[i]->getSoSP() < a[index]->getSoSP()) index = i;
                }
                if (index > n) cout << "Khong co nhan vien san xuat" << endl;
                else
                {
                    cout << "Nhan vien san xuat co so san pham it nhat la:" << endl;
                    a[index]->xuatNVcoluong();
                }
                break;
            case 9:
                cout << "Top 10 nhan vien co so san pham cao nhat" << endl;
                for (int i = 0; i < n - 1; i++)
                {
                    if (a[i]->getLuongCB() != 5300000) continue;
                    else for (int j = i + 1; j < n; j++)
                    {
                        if (a[j]->getLuongCB() != 5300000) continue;
                        else if (a[i]->getSoSP() < a[j]->getSoSP()) swap(a[i], a[j]);
                    }
                }
                dem = 0;
                for (int i = 0; i < n && dem < 10; i++)
                {
                    if(a[i]->getLuongCB() != 5300000) continue;
                    else
                    {
                        dem++;
                        a[i]->xuatNVcoluong();
                    }
                }
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}

