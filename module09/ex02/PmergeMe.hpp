#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <set>


class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  std::vector<int> fordJohnson(std::vector<int> input);
  std::deque<int> fordJohnson(std::deque<int> input);

  template <typename T>
  bool hasRepeats(const T &arr) const;

 private:
  int jacobsthal(int n);
  std::vector<int> buildInsertionOrder(int pend_size); //I save the insertion order the way I want
  


	
};
