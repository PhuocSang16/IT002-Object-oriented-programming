#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
    private:
        int tuSo, mauSo;
    public:
        void khoiTao(int tu,int mau);
        void nhapPS();
        void layTuSo();
        void layMauSo();
        void xuatPS();
        void rutGonPS();
        int gcd(int tu, int mau);
        int lcm(int tu, int mau);
        void quyDongPS(PhanSo &a);
        PhanSo tongPS(PhanSo a);
        PhanSo hieuPS(PhanSo a);
        PhanSo tichPS(PhanSo a);
        PhanSo thuongPS(PhanSo a);
};

void PhanSo::khoiTao(int tu, int mau)
{
     this->tuSo = tu;
     this->mauSo = mau;
}

void PhanSo::layTuSo()
{
    cout << "Nhap lai tu so: ";
    cin >> this->tuSo;
}

void PhanSo::layMauSo()
{
    cout << "Nhap lai mau so: ";
    cin >> this->mauSo;
}

void PhanSo::nhapPS()
{
    cout << "Nhap lan luot tu va mau: ";
    cin >> tuSo >> mauSo;
    while (mauSo == 0)
        layMauSo();
}

void PhanSo::rutGonPS()
{
    int k = gcd(tuSo,mauSo);
    this->tuSo /= k;
    this->mauSo /= k;
}

void PhanSo::xuatPS()
{
    if (mauSo < 0)
    {
        tuSo = - tuSo;
        mauSo = - mauSo;
    }
    if (mauSo == 1)
        cout << tuSo << endl;
    else
        cout << tuSo << "/" << mauSo << endl;
}

int PhanSo::gcd(int tuSo,int mauSo)
{
    if (mauSo == 0)
        return tuSo;
    return gcd(mauSo, tuSo % mauSo);
}

int PhanSo::lcm(int tuSo, int mauSo)
{
    return tuSo * mauSo / gcd(tuSo,mauSo);
}

PhanSo PhanSo::tichPS(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = a.tuSo * this->tuSo;
    kq.mauSo = a.mauSo * this->mauSo;
    kq.rutGonPS();
    return kq;
}

PhanSo PhanSo::thuongPS(PhanSo a)
{
    PhanSo kq;
    kq.tuSo = a.mauSo * this->tuSo;
    kq.mauSo = a.tuSo * this->mauSo;
    kq.rutGonPS();
    return kq;
}

void PhanSo::quyDongPS(PhanSo &a)
{
    int k = lcm(mauSo,a.mauSo);
    this->tuSo *= k / this->mauSo;
    a.tuSo *= k / a.mauSo;
    a.mauSo = k;
    this->mauSo = k;
}

PhanSo PhanSo::tongPS(PhanSo a)
{
    PhanSo kq;
    quyDongPS(a);
    kq.tuSo = a.tuSo + this->tuSo;
    kq.mauSo = a.mauSo;
    kq.rutGonPS();
    return kq;
}

PhanSo PhanSo::hieuPS(PhanSo a)
{
    PhanSo kq;
    quyDongPS(a);
    kq.tuSo = a.tuSo - this->tuSo;
    kq.mauSo = a.mauSo;
    kq.rutGonPS();
    return kq;
}


int main()
{
    int n, t, m;
    PhanSo p, q;
    while (1)
    {
        cout << "============MENU============" << endl;
        cout << "Lua chon 1: Nhap phan so tu ban phim" << endl;
        cout << "Lua chon 2: Nhap phan so tu dong" << endl;
        cout << "Lua chon 3: Xuat phan so" << endl;
        cout << "Lua chon 4: Tinh tong" << endl;
        cout << "Lua chon 5: Tinh hieu" << endl;
        cout << "Lua chon 6: Tinh tich" << endl;
        cout << "Lua chon 7: Tinh thuong" << endl;
        cout << "============================" << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                p.nhapPS();
                break;
            case 2:
                srand(time(0));
                t = rand() % 100;
                m = rand() % 100 + 1;//Tranh mau = 0
                p.khoiTao(t,m);
                cout << "Phan so ngau nhien vua khoi tao la:" << endl;
                p.xuatPS();
                break;
            case 3:
                p.nhapPS();
                cout << "Phan so vua nhap (da rut gon) la:" << endl;
                p.rutGonPS();
                p.xuatPS();
                break;
            case 4:
                cout << "Nhap phan so thu 1:" << endl;
                p.nhapPS();
                cout << "Nhap phan so thu 2:" << endl;
                q.nhapPS();
                cout << "Tong 2 phan so vua nhap:" << endl;
                p.tongPS(q).xuatPS();
                break;
            case 5:
                cout << "Nhap phan so thu 1:" << endl;
                p.nhapPS();
                cout << "Nhap phan so thu 2:" << endl;
                q.nhapPS();
                cout << "Hieu 2 phan so vua nhap:" << endl;
                p.hieuPS(q).xuatPS();
                break;
            case 6:
                cout << "Nhap phan so thu 1:" << endl;
                p.nhapPS();
                cout << "Nhap phan so thu 2:" << endl;
                q.nhapPS();
                cout << "Tich 2 phan so vua nhap:" << endl;
                p.tichPS(q).xuatPS();
                break;
            case 7:
                cout << "Nhap phan so thu 1:" << endl;
                p.nhapPS();
                cout << "Nhap phan so thu 2:" << endl;
                q.nhapPS();
                cout << "Thuong 2 phan so vua nhap:" << endl;
                p.thuongPS(q).xuatPS();
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
