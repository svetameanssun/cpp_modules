#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <set>
#include <iomanip>


class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  std::vector<int> fordJohnson(std::vector<int> input);
  std::deque<int> fordJohnson(std::deque<int> input);

  template <typename T>
    bool hasRepeats(T &arr) const {
    std::set<int> s;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (!s.insert(arr[i]).second) return true;
    }
    return false;
}

 private:
  int jacobsthal(int n);
  std::vector<int> buildInsertionOrder(int pend_size); //I save the insertion order the way I want
  


	
};
