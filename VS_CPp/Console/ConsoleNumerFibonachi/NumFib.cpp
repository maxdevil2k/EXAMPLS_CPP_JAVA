#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	system("color 1F");

	cout << "\n\n\t����i����i��� ����� �i�����i:\n\n";

	long a1, a2, a3;
	int n;

	a1 = a2 = 1; a3 = a2 + a1;
	printf("%8i%8i%8i", a1, a2, a3);

	n = 4;
	while (n < 47)
	{
		a1 = a2;
		a2 = a3;
		a3 = a2 + a1;
		printf("%16i", a3);
		n++;
	}

	cout << "\n\n\t";
	system("pause");
	return 0;
}