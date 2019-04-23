#include "class.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	matrix b,a;
	b.set_heigth(2);
	b.set_length(3);
	cin >> b;
	b.print();
	a.print();
	system("pause");
}