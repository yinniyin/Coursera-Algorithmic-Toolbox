#include <iostream>
#include <stdlib.h>

int get_change(int m) {
	int n = 0;
	while (m > 0)
	{
		if (m >= 10)
		{
			n += 1;
			m -= 10;
		}
		else if (m >= 5)
		{
			n += 1;
			m -= 5;
		}
		else
		{
			n += 1;
			m -= 1;
		}
	}
	return n;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << std::endl;
	//srand(0);
	//for (int i = 0; i < 100; i++)
	//{
	//	int m = rand() % 1000;
	//	std::cout << m << " " << get_change(m) << '\n';
	//}
	//system("pause");
	return 0;
}
