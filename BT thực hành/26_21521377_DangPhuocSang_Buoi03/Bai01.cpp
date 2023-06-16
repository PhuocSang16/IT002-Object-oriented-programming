#include<bits/stdc++.h>
using namespace std;

typedef class PhanSo
{
    private:
        int tuSo, mauSo;
    public:
        PhanSo()
        {
            tuSo = 0;
            mauSo = 1;
        }
        PhanSo(int t, int m)
        {
            tuSo = t;
            mauSo = m;
        }
        void nhapPS();
        void randomPS();
        int layTuSo();
        int layMauSo();
        void xuatPS();
        void rutGonPS();
        int gcd(int t, int m);
        int lcm(int t, int m);
        void quyDongPS(PhanSo &a);
        PhanSo operator*(PhanSo b);
        PhanSo operator/(PhanSo b);
        PhanSo operator+(PhanSo b);
        PhanSo operator-(PhanSo b);
        PhanSo operator+(int a);
        PhanSo operator-(int a);
        PhanSo operator*(int a);
        PhanSo operator/(int a);
        friend PhanSo operator+(int b, PhanSo a);
        PhanSo operator-();
        bool operator<(PhanSo a);
        bool operator<=(PhanSo a);
        bool operator>(PhanSo a);
        bool operator>=(PhanSo a);
        friend istream& operator >> (istream &is, PhanSo &b);
        friend ostream& operator << (ostream &os, PhanSo b);
} PS;

int PS::layTuSo()
{
    return tuSo;
}

int PS::layMauSo()
{
    return mauSo;
}

void PS::nhapPS()
{
    cout << "Nhap lan luot tu va mau: ";
    cin >> tuSo >> mauSo;
    while (mauSo == 0)
    {
        cout << "Nhap lai mau so:" << endl;
        cin >> mauSo;
    }

}

void PS::randomPS()
{
    srand((int)time(0));
    tuSo = rand() % 1000;
    mauSo = rand() % 1000;
    while (mauSo == 0) mauSo = rand() % 1000;
}

istream& operator >> (istream &is, PS &b)
{
    cout << "Nhap lan luot tu va mau: ";
    is >> b.tuSo >> b.mauSo;
    while (b.mauSo == 0)
    {
        cout << "Nhap lai mau so:" << endl;
        is >> b.mauSo;
    }
    return is;
}

ostream& operator << (ostream &os, PS b)
{
    if (b.mauSo < 0)
    {
        b.tuSo = - b.tuSo;
        b.mauSo = - b.mauSo;
    }
    if (b.mauSo == 1)
        os << b.tuSo << endl;
    else
        os << b.tuSo << "/" << b.mauSo << endl;
    return os;
}

void PS::xuatPS()
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

int PS::gcd(int tuSo,int mauSo)
{
    if (mauSo == 0)
        return tuSo;
    return gcd(mauSo, tuSo % mauSo);
}

int PS::lcm(int tuSo, int mauSo)
{
    return tuSo * mauSo / gcd(tuSo,mauSo);
}

void PS::rutGonPS()
{
    int k = gcd(tuSo,mauSo);
    this->tuSo /= k;
    this->mauSo /= k;
}

void PS::quyDongPS(PS &a)
{
    int k = lcm(mauSo,a.mauSo);
    this->tuSo *= k / this->mauSo;
    a.tuSo *= k / a.mauSo;
    a.mauSo = k;
    this->mauSo = k;
}

bool PS::operator<(PS a)
{
    if ((double)(tuSo/mauSo) < (double)(a.tuSo/a.mauSo))
        return true;
    else return false;
}

bool PS::operator<=(PS a)
{
    if ((double)(tuSo/mauSo) <= (double)(a.tuSo/a.mauSo))
        return true;
    else return false;
}

bool PS::operator>(PS a)
{
    if ((double)(tuSo/mauSo) > (double)(a.tuSo/a.mauSo))
        return true;
    else return false;
}

bool PS::operator>=(PS a)
{
    if ((double)(tuSo/mauSo) >= (double)(a.tuSo/a.mauSo))
        return true;
    else return false;
}

