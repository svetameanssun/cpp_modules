#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <sstream>
#include <set>


class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  int jacobsthal(int n);
  std::vector<int> buildInsertionOrder(int pend_size); //I save the insertion order the way I want
  std::vector<int> fordJohnson(std::vector<int> input);
  std::deque<int> fordJohnson(std::deque<int> input);
  template <typename T>
  bool hasRepeats(T &arr, int n) const;

	
};
