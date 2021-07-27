/*
#include <iostream>
#include <vector>
#include <limits.h>

int coins[] = { 1, 3, 4 };

int get_change(int m, std::vector<int>& table) 
{
	//write your code here
	for (int i = 1; i <= m; i++)
	{
		for (int coin : coins)
		{
			if (coin <= i)
			{
				//check if m-coin is calculated previously
				int ret;
				if (table[i - coin] != INT_MAX)
				{
					ret = table[i - coin];
				}
				else
				{
					ret = get_change(i - coin, table);
				}
				if (ret != INT_MAX && ret + 1 < table[i])
				{
					table[i] = ret + 1;
				}
			}
		}
	}
	return table[m];
}

int main() 
{
	int m;
	std::cin >> m;
	std::vector<int> table;
	table.reserve(m + 1);
	table.push_back(0);
	for (int i = 1; i <= m; i++)
	{
		table.push_back(INT_MAX);
	}
	std::cout << get_change(m, table) << '\n';
	system("pause");
	return 0;
}
*/