PS PS::operator*(PS b)
{
    PS kq;
    kq.tuSo = tuSo * b.tuSo;
    kq.mauSo = mauSo * b.mauSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator/(PS b)
{
    PS kq;
    kq.tuSo = tuSo * b.mauSo;
    kq.mauSo = mauSo * b.tuSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator+(PS b)
{
    quyDongPS(b);
    PS kq;
    kq.mauSo = b.mauSo;
    kq.tuSo = b.tuSo + tuSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator-(PS b)
{
    quyDongPS(b);
    PS kq;
    kq.mauSo = b.mauSo;
    kq.tuSo = tuSo - b.tuSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator+(int a)
{
    PS kq;
    kq.tuSo = tuSo + a * mauSo;
    kq.mauSo = mauSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator-(int a)
{
    PS kq;
    kq.tuSo = tuSo - a * mauSo;
    kq.mauSo = mauSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator*(int a)
{
    PS kq;
    kq.tuSo = tuSo * a;
    kq.mauSo = mauSo;
    kq.rutGonPS();
    return kq;
}

PS PS::operator/(int a)
{
    PS kq;
    kq.tuSo = tuSo;
    kq.mauSo = mauSo * a;
    kq.rutGonPS();
    return kq;
}

PS PS::operator-()
{
    PS kq;
    kq.tuSo = -tuSo;
    kq.mauSo = mauSo;
    kq.rutGonPS();
    return kq;
}

PS operator+(int b, PS a)
{
    PS kq;
    kq.tuSo = a.tuSo + b * a.mauSo;
    kq.mauSo = a.mauSo;
    kq.rutGonPS();
    return kq;
}

int main()
{
    PS a, b;
    int n, k, x;
    while(1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap phan so tu ban phim" << endl;
        cout << "Lua chon 2: Nhap phan so ngau nhien" << endl;
        cout << "Lua chon 3: Xuat phan so" << endl;
        cout << "Lua chon 4: Cong phan so" << endl;
        cout << "Lua chon 5: Tru phan so" << endl;
        cout << "Lua chon 6: Nhan phan so" << endl;
        cout << "Lua chon 7: Chia phan so" << endl;
        cout << "Lua chon 8: Thuc hien phep so sanh" << endl;
        cout << "Lua chon 9: Tinh phan so voi 1 so" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                cin >> a;
                break;
            case 2:
                a.randomPS();
                break;
            case 3:
                cout << a;
                break;
            case 4:
                cout << "Nhap phan so thu 1" << endl;
                cin >> a;
                cout << "Nhap phan so thu 2" << endl;
                cin >> b;
                cout << "Tong 2 phan so:" << a + b << endl;
                break;
            case 5:
                cout << "Nhap phan so thu 1" << endl;
                cin >> a;
                cout << "Nhap phan so thu 2" << endl;
                cin >> b;
                cout << "Hieu 2 phan so:" << a - b << endl;
                break;
            case 6:
                cout << "Nhap phan so thu 1" << endl;
                cin >> a;
                cout << "Nhap phan so thu 2" << endl;
                cin >> b;
                cout << "Tich 2 phan so:" << a * b << endl;
                break;
            case 7:
                cout << "Nhap phan so thu 1" << endl;
                cin >> a;
                cout << "Nhap phan so thu 2" << endl;
                cin >> b;
                cout << "Thuong 2 phan so:" << a / b << endl;
                break;
            case 8:
                cout << "Nhap 1, 2, 3, 4 de so sanh < <= > >=" << endl;
                cin >> k;
                switch(k)
                {
                    case 1:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << "Nhap phan so thu 2" << endl;
                        cin >> b;
                        if (a < b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 2:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << "Nhap phan so thu 2" << endl;
                        cin >> b;
                        if (a <= b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 3:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << "Nhap phan so thu 2" << endl;
                        cin >> b;
                        if (a > b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 4:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << "Nhap phan so thu 2" << endl;
                        cin >> b;
                        if (a >= b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    default:
                        cout << "Khong co lua chon" << endl;
                        break;
                }
                break;
            case 9:
                cout << "Nhap 1, 2, 3, 4 de tinh + - * /" << endl;
                cin >> k;
                switch(k)
                {
                    case 1:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << " Nhap so nguyen: ";
                        cin >> x;
                        cout << a + x;
                        break;
                    case 2:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << " Nhap so nguyen: ";
                        cin >> x;
                        cout << a - x;
                        break;
                    case 3:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << " Nhap so nguyen: ";
                        cin >> x;
                        cout << a * x;
                        break;
                    case 4:
                        cout << "Nhap phan so thu 1" << endl;
                        cin >> a;
                        cout << " Nhap so nguyen: ";
                        cin >> x;
                        cout << a / x;
                        break;
                    default:
                        cout << "Khong co lua chon" << endl;
                        break;
                }
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                break;
        }
    }
    return 0;
}
