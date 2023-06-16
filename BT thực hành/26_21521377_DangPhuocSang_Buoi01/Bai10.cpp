#include <bits/stdc++.h>
using namespace std;

struct Day
{
    int dd, mm, yy;
};

typedef struct SinhVien
{
    int maSo;
    string hoTen;
    Day ngaySinh;
    double TB;
    int hocLuc;
} SV;

void NhapDay(Day &a)
{
    cin >> a.dd >> a.mm >> a.yy;
}

bool checkYear(int n)
{
    if (n % 400 == 0 || (n & 100 != 0 && n % 4 == 0))
        return true;
    return false;
}

bool checkDay(int n, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || n < 1)
        return false;
    else
    {
        int daymax;
        if (checkYear(year) == true)
        {
            switch(month)
            {
                case 4: case 6: case 9: case 11:
                    daymax = 30;
                    break;
                case 2:
                    daymax = 29;
                    break;
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    daymax = 31;
                    break;
            }
            if (n > daymax)
                return false;
            else
                return true;
        }
        else
        {
            switch(month)
            {
                case 4: case 6: case 9: case 11:
                    daymax = 30;
                    break;
                case 2:
                    daymax = 29;
                    break;
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    daymax = 31;
                    break;
            }
            if (n > daymax)
                return false;
            else
                return true;
        }
    }
}

void nhapThuCong(SV a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tinh sinh vien thu " << i+1 << endl;
        cout << "Nhap ma so sinh vien: ";
        cin >> a[i].maSo;
        cin.ignore();
        cout << "Nhap ho va ten: ";
        getline(cin,a[i].hoTen);
        cout << "Nhap ngay, thang, nam sinh: ";
        NhapDay(a[i].ngaySinh);
        while (checkDay(a[i].ngaySinh.dd,a[i].ngaySinh.mm,a[i].ngaySinh.yy) == false)
        {
            cout << "Ngay, thang, nam khong hop le, vui long nhap lai:" << endl;
            NhapDay(a[i].ngaySinh);
        }
        cout << "Nhap diem trung binh: ";
        cin >> a[i].TB;
    }
}

int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

void randomDate(SV a[],int &n)
{
    srand((int)time(0));
    for (int i = 0; i< n; i++)
    {
        a[i].ngaySinh.yy = random(1980,2010);
        a[i].ngaySinh.mm = random(1,12);
        a[i].ngaySinh.dd = random(1,31);
        while (checkDay(a[i].ngaySinh.dd,a[i].ngaySinh.mm,a[i].ngaySinh.yy) == false)
        {
            a[i].ngaySinh.yy = random(1980,2010);
            a[i].ngaySinh.mm = random(1,12);
            a[i].ngaySinh.dd = random(1,31);
        }
    }
}

double random(double minD, double maxD)
{
    double scale = rand()/ (double) RAND_MAX;
    return minD + scale * (maxD - minD);
}

void randomMSSV(SV a[], int &n)
{
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        a[i].maSo = random(10000000,99999999);
    }
}

void randomHoten(SV a[], int &n)
{
    string ho[10] = {"Nguyen","Tran","Le","Ly","Dang"};
    string lot[10] = {"Khanh","Phuoc","Kim","Gia","Huynh","Minh"};
    string ten[10] = {"Sang","Vy","Ha","Giang","Thu"};
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        int h = random(0,4);
        int l = random(0,5);
        int t = random(0,4);
        a[i].hoTen = ho[h] + " " + lot[l] + " " + ten[t] + "\0";
    }
}

void randomTB(SV a[], int &n)
{
    srand((int)time(0));
    for (int i = 0; i < n; i++)
    {
        a[i].TB = random(0.0,10.0);
    }
}

void xuatSV(SV a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].maSo << "\t" << a[i].hoTen << "\t" << a[i].ngaySinh.dd << "/" << a[i].ngaySinh.mm << "/" << a[i].ngaySinh.yy << "\t" << a[i].TB << endl;
    }
}

SV SVmax(SV a[], int n)
{
    double MaxTB = a[0].TB;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].TB > MaxTB)
        {
            MaxTB = a[i].TB;
            index = i;
        }
    }
    return a[index];
}

void Xuat(SV a)
{
    cout << a.maSo << "\t" << a.hoTen << "\t" << a.ngaySinh.dd << "/" << a.ngaySinh.mm << "/" << a.ngaySinh.yy << "\t" << a.TB << endl;
}

int hocLuc(double a)
{
    if (a < 3.5) return 0;
    else if (a >= 3.5 && a < 5.0) return 1;
    else if (a >= 5.0 && a < 7.0) return 2;
    else if (a >= 7.0 && a < 8.0) return 3;
    else if (a >= 8.0 && a < 9.0) return 4;
    return 5;
}

void quyDoiGPA(SV a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].hocLuc = hocLuc(a[i].TB);
    }
}

void xuatSVcoGPA(SV a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        Xuat(a[i]);
        switch(a[i].hocLuc)
        {
            case 0:
                cout << "Hoc luc: Kem" << endl;
                break;
            case 1:
                cout << "Hoc luc: Yeu" << endl;
                break;
            case 2:
                cout << "Hoc luc: Trung binh" << endl;
                break;
            case 3:
                cout << "Hoc luc: Kha" << endl;
                break;
            case 4:
                cout << "Hoc luc: Gioi" << endl;
                break;
            case 5:
                cout << "Hoc luc: Xuat sac" << endl;
                break;
        }
    }
}

