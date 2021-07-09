#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int64_t max_dot_product(vector<int>& a, vector<int>& b) {
  // write your code here
  int64_t result = 0;
  std::sort(a.begin(), a.end(), [](const int& a, const int&b) { return a > b; });
  std::sort(b.begin(), b.end(), [](const int& a, const int&b) { return a > b; });
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  //system("pause");
  return 0;
}
