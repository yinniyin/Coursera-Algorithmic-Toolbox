#include <iostream>
#include <vector>

using std::vector;

inline int max(int a, int b) { return (a > b) ? a : b; }

//int W: available knapsack capacity; int n: number of items left 
int optimal_weight(int W, const vector<int> &w, int n, std::vector<std::vector<int>>& table)
{
	//write your code here
	if (n == 0 || W == 0)
	{
		return 0;
	}
	if (w[n - 1] > W)
	{
		return optimal_weight(W, w, n - 1, table);
	}
	else
	{
		if (table[n - 1][W - w[n - 1]] == 0)
		{
			table[n - 1][W - w[n - 1]] = optimal_weight(W - w[n - 1], w, n - 1, table);
		}
		if (table[n - 1][W] == 0)
		{
			table[n - 1][W] = optimal_weight(W, w, n - 1, table);
		}
		int ret = max(w[n - 1] + table[n - 1][W - w[n - 1]], table[n - 1][W]);
		table[n][W] = ret;
		return ret;
	}
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) 
	{
		std::cin >> w[i];
	}
	//capacity, optimal weight
	std::vector<std::vector<int>> table(n + 1, vector<int>(W + 1, 0));
	std::cout << optimal_weight(W, w, n, table) << '\n';
	system("pause");
}