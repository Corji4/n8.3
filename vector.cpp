#include "class.h"

vector::vector()
{
	this->size = 0;
	this->element = NULL;
}

vector::vector(vector *copy)
{
	this->size = copy->size;
	this->element = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->element[i] = copy->element[i];
	}
}

vector::~vector()
{
	delete [] this->element;
}

istream& operator>> (istream &in, vector &point)
{
	point.element = new int[point.size];
	for (int i = 0; i < point.size; i++)
	{
		in >> point.element[i];
	}
	return in;
}

void vector::print()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->element[i] << " ";
	}
	cout << endl;
}

void vector::set_size(int s)
{
	this->size = s;
}

int vector::operator[] (int i)
{
	try
	{
		if (i <= 0 || i >= this->size)
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

void vector::random()
{
	this->element = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->element[i] = rand() % 10;
	}
}

int vector::get(int i)
{
	if (i >= 0 && i < this->size)
	{
		return this->element[i];
	}
}

void vector::set(int i, int number)
{
	if (i >= 0 && i < this->size)
	{
		this->element[i] = number;
	}
}

vector vector::operator+ (vector second)
{
	vector result;
	result.element = new int[this->size];
	result.size = this->size;
	for (int i = 0; i < this->size; i++)
	{
		result.element[i] = this->element[i] + second.element[i];
	}
	return result;
}

void vector::operator= (vector second)
{
	delete [] this->element;
	this->size = second.size;
	this->element = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->element[i] = second.element[i];
	}
}