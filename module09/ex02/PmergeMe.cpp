#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other; 
    return *this; 
}
PmergeMe::~PmergeMe() {}

int PmergeMe::jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    return b;
}

std::vector<int> PmergeMe::buildInsertionOrder(int pend_size) {
    std::vector<int> order;
    if (pend_size == 0) return order;
    order.push_back(1);
    if (pend_size == 1) return order;
    int k = 2;
    while (true) {
        int jk      = jacobsthal(k);
        int jk_prev = jacobsthal(k - 1);
        int group_start = std::min(jk, pend_size);
        int group_end   = jk_prev + 1;
        for (int idx = group_start; idx >= group_end; idx--)
            order.push_back(idx);
        if (jk >= pend_size) break;
        k++;
    }
    return order;
}

std::deque<int> PmergeMe::fordJohnson(std::deque<int> input){

    if (input.size() <= 1) {
        return input;
    }
    if (input.size() == 2) {
        if (input[0] > input[1]) std::swap(input[0], input[1]);
        return input;
    }

    // Step 1: adjacent pairs
    std::vector<std::pair<int,int> > pairs;
    bool has_straggler = (input.size() % 2 != 0);
    int  straggler     = has_straggler ? input.back() : 0;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int lo = std::min(input[i], input[i+1]);
        int hi = std::max(input[i], input[i+1]);
        pairs.push_back(std::make_pair(lo, hi));
    }

    // Step 2: extract a's and sort them RECURSIVELY
    std::deque<int> bigVals;
    for (size_t i = 0; i < pairs.size(); i++)
        bigVals.push_back(pairs[i].second);

    std::deque<int> sortedBigVals = fordJohnson(bigVals);

    // Step 3: reorder pairs to follow sorted a's (carry b with its a)
    std::vector<std::pair<int,int> > sortedPairs;
    for (size_t i = 0; i < sortedBigVals.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == sortedBigVals[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    // Step 4: main chain + pend
    std::deque<int> main_chain = sortedBigVals;
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); i++)
        pend.push_back(sortedPairs[i].first);


    // Step 5: insert b1 at front
    main_chain.insert(main_chain.begin(), pend[0]);

    // Step 6: Jacobsthal-ordered insertions
    std::vector<int> order = buildInsertionOrder((int)pend.size());
    for (size_t i = 1; i < order.size(); i++) {
        int b_idx = order[i];
        int b_val = pend[b_idx - 1];
        int a_val = sortedPairs[b_idx - 1].second;

        std::deque<int>::iterator bound_it =
            std::find(main_chain.begin(), main_chain.end(), a_val);
        std::deque<int>::iterator pos =
            std::lower_bound(main_chain.begin(), bound_it + 1, b_val);

        main_chain.insert(pos, b_val);
    }

    // Step 7: straggler
    if (has_straggler) {
        std::deque<int>::iterator pos =
            std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }
  
    return main_chain;
}



std::vector<int> PmergeMe::fordJohnson(std::vector<int> input){

    if (input.size() <= 1) {
        return input;
    }
    if (input.size() == 2) {
        if (input[0] > input[1]) std::swap(input[0], input[1]);
        return input;
    }

    // Step 1: adjacent pairs
    std::vector<std::pair<int,int> > pairs;
    bool has_straggler = (input.size() % 2 != 0);
    int  straggler     = has_straggler ? input.back() : 0;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int lo = std::min(input[i], input[i+1]);
        int hi = std::max(input[i], input[i+1]);
        pairs.push_back(std::make_pair(lo, hi));
    }

    // Step 2: extract a's and sort them RECURSIVELY
    std::vector<int> bigVals;
    for (size_t i = 0; i < pairs.size(); i++)
        bigVals.push_back(pairs[i].second);

    std::vector<int> sortedBigVals = fordJohnson(bigVals);

    // Step 3: reorder pairs to follow sorted a's (carry b with its a)
    std::vector<std::pair<int,int> > sortedPairs;
    for (size_t i = 0; i < sortedBigVals.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == sortedBigVals[i]) {
                sortedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    // Step 4: main chain + pend
    std::vector<int> main_chain = sortedBigVals;
    std::vector<int> pend;
    for (size_t i = 0; i < sortedPairs.size(); i++)
        pend.push_back(sortedPairs[i].first);


    // Step 5: insert b1 at front
    main_chain.insert(main_chain.begin(), pend[0]);

    // Step 6: Jacobsthal-ordered insertions
    std::vector<int> order = buildInsertionOrder((int)pend.size());
    for (size_t i = 1; i < order.size(); i++) {
        int b_idx = order[i];
        int b_val = pend[b_idx - 1];
        int a_val = sortedPairs[b_idx - 1].second;

        std::vector<int>::iterator bound_it =
            std::find(main_chain.begin(), main_chain.end(), a_val);
        std::vector<int>::iterator pos =
            std::lower_bound(main_chain.begin(), bound_it + 1, b_val);

        main_chain.insert(pos, b_val);
    }

    // Step 7: straggler
    if (has_straggler) {
        std::vector<int>::iterator pos =
            std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    /*std::cout << indent << "<< returning: ";
    for (size_t i = 0; i < main_chain.size(); i++) std::cout << main_chain[i] << " ";
    std::cout << "\n";*/

    return main_chain;
}



