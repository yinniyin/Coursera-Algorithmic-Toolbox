#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
	//write your code here
	auto cmp = [](const string&a, const string&b) 
				{ 
					string leftfirst = a + b;
					string rightfirst = b + a;
					return stoi(leftfirst) > stoi(rightfirst);
				};
	sort(a.begin(), a.end(), cmp);
	std::stringstream ret;
	for (size_t i = 0; i < a.size(); i++) {
	ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  //system("pause");
}
