//IntrodactioOOP
#include <iostream>
using namespace std;

#define WIDTH 22
#define delimetr "\n_______________________________________________________________________\n"

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
	//   Constructors:
	/*Point() // конструктор по умолчанию
	{
		x = y = double();// double () - значение по умолчанию для типа double 
		cout.width(WIDTH);
		cout <<left<< "Constructor:" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout.width(WIDTH);
		cout << left << "SingleArgConstructor: " << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout.width(WIDTH);
		cout << left << "Parametrised constructor: " << this << endl;
	}
	
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << "CopyConstructor:" << this << endl;
	}
	
	~Point()
	{
		cout.width(WIDTH);
		cout << left<<"Destructor:" << this << endl;
	}

	//Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout.width(WIDTH);
		cout << left << "CopyAssigment: " << this << endl;
		return *this;
	}

	//   Methods
	double Distance(const Point& other) const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print() const
	{
		cout.width(WIDTH);
		cout<<left << "X = " << x << "Y = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

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

#ifdef DISTANCE_CHECK

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(5);
	B.set_y(7);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до точки В: " << A.Distance(B) << endl;
	cout << delimetr;
	cout << "Расстояние от точки B до точки A: " << B.Distance(A) << endl;
	cout << delimetr;
	cout << "Расстояние от точки А до точки В: " << distance( A, B) << endl;
	cout << delimetr;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor
	A.print();

	Point B = 5; // Single-argument constructor (конструктор с одним параметром)
	B.print();

	Point C(2, 3); // Parametrised constructor
	C.print();

	Point D = C; // CopyConstructor
	D.print();

	Point E;
	E = D; //CopyAssignment
	E.print();

#endif // CONSTRUCTORS_CHECK

	Point A, B, C;
	cout << delimetr << endl;
	A = B = C = Point(2, 3);
	cout << delimetr << endl;
}