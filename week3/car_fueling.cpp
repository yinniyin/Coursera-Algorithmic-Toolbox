#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
// write your code here
int refills = 0, currPos = 0, remain = tank;
for (int i = 0; i < stops.size(); i++)
{
	if (stops[i] - currPos > tank)
	{
	return -1;
	}
	remain -= stops[i] - currPos;
	currPos = stops[i];
	if (i != stops.size() - 1)
	{
		if (remain < stops[i + 1] - currPos)
		{
			remain = tank;
			refills += 1;
		}
		}
		else
		{
			if (dist - currPos > tank)
			{
				return -1;
			}
			if (remain < dist - currPos)
			{
				refills += 1;
			}
		}
	}
	return refills;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> stops.at(i);
	}

	cout << compute_min_refills(d, m, stops) << "\n";

	//	system("pause");
	return 0;
}


