#include "class.h"

matrix::matrix()
{
	count++;
	int x = count;
	string number = "";
	while (x)
	{
		number += x % 10 + 48;
		x /= 10;
	}
	reverse(number.begin(), number.end());
	this->name = "Матрица " + number;
	this->heigth = 0;
	this->length = 0;
}

matrix::matrix(matrix *copy)
{
	count++;
	int x = count;
	string number = "";
	while (x)
	{
		number += x % 10 + 48;
		x /= 10;
	}
	reverse(number.begin(), number.end());
	this->name = "Матрица " + number;
	this->heigth = copy->heigth;
	this->length = copy->length;
	this->element = new vector[this->heigth];
	for (int i = 0; i < this->heigth; i++)
	{
		this->element[i].set_size(this->length);
		this->element[i] = copy->element[i].get_copy();
	}
}

matrix::~matrix()
{
	delete [] this->element;
}

int matrix::count = 0;

void matrix::set_length(int n)
{
	if (n > 0)
	{
		this->length = n;
	}
}

void matrix::set_heigth(int n)
{
	if (n > 0)
	{
		this->heigth = n;
	}
}

istream& operator>> (istream &in, matrix &point)
{
	point.element = new vector[point.heigth];
	for (int i = 0; i < point.heigth; i++)
	{
		point.element[i].set_size(point.length);
		in >> point.element[i];
	}
	return in;
}

void matrix::print()
{
	cout << this->name << endl;
	if (this->length*this->heigth)
	{
		for (int i = 0; i < this->heigth; i++)
		{
			this->element[i].print();
		}
	}
	else
	{
		cout << "Матрица пуста" << endl;
	}
}