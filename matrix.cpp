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
	this->heigth = 3;
	this->length = 3;
	this->element = new vector[this->heigth];
	for (int i = 0; i < this->heigth; i++)
	{
		this->element[i].set_size(this->length);
		this->element[i].random();
	}
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
	this->heigth = copy->get_heigth();
	this->length = copy->get_length();
	this->element = new vector[this->heigth];
	for (int i = 0; i < this->heigth; i++)
	{
		this->element[i].set_size(this->length);
		this->element[i] = copy->element[i];
	}
}

matrix::~matrix()
{
}

int matrix::count = 0;

void matrix::set_length(int n)
{
	if (n > 0)
	{
		this->length = n;
	}
}

int matrix::get_length()
{
	return this->length;
}

int matrix::get_heigth()
{
	return this->heigth;
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
	do
	{
		cout << "Введите количество строк:\n";
		cin >> point.heigth;
	} while (point.heigth < 1);
	do
	{
		cout << "Введите количество столбцов:\n";
		cin >> point.length;
	} while (point.length < 1);
	point.element = new vector[point.heigth];
	cout << "Введите элементы матрицы:\n";
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

vector matrix::operator[] (int i)
{
	try
	{
		if (i <= 0 || i >= this->heigth)
		{
			throw 0;
		}
	}
	catch (int i)
	{
		return this->element[i];
	};
	return this->element[i];
}

void matrix::operator= (matrix second)
{
	if (this->heigth != second.heigth ||
		this->length != second.length)
	{
		return;
	}
	for (int i = 0; i < this->heigth; i++)
	{
		this->element[i] = second.element[i];
	}
}

matrix matrix::operator+ (matrix second)
{
	if (this->heigth != second.heigth ||
		this->length != second.length)
	{
		return *this;
	}
	matrix result;
	result.set_heigth(this->heigth);
	result.set_length(this->length);
	for (int i = 0; i < this->heigth; i++)
	{
		result.element[i] = this->element[i] + second.element[i];
	}
	return result;
}

matrix matrix::operator* (matrix second)
{
	if (this->heigth != second.length)
	{
		return *this;
	}
	matrix result;
	result.set_heigth(this->heigth);
	result.set_length(second.length);
	for (int i = 0; i < this->heigth; i++)
	{
		for (int j = 0; j < second.length; j++)
		{
			int summ = 0;
			for (int k = 0; k < second.heigth; k++)
			{
				summ += this->element[k].get(i) * second.element[j].get(k);
			}
			result.element[j].set(i, summ);
		}	
	}
	return result;
}

void matrix::operator+= (matrix second)
{
	if (this->heigth != second.heigth ||
		this->length != second.length)
	{
		return;
	}
	for (int i = 0; i < this->heigth; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->element[i].set(j, this->element[i].get(j) + second.element[i].get(j));
		}
	}
}

void matrix::e(matrix &second)
{
	this->length = second.length;
	this->heigth = second.heigth;
	for (int i = 0; i < this->heigth; i++)
	{
		this->element[i].set_size(this->length);
		for (int j = 0; j < this->length; j++)
		{
			this->element[i].set(j, 0);
			this->element[i].set(i, 1);
		}
	}
}

void matrix::power(int n)
{
	if (n <= 1)
	{
		return;
	}
	matrix copy = *this;
	for (int i = 1; i < n; i++)
	{
		*this = *this * copy;
	}
}