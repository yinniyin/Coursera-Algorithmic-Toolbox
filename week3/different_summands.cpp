#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int remain = n;
  for (int i = 1; i <= n; i++)
  {
	  if (i <= remain)
	  {
		  remain -= i;
		  summands.push_back(i);
	  }
	  else
	  {
		  summands.back() += remain;
		  break;
	  }
	  if (remain <= 0)
	  {
		  break;
	  }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  //system("pause");
}

