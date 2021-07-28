#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <random>

using std::vector;

inline int max(int a, int b) { return (a > b) ? a : b; }

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

	std::default_random_engine e(0);

	int n;
	std::cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) 
	{
		std::cin >> A[i];
	}
	int sum = 0;
	for (size_t i = 0; i < A.size(); ++i)
	{
		sum += A[i];
	}
	if (sum % 3 != 0)
	{
		std::cout << 0 << '\n';
	}
	else
	{
		std::vector<std::vector<int>> table(n + 1, std::vector<int>(sum + 1, 0));
		std::set<int> result;
		int weight = optimal_weight(sum / 3, A, n, table);
		if (weight != sum / 3)
		{
			std::cout << 0 << '\n';
		}
		else
		{
			/*
			1. check if there is any subset has sum equal 1/3.
			2. if 1. is yes use backtrack to get which number is in that subset.
			3. check if we can pick anthoner subset has sum equal 1/3  if yes return 1 else return 0. There will be the case that you can not find the subset
			4 if 3 failed, shuffle the input and try again from step 1. Set a count variable for this step, return zero if the failure litmit is reach.
			*/

			//maximum shuffle 5 times
			bool can_split = false;
			for (int i = 0; i < 3; i++)
			{
				int curr_weight = sum / 3;
				std::vector<int> elements;
				while (curr_weight > 0)
				{
					for (int i = 1; i <= n; i++)
					{
						bool end = false;
						for (int j = 0; j <= sum; j++)
						{
							if (table[i][j] == curr_weight)
							{
								curr_weight -= A[i - 1];
								elements.push_back(A[i - 1]);
								end = true;
								break;
							}
						}
						if (end)
						{
							break;
						}
					}
				}
				std::vector<int> temp(A);
				for (int element : elements)
				{
					auto it = std::find(temp.begin(), temp.end(), element);
					if (it != temp.end())
					{
						temp.erase(it);
					}
				}
				weight = optimal_weight(sum / 3, temp, temp.size(), table);
				if (weight == sum / 3)
				{
					can_split = true;
					break;
				}
				else
				{
					std::shuffle(A.begin(), A.end(), e);
					optimal_weight(sum / 3, A, n, table); //reload table
				}
			}
			if (can_split)
			{
				std::cout << 1 << '\n';
			}
			else
			{
				std::cout << 0 << '\n';
			}
		}
	}
	system("pause");
	return 0;
}
