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
	//delete [] this->element;
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
	if (i <= 0)
	{
		return this->element[0];
	}
	else if (i >= this->size)
	{
		return this->element[this->size - 1];
	}
	else
	{
		return this->element[i];
	}
<<<<<<< HEAD
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
	for (int i = 0; i < this->size; i++)
	{
		this->element[i] = second.element[i];
	}
}

vector vector::get_copy()
{
	vector copy;
	copy.size = this->size;
	copy.element = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		copy.element[i] = this->element[i];
	}
	return copy;
=======
>>>>>>> parent of 1c31f9e... финал
}