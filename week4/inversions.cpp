#include <iostream>
#include <vector>

using std::vector;
using std::swap;

int64_t get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	int64_t number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;   
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here
	//get inversion number
	int leftId = left, rightId = ave;
	for (size_t j = ave; j < right; j++)
	{
		for (size_t i = left; i < ave; i++)
		{
			if (a[i] > a[j])
			{
				number_of_inversions++;
			}
		}
	}

	//sorting
	leftId = left, rightId = ave;
	for (size_t i = left; i < right; i++)
	{
		if (leftId < ave && rightId < right)
		{
			if (a[leftId] <= a[rightId])
			{
				b[i] = a[leftId];
				leftId++;
			}
			else
			{
				b[i] = a[rightId];
				rightId++;
			}
		}
		else if (leftId >= ave)
		{
			b[i] = a[rightId];
			rightId++;
		}
		else if (rightId >= right)
		{
			b[i] = a[leftId];
			leftId++; 
		}
	}
	for (size_t i = left; i < right; i++)
	{
		a[i] = b[i];
	}
	
	return number_of_inversions;
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

int main() {

	int n;
	std::cin >> n;
	vector<int> a(n);                       
	for (size_t i = 0; i < a.size(); i++) {
	std::cin >> a[i];
	}
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

	//stress test
	/*
	srand(3);
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 10000;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
		{
			a[j] = rand() % 10000;
		}
		vector<int> a1(a);
		vector<int> b(a.size());
		randomized_quick_sort3(a, 0, a.size() - 1);
		get_number_of_inversions(a1, b, 0, a.size());
		bool wrong = false;
		for (int j = 0; j < n; j++)
		{
			if (a[j] != a1[j])
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
	system("pause");
	return 0;
}

