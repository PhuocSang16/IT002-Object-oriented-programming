#include <iostream>
using namespace std;
typedef struct ThoiGian
{
	int ngay, thang, nam;
} TG;
void Nhap(TG &x, int &Ngaycuoi)
{
	cout << "Nhap ngay: ";
	cin >> x.ngay;
	cout << "Nhap thang: ";
	cin >> x.thang;
	cout << "Nhap nam: ";
	cin >> x.nam;
	switch (x.thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		Ngaycuoi = 31;
		break;
	case 4: case 6: case 9: case 11:
		Ngaycuoi = 30;
		break;
	case 2:
		if (x.nam % 400 == 0 || (x.nam % 4 == 0 && x.nam % 100 != 0))
			Ngaycuoi = 29;
		else Ngaycuoi = 28;
		break;
	default:
	    Ngaycuoi = 0;
	}
	if (Ngaycuoi == 0 || x.nam < 1 || (Ngaycuoi != 0 && (x.ngay > Ngaycuoi || x.ngay < 1)))
	{
		cout << "Ngay thanh nam khong hop le, vui long nhap lai:" << endl;
		Nhap(x, Ngaycuoi);
	}
}
void Ngaytieptheo(TG x,TG &y,int n)
{
	if (x.ngay < n)
	{
		y.ngay = x.ngay + 1;
		y.thang = x.thang;
		y.nam = x.nam;
	}
	else
	{
		if (x.thang != 12)
		{
			y.ngay = 1;
			y.thang = x.thang + 1;
			y.nam = x.nam;
		}
		else
		{
			y.ngay = 1;
			y.thang = 1;
			y.nam = x.nam + 1;
		}
	}
}
int main()
{
	TG d1, d2;
	int Ngaycuoi;
	Nhap(d1,Ngaycuoi);
	Ngaytieptheo(d1, d2, Ngaycuoi);
    cout << "Ngay ke tiep la: " << d2.ngay << "/" << d2.thang << "/" << d2.nam;
	return 0;
}
