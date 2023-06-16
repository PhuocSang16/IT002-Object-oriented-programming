#include <bits/stdc++.h>
using namespace std;

typedef class SinhVien
{
    protected:
        int maSV;
        string hoTen;
        float TB;
    public:
        SinhVien()
        {
            maSV = TB = 0;
            hoTen = "";
        }
        ~SinhVien(){}
        virtual void nhapSV();
        void xuatSV();
        virtual void randomSV();
        float getTB();
        int getMa();
        bool checkThoiHoc();
} SV;

void SV::nhapSV()
{
    cout << "Nhap ma so sinh vien: ";
    cin >> maSV;
    cout << "Nhap ho va ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap diem TB: ";
    cin >> TB;
}

void SV::xuatSV()
{
    cout << "MSSV: " << maSV << endl;
    cout << hoTen << " " << "TB: " << TB << endl;
}

void SV::randomSV()
{
    maSV = (rand() % 9999) + 21520000;
    string h[5] = {"Nguyen", "Tran", "Le", "Dang", "Vo"};
    string l[5] = {"Thi", "Phuoc", "Bao", "Chau", "Minh"};
    string t[5] = {"Sang", "Khanh", "Thy", "Hanh", "Phat"};
    int hx = rand() % 5;
    int lx = rand() % 5;
    int tx = rand() % 5;
    hoTen = h[hx] + " " + l[lx] + " " + t[tx] + "\0";
    TB = (float)((rand() % 100) / 10);
}

float SV::getTB()
{
    return TB;
}

int SV::getMa()
{
    return maSV;
}

bool SV::checkThoiHoc()
{
    return (TB < 5);
}

typedef class SinhVienCLC:public SV
{
    protected:
        float QT;
    public:
        SinhVienCLC():SinhVien()
        {
            QT = 0;
        }
        ~SinhVienCLC(){}
        void updateTB();
        void nhapSV();
        void randomSV();
} SVCLC;

void SVCLC::updateTB()
{
    TB = (TB + QT) / 2;
}

void SVCLC::nhapSV()
{
    SV::nhapSV();
    cout << "Nhap diem QT: ";
    cin >> QT;
    updateTB();
}

void SVCLC::randomSV()
{
    SV::randomSV();
    QT = (float)((rand() % 100) / 10);
    updateTB();
}

class Chuan
{
    private:
        SV svc[50];
        int soSV;
    public:
        Chuan()
        {
            soSV = 0;
        }
        ~Chuan(){}
        void nhap();
        void random();
        void xuat();
        int timSV(int ma);
        SV getSV(int index);
        void xuatSVthoihoc();
        SV getSVmax();
};

void Chuan::nhap()
{
    cout << "Nhap so sinh vien: ";
    cin >> soSV;
    for (int i = 0; i < soSV; i++)
    {
        svc[i].nhapSV();
    }
}

void Chuan::random()
{
    cout << "Nhap so sinh vien: ";
    cin >> soSV;
    for (int i = 0; i < soSV; i++)
    {
        svc[i].randomSV();
    }
}

void Chuan::xuat()
{
    cout << "Si so lop: " << soSV << endl;
    for (int i = 0; i < soSV; i++)
    {
        svc[i].xuatSV();
    }
}

int Chuan::timSV(int ma)
{
    for (int i = 0; i < soSV; i++)
        if (svc[i].getMa() == ma) return i;
    return -1;
}

SV Chuan::getSV(int index)
{
    return svc[index];
}

void Chuan::xuatSVthoihoc()
{
    for (int i = 0; i < soSV; i++)
        if (svc[i].checkThoiHoc() == true) svc[i].xuatSV();
}

SV Chuan::getSVmax()
{
    SV ans = svc[0];
    for (int i = 1; i < soSV; i++)
    {
        if (svc[i].getTB() > ans.getTB()) ans = svc[i];
    }
    return ans;
}

class CLC
{
    protected:
        SVCLC svcl[50];
        int soSV;
    public:
        CLC()
        {
            soSV = 0;
        }
        ~CLC(){}
        void nhap();
        void random();
        void xuat();
        int timSV(int ma);
        SVCLC getSV(int index);
        void xuatSVCLthoihoc();
        SVCLC getSVCLmax();
};

void CLC::nhap()
{
    cout << "Nhap so sinh vien: ";
    cin >> soSV;
    for (int i = 0; i < soSV; i++)
    {
        svcl[i].nhapSV();
    }
}

void CLC::xuat()
{
    cout << "Si so lop: " << soSV << endl;
    for (int i = 0; i < soSV; i++)
    {
        svcl[i].xuatSV();
    }
}

void CLC::random()
{
    cout << "Nhap so sinh vien: ";
    cin >> soSV;
    for (int i = 0; i < soSV; i++)
    {
        svcl[i].randomSV();
    }
}

int CLC::timSV(int ma)
{
    for (int i = 0; i < soSV; i++)
        if (svcl[i].getMa() == ma) return i;
    return -1;
}

SVCLC CLC::getSV(int index)
{
    return svcl[index];
}

void CLC::xuatSVCLthoihoc()
{
    for (int i = 0; i < soSV; i++)
        if (svcl[i].checkThoiHoc() == true) svcl[i].xuatSV();
}

SVCLC CLC::getSVCLmax()
{
    SVCLC ans = svcl[0];
    for (int i = 1; i < soSV; i++)
    {
        if (svcl[i].getTB() > ans.getTB()) ans = svcl[i];
    }
    return ans;
}

