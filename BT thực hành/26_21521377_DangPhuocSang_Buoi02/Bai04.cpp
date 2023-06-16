#include <bits/stdc++.h>
using namespace std;

class TamGiac
{
    private:
        int AB, BC, AC;
    public:
        void nhapTG();
        void xuatTG();
        void kiemtraTG();
        void xetloaiTG();
        int chuviTG();
        float dientichTG();
};

void TamGiac::nhapTG()
{
    cout << "Nhap lan luot do dai 3 canh tam giac (AB, BC, AC): ";
    cin >> AB >> BC >> AC;
}

void TamGiac::kiemtraTG()
{
    while (AB + BC <= AC || BC + AC <= AB || AB + AC <= BC)
    {
        cout << "Tam giac khong hop le" << endl;
        nhapTG();
    }
}

void TamGiac::xuatTG()
{
    cout << "Tam giac co do dai cac canh lan luot la: " << AB << " " << BC << " " << AC << endl;
}

void TamGiac::xetloaiTG()
{
    if (AB == BC && BC == AC)
        cout << "Tam giac deu" << endl;
    else if (AB == BC || AB == AC || BC == AC)
        cout << "Tam giac can" << endl;
    else if (AB*AB == BC*BC + AC*AC || BC*BC == AB*AB + AC*AC || AC*AC == BC*BC + AB*AB )
        cout << "Tam giac vuong" << endl;
    else if (AB*AB > BC*BC + AC*AC || BC*BC > AB*AB + AC*AC || AC*AC > BC*BC + AB*AB)
        cout << "Tam giac tu" << endl;
    else
        cout << "Tam giac nhon" << endl;
}

int TamGiac::chuviTG()
{
    return AB + BC + AC;
}

float TamGiac::dientichTG()
{
    int p = chuviTG() / 2;
    return sqrt(p*(p-AB)*(p-BC)*(p-AC));
}

int main()
{
    TamGiac a;
    int n;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap tam giac" << endl;
        cout << "Lua chon 2: Xuat thong tin tam giac" << endl;
        cout << "Lua chon 3: Xet loai" << endl;
        cout << "Lua chon 4: Tinh chu vi" << endl;
        cout << "Lua chon 5: Tinh dien tich" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                a.nhapTG();
                a.kiemtraTG();
                break;
            case 2:
                a.xuatTG();
                break;
            case 3:
                a.nhapTG();
                a.kiemtraTG();
                cout << "Thong tin tam giac vua nhap la:" << endl;
                a.xuatTG();
                a.xetloaiTG();
                break;
            case 4:
                a.nhapTG();
                a.kiemtraTG();
                cout << "Thong tin tam giac vua nhap la:" << endl;
                a.xuatTG();
                cout << "Chu vi tam giac la:" << a.chuviTG() << endl;
                break;
            case 5:
                a.nhapTG();
                a.kiemtraTG();
                cout << "Thong tin tam giac vua nhap la:" << endl;
                a.xuatTG();
                cout << "Dien tich tam giac la:" << a.dientichTG() << endl;
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
