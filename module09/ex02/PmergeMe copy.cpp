#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

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

template <typename T>
bool PmergeMe::hasRepeats(T&arr, int n) const{
    std::unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i]))
            return (true);
        else{
            seen.insert(arr[i]);
        }
    }
    return (false);
}

int main(int argc, char **argv) {
    try{
        if (argc == 1){
            throw std::invalid_argument("Usage: ./program <arg>");
        }
    }catch(std::exception&e){
        std::cerr<< "Error: " << e.what() << std::endl;
        return (1);
    }
    
   //std::vector<int> input = {847, 392, 105, 678, 921, 56, 734, 289, 460, 812, 193, 574, 368, 999, 241, 670, 88, 715, 502, 349, 120, 955, 437, 681, 264, 790, 53, 826, 315, 908, 472, 619, 157, 843, 290, 731, 564, 982, 410, 275, 699, 34, 851, 223, 768, 599, 142, 907, 388, 621, 77, 455, 834, 266, 913, 548, 301, 694, 125, 872, 489, 250, 763, 910, 408, 662, 175, 5990, 521, 836, 92, 744, 317, 658, 481, 903, 229, 570, 346, 814, 67, 988, 432, 709, 284, 561, 798, 140, 623, 359, 875, 218, 946, 537, 660, 104, 722, 483, 591, 306};
    std::vector<int> vect;
    std::deque<int> deq;
    int num;
    for (int i = 1; i < argc; i++){
        num = atoi(argv[i]);
        try{
            if (num <= 0 ){
                throw std::invalid_argument("Wrong input");
            }
        }catch (std::exception &e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
        vect.push_back(num);
        deq.push_back(num);
    }
    PmergeMe pmm;
    try{
        if (pmm.hasRepeats(vect, vect.size())){
                throw std::invalid_argument("Repeated ints");
            }
        }catch (std::exception &e){
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }

    /*std::cout << "=== Input: ";
    for (size_t i = 0; i < vect.size(); i++) std::cout << vect[i] << " ";
    std::cout << "\n\n";*/
    clock_t start = clock();
    std::vector<int> resVect = pmm.fordJohnson(vect);
    clock_t end = clock();

    // Convert to microseconds
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vect.size()
              << " elements with std::vector : "
              << duration << " us" << std::endl;

    start = clock();
    std::deque <int> resDeq = pmm.fordJohnson(deq);
    end = clock();
    // Convert to microseconds
    duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : "
              << duration << " us" << std::endl;

    std::cout << "\n=== Final sorted result ===\n";
    for (size_t i = 0; i < resVect.size(); i++) std::cout << resVect[i] << " ";
    std::cout << "\n";
    return 0;
}