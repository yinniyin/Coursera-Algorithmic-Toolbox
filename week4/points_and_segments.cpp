#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int binary_search(const vector<std::pair<int, int>>& range, int x) {
	int left = 0, right = (int)range.size() - 1;
	//write your code here
	int count = 0;
	while (left != right)
	{
		if (x <= range[(int)(right - left) / 2 + left].second)
		{
			right = (int)(right - left) / 2 + left;
		}
		else
		{
			left = (int)(right - left) / 2 + left + 1;
		}
		count++;
	}
	//now range[left].second is cloest to x (range[left-1].second < x and range[left+1].second > x)
	if (range[left].second >= x)
	{
		return left;
	}
	else if (left < range.size() - 1)
	{
		if (range[left + 1].second >= x)
		{
			return left + 1;
		}
	}
	else
	{
		return -1;
	}
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	vector<std::pair<int, int>> range(starts.size());
	//write your code here
	for (size_t i = 0; i < starts.size(); i++)
	{
		range[i] = std::make_pair(starts[i], ends[i]);
	}
	std::sort(range.begin(), range.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
			{
				return a.second < b.second;
			});
	for (size_t i = 0; i < points.size(); i++)
	{
		int count = 0;
		int startIdx = binary_search(range, points[i]);
		if (startIdx != -1)
		{
			for (int j = startIdx; j < (int)range.size(); j++)
			{
				if (points[i] >= range[j].first)
				{
					count++;
				}
			}
		}
		cnt[i] = count;
	}
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
	
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) 
	{
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) 
	{
		std::cin >> points[i];
	}
	//use fast_count_segments
	//vector<int> cnt = naive_count_segments(starts, ends, points);
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++)
	{
		std::cout << cnt[i] << ' ';
	}
	
	//stress test
	/*
	srand(2);
	int wrong_count = 0;
	for (int j = 0; j < 100; j++)
	{
		int n = rand() % 1000 + 1;
		int m = rand() % 1000 + 1;
		vector<int> starts(n), ends(n);
		for (size_t i = 0; i < starts.size(); i++)
		{
			starts[i] = rand() % (2 * 100000000) - 100000000;
			ends[i] = rand() % (2 * 100000000) - 100000000;
		}
		vector<int> points(m);
		for (size_t i = 0; i < points.size(); i++)
		{
			points[i] = rand() % (2 * 100000000) - 100000000;
		}
		vector<int> cnt = naive_count_segments(starts, ends, points);
		vector<int> cnt2 = fast_count_segments(starts, ends, points);
		bool wrong = false;
		for (size_t i = 0; i < cnt.size(); i++)
		{
			if (cnt[i] != cnt2[i])
			{
				wrong = true;
				break;
			}
		}
	}
	std::cout << wrong_count << std::endl;
	*/
	system("pause");
}