void timMaso(SV a[], int &n)
{
    int x, c = 0;
    cout << "Nhap ma so sinh vien can tim: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i].maSo == x)
        {
            Xuat(a[i]);
            c++;
        }
    }
    if (c == 0)
        cout << "Khong tim thay" << endl;
}

void timTB(SV a[], int &n)
{
    double x; int c = 0;
    cout << "Nhap diem TB can tim: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i].TB == x)
        {
            Xuat(a[i]);
            c++;
        }
    }
    if (c == 0)
        cout << "Khong tim thay" << endl;
}

void Top10Highest(SV a[], int &n)
{
    cout << "Top 10 sinh vien co TB cao nhat:" << endl;
    if (n <= 10)
        xuatSV(a,n);
    else
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].TB < a[j].TB)
                    swap(a[i].TB,a[j].TB);
        for (int i = 0; i < n; i++)
            Xuat(a[i]);
    }
}

void Top10Lowest(SV a[], int &n)
{
    cout << "Top 10 sinh vien co TB thap nhat:" << endl;
    if (n <= 10)
        xuatSV(a,n);
    else
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].TB > a[j].TB)
                    swap(a[i].TB,a[j].TB);
        for (int i = 0; i < n; i++)
            Xuat(a[i]);
    }
}

void timDate(SV a[], int &n)
{
    int d, m, y;
    cout << "Nhap ngay thang nam: ";
    cin >> d >> m >> y;
    while (checkDay(d,m,y) == false)
    {
        cout << "Ngay thang nam khong hop le, vui long nhap lai:" << endl;
        cin >> d >> m >> y;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].ngaySinh.dd == d && a[i].ngaySinh.mm == m && a[i].ngaySinh.yy == y)
        {
            Xuat(a[i]);
            c++;
        }
    }
    if (c == 0)
        cout << "Khong tim thay sinh vien" << endl;
}

void timMonth(SV a[], int &n)
{
    int m;
    cout << "Nhap thang can tim: ";
    cin >> m;
    while (m < 1 || m > 12)
    {
        cout << "Thang khong hop le, vui long nhap lai:" << endl;
        cin >> m;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].ngaySinh.mm == m)
        {
            Xuat(a[i]);
            c++;
        }
    }
    if (c == 0)
        cout << "Khong tim thay sinh vien" << endl;
}

int main()
{
    SV a[200];
    int k, n; SV maxTB;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap thu cong n sinh vien" << endl;
        cout << "Lua chon 2: Khoi tao ngau nhien cac sinh vien" << endl;
        cout << "Lua chon 3: Xuat thong tin sinh vien" << endl;
        cout << "Lua chon 4: Xuat thong tin sinh vien co diem trung binh lon nhat" << endl;
        cout << "Lua chon 5: Cap nhat xep loai hoc luc sinh vien" << endl;
        cout << "Lua chon 6: Tim sinh vien theo ma sinh vien" << endl;
        cout << "Lua chon 7: Tim sinh vien theo diem trung binh" << endl;
        cout << "Lua chon 8: Tra ve 10 sinh vien co diem trung binh cao nhat" << endl;
        cout << "Lua chon 9: Tra ve 10 sinh vien co diem trung binh thap nhat" << endl;
        cout << "Lua chon 10: Tim kiem sinh vien theo ngay thang nam sinh" << endl;
        cout << "Lua chon 11: Tim kiem sinh vien theo thang" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> k;
        switch(k)
        {
            case 1:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                break;
            case 2:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cout << "Nhap ngau nhien." << endl;
                randomHoten(a,n);
                randomMSSV(a,n);
                randomDate(a,n);
                randomTB(a,n);
                xuatSV(a,n);
                break;
            case 3:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                cout << "Xuat sinh vien:" << endl;
                xuatSV(a,n);
                break;
            case 4:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cout << "Nhap ngau nhien." << endl;
                randomHoten(a,n);
                randomMSSV(a,n);
                randomDate(a,n);
                randomTB(a,n);
                xuatSV(a,n);
                maxTB = SVmax(a,n);
                cout << "Sinh vien co diem trung binh cao nhat:";
                Xuat(maxTB);
                break;
            case 5:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cout << "Nhap ngau nhien." << endl;
                randomHoten(a,n);
                randomMSSV(a,n);
                randomDate(a,n);
                randomTB(a,n);
                quyDoiGPA(a,n);
                xuatSVcoGPA(a,n);
                break;
            case 6:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                timMaso(a,n);
                break;
            case 7:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                timTB(a,n);
                break;
            case 8:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cout << "Nhap ngau nhien." << endl;
                randomHoten(a,n);
                randomMSSV(a,n);
                randomDate(a,n);
                randomTB(a,n);
                Top10Highest(a,n);
                break;
            case 9:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                cout << "Nhap ngau nhien." << endl;
                randomHoten(a,n);
                randomMSSV(a,n);
                randomDate(a,n);
                randomTB(a,n);
                Top10Lowest(a,n);
                break;
            case 10:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                timDate(a,n);
                break;
            case 11:
                cout << "Nhap so luong sinh vien: ";
                cin >> n;
                nhapThuCong(a,n);
                timMonth(a,n);
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
        }
    }
    return 0;
}
