#include <algorithm>
#include <iostream>
#include <vector>
//#include <stdlib.h>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
	//special case
	if (a.size() == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			int count = 0;
			for (int j = 0; j < 3; j++)
			{
				if (a[i] == a[j])
				{
					count++;
					if (count == 2)
					{
						return a[i];
					}
				}
			}
		}
		return -1;
	}
	//general case
	if (left == right)
	{
		return -1;
	}
	if (left + 1 == right)
	{
		if (a[left] == a[right])
		{
			return a[left];
		}
		else
		{
			return -1;
		}                          
	}
	//write your code here
	int leftans = get_majority_element(a, left, (int)(right - left) / 2 + left);
	int rightans = get_majority_element(a, (int)(right - left) / 2 + left + 1, right);
	if (rightans != -1)
	{
		int count = 0;
		for (int i = left; i <= right; i++)
		{
			if (a[i] == rightans)
			{
				count += 1;
			}
		}
		if (count >= (int)(right - left + 1) / 2 + 1)
		{
			return std::max(leftans, rightans);
		}
	}
	if (leftans != -1)
	{
		int count = 0;
		for (int i = left; i <= right; i++)
		{
			if (a[i] == leftans)
			{
				count += 1;
			}
		}
		if (count >= (int)(right - left + 1) / 2 + 1)
		{
			return std::max(leftans, rightans);
		}
	}
	return -1;
}

int naive(vector<int> &a)
{
	if (a.size() == 1)
	{
		return -1;
	}
	for (int i = 0; i < (int)a.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < (int)a.size(); j++)
		{
			if (a[j] == a[i]) 
			{
				count += 1;
			}
		}
		if (count >= (int) a.size() / 2 + 1)
		{
			return a[i];
		}
	}
	return -1;
}

int main() {

	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';

	//stress test
	/*
	srand(4);
	for (int i = 300; i < 500; i++)
	{
		srand(i);
		int n = rand() % 100000 + 1;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 1000000000;
		}
		if (get_majority_element(a, 0, a.size() - 1) != naive(a))
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << a[j] << " ";
			}
			std::cout << std::endl;
			std::cout << get_majority_element(a, 0, a.size() - 1) << " " << naive(a) << std::endl;
		}
	}
	*/
	system("pause");
	return 0;
}

