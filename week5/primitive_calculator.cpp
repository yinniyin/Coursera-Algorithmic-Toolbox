/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

//table: (#operations, previous value)
int optimal_dp(int n, vector<std::pair<int, int>>& table)
{
	for (int i = 1; i < n; i++)
	{
		if (i * 3 <= n)
		{
			if (table[i].first + 1 < table[i * 3].first)
			{
				table[i * 3].first = table[i].first + 1;
				table[i * 3].second = i;
			}
		}
		if (i * 2 <= n)
		{
			if (table[i].first + 1 < table[i * 2].first)
			{
				table[i * 2].first = table[i].first + 1;
				table[i * 2].second = i;
			}
		}
		if (i + 1 <= n)
		{
			if (table[i].first + 1 < table[i + 1].first)
			{
				table[i + 1].first = table[i].first + 1;
				table[i + 1].second = i;
			}
		}
	}
	return table[n].first;
}

int main() {
	int n;
	std::cin >> n;
	vector<std::pair<int, int>> table;
	table.reserve(n + 1);
	table.push_back(std::make_pair(0, 1));
	table.push_back(std::make_pair(0, 1));
	for (int i = 2; i <= n; i++)
	{
		table.push_back(std::make_pair(INT_MAX, 1));
	}
	int end = optimal_dp(n, table);
	std::cout << end << std::endl;
	
	vector<int> steps;
	steps.reserve(n);
	std::pair<int, int> trace = table[n];
	steps.push_back(n);
	while (trace.first != 0)
	{
		steps.push_back(trace.second);
		trace = table[trace.second];
	}
	reverse(steps.begin(), steps.end());
	for (int s : steps)
	{
		std::cout << s << " ";
	}
	system("pause");
	return 0;
	//vector<int> sequence = optimal_sequence(n);
	//std::cout << sequence.size() - 1 << std::endl;
	//for (size_t i = 0; i < sequence.size(); ++i) {
	//std::cout << sequence[i] << " ";
	//}
}
*/