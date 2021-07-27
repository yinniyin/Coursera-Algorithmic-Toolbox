/*
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using std::string;

inline int min(int x, int y) { return (x < y) ? x : y; }
inline int min3(int x, int y, int z) { return min(min(x, y), z); }

int edit_distance(string str1, string str2)
{
	std::vector<int> init(str2.length() + 1, INT_MAX);
	std::vector<std::vector<int>> table(2, init);
	int m = str1.length(), n = str2.length();
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
			{
				table[i % 2][j] = j;
			}
			else if (j == 0)
			{
				table[i % 2][j] = i;
			}
			else if (str1[i - 1] == str2[j - 1])
			{
				table[i % 2][j] = table[(i - 1) % 2][j - 1];
			}
			else
			{
				table[i % 2][j] = 1 + min3(table[(i - 1) % 2][j], table[i % 2][j - 1], table[(i - 1) % 2][j - 1]);
			}
		}
	}
	return table[m % 2][n];
}

// Driver code
int main()
{
	// your code goes here
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	system("pause");
	return 0;
}
*/
