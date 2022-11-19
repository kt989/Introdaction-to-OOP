//homework 12.11.2022
#include <iostream>
#include <math.h>
using namespace std;

class Dist
{
	double x;
	double y;
	double dist;

public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	double get_dist() const
	{
		return dist;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_dist(double x, double y)
	{
		dist = sqrt(pow(x, 2) + pow(y, 2));
	}
};

double Distance(double x1, double y1, double x2, double y2);

void main()
{
	setlocale(LC_ALL, "");
	double A_x, A_y;
	cout << "Введите координаты точки, до которой нуно найти расстояние: "; cin >> A_x; cin >> A_y;
	Dist A;
	A.set_x(A_x);
	A.set_y(A_y);
	//cout << A.get_x() << "\t" << A.get_y()<<endl;
	A.set_dist(A.get_x(), A.get_y());
	cout << A.get_dist() << endl;

	cout << "\nРасстояние между двумя точками: \n\n";
	cout << "Введите координаты первой точки: "; cin >> A_x; cin >> A_y;
	double B_x, B_y;
	cout << "Введите координаты второй точки: "; cin >> B_x; cin >> B_y;
	cout << "\n\n Расстояние между точками равно: " << Distance(A_x, A_y, B_x, B_y)<<endl;
}

double Distance(double x1, double y1, double x2, double y2)
{
	double dist, x, y;
	x = x2 - x1;
	y = y2 - y1;
	dist = sqrt(pow(x, 2) + pow(y, 2));
	return dist;
}