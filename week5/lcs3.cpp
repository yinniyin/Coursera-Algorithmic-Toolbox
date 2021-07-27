#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

inline int min(int a, int b) { return (a < b) ? a : b; }
inline int max(int a, int b) { return (a > b) ? a : b; }
inline int max3(int a, int b, int c)
{
	int ab = (a > b) ? a : b;
	return (ab > c) ? ab : c;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	//write your code here
	vector<int> l(c.size(), 0);
	vector<vector<int>> m(b.size(), l);
	vector<vector<vector<int>>> table(a.size(), m);
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			for (size_t k = 0; k < c.size(); k++)
			{
				if (a[i] != b[j] || a[i] != c[k] || b[j] != c[k])
				{
					int iid = (i > 0) ? i - 1 : 0;
					int jid = (j > 0) ? j - 1 : 0;
					int kid = (k > 0) ? k - 1 : 0;
					table[i][j][k] = max3(table[iid][j][k], table[i][jid][k], table[i][j][kid]);
				}
				else
				{
					if (i == 0 || j == 0 || k == 0)
					{
						table[i][j][k] = 1;
					}
					else
					{
						table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
					}
				}
			}
		}
	}
	return table[a.size() - 1][b.size() - 1][c.size() -1];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) 
	{
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) 
	{
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) 
	{
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
	system("pause");
	return 0;
}
