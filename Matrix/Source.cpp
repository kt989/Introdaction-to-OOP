//Matrix Homework 03/12/2022
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define WIDTH 20
#define DELIMITER "____________________________________________________________________________________________________"

class Matrix
{
	int cols;
	int rows;
	int** array;
		

public:
	int get_cols() const
	{
		return cols;
	}
	int get_rows() const
	{
		return cols;
	}
	void set_cols(int cols) 
	{
		this->cols=cols;
	}
	void set_rows(int rows)
	{
		this->rows = rows;
	}
	const int** get_array() const
	{
		return array;
	}
    int** get_array() 
	{
		return array;
	}
	//Constructors
	Matrix() //DefaultConstructor
	{
		this->cols = 5;
		this->rows = 5;
		this->array = new int*[rows] {};

		for (int i = 0; i < rows;i++)
		{
			array[i] = new int[cols]{};
		}
		cout.width(WIDTH);
		cout << std::left << "DeafaultConstructor" << this << endl;
	}

	Matrix(int cols) //SinglArgumentConstructor
	{
		this->cols = cols;
		this->rows = 5;
		this->array = new int* [rows] {};

		for (int i = 0; i < rows;i++)
		{
			array[i] = new int[cols] {};
		}
		cout.width(WIDTH);
		cout << std::left << "SinglArgumentConstructor:" << this << endl;
	}


	Matrix(int cols, int rows) //SinglArgumentConstructor
	{
		this->cols = cols;
		this->rows = rows;
		this->array = new int* [rows] {};

		for (int i = 0; i < rows;i++)
		{
			array[i] = new int[cols] {};
		}
		cout.width(WIDTH);
		cout << std::left << "TwoArgumentConstructor:" << this << endl;
	}

	~Matrix()
	{
		for (int i = 0; i < rows;i++)
		{
			delete array[i];
		}
		delete[] array;
		cout.width(WIDTH);
		cout << std::left << "Default Constructor:" << this << endl;
	}



	//Methods

	void fillrand() 
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j]=rand()%100;
			}
		}
	}
	
	void print() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
	}




};


Matrix operator+ (Matrix left, Matrix right)
{
	Matrix res;
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < left.get_cols(); j++)
		{
			res[i][j] = left.get_array()[i][j] + right.get_array()[i][j];
		}
	}
	return res;
}

void main()
{
	setlocale(LC_ALL, "");
	Matrix A(10, 10);
	A.fillrand();
	A.print();
	cout << endl<<DELIMITER << endl;
	Matrix B(10, 10);
	A.fillrand();
	A.print();
	Matrix C;
	C = A + B;
}
