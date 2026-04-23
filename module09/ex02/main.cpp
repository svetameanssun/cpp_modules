#include "PmergeMe.hpp"
#include <set>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; i < argc; ++i) {
        int val = std::atoi(argv[i]);
        if (val <= 0) { // По условию только положительные
            std::cerr << "Error" << std::endl;
            return 1;
        }
        v.push_back(val);
        d.push_back(val);
    }

    PmergeMe pmm;
    if (pmm.hasDuplicates(v)) {
        std::cerr << "Error: duplicates found" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << std::endl;

    clock_t startV = clock();
    std::vector<int> resV = pmm.fordJohnson(v);
    clock_t endV = clock();

    clock_t startD = clock();
    std::deque<int> resD = pmm.fordJohnson(d);
    clock_t endD = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < resV.size(); ++i) std::cout << resV[i] << " ";
    std::cout << std::endl;

    double timeV = static_cast<double>(endV - startV) / CLOCKS_PER_SEC * 1e6;
    double timeD = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeD << " us" << std::endl;

    return 0;
}
