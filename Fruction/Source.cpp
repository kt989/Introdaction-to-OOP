//Fraction
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define WIDTH 26
//#define CONSTRUCTORS_CHECK
//#define ARIFMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define CONVERTION_FROM_CLASS_TO_OTHER
//#define HOMEWORK_1
#define HOMEWORK_2

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);
Fraction operator+ (Fraction left, Fraction right);
Fraction operator- (Fraction left, Fraction right);

class Fraction
{
	int integer; //целая часть
	int numerator;//числитель
	int denominator;//знаменатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	// Constructors
	Fraction()
	{
		this->integer=0;
		this->numerator=0;
		this->denominator=1;
		cout.width(WIDTH);
		cout << std::left<<"Default Constructor:" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left<<"SinglArgumentConstructor:" << this << endl;
	}

	Fraction(double other)
	{
		this->integer = int(other); 
		//cout << this->integer << "     integer" << endl;
		double buffer = other - this->integer;
		//cout << buffer << "   buffer"<<endl;
		int count = 1;
		double buffer_check = buffer;
		while ((buffer_check * 10 - (int)(buffer_check * 10)) != 0) //считаем сколько цифр после запятой
		{
			count++;
			if ((buffer_check * 10 - (int)(buffer_check*10)) != 0)
			{
				buffer_check *= 10;
			}
			//cout << count << "     count" << endl;
		}
		this->numerator = buffer*pow(10, count);
		//cout << this->numerator << "     numerator" << endl;
		this->denominator = pow(10, count);
		//cout << this->denominator << "     denominator" << endl;
		reduce();
		cout.width(WIDTH);
		cout << std::left << "SinglArgumentConstructor for double:" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		//this->denominator = denominator;
		cout.width(WIDTH);
		cout <<std::left<< "SinglArgumentConstructor:" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout <<std::left<< "Constructor:" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "CopyConstructor:" << this << endl;
	}
	~Fraction()
		{
		cout.width(WIDTH);
		cout <<std::left<< "Destructor:" << this << endl;
		}
	// Operators
		
	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout.width(WIDTH);
		cout << std::left << "OperatorAssignment:" << this << endl;
		return *this;
	}

	Fraction& operator*= (const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/= (const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+= (const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-= (const Fraction& other)
	{
		return *this = *this - other;
	}

	//            Increment/Decrement
	Fraction& operator++() //prefix increment
	{
		integer++;
		return *this;
	}

	Fraction& operator++(int) //postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--() //prefix decrement
	{
		integer--;
		return *this;
	}

	Fraction& operator--(int) //postfix decrement
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	// Type-cast operators
	explicit operator int() 
	{
		return  to_proper().integer;
	}

	explicit operator double() const
	{
		return integer+(double)numerator/denominator;
	}

	// Methods

	Fraction& to_proper() //Преобразует дробь в правильную
	{
		//Преобразует дробь в правильную
			integer += numerator / denominator;
			numerator %= denominator;
			return *this;
	}

	Fraction& to_improper() //Преобразует дробь в неправильную
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction inverted() const //Переворачивает дробь
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduce() //сокращает дробь
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}


void print() const
{
	if (integer) cout << integer;
	if (numerator)
	{
		if (numerator) cout << "(";
		cout << numerator << "/" << denominator;
		if (denominator) cout << ")";

	}
	cout << endl << endl;
}

};

Fraction operator*(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	Fraction res;
	/*res.set_numerator(left.get_numerator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());*/
	/* {
		left.get_numerator()* right.get_numerator(),
			left.get_denominator()* right.get_denominator()
	};
	res.to_proper();
	return res;*/
	return Fraction
	{
			left.get_numerator()* right.get_numerator(),
			left.get_denominator() * right.get_denominator()
	}.to_proper().reduce();

}

Fraction operator/ (const Fraction&  left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	{
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	}.to_proper();*/
	return left * right.inverted();
}

Fraction operator+ (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator (left.get_numerator() * right.get_denominator()+ left.get_denominator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res.to_proper();
}

Fraction operator- (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction res;
	res.set_numerator(left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator());
	res.set_denominator(left.get_denominator() * right.get_denominator());
	return res.to_proper();
}

//////// Comparison operators

bool operator== (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*f (left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() ==
		left.get_denominator() * right.get_numerator();
}

bool operator!= (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator> (Fraction left, Fraction right)
{

	return left.get_numerator() * right.get_denominator() >
		left.get_denominator() * right.get_numerator();
}

bool operator< (Fraction left, Fraction right)
{

	return left.get_numerator() * right.get_denominator() <
		left.get_denominator() * right.get_numerator();
}

bool operator>= (const Fraction& left, const Fraction& right)
{

	/*return ((left.get_numerator() * right.get_denominator() >
		left.get_denominator() * right.get_numerator()) || (left.get_numerator() * right.get_denominator() ==
		left.get_denominator() * right.get_numerator()));*/
	return left > right || left == right;
}

bool operator<= (const Fraction& left, const Fraction& right)
{

	/*return ((left.get_numerator() * right.get_denominator() <
		left.get_denominator() * right.get_numerator()) || (left.get_numerator() * right.get_denominator() ==
			left.get_denominator() * right.get_numerator()));*/
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, Fraction obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_numerator()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_denominator()) os << ")";

	}
	return os;
}

std::istream& operator>>(std::istream& os, Fraction& obj)
{
	int buffer;
	os >> buffer;
	obj.set_integer(buffer);
	//cout << obj.get_integer() << "   integer" << endl;
	os >> buffer;
	obj.set_numerator(buffer);
	//cout << obj.get_numerator() << "   numerator" << endl;
	os >> buffer;
	if (buffer == 0) obj.set_denominator(buffer+1);
	else obj.set_denominator(buffer);
	//cout << obj.get_denominator() << "   denominator" << endl;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();
	cout << "\n-----------------------\n";
	Fraction B = 5; //Single-argument constructor
	B.print();
	cout << "\n-----------------------\n";
	Fraction C(1, 2);//Double-argument constructor
	C.print();
	cout << "\n-----------------------\n";
	Fraction D(2, 3, 6); //Argument constructor
	D.print();
	cout << "\n-----------------------\n";

	Fraction E = D;//CopyConstructor
	E.print();
	cout << "\n-----------------------\n";

	Fraction F;
	F = D; // Operator Assignment
	F.print();
	cout << "\n-----------------------\n";
#endif // CONSTRUCTORS_CHECK


#ifdef ARIFMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	A.to_improper();
	/*A.print();
	A.to_proper();
	A.print();*/

	Fraction B(3, 4, 5);
	B.print();
	B.to_improper();
	/*B.print();
	B.to_proper();
	B.print();*/

	Fraction C = A * B;
	cout << "C = A * B;" << endl;
	C.print();

	cout << "C = A / B;" << endl;
	C = A / B;
	C.print();


	cout << "A + B;" << endl;
	C = A + B;
	C.print();

	cout << "A - B;" << endl;
	C = A - B;
	C.print();

	cout << "A += B;" << endl;
	A += B;
	A.print();

	cout << "A -= B;" << endl;
	A -= B;
	A.print();

	/*cout << "A *= B;" << endl;
	A *= B;
	A.print();

	cout << "A /= B;" << endl;

	A /= B;
	A.print();*/


#endif // ARIFMETICAL_OPERATORS_CHECK

	
#ifdef INCREMENT_CHECK
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}

	for (Fraction i(10, 1, 2); i.get_integer() >0; --i)
	{
		i.print();
	}
#endif // INCREMENT_CHECK


#ifdef COMPARISON_OPERATORS_CHECK
	cout << (Fraction(1, 4) > Fraction(1, 2)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef HOMEWORK_1
	Fraction A(2, 3, 4);
	cout << A << endl;
	cout << "Введите дробь в формате: целая_часть числитель знаменатель" << endl;
	Fraction B, C;
	cin >> B; /// НЕ ВЫВОДИТ НИЧЕГО!!!!!!!
	cout << B << endl;

#endif // HOMEWORK_1


#ifdef HOMEWORK_2
	Fraction B = 2.75;
	cout << B << endl;
#endif // HOMEWORK_2

#ifdef CONVERTION_FROM_CLASS_TO_OTHER
	Fraction A(5);
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	double b = (double)B;
	cout << b << endl;
#endif // CONVERTION_FROM_CLASS_TO_OTHER

} 