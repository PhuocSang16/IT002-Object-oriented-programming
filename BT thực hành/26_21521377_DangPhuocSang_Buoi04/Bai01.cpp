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
        void setTuSo(int k);
        void setMauSo(int k);
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
        friend PhanSo operator-(int b, PhanSo a);
        friend PhanSo operator*(int b, PhanSo a);
        friend PhanSo operator/(int b, PhanSo a);
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

void PS::setTuSo(int k)
{
    tuSo = k;
}

void PS::setMauSo(int k)
{
    if (k != 0)
        mauSo = k;
    else
        cout << "Tham so khong hop le" << endl;
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

PS operator-(int b, PS a)
{
    PS kq;
    kq.tuSo = b * a.mauSo - a.tuSo;
    kq.mauSo = a.mauSo;
    kq.rutGonPS();
    return kq;
}

PS operator*(int b, PS a)
{
    PS kq;
    kq.tuSo = b * a.tuSo;
    kq.mauSo = a.mauSo;
    kq.rutGonPS();
    return kq;
}

PS operator/(int b, PS a)
{
    PS kq;
    kq.mauSo = b * a.mauSo;
    kq.tuSo = a.tuSo;
    return kq;
}

typedef class HonSo: public PhanSo
{
    private:
        int nguyen;
    public:
        HonSo():PhanSo()
        {
            nguyen = 0;
        }
        HonSo(int n, int tu, int mau):PhanSo(tu,mau)
        {
            nguyen = n;
        }
        int layTuSo();
        int layMauSo();
        void toigianHS();
        void setTuSo(int k);
        void setMauSo(int k);
        friend istream& operator >> (istream &is, HonSo &b);
        friend ostream& operator << (ostream &os, HonSo b);
        void randomHS();
        HonSo chuyen(PhanSo a);
        PhanSo chuyen();
        HonSo operator+(HonSo b);
        HonSo operator-(HonSo b);
        HonSo operator*(HonSo b);
        HonSo operator/(HonSo b);
        HonSo operator+(int k);
        HonSo operator-(int k);
        friend HonSo operator-(int k, HonSo b);
        friend HonSo operator/(int k, HonSo b);
        HonSo operator*(int k);
        HonSo operator/(int k);
        bool operator<(HonSo b);
        bool operator<=(HonSo b);
        bool operator>(HonSo b);
        bool operator>=(HonSo b);
} HS;

int HS::layTuSo()
{
    return PS::layTuSo();
}

int HS::layMauSo()
{
    return PS::layMauSo();
}

void HS::setTuSo(int k)
{
    PS::setTuSo(k);
}

void HS::setMauSo(int k)
{
    PS::setMauSo(k);
}

void HS::toigianHS()
{
    int t = layTuSo();
    int m = layMauSo();
    if (t < 0 || m < 0)
    {
        if (t < 0 && m >= 0)
        {
            nguyen = -nguyen;
            t = -t;
        }
        else if (t >= 0 && m < 0)
        {
            nguyen = -nguyen;
            m = -m;
        }
        else
        {
            t = -t;
            m = -m;
        }
    }
    while (t >= m)
    {
        if (nguyen < 0)
        {
            nguyen--;
            t -= m;
        }
        else
        {
            nguyen++;
            t -=m;
        }
    }
    setTuSo(t);
    setMauSo(m);
}

istream& operator >> (istream &is, HS &b)
{
    cout << "Nhap phan nguyen: ";
    is >> b.nguyen;
    cout << "Nhap phan phan so" << endl;
    int t, m;
    cout << "Nhap lan luot tu va mau: ";
    is >> t >> m;
    b.setTuSo(t);
    b.setMauSo(m);
    b.toigianHS();
    return is;
}

ostream& operator << (ostream &os, HS b)
{
    os << b.nguyen << " va ";
    int mau = b.layMauSo();
    int tu = b.layTuSo();
    if (mau < 0)
    {
        mau = -mau;
        tu = -tu;
    }
    if (mau == 0)
        os << tu << endl;
    else
        os << tu << "/" << mau << endl;
    return os;
}

void HS::randomHS()
{
    srand((int)time(0));
    nguyen = rand() % 1000;
    PS::randomPS();
}

HS HS::chuyen(PS a)
{
    HS kq;
    kq.nguyen = a.layTuSo()/a.layMauSo();
    if (kq.nguyen >= 0)
        a = a - kq.nguyen;
    else
        a = -(a - kq.nguyen);
    kq.setTuSo(a.layTuSo());
    kq.setMauSo(a.layMauSo());
    return kq;
}

PS HS::chuyen()
{
    PS kq(layTuSo(),layMauSo());
    if (nguyen < 0)
        kq = -kq + nguyen;
    else
        kq = kq + nguyen;
    kq.rutGonPS();
    return kq;
}

HS HS::operator+(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    HS kq = kq.chuyen(x+y);
    return kq;
}

HS HS::operator-(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    HS kq = kq.chuyen(x-y);
    return kq;
}

HS HS::operator*(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    HS kq = kq.chuyen(x*y);
    return kq;
}

HS HS::operator/(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    HS kq = kq.chuyen(x/y);
    return kq;
}

HS HS::operator+(int k)
{
    PS x = this->chuyen();
    HS kq = kq.chuyen(x+k);
    return kq;
}

HS HS::operator-(int k)
{
    PS x = this->chuyen();
    HS kq = kq.chuyen(x-k);
    return kq;
}

HS HS::operator*(int k)
{
    PS x = this->chuyen();
    HS kq = kq.chuyen(x*k);
    return kq;
}

HS HS::operator/(int k)
{
    PS x = this->chuyen();
    HS kq = kq.chuyen(x/k);
    return kq;
}

HS operator-(int k, HS b)
{
    PS x = b.chuyen();
    HS kq = kq.chuyen(k-x);
    return kq;
}

HS operator/(int k, HS b)
{
    PS x = b.chuyen();
    HS kq = kq.chuyen(k/x);
    return kq;
}

bool HS::operator<(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    return (x<y);
}

bool HS::operator<=(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    return (x<=y);
}

bool HS::operator>(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    return (x>y);
}

bool HS::operator>=(HS b)
{
    PS x = this->chuyen();
    PS y = b.chuyen();
    return (x>=y);
}

int main()
{
    HS a, b;
    PS p;
    int n, k, m, x;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap hon so tu ban phim" << endl;
        cout << "Lua chon 2: Random hon so" << endl;
        cout << "Lua chon 3: Xuat hon so" << endl;
        cout << "Lua chon 4: Chuyen hon so sang phan so" << endl;
        cout << "Lua chon 5: Chuyen phan so sang hon so" << endl;
        cout << "Lua chon 6: Tinh toan cong tru nhan chia" << endl;
        cout << "Lua chon 7: Thuc hien so sanh" << endl;
        cout << "========================" << endl;
        cout << "Nhap lua chon: ";
        cin >> n;
        switch(n)
        {
            case 1:
                cout << "Nhap hon so tu ban phim" << endl;
                cin >> a;
                break;
            case 2:
                cout << "Khoi tao ngau nhien 1 hon so" << endl;
                a.randomHS();
                cout << "Hon so vua khoi tao: ";
                cout << a;
                break;
            case 3:
                cout << "Xuat hon so" << endl;
                cout << a;
                break;
            case 4:
                cout << "Chuyen doi HS sang PS" << endl;
                cout << "Nhap hon so tu ban phim" << endl;
                cin >> a;
                p = a.chuyen();
                cout << "Phan so: " << p;
                break;
            case 5:
                cout << "Chuyen doi PS sang HS" << endl;
                cout << "Nhap phan so tu ban phim" << endl;
                cin >> p;
                a = a.chuyen(p);
                cout << "Hon so: " << a;
                break;
            case 6:
                cout << "Tinh toan" << endl;
                cout << "Phuong thuc 1: Tinh toan giua 2 HS" << endl;
                cout << "Phuong thuc 2: Tinh toan giua HS va 1 so nguyen" << endl;
                cout << "Nhap phuong thuc: ";
                cin >> k;
                switch(k)
                {
                    case 1:
                        cout << "Cac loai phep tinh" << endl;
                        cout << "Loai 1: Cong 2 HS" << endl;
                        cout << "Loai 2: Tru 2 HS" << endl;
                        cout << "Loai 3: Nhan 2 HS" << endl;
                        cout << "Loai 4: Chia 2 HS" << endl;
                        cout << "Nhap loai phep tinh: ";
                        cin >> m;
                        switch(m)
                        {
                            case 1:
                                cout << "Nhap hon so thu nhat" << endl;
                                cin >> a;
                                cout << "Nhap hon so thu hai" << endl;
                                cin >> b;
                                cout << "Tong 2 hon so la: " << a+b;
                                break;
                            case 2:
                                cout << "Nhap hon so thu nhat" << endl;
                                cin >> a;
                                cout << "Nhap hon so thu hai" << endl;
                                cin >> b;
                                cout << "Hieu 2 hon so (a-b) la: " << a-b;
                                cout << "Hieu 2 hon so (b-a) la: " << b-a;
                                break;
                            case 3:
                                cout << "Nhap hon so thu nhat" << endl;
                                cin >> a;
                                cout << "Nhap hon so thu hai" << endl;
                                cin >> b;
                                cout << "Tich 2 hon so la: " << a*b;
                                break;
                            case 4:
                                cout << "Nhap hon so thu nhat" << endl;
                                cin >> a;
                                cout << "Nhap hon so thu hai" << endl;
                                cin >> b;
                                cout << "Thuong 2 hon so (a/b) la: " << a/b;
                                cout << "Thuong 2 hon so (b/a) la: " << b/a;
                                break;
                            default:
                                cout << "Khong co phep tinh nay" << endl;
                                exit(2);
                        }
                        break;
                    case 2:
                        cout << "Cac loai phep tinh" << endl;
                        cout << "Loai 1: Cong HS voi 1 so" << endl;
                        cout << "Loai 2: Tru HS voi 1 so (hoac nguoc lai)" << endl;
                        cout << "Loai 3: Nhan HS voi 1 so" << endl;
                        cout << "Loai 4: Chia HS voi 1 so (hoac nguoc lai)" << endl;
                        cout << "Nhap loai phep tinh: ";
                        cin >> m;
                        switch(m)
                        {
                            case 1:
                                cout << "Nhap hon so" << endl;
                                cin >> a;
                                cout << "Nhap so nguyen x" << endl;
                                cin >> x;
                                cout << "Tong HS + x: " << a + x;
                                break;
                            case 2:
                                cout << "Nhap hon so" << endl;
                                cin >> a;
                                cout << "Nhap so nguyen x" << endl;
                                cin >> x;
                                cout << "Hieu HS - x: " << a - x;
                                cout << "Hieu x - HS: " << x - a;
                                break;
                            case 3:
                                cout << "Nhap hon so" << endl;
                                cin >> a;
                                cout << "Nhap so nguyen x" << endl;
                                cin >> x;
                                cout << "Tich HS * x: " << a * x;
                                break;
                            case 4:
                                cout << "Nhap hon so" << endl;
                                cin >> a;
                                cout << "Nhap so nguyen x" << endl;
                                cin >> x;
                                cout << "Thuong HS / x: " << a / x;
                                cout << "Thuong x / HS: " << x / a;
                                break;
                            default:
                                cout << "Khong co phep tinh nay" << endl;
                                exit(2);
                        }
                        break;
                    default:
                        cout << "Khong co phuong thuc nay" << endl;
                        exit(1);
                }
                break;
            case 7:
                cout << "So sanh" << endl;
                cout << "Phuong thuc 1: So sanh a<b" << endl;
                cout << "Phuong thuc 2: So sanh a<=b" << endl;
                cout << "Phuong thuc 3: So sanh a>b" << endl;
                cout << "Phuong thuc 4: So sanh a>=b" << endl;
                cout << "Nhap phuong thuc: ";
                cin >> k;
                switch(k)
                {
                    case 1:
                        cout << "Nhap hon so a" << endl;
                        cin >> a;
                        cout << "Nhap hon so b" << endl;
                        cin >> b;
                        if (a<b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 2:
                        cout << "Nhap hon so a" << endl;
                        cin >> a;
                        cout << "Nhap hon so b" << endl;
                        cin >> b;
                        if (a<=b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 3:
                        cout << "Nhap hon so a" << endl;
                        cin >> a;
                        cout << "Nhap hon so b" << endl;
                        cin >> b;
                        if (a>b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    case 4:
                        cout << "Nhap hon so a" << endl;
                        cin >> a;
                        cout << "Nhap hon so b" << endl;
                        cin >> b;
                        if (a>=b)
                            cout << "True" << endl;
                        else
                            cout << "False" << endl;
                        break;
                    default:
                        cout << "Khong co phuong thuc nay" << endl;
                        exit(1);
                }
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(0);
        }
    }
    return 0;
}

