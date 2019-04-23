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

