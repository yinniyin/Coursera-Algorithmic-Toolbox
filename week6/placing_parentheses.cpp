#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <limits.h>

inline int max(int a, int b) { return (a > b) ? a : b; }
inline int min(int a, int b) { return (a < b) ? a : b; }

using std::vector;
using std::string;

int64_t eval(int64_t a, int64_t b, char op) 
{
	if (op == '*') 
	{
		return a * b;
	} 
	else if (op == '+')
	{
		return a + b;
	} 
	else if (op == '-') 
	{
		return a - b;
	} 
	else
	{
		assert(0);
	}
}

int64_t get_maximum_value(const string &exp, int offset, std::vector<std::vector<int64_t>>& maxTable, std::vector<std::vector<int64_t>>& minTable, bool isMax)
{
	//base case
	if (exp.length() == 1)
	{
		std::stringstream l;
		int ret;
		l << exp[0];
		l >> ret;
		return ret;
	}
	vector<int64_t> result;
	for (size_t i = 1; i <= exp.length() - 2; i += 2)
	{
		string lexp = exp.substr(0, i);
		string rexp = exp.substr(i + 1, exp.length() - i - 1);
		int64_t maxlhs, minlhs, maxrhs, minrhs;
		if (maxTable[0 + offset][i - 1 + offset] != LLONG_MAX)
		{
			maxlhs = maxTable[0 + offset][i - 1 + offset];
			minlhs = minTable[0 + offset][i - 1 + offset];
		}
		else
		{
			maxlhs = get_maximum_value(lexp, offset, maxTable, minTable, true);
			minlhs = get_maximum_value(lexp, offset, maxTable, minTable, false);
		}
		if (maxTable[i + 1 + offset][exp.length() - 1 + offset] != LLONG_MAX)
		{
			maxrhs = maxTable[i + 1 + offset][exp.length() - 1 + offset];
			minrhs = minTable[i + 1 + offset][exp.length() - 1 + offset];
		}
		else
		{
			maxrhs = get_maximum_value(rexp, offset + i + 1, maxTable, minTable, true);
			minrhs = get_maximum_value(rexp, offset + i + 1, maxTable, minTable, false);
		}
		result.push_back(eval(maxlhs, maxrhs, exp[i]));
		result.push_back(eval(maxlhs, minrhs, exp[i]));
		result.push_back(eval(minlhs, maxrhs, exp[i]));
		result.push_back(eval(minlhs, minrhs, exp[i]));
	}
	int64_t ret = result[0];
	for (auto i : result)
	{
		if (i > ret)
		{
			ret = i;
		}
	}
	maxTable[0 + offset][exp.length() - 1 + offset] = ret;
	ret = result[0];
	for (auto i : result)
	{
		if (i < ret)
		{
			ret = i;
		}
	}
	minTable[0 + offset][exp.length() - 1 + offset] = ret;
	if (isMax)
	{
		return maxTable[0 + offset][exp.length() - 1 + offset];
	}
	else
	{
		return minTable[0 + offset][exp.length() - 1 + offset];
	}
}

int main() 
{
	string s;
	std::cin >> s;
	//Table[start_id][end_id]
	std::vector<std::vector<int64_t>> maxTable(s.length(), std::vector<int64_t>(s.length(), LLONG_MAX));
	std::vector<std::vector<int64_t>> minTable(s.length(), std::vector<int64_t>(s.length(), LLONG_MAX));
	std::cout << get_maximum_value(s, 0, maxTable, minTable, true) << '\n';
	system("pause");
}