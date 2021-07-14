#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>
#include <algorithm> 
#include <assert.h>

using std::vector;
using std::string;
using std::pair;
using std::min;

long double minimal_distance(vector<int>& x, vector<int>& y) 
{
	if (x.size() < 2)
	{
		return std::numeric_limits<double>::max();
	}
	if (x.size() == 2)
	{
		//to avoid overflow, cast the difference into double before performing square operation
		long double xdiff = (x[0] - x[1]);
		long double ydiff = (y[0] - y[1]);
		long double temp = xdiff*xdiff + ydiff*ydiff;
		assert(temp >= 0.);
		return temp;
	}
	//write your code here
	//split into two halves
	int mid = (x.size() - 1) / 2;
	vector<int> xLeft(mid + 1), xRight(x.size() - mid - 1);
	vector<int> yLeft(mid + 1), yRight(x.size() - mid - 1);
	xLeft.assign(x.begin(), x.begin() + mid + 1);
	xRight.assign(x.begin() + mid + 1, x.end()); 
	yLeft.assign(y.begin(), y.begin() + mid + 1);
	yRight.assign(y.begin() + mid + 1, y.end());
	//assert(xLeft.size() + xRight.size() == x.size());
	long double min_left = minimal_distance(xLeft, yLeft);
	long double min_right = minimal_distance(xRight, yRight);
	long double min = std::min(min_left, min_right);
	//assert(min >= 0.);
	//check the strip area
	long double midx = (long double) (xLeft[mid] + xRight[0]) / 2.;
	vector<pair<int, int>> strip_points;
	strip_points.reserve(x.size());
	long double sqrt_min = sqrtl(min);
	if (xLeft.size() > 0)
	{
		for (int i = (int) xLeft.size() - 1; i >= 0; i--)
		{
			if (midx - xLeft[i] <= sqrt_min)
			{
				strip_points.push_back(std::make_pair(xLeft[i], yLeft[i]));
			}
			else
			{
				break;
			}
		}
	}
	for (size_t i = 0; i < xRight.size(); i++)
	{
		if (xRight[i] - midx <= sqrt_min)
		{
			strip_points.push_back(std::make_pair(xRight[i], yRight[i]));
		}
		else
		{
			break;
		}
	}
	if (strip_points.size() < 2)
	{
		return min;
	}
	else
	{
		std::sort(strip_points.begin(), strip_points.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
		long double current_min = min;
		for (size_t i = 0; i < strip_points.size(); i++)
		{
			for (size_t j = i + 1; j < strip_points.size(); j++)
			{
				if (j - i > 7)
				{
					break;
				}
				//to avoid overflow, cast the difference into double before performing square operation
				long double xdiff = strip_points[i].first - strip_points[j].first;
				long double ydiff = strip_points[i].second - strip_points[j].second;
				long double temp = xdiff*xdiff + ydiff*ydiff;
				//assert(temp >= 0.);
				if (temp == 0.)
				{
					return 0.;
				}
				current_min = std::min(temp, current_min);
			}
		}
		return current_min;
	}
}

double naive(vector<int>& x, vector<int>& y)
{
	double ret = std::numeric_limits<double>::max();
	for (size_t i = 0; i < x.size(); i++)
	{
		for (size_t j = i + 1; j < x.size(); j++)
		{
			double xdiff = x[i] - x[j];
			double ydiff = y[i] - y[j];
			ret = std::min(xdiff*xdiff + ydiff*ydiff, ret);
			if (ret == 0)
			{
				return ret;
			}
		}
	}
	return ret;
}

int main() {

	size_t n;
	std::cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (size_t i = 0; i < n; i++) 
	{
		std::cin >> x[i] >> y[i];
	}
	vector<pair<int, int>> coor(n);
	for (size_t i = 0; i < n; i++)
	{
		coor[i] = std::make_pair(x[i], y[i]);
	}
	std::sort(coor.begin(), coor.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first; });
	for (size_t i = 0; i < n; i++)
	{
		x[i] = coor[i].first;
		y[i] = coor[i].second;
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << sqrtl(minimal_distance(x, y)) << "\n";

	//stress test
	/*
	srand(6);
	for (int j = 0; j < 100; j++)
	{
		size_t n = rand() % (100000 - 2) + 2;
		vector<int> x(n);
		vector<int> y(n);
		for (size_t i = 0; i < n; i++)
		{
			x[i] = rand() % (2 * 1000000000) - 1000000000;
			y[i] = rand() % (2 * 1000000000) - 1000000000;
		}
		vector<pair<int, int>> coor(n);
		for (size_t i = 0; i < n; i++)
		{
			coor[i] = std::make_pair(x[i], y[i]);
		}
		std::sort(coor.begin(), coor.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first < b.first; });
		for (size_t i = 0; i < n; i++)
		{
			x[i] = coor[i].first;
			y[i] = coor[i].second;
		}
		double min1 = sqrt(minimal_distance(x, y));
		double min2 = sqrt(naive(x, y));
		if (min1 != min2)
		{

			std::cout << min1 << " " << min2 << std::endl;
			break;
		}
	}
	*/
	system("pause");
}
