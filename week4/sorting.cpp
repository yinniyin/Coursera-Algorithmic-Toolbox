#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}


void partition3(vector<int> &a, int l, int r, int& j, int& mr) {
	int x = a[l];
	vector<int> left, pivot, right;
	left.reserve(r - l + 1);
	pivot.reserve(r - l + 1);
	right.reserve(r - l + 1);
	for (int i = l; i <= r; i++) {
		if (a[i] == x)
		{
			pivot.push_back(a[i]);
		}
		else if (a[i] < x) 
		{                                       
			left.push_back(a[i]);
		}
		else
		{
			right.push_back(a[i]);
		}
	}
	int count = l;
	for (auto i : left)
	{
		a[count] = i;
		count++;
	}
	j = count;                              //beginning of pivot
	for (auto i : pivot)
	{
		a[count] = i;
		count++;
	}
	mr = count - 1;                         //end of pivot
	for (auto i : right)
	{
		a[count] = i;
		count++;
	}
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m, mr;
  partition3(a, l, r, m, mr);
  randomized_quick_sort3(a, l, m - 1);
  randomized_quick_sort3(a, mr + 1, r);
}


void randomized_quick_sort2(vector<int> &a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m = partition2(a, l, r);
	randomized_quick_sort2(a, l, m - 1);
	randomized_quick_sort2(a, m + 1, r);
}


int main() {
	
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) 
	{
		std::cin >> a[i];
	}
	randomized_quick_sort3(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cout << a[i] << ' ';
	}
	
	//stress test
	/*
	srand(3);
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 100000;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 1000000000;
		}
		vector<int> b(a);
		randomized_quick_sort3(a, 0, a.size() - 1);
		randomized_quick_sort2(b, 0, a.size() - 1);
		bool wrong = false;
		for (int j = 0; j < n; j++)
		{
			if (a[j] != b[j])
			{
				wrong = true;
				break;
			}
		}
		if (wrong)
		{
			count++;
		}
	}
	std::cout << count << std::endl;
	*/
	//system("pause");
	return 0;
}