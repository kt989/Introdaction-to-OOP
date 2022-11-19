//IntrodactioOOP
#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;

public:
	double get_x() const //метод получения х
	{
		return x;
	}
	double get_y() const //метод получения х
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT
#define STRUCT_POINT_2

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef STRUCT_POINT
	
	int a;//Объявление переменной 'а' типа 'int'
	Point A;// Объявление переменной 'А' типа 'Point'
	        //Создание объекта 'А' структуры 'Point'
	        // Создание экземпляра 'А' структуры 'Point'
	A.x = 2;
	A.y = 3;
	
	cout << A.x << "\t" << A.y<<endl;
	Point* pA = &A;
	cout << pA << endl;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl; // тоже самое cout << pA->x << "\t" << pA->y << endl;
	cout << sizeof(Point) << endl;
#endif //STRUCT_POINT

#ifdef STRUCT_POINT_2

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

#endif // STRUCT_POINT_2


}