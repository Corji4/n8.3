#include "class.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	matrix a;
	cin >> a;
	int m;
	do
	{
		cout << "¬ведите m>1\n";
		cin >> m;
	} while (m < 2);
	matrix result;
	result.e(a);
	result += a;
	for (int i = 1; i < m; i++)
	{
		matrix copy(a);
		copy.power(i + 1);
		result += copy;
	}
	result.print();
	system("pause");
}