#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class vector
{
public:
	vector();
	~vector();
	void print();
	void set_size(int s);
	friend istream& operator>> (istream &in, vector &point);
	int operator[] (int i);
private:
	int size;
	int *element;
};

class matrix
{
public:
	matrix();
	~matrix();
	void set_length(int n);
	void set_heigth(int n);
	void print();
	friend istream& operator>> (istream &in, matrix &point);
private:
	static int count;
	int length;
	int heigth;
	string name;
	vector *element;
};