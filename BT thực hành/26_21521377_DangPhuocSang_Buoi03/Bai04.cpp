#include <bits/stdc++.h>
using namespace std;

typedef class NhanVien
{
    private:
        int maSo;
        string hoTen;
        int soSP;
        int luong;
    public:
        void nhapNV();
        void xuatNV();
        void randomNV(NhanVien a[], int &n);
        int timNV(NhanVien a[], int n, int ma);
        void capnhatNV(NhanVien a[], int &n, int ma);
        void luongNV(NhanVien a[], int &n);
        void xuatNVcoluong();
        NhanVien maxluong(NhanVien a[], int n);
        NhanVien minluong(NhanVien a[], int n);
        void top10NV(NhanVien a[], int &n);
} NV;

void NV::nhapNV()
{
    cout << "Nhap ma so NV: ";
    cin >> maSo;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin,hoTen);
    cout << "Nhap so san pham da lam: ";
    cin >> soSP;
}

void NV::xuatNV()
{
    cout << maSo << " " << hoTen << " " << soSP << endl;
}

void NV::randomNV(NV a[], int &n)
{
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        a[i].maSo = 1000 + rand() % 10000;
        string ho[5] = {"Nguyen","Tran","Le","Ly","Dang"};
        string lot[6] = {"Khanh","Phuoc","Kim","Gia","Huynh","Minh"};
        string ten[5] = {"Sang","Vy","Ha","Giang","Thu"};
        int h = rand() % 5;
        int l = rand() % 6;
        int t = rand() % 5;
        a[i].hoTen = ho[h] + " " + lot[l] + " " + ten[t] + "\0";
        a[i].soSP = rand() % 50;
    }

}

int NV::timNV(NV a[], int n, int ma)
{
    for (int i = 0; i < n; i++)
        if (a[i].maSo == ma)
            return i;
    return -1;
}

void NV::capnhatNV(NV a[], int &n, int ma)
{
    int index = timNV(a,n,ma);
    int luachon;
    if (index != -1)
    {
        cout << "Nhap 1 de thay doi ma so" << endl;
        cout << "Nhap 2 de thay doi ho ten" << endl;
        cout << "Nhap 3 de thay doi so sp lam ra" << endl;
        cout << "Nhap lua chon: ";
        cin >> luachon;
        switch(luachon)
        {
            case 1:
                cout << "Nhap ma so moi: ";
                cin >> a[index].maSo;
                break;
            case 2:
                cout << "Nhap ho va ten moi: ";
                cin.ignore();
                getline(cin,a[index].hoTen);
                break;
            case 3:
                cout << "Cap nhat so san pham lam ra: ";
                cin >> a[index].soSP;
                break;
            default:
                exit(1);
        }
    }
    else
        cout << "Khong tim thay nhan vien nay" << endl;
}

void NV::luongNV(NV a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].luong = 4500000 + a[i].soSP * 175000;
    }
    cout << "Da cap nhat luong nhan vien" << endl;
}

void NV::xuatNVcoluong()
{
    cout << maSo << " " << hoTen << " " << soSP << " " << luong << endl;
}

NV NV::maxluong(NV a[], int n)
{
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
    return a[index];
}

NV NV::minluong(NV a[], int n)
{
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
    return a[index];
}

void NV::top10NV(NV a[], int &n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].luong < a[j].luong) swap(a[i],a[j]);
        }
    }
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            a[i].xuatNVcoluong();
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            a[i].xuatNVcoluong();
        }
    }
}

int main()
{
    NV a[500];
    NV nv;
    int n, k;
    int ma;
    while(1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap nhan vien thu cong" << endl;
        cout << "Lua chon 2: Khoi tao ngau nhien nhan vien" << endl;
        cout << "Lua chon 3: Xuat cac nhan vien" << endl;
        cout << "Lua chon 4: Tim nhan vien theo ma" << endl;
        cout << "Lua chon 5: Cap nhat thong tin nhan vien theo ma" << endl;
        cout << "Lua chon 6: Cap nhat luong" << endl;
        cout << "Lua chon 7: Tim nhan vien co luong cao nhat" << endl;
        cout << "Lua chon 8: Tim nhan vien co luong thap nhat" << endl;
        cout << "Lua chon 9: Xuat top 10 nhan vien co luong cao nhat" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> k;
        switch(k)
        {
            case 1:
                cout << "Nhap so luong nhan vien: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    a[i].nhapNV();
                }
                break;
            case 2:
                cout << "Nhap so luong nhan vien muon khoi tao ngau nhien: ";
                cin >> n;
                nv.randomNV(a,n);
                break;
            case 3:
                cout << "Xuat tat ca nhan vien" << endl;
                for (int i = 0; i < n; i++)
                {
                    a[i].xuatNV();
                }
                break;
            case 4:
                cout << "Nhap ma nhan vien can tim: ";
                cin >> ma;
                if (nv.timNV(a,n,ma) == -1)
                    cout << "Khong tim thay" << endl;
                else
                    a[nv.timNV(a,n,ma)].xuatNV();
                break;
            case 5:
                cout << "Nhap ma nhan vien can cap nhat: ";
                cin >> ma;
                nv.capnhatNV(a,n,ma);
                break;
            case 6:
                nv.luongNV(a,n);
                for (int i = 0; i < n; i++)
                    a[i].xuatNVcoluong();
                break;
            case 7:
                nv = nv.maxluong(a,n);
                cout << "Nhan vien co luong cao nhat:" << endl;
                nv.xuatNVcoluong();
                break;
            case 8:
                nv = nv.minluong(a,n);
                cout << "Nhan vien co luong thap nhat:" << endl;
                nv.xuatNVcoluong();
                break;
            case 9:
                nv.top10NV(a,n);
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}


