#include <iostream>
#include <cassert>
#include <vector>
//#include <stdlib.h>
//#include <algorithm>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size() - 1; 
  //write your code here
  int count = 0;
  while (left != right)
  {
	  if (x <= a[(int)(right - left) / 2 + left])
	  {
		  right = (int)(right - left) / 2 + left;
	  }
	  else
	  {
		  left = (int)(right - left) / 2 + left + 1;
	  }
	  count++;
  }
  if (a[left] == x)
  {
	  return left;
  }
  else
  {
	  return -1;
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {

	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) 
	{
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) 
	{
		std::cin >> b[i];
	}

	for (int i = 0; i < m; ++i) 
	{
		//replace with the call to binary_search when implemented
		//std::cout << linear_search(a, b[i]) << ' ';
		std::cout << binary_search(a, b[i]) << ' ';
	}
    //stress test
	/*
	srand(0);
	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 3 * 10000 + 1;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 1000000000 + 1;
		}
		std::sort(a.begin(), a.end());
		a.erase(std::unique(a.begin(), a.end()), a.end());
		for (int j = 0; j < 100; j++)
		{
			int test = rand() % 1000000000 + 1;
			if (linear_search(a, test) != binary_search(a, test))
			{
				std::cout << test << " " << linear_search(a, test) << " " << a[linear_search(a, test)];
				std::cout << binary_search(a, test) << " " << a[binary_search(a, test)] << std::endl;
			}
		}
	}
	*/
  system("pause");
  return 0;
}
