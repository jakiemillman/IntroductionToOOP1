

#include <iostream>
using namespace std;

class Matrix
{
	int rows;
	int columns;
	int** mtr;
public:
	Matrix(int rows, int colums) 
	{
		this->rows = rows;
		this->columns = colums;
		this->mtr = new int* [rows];
		for (int i = 0; i < rows; i++)mtr[i] = new int [colums] {};
		cout << "2ArgContructor:\t" << this << endl;
	}
	Matrix(int* obj)
	{

	}
	~Matrix()
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[]mtr[i];
		}
		cout << "Destructor:\t" << this << endl;
		delete[]mtr;
	}
	//methods

	int get_rows()const
	{
		return rows;
	}
	int get_rows()const
	{
		return columns;
	}
	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)cout << mtr[i][j] << " ";
			cout << endl;
		}
		
	}
	

};



int main()
{
    setlocale(LC_ALL, "rus");
	Matrix A(2, 3);
	A.print();
}

