//homework 12.11.2022
#include <iostream>
#include <math.h>
using namespace std;

class Point
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

	//Methods
	double distance (Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
		return distance;
	}
};

double Distance(Point A, Point B)
{
	double x_distance = B.get_x() - A.get_x();
	double y_distance = B.get_x() - A.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}

void main()
{
	setlocale(LC_ALL, "");
	double A_x, A_y;
	cout << "Введите координаты первой точки: "; cin >> A_x; cin >> A_y;
	Point A;
	A.set_x(A_x);
	A.set_y(A_y);


	Point B;
	double B_x, B_y;
	cout << "Введите координаты второй точки: "; cin >> B_x; cin >> B_y;
	B.set_x(B_x);
	B.set_y(B_y);
	cout << "\n\n Расстояние между точками равно: " << A.distance(B)<<endl;


	
	cout << "\nРасстояние между двумя точками: \n\n";
	cout << "Введите координаты первой точки: "; cin >> A_x; cin >> A_y;
	
	cout << "Введите координаты второй точки: "; cin >> B_x; cin >> B_y;
	cout << "\n\n Расстояние между точками равно: " << Distance(A, B) << endl;
	A.distance(B);
}


