#include <bits/stdc++.h>
using namespace std;

class TuGiac
{
    protected:
        float dai, rong, cao;
    public:
        TuGiac()
        {
            dai = rong =  cao = 0;
        }
        ~TuGiac(){}
        float getDai();
        float getRong();
        float getCao();
        void setCao(float x);
        void setDai(float x);
        void setRong(float x);
        virtual void nhap(){}
        virtual void xuat(){}
        virtual float tinhCV(){}
        virtual float tinhDT(){}
};

float TuGiac::getDai()
{
    return dai;
}

float TuGiac::getCao()
{
    return cao;
}

float TuGiac::getRong()
{
    return rong;
}

void TuGiac::setCao(float x)
{
    cao = x;
}

void TuGiac::setDai(float x)
{
    dai = x;
}

void TuGiac::setRong(float x)
{
    rong = x;
}

class HCN:public TuGiac
{
    public:
        HCN()
        {
            dai = rong = cao = 0;
        }
        ~HCN(){}
        void nhap();
        void xuat();
        bool checkHCN();
        float tinhCV();
        float tinhDT();
};

void HCN::nhap()
{
    cout << "Nhap hinh chu nhat" << endl;
    cout << "Nhap chieu dai va chieu rong: ";
    cin >> dai >> rong;
    cao = rong;
}

bool HCN::checkHCN()
{
    return (cao == dai || cao == rong);
}

void HCN::xuat()
{
    cout << "Hinh chu nhat" << endl;
    cout << "Chieu dai: " << dai << endl;
    cout << "Chieu rong: " << rong << endl;
}

float HCN::tinhCV()
{
    return (dai + rong) * 2;
}

float HCN::tinhDT()
{
    return dai * rong;
}


class HBH:public TuGiac
{
    public:
        HBH()
        {
            dai = rong = cao = 0;
        }
        ~HBH(){}
        virtual void nhap();
        virtual void xuat();
        bool checkHBH();
        virtual float tinhCV();
        virtual float tinhDT();
};

bool HBH::checkHBH()
{
    return (cao <= min(dai,rong));
}

void HBH::nhap()
{
    cout << "Nhap hinh binh hanh" << endl;
    cout << "Nhap 2 canh va chieu cao (chieu cao tuong ung voi canh nho hon)" << endl;
    cin >> dai >> rong >> cao;
    while (checkHBH() == false)
    {
        cout << "Chieu cao ko hop le, vui long nhap lai: ";
        cin >> dai >> rong >> cao;
    }
}

void HBH::xuat()
{
    cout << "Hinh binh hanh" << endl;
    cout << "Do dai 2 canh: " << dai << " " << rong << endl;
    cout << "Chieu cao: " << cao << endl;
}

float HBH::tinhCV()
{
    return (dai + rong) * 2;
}

float HBH::tinhDT()
{
    return min(dai,rong) * cao;
}

class Thoi:public TuGiac
{
    protected:
        float cheo1, cheo2;
    public:
        Thoi():TuGiac()
        {
            cheo1 = cheo2 = 0;
        }
        ~Thoi(){}
        bool checkThoi();
        virtual void nhap();
        virtual void xuat();
        virtual float tinhCV();
        virtual float tinhDT();
};

bool Thoi::checkThoi()
{
    return (dai == rong && (dai * 2 == sqrt(cheo1 * cheo1 + cheo2 * cheo2)));
}

void Thoi::nhap()
{
    cout << "Nhap hinh thoi" << endl;
    cout << "Nhap canh hinh thoi: ";
    cin >> dai;
    rong = dai;
    cout << "Nhap 2 duong cheo: ";
    cin >> cheo1 >> cheo2;
    while (checkThoi() == false)
    {
        cout << "Hai duong cheo ko hop le, vui long nhap lai" << endl;
        cout << "Nhap canh hinh thoi: ";
        cin >> dai;
        rong = dai;
        cout << "Nhap 2 duong cheo: ";
        cin >> cheo1 >> cheo2;
    }
}

void Thoi::xuat()
{
    cout << "Hinh thoi" << endl;
    cout << "Canh: " << dai << endl;
    cout << "Duong cheo 1 va 2: " << cheo1 << " " << cheo2 << endl;
}

float Thoi::tinhCV()
{
    return dai * 4;
}

float Thoi::tinhDT()
{
    return (cheo1 * cheo2) / 2;
}

class HV:public Thoi
{
    public:
        HV():Thoi(){}
        ~HV(){}
        void nhap();
        bool checkHV();
        void xuat();
        float tinhCV();
        float tinhDT();
};

bool HV::checkHV()
{
    return (dai == cao&& checkThoi() == true);
}

void HV::nhap()
{
    cout << "Nhap hinh vuong" << endl;
    cout << "Nhap canh: ";
    cin >> dai;
    rong = cao = dai;
    cheo1 = cheo2 = dai * sqrt(2);
}

void HV::xuat()
{
    cout << "Hinh vuong" << endl;
    cout << "Canh: " << dai << endl;
}

float HV::tinhCV()
{
    return Thoi::tinhCV();
}

float HV::tinhDT()
{
    return dai * dai;
}

int main()
{
    TuGiac *a[50];
    int n, lc, k, x;
    while (1)
    {
        cout << "==========MENU==========" << endl;
        cout << "Lua chon 1: Nhap danh sach cac hinh" << endl;
        cout << "Lua chon 2: Xuat danh sach cac hinh" << endl;
        cout << "Lua chon 3: Tinh chu vi va dien tich cac hinh trong danh sach" << endl;
        cout << "Nhap lua chon: ";
        cin >> lc;
        switch (lc)
        {
            case 1:
                cout << "Nhap so luong hinh: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "1 la hinh binh hanh" << endl;
                    cout << "2 la hinh chu nhat" << endl;
                    cout << "3 la hinh thoi" << endl;
                    cout << "4 la hinh vuong" << endl;
                    cout << "Chon: ";
                    cin >> k;
                    switch (k)
                    {
                        case 1:
                            a[i] = new HBH;
                            a[i]->nhap();
                            break;
                        case 2:
                            a[i] = new HCN;
                            a[i]->nhap();
                            break;
                        case 3:
                            a[i] = new Thoi;
                            a[i]->nhap();
                            break;
                        case 4:
                            a[i] = new HV;
                            a[i]->nhap();
                            break;
                        default:
                            break;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; i++)
                {
                    a[i]->xuat();
                    cout << endl;
                }
                break;
            case 3:
                for (int i = 0; i < n; i++)
                {
                    a[i]->xuat();
                    cout << "Chu vi: " << a[i]->tinhCV() << endl;
                    cout << "Dien tich: " << a[i]->tinhDT() << endl;
                    cout << endl;
                }
                break;
            default:
                cout << "Khong co lua chon nay" << endl;
                exit(1);
        }
    }
    return 0;
}

