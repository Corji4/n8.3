#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

class vector
{
public:
	vector();
	vector(vector *copy);
	~vector();
	void print();
	void random();
	void set_size(int s);
	int get(int i);
	void set(int i, int number);
	friend istream& operator>> (istream &in, vector &point);
	int operator[] (int i);
	vector operator+ (vector second);
	void operator= (vector second);
	vector get_copy();
private:
	int size;
	int *element;
};

class matrix
{
public:
	matrix();
	matrix(matrix *copy);
	~matrix();
	void set_length(int n);
	void set_heigth(int n);
	void e(matrix &second);
	void print();
	vector operator[] (int i);
	friend istream& operator>> (istream &in, matrix &point);
	void operator= (matrix second);
	matrix operator+ (matrix second);
	matrix operator* (matrix second);
	void operator+= (matrix second);
	void power(int n);
private:
	static int count;
	int length;
	int heigth;
	string name;
	vector *element;
};