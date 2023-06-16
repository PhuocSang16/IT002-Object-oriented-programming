#include <bits/stdc++.h>
using namespace std;

typedef class ToaDo
{
    private:
        double tung, hoanh;
    public:
        ToaDo()
        {
            tung = 0;
            hoanh = 0;
        }
        ToaDo(double t, double h)
        {
            tung = t;
            hoanh = h;
        }
        void nhapTD();
        void xuatTD();
        double layhoanhTD();
        double laytungTD();
        double dodaiTD(ToaDo a);
} TD;

void TD::nhapTD()
{
    cout << "Nhap lan luot hoanh va tung:" << endl;
    cin >> hoanh >> tung;
}

void TD::xuatTD()
{
    cout << "(" << hoanh << "," << tung << ")" << endl;
}

double TD::layhoanhTD()
{
    return hoanh;
}

double TD::laytungTD()
{
    return tung;
}

double TD::dodaiTD(TD a)
{
    return sqrt(pow((hoanh - a.hoanh),2) + pow((tung - a.tung),2));
}

typedef class TamGiac
{
    private:
        TD A, B, C;
    public:
        TamGiac()
        {
            A = {0,0};
            B = {0,1};
            C = {1,0};
        }
        TamGiac(double xA, double yA, double xB, double yB, double xC, double yC) : A(xA,yA), B(xB,yB), C(xC,yC)
        {
            cout << "Da khoi tao 1 tam giac" << endl;
        }
        void nhapTG();
        void xuatTG();
        bool checkTG();
        void xetloaiTG();
        TD laydiemA();
        TD laydiemB();
        TD laydiemC();
        double chuviTG();
        double dientichTG();
        TD noitiepTG();
        TD ngoaitiepTG();
} TG;

bool TG::checkTG()
{
    double ab = A.dodaiTD(B);
    double ac = A.dodaiTD(C);
    double bc = B.dodaiTD(C);
    if (ab + ac <= bc || ac + bc <= ab || ab + bc <= ac)
        return false;
    else return true;
}

void TG::nhapTG()
{
    cout << "Nhap toa do diem A" << endl;
    A.nhapTD();
    cout << "Nhap toa do diem B" << endl;
    B.nhapTD();
    cout << "Nhap toa do diem C" << endl;
    C.nhapTD();
    while (checkTG() == false)
    {
        cout << "3 diem khong tao thanh tam giac, vui long kiem tra va nhap lai:" << endl;
        cout << "Nhap toa do diem A" << endl;
        A.nhapTD();
        cout << "Nhap toa do diem B" << endl;
        B.nhapTD();
        cout << "Nhap toa do diem C" << endl;
        C.nhapTD();
    }
}

void TG::xuatTG()
{
    cout << "Tam giac co toa do A, B, C lan luot la:" << endl;
    A.xuatTD();
    B.xuatTD();
    C.xuatTD();
}

TD TG::laydiemA()
{
    return A;
}

TD TG::laydiemB()
{
    return B;
}

TD TG::laydiemC()
{
    return C;
}

void TG::xetloaiTG()
{
    double ab = A.dodaiTD(B);
    double ac = A.dodaiTD(C);
    double bc = B.dodaiTD(C);
    if (ab == bc && ab == ac)
        cout << "Tam giac deu" << endl;
    else if (ab == bc || bc == ac || ab == ac)
        cout << "Tam giac can" << endl;
    else if (ab*ab == ac*ac + bc*bc || ac*ac == ab*ab + bc*bc || bc*bc == ab*ab + ac*ac)
        cout << "Tam giac vuong" << endl;
    else if (ab*ab < ac*ac + bc*bc || ac*ac < ab*ab + bc*bc || bc*bc < ab*ab + ac*ac)
        cout << "Tam giac nhon" << endl;
    else
        cout << "Tam giac tu" << endl;
}

double TG::chuviTG()
{
    double ab = A.dodaiTD(B);
    double ac = A.dodaiTD(C);
    double bc = B.dodaiTD(C);
    return ab + ac + bc;
}

double TG::dientichTG()
{
    double ab = A.dodaiTD(B);
    double ac = A.dodaiTD(C);
    double bc = B.dodaiTD(C);
    double p = (ab + ac + bc) / 2;
    return sqrt(p*(p-ab)*(p-bc)*(p-ac));
}

TD TG::noitiepTG()
{
    double a = A.dodaiTD(A);
    double b = B.dodaiTD(B);
    double c = C.dodaiTD(C);
    TD kq;
    kq.hoanh = a * A.layhoanhTD() + b * B.layhoanhTD() + c * C.layhoanhTD();
    kq.tung = a * A.laytungTD() + b * B.laytungTD() + c * C.laytungTD();
    return kq;
}


int main()
{
    TG a;
    int n;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap tam giac" << endl;
        cout << "Lua chon 2: Xuat tam giac" << endl;
        cout << "Lua chon 3: Xet loai tam giac" << endl;
        cout << "Lua chon 4: Tinh chu vi" << endl;
        cout << "Lua chon 5: Tinh dien tich" << endl;
        cout << "Lua chon 6: Tim tam duong tron ngoai tiep tam giac" << endl;
        cout << "Lua chon 7: Tim tam duong tron noi tiep tam giac" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                a.nhapTG();
                break;
            case 2:
                a.xuatTG();
                break;
            case 3:
                a.nhapTG();
                a.xetloaiTG();
                break;
            case 4:
                a.nhapTG();
                cout << "Chu vi tam giac la: " << a.chuviTG();
                break;
            case 5:
                a.nhapTG();
                cout << "Dien tich tam giac la: " << a.dientichTG();
                break;
            case 6:
                a.nhapTG();
                cout << "Toa do tam duong tron ngoai tiep tam giac" << endl;
                a.ngoaitiepTG().xuatTD();
                break;
            case 7:
                a.nhapTG();
                cout << "Toa do tam duong tron noi tiep tam giac" << endl;
                a.noitiepTG().xuatTD();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}