int main()
{
    Chuan a[80];
    CLC b[80];
    int n1, n2, ma, x, index, lc;
    while(1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap sinh vien cho lop chuan" << endl;
        cout << "Lua chon 2: Nhap sinh vien cho lop CLC" << endl;
        cout << "Lua chon 3: Khoi tao sinh vien lop chuan" << endl;
        cout << "Lua chon 4: Khoi tao sinh vien lop CLC" << endl;
        cout << "Lua chon 5: Xuat cac sinh vien lop chuan" << endl;
        cout << "Lua chon 6: Xuat cac sinh vien lop CLC" << endl;
        cout << "Lua chon 7: Tim sinh vien theo ma SV" << endl;
        cout << "Lua chon 8: Xuat cac sinh vien thoi hoc" << endl;
        cout << "Lua chon 9: Xuat cac sinh vien co diem TB cao nhat cua moi lop" << endl;
        cout << "Lua chon 10: Xuat sinh vien co TB cao nhat trong cac lop chuan, lop CLC" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        switch(lc)
        {
            case 1:
                cout << "Nhap so luong cac lop chuan: ";
                cin >> n1;
                for (int i = 0; i < n1; i++)
                {
                    cout << "Nhap cac sinh vien cho lop chuan thu " << i + 1 << endl;
                    a[i].nhap();
                }
                break;
            case 2:
                cout << "Nhap so luong cac lop CLC: ";
                cin >> n2;
                for (int i = 0; i < n2; i++)
                {
                    cout << "Nhap cac sinh vien cho lop CLC thu " << i + 1 << endl;
                    b[i].nhap();
                }
                break;
            case 3:
                cout << "Nhap so luong cac lop chuan: ";
                cin >> n1;
                for (int i = 0; i < n1; i++)
                {
                    cout << "Khoi tao cac sinh vien cho lop chuan thu " << i + 1 << endl;
                    srand((int)time(0));
                    a[i].random();
                }
                break;
            case 4:
                cout << "Nhap so luong cac lop CLC: ";
                cin >> n2;
                for (int i = 0; i < n2; i++)
                {
                    cout << "Khoi tao cac sinh vien cho lop CLC thu " << i + 1 << endl;
                    srand((int)time(0));
                    b[i].random();
                }
                break;
            case 5:
                for (int i = 0; i < n1; i++)
                {
                    cout << "Lop chuan thu " << i + 1 << endl;
                    a[i].xuat();
                }
                break;
            case 6:
                for (int i = 0; i < n2; i++)
                {
                    cout << "Lop CLC thu " << i + 1 << endl;
                    b[i].xuat();
                }
                break;
            case 7:
                cout << "Nhap ma sinh vien can tim: ";
                cin >> ma;
                index = -1;
                for (int i = 0; i < n1; i++)
                {
                    index = a[i].timSV(ma);
                    if (index != -1)
                    {
                        cout << "Da tim thay" << endl;
                        cout << "Sinh vien cua lop chuan thu " << i + 1 << endl;
                        a[i].getSV(index).xuatSV();
                        break;
                    }
                }
                if (index == -1)
                {
                    for (int i = 0; i < n2; i++)
                    {
                        index = b[i].timSV(ma);
                        if (index != -1)
                        {
                            cout << "Da tim thay" << endl;
                            cout << "Sinh vien cua lop CLC thu " << i + 1 << endl;
                            b[i].getSV(index).xuatSV();
                            break;
                        }
                    }
                    if (index == -1) cout << "Khong tim thay sinh vien" << endl;
                }
                break;
            case 8:
                cout << "Cac sinh vien thoi hoc cua cac lop Chuan" << endl;
                for (int i = 0; i < n1; i++)
                {
                    cout << "Lop chuan thu " << i + 1 << endl;
                    a[i].xuatSVthoihoc();
                }
                cout << "Cac sinh vien thoi hoc cua lop CLC" << endl;
                for (int i = 0; i < n2; i++)
                {
                    cout << "Lop CLC thu " << i + 1 << endl;
                    b[i].xuatSVCLthoihoc();
                }
                break;
            case 9:
                cout << "Cac sinh vien co diem TB cao nhat cua lop Chuan" << endl;
                for (int i = 0; i < n1; i++)
                {
                    cout << "Lop chuan thu " << i + 1 << endl;
                    a[i].getSVmax().xuatSV();
                }
                cout << "Cac sinh vien co diem TB cao nhat cua lop CLC" << endl;
                for (int i = 0; i < n2; i++)
                {
                    cout << "Lop CLC thu " << i + 1 << endl;
                    b[i].getSVCLmax().xuatSV();
                }
                break;
            case 10:
                index = 0;
                cout << "Sinh vien co diem TB cao nhat trong cac lop Chuan:" << endl;
                for (int i = 1; i < n1; i++)
                {
                    if (a[i].getSVmax().getTB() > a[index].getSVmax().getTB()) index = i;
                }
                a[index].getSVmax().xuatSV();

                index = 0;
                cout << "Sinh vien co diem TB cao nhat trong cac lop CLC:" << endl;
                for (int i = 1; i < n2; i++)
                {
                    if (b[i].getSVCLmax().getTB() > b[index].getSVCLmax().getTB()) index = i;
                }
                b[index].getSVCLmax().xuatSV();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}

