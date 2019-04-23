#include "class.h"

vector::vector()
{
	this->size = 0;
}

vector::~vector()
{
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
}