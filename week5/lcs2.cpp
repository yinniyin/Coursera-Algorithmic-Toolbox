/*
#include <iostream>
#include <vector>

using std::vector;

inline int max(int a, int b) { return (a > b) ? a : b; }

int lcs2(vector<int> &a, vector<int> &b) {
	//write your code here
	vector<int> row(b.size(), 0);
	vector<vector<int>> table(a.size(), row);
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			if (a[i] != b[j])
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				else if (i == 0 && j != 0)
				{
					table[i][j] = table[i][j-1];
				}
				else if (i != 0 && j == 0)
				{
					table[i][j] = table[i - 1][j];
				}
				else
				{
					table[i][j] = max(table[i - 1][j], table[i][j - 1]);
				}
			}
			else
			{
				if (i == 0 || j == 0)
				{
					table[i][j] = 1;
				}
				else
				{
					table[i][j] = table[i - 1][j - 1] + 1;
				}
			}
		}
	}
	return table[a.size() - 1][b.size() - 1];
}

int main() 
{
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) 
	{
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) 
	{
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
	
	system("pause");
	return 0;
}
*/